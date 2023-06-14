#include "dynamicprogram.h"


// ��509 쳲���������
int dpSolution::fib(int n) {
	if (n <= 1) return n; // ���ж�n 
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
//	if (n <= 1) return dp[n]; //����������ʱ��Ҳ���ʼ��dp[1]
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	
	}
	return dp[n];
}


// ��70 ��¥��
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

// �����������
//��άdp����
void dpSolution::test_wei_bag_problem() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagweight = 4;

	// dp��ά���� ��С=��Ʒ���� ��ʼ��Ϊ0
	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

	// ��ʼ��
	for (int j = weight[0]; j < bagweight; j++) {
		dp[0][j] = value[0];
	}

	for (int i = 1; i < weight.size(); i++) { //������Ʒ
		for (int j = 0; j <= bagweight; j++) { // ��������
			if (j < weight[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		
		}
	
	}
	cout << dp[weight.size() - 1][bagweight] << endl;

}

// һάdp����
void dpSolution::test_1_wei_bag_problem() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagweight = 4;

	// ��ʼ��һά����
	vector<int> dp(bagweight + 1, 0);
	for (int i = 0; i < weight.size(); i++) {
		for (int j = bagweight; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[bagweight] << endl;
}

// ��416 �ָ�Ⱥ��Ӽ�
// 01����
bool dpSolution::canPartition(vector<int>& nums) {
	int sum = 0;

	// ��ʼ��dp����
	vector<int> dp(10001, 0);

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}

	if (sum % 2 == 1) return false;
	int target = sum / 2;

	// ��ʼ01����
	for (int i = 0; i < nums.size(); i++) {
		for (int j = target; j >= nums[i]; j--) {
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		
		}
	}
	if (dp[target] == target) return true;
	return false;
}

// ��494 Ŀ���
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

// ��62 ��ͬ·��
// ��άdp����
int dpSolution::uniquePaths(int m, int n) {
	// ����m��n�Ķ�ά����
	vector<vector<int>> dp(m, vector<int>(n, 0));

	// ��ʼ��dp����
	for (int i = 0; i < m; i++) {
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {
		dp[0][j] = 1;
	}

	// ��ʼ����
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

// ��64 ��С·����
int dpSolution::minPathSum(vector<vector<int>>& grid) {
	// ����������ĳ���
	int width = grid[0].size();
	int length = grid.size();

	vector<vector<int>> dp(length, vector<int>(width, 0));
	
	// ��ʼ��
	dp[0][0] = grid[0][0];
	for (int i = 1; i < length;i++) {
		dp[i][0] = grid[i][0] + dp[i - 1][0];

	}
	for (int j = 1; j < width; j++) {
		dp[0][j] = grid[0][j] + dp[0][j - 1];
	}

	// ��ʼ����
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		
		}
	}
	return dp[length - 1][width - 1];
}

// ��63 ��ͬ·��II
int dpSolution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int length = obstacleGrid.size();
	int width = obstacleGrid[0].size();

	// �ϰ������������յ�����
	if (obstacleGrid[0][0] == 1 || obstacleGrid[length - 1][width - 1] == 1) {
		return 0;
	}

	// ���嶯̬�滮����
	vector<vector<int>> dp(length, vector<int>(width, 0));

	// ��ʼ������
	for (int i = 0; i < length&&obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
	for (int j = 0; j < width&&obstacleGrid[0][j] == 0; j++)dp[0][j] = 1;

	// ��ʼ���� �����ң����ϵ���
	for (int i = 1; i < length; i++) {
		for (int j = 1; j < width; j++) {
			if (obstacleGrid[i][j] == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[length - 1][width - 1];
}