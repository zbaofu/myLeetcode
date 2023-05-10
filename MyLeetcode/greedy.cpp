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