#include "dynamicprogram.h"


// 题509 斐波那契数列
int dpSolution::fib(int n) {
	if (n <= 1) return n; // 先判断n 
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
//	if (n <= 1) return dp[n]; //报错，输入零时，也会初始化dp[1]
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	
	}
	return dp[n];
}


// 题70 爬楼梯
int dpSolution::climbStairs(int n) {
	if (n <= 1) return n;
	vector<int> dp(3);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		int sum = dp[1] + dp[2];
		dp[1] = dp[2];
		dp[2] = sum;
	}
	return dp[2];
}

// 题746 使用最小花费爬楼梯
int dpSolution::minCostClimbingStairs(vector<int>& cost) {
	if (cost.size() <= 1) return 0;
	// 定义dp数组 跳到楼顶 +1
	vector<int> dp(cost.size() + 1);

	// 初始化
	dp[0] = 0;
	dp[1] = 0;

	// 开始背包遍历
	for (int i = 2; i <= cost.size(); i++) {
		dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
	}

	return dp[cost.size()];

}

// 背包问题测试
//二维dp数组
void dpSolution::test_wei_bag_problem() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagweight = 4;

	// dp二维数组 大小=物品数量 初始化为0
	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

	// 初始化
	for (int j = weight[0]; j < bagweight; j++) {
		dp[0][j] = value[0];
	}

	for (int i = 1; i < weight.size(); i++) { //遍历物品
		for (int j = 0; j <= bagweight; j++) { // 遍历背包
			if (j < weight[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		
		}
	
	}
	cout << dp[weight.size() - 1][bagweight] << endl;

}

// 一维dp数组
void dpSolution::test_1_wei_bag_problem() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagweight = 4;

	// 初始化一维数组
	vector<int> dp(bagweight + 1, 0);
	for (int i = 0; i < weight.size(); i++) {
		for (int j = bagweight; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[bagweight] << endl;
}

// 题416 分割等和子集
// 01背包
bool dpSolution::canPartition(vector<int>& nums) {
	int sum = 0;

	// 初始化dp数组
	vector<int> dp(10001, 0);

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}

	if (sum % 2 == 1) return false;
	int target = sum / 2;

	// 开始01背包
	for (int i = 0; i < nums.size(); i++) {
		for (int j = target; j >= nums[i]; j--) {
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		
		}
	}
	if (dp[target] == target) return true;
	return false;
}

// 题494 目标和
int dpSolution::findTargetSumWays(vector<int>& nums, int target) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	if (abs(target) > sum) return 0;
	if ((target + sum) % 2 == 1) return 0;
	int bagSize = (target + sum) / 2;
	vector<int> dp(bagSize + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = bagSize; j >= nums[i]; j--) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[bagSize];
}

// 题62 不同路径
// 二维dp数组
int dpSolution::uniquePaths(int m, int n) {
	// 定义m×n的二维数组
	vector<vector<int>> dp(m, vector<int>(n, 0));

	// 初始化dp数组
	for (int i = 0; i < m; i++) {
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {
		dp[0][j] = 1;
	}

	// 开始背包
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

// 题64 最小路径和
int dpSolution::minPathSum(vector<vector<int>>& grid) {
	// 求输入数组的长宽
	int width = grid[0].size();
	int length = grid.size();

	vector<vector<int>> dp(length, vector<int>(width, 0));
	
	// 初始化
	dp[0][0] = grid[0][0];
	for (int i = 1; i < length;i++) {
		dp[i][0] = grid[i][0] + dp[i - 1][0];

	}
	for (int j = 1; j < width; j++) {
		dp[0][j] = grid[0][j] + dp[0][j - 1];
	}

	// 开始背包
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		
		}
	}
	return dp[length - 1][width - 1];
}

// 题63 不同路径II
int dpSolution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int length = obstacleGrid.size();
	int width = obstacleGrid[0].size();

	// 障碍物在起点或者终点的情况
	if (obstacleGrid[0][0] == 1 || obstacleGrid[length - 1][width - 1] == 1) {
		return 0;
	}

	// 定义动态规划数组
	vector<vector<int>> dp(length, vector<int>(width, 0));

	// 初始化数组
	for (int i = 0; i < length&&obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
	for (int j = 0; j < width&&obstacleGrid[0][j] == 0; j++)dp[0][j] = 1;

	// 开始遍历 从左到右，从上到下
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			if (obstacleGrid[i][j] == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[length - 1][width - 1];
}

// 题343 整数拆分
int dpSolution::integerBreak(int n) {
	// 定义动规数组 包括dp[0]
	vector<int> dp(n + 1);

	// 初始化
	dp[2] = 1;

	// 开始遍历 从小到大
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], max(dp[i - j] * j, (i - j)*j));
		}
	}

	return dp[n];

}


// 题96 不同的二叉搜索树
int dpSolution::numTrees(int n) {
	// 定义动规数组
	vector<int> dp(n+1);

	// 初始化
	dp[0] = 1;

	// 开始遍历
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] += dp[j - 1] * dp[i - j];
		
		}
	}
	return dp[n];
}

// 题1049 最后一块石头的重量
int dpSolution::lastStoneWeightII(vector<int>& stones) {
	// 定义动规数组
	vector<int> dp(15001, 0);
	int sum = 0;
	for (int i = 0; i < stones.size(); i++) {
		sum += stones[i];
	}
	int target = sum / 2;
	for (int i = 0; i < stones.size(); i++) { // 物品遍历
		for (int j = target; j >= stones[i]; j--) { // 背包遍历
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	}
	return sum - dp[target] - dp[target];

}

// 题474 一和零
int dpSolution::findMaxForm(vector<string>& strs, int m, int n) {
	// 创建dp数组 初始化为0
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (string str : strs) { //遍历物品
		int Onenum = 0, Zeronum = 0;
		for (char c : str) {
			if (c == '0') Zeronum++;
			else Onenum++;
		}
		// 背包遍历
		for (int i = m; i >= Zeronum; i--) { 
			for (int j = n; j >= Onenum; j--) {
				dp[i][j] = max(dp[i][j], dp[i - Zeronum][j - Onenum] + 1);
			}
		}
	}
	return dp[m][n];

}

// 题518 零钱兑换II
int dpSolution::change(int amount, vector<int>& coins) {
	// 定义dp数组 
	vector<int> dp(amount + 1, 0);
	// 初始化数组
	dp[0] = 1;
	// 先遍历物品，再遍历背包 求组合数
	for (int i = 0; i < coins.size(); i++) {
		for (int j = coins[i]; j <= amount; j++) {
			dp[j] += dp[j - coins[i]];
		}
	}
	return dp[amount];
}

// 题377 组合总和IV
int dpSolution::combinationSum4(vector<int>& nums, int target) {
	// 定义dp数组
	vector<int> dp(target + 1, 0);
	// 初始化
	dp[0] = 1;
	// 先遍历背包再遍历物品，求排列数
	for (int j = 0; j <= target; j++) {
		for (int i = 0; i < nums.size(); i++) {
			if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j-nums[i]]) {
				dp[j] += dp[j - nums[i]];
			}
		}
	}
	return dp[target];

}

// 爬楼梯（进阶，完全背包）
int dpSolution::climbStairs2(int n,int m ) {
	// 定义dp数组
	vector<int> dp(n + 1, 0);

	// 初始化
	dp[0] = 1;

	// 遍历顺序 先背包再物品求排列数
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < -m; j++) {
			if (i - j >= 0) dp[i] += dp[i - j];
		}
	
	}
	return dp[n];

}

// 题322 零钱兑换
int dpSolution::coinChange(vector<int>& coins, int amount) {
	//定义dp数组
	vector<int> dp(amount + 1, INT_MAX);

	// 初始化
	dp[0] = 0;

	//遍历 先物品再背包
	for (int i = 0; i < coins.size(); i++) { 
		for (int j = coins[i]; j <= amount; j++) {
			if (dp[j - coins[i]] != INT_MAX) { // 若是初始值则跳过
				dp[j] = min(dp[j - coins[i]] + 1, dp[j]); // 递推公式
			}
			
		}
	
	}
	if (dp[amount] == INT_MAX) return -1;
	return dp[amount];
}

// 题279 完全平方数
int dpSolution::numSquares(int n) {
	// 定义dp数组 递推公式为求最小值，初始化为INT_MAX
	vector<int> dp(n + 1, INT_MAX);

	// 初始化
	dp[0] = 0;

	// 遍历 先背包再物品
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]); // 递推公式
		}
	
	}
	return dp[n];
}