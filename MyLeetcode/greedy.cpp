#include "greedy.h"


// 题455 分发饼干
int greedySolution::findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int res = 0;
	int index = s.size() - 1;
	for (int i = g.size() - 1; i >= 0; i--) {
		if (index >= 0 && s[index] >= g[i] ) { // 先判断index大于等于0
			index--;
			res++;
		}
	}
	return res;

}

// 题376 摆动序列
int greedySolution::wiggleMaxLength(vector<int>& nums) {
	if (nums.size() <= 1) return nums.size();

	int prediff = 0; // 与前一个数字的差值
	int curdiff = 0; // 与后一个数字的差值
	int res = 1; // 记录峰值个数，默认序列最右边有一个峰值
	for (int i = 0; i < nums.size()-1; i++) {

		curdiff = nums[i + 1] - nums[i];
		// 出现峰值
		if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)) {
			res++;
			prediff = curdiff; //只在摆动变化时，更新前一个差值
		}
	}
	return res;
}

// 题122 买卖股票的最佳时机
int greedySolution::maxProfit(vector<int>& prices) {
	int res = 0; //记录利润
	int diff = 0;
	for (int i = 0; i < prices.size()-1; i++) {
		diff = prices[i + 1] - prices[i];
		if (diff > 0) {
			res += diff;
		}
	}
	return res;
}

// 题55 跳跃游戏
bool greedySolution::canJump(vector<int>& nums) {
	if (nums.size() == 1) return true;
	int cover = 0;

	for (int i = 0; i <= cover; i++) {
		cover = max(i + nums[i], cover);
		if (cover >= nums.size()-1) return true;
	}
	return false;

}

// 题53 最大子数组和
int greedySolution::maxSubArray(vector<int>& nums) {
	int count = 0;
	int res = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		count += nums[i];
		if (res < count) res = count; // 加上当前元素大于res，则更新count
		if (count < 0) count = 0; // 加上当前元素小于0，则count归0
	}
	return res;
}

// 题45 跳跃游戏II
int greedySolution::jump(vector<int>& nums) {
	if (nums.size() == 1) return 0;
	int curDis = 0; // 当前覆盖范围
	int nextDis = 0;  // 下一步覆盖范围
	int res = 0; // 跳跃次数
	for (int i = 0; i < nums.size(); i++) {
		nextDis = max(nums[i] + i,nextDis); // 更新下一步范围

		if (i == curDis) { // 走到当前最大覆盖范围
			curDis = nextDis; // 更新当前最大范围为下一步最大范围
			res++; // 跳跃次数加一
			if (nextDis >= nums.size() - 1) break;
		}
	}
	return res;
}

// 题1005 K次取反后最大化的数组和
int greedySolution::largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end(), cmp); // 从大到小排序
	for (int i = 0; i < nums.size(); i++) { // 从大到小遍历，遇到负数则反转
		if (nums[i] < 0 && k>0) {
			nums[i] *= -1;
			k--;
		}
	}
	if (k % 2 == 1) nums[nums.size() - 1] *= -1; // 多余的k值用于反转最小值
	int res = 0;
	for (int a : nums) res += a; // 求和
	return res;
}


// 题134 加油站
int greedySolution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int sum = 0; // 跑完全程邮箱总油量
	int min = INT_MAX; // 油箱中油量最小值
	for (int i = 0; i < gas.size(); i++) {
		int rest = gas[i] - cost[i];
		sum += rest;
		if (sum < min) {
			min = sum;
		}
	}
	if (sum < 0) return -1; // 总量小于0，则肯定跑不了一圈
	if (min >= 0) return 0; // 邮箱中油量最小值都大于等于0，则直接从0出发
	// 若最小值是负数，则从后向前遍历，直到哪个节点的油量能填平该负数
	for (int i = gas.size() - 1; i >= 0; i--) {
		int rest = gas[i] - cost[i];
		min += rest;
		if (min >= 0) {
			return i;
		}
	}
	return -1;
}

int greedySolution::canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
	int curSum = 0;
	int totalSum = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++) {
		curSum += gas[i] - cost[i];
		totalSum += gas[i] - cost[i];
		if (curSum < 0) {
			start = i + 1;
			curSum = 0;
		}
	}
	if (totalSum < 0) return -1;
	return start;
}

// 题135 分发糖果
int greedySolution::candy(vector<int>& ratings) {
	// 初始化糖果分配数组
	vector<int> candyvec(ratings.size(), 1);

	// 从左到右遍历，右孩子大于左孩子
	for (int i = 0; i < ratings.size() - 1; i++) {
		if (ratings[i + 1] > ratings[i]) {
			candyvec[i + 1] = candyvec[i] + 1;
		}
	}

	// 从右到左遍历，左孩子大于右孩子
	for (int i = ratings.size() - 1; i >= 1; i--) {
		if (ratings[i - 1] > ratings[i]) {
			candyvec[i - 1] = max(candyvec[i - 1], candyvec[i] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < candyvec.size(); i++) {
		res += candyvec[i];
	}
	//for (int a : candyvec) res += a;
	return res;
}

// 题860 柠檬水找零
bool greedySolution::lemonadeChange(vector<int>& bills) {
	int five = 0, ten = 0, twenty = 0;
	for (int bill : bills) {
		// 收到5元
		if (bill == 5) five++;

		// 收到10元
		if (bill == 10) {
			if (five <= 0) return false;
			five--; // 找5元
			ten++;
			
		}
		
		// 收到20元
		if (bill == 20) {
			if (five>0 && ten > 0) {
				ten--; //找10+5
				five--;
				twenty++;
			}
			else if(five >= 3) {
				five -= 3; //找5+5+5
				twenty++;
			}
			else return false;
		}
	}
	return true;
}

// 题406 根据身高重建队列
vector<vector<int>> greedySolution::reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), cmp2); // 按身高从大到小排序
	vector<vector<int>> que;
	for (int i = 0; i < people.size(); i++) {
		int position = people[i][1]; // 记录插入位置
		que.insert(que.begin() + position, people[i]); // 将people[i]插入指定k值的位置
	}
	return que;
}

// 题452 用最少数量的箭引爆气球
int greedySolution::findMinArrowShots(vector<vector<int>>& points) {
	if (points.size() == 0) return 0;
	sort(points.begin(), points.end(), cmp3); // 按照左边界从小到大排序
	int res = 1; // 记录箭的数量
	for (int i = 0; i < points.size() - 1; i++) {
		if (points[i][1] < points[i + 1][0]) { // 当前气球与下一个没有重叠，加一箭
			res++;
		}
		else { // 当前气球与下一个重叠，则更新下一个气球右边界为当前和下一气球有边界的最小值
			points[i+1][1] = min(points[i][1], points[i + 1][1]);
		}
	}
	return res;
}

// 题435 无重叠区间
// 思路与上一题类似，只需要在重叠判断加上边界相等情况，最后的返回值为size()-res
int greedySolution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.size() == 0) return 0;
	sort(intervals.begin(), intervals.end(), cmp3);
	int res = 1;
	for (int i = 0; i < intervals.size() - 1; i++) {
		if (intervals[i][1] <= intervals[i + 1][0]) { //没有重叠
			res++;
		}
		else {
			intervals[i + 1][1] = min(intervals[i][1], intervals[i + 1][1]);
		}
	}
	return intervals.size() - res;
}

// 题763 划分字母区间
vector<int> greedySolution::partitionLabels(string s) {
	int hash[27] = { 0 }; // 记录每个字母出现的最后位置
	for (int i = 0; i < s.size(); i++) {
		hash[s[i] - 'a'] = i;
	}
	int left = 0, right = 0;
	vector<int> res;
	for (int i = 0; i < s.size(); i++) {
		right = max(right, hash[s[i] - 'a']);
		if (i == right) {
			res.push_back(right - left + 1);
			left = right + 1;
		}
	}
	return res;
}


// 题56 合并区间
vector<vector<int>> greedySolution::merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res; // 定义结果集
	if (intervals.size() == 0) return res;
	sort(intervals.begin(), intervals.end(), cmp3); // 按左边界从小到大排序
	res.push_back(intervals[0]); //第一个区间 

	for (int i = 1; i < intervals.size() ; i++) {
		if (res.back()[1] < intervals[i][0]) { // 无重叠
			res.push_back(intervals[i]);
		}
		else { // 重叠 更新最后元素的右边界
			res.back()[1] = max(res.back()[1], intervals[i][1]);
		}
	}
	return res;
}

// 题738 单调递增的数字
int greedySolution::monotoneIncreasingDigits(int n) {
	string str = to_string(n); // 将给定数字转成字符串
	int flag = str.size();  // 记录需要换成9的起始位

	// 从后向前遍历，找到出现递减的位置
	for (int i = str.size() - 1; i >= 1; i--) {
		if (str[i - 1] > str[i]) {// 出现递减 记录递减位置
			str[i - 1]--;
			flag = i;
		} 
	}
	// 将出现递减位后数字替换成9
	for (int i = flag; i < str.size(); i++) {
		str[i] = '9';
	}
	return stoi(str);
}

// 题968 监控二叉树
// 二叉树深度优先遍历 后序遍历 左右中
int greedySolution::cameraTraversal(TreeNode* cur) {
	// 节点三种状态 0：未覆盖到 1：有摄像头 2：有覆盖
	// 终止条件 空节点 设置为有覆盖 才能设置叶子节点父节点有摄像头
	if (cur == NULL) return 2;

	// 遍历
	int left = cameraTraversal(cur->left);
	int right = cameraTraversal(cur->right);

	// 情况一 左右节点都有覆盖
	if (left == 2 && right == 2) return 0;

	// 情况二 左右节点至少有一个无覆盖则需要加一个相机
	if (left == 0 || right == 0) {
		res++;
		return 1;
	}

	// 情况三 左右节点至少有一个有相机则该节点有覆盖
	if (left == 1 || right == 1) {
		return 2;
	}
	return -1; // 不会执行到这一步

}

int greedySolution::minCameraCover(TreeNode* root) {
	res = 0;
	if (cameraTraversal(root) == 0) { //进行遍历并判断根节点有无覆盖 无覆盖则根节点放置相机
		res++;
	}
	return res;
}

