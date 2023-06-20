#pragma once
#ifndef _GREEDY_H_
#define _GREEDY_H_
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "binarytree.h"

using namespace std;



class greedySolution
{
public:
	// 题455 分发饼干
	int findContentChildren(vector<int>& g, vector<int>& s);

	// 题376 摆动序列
	int wiggleMaxLength(vector<int>& nums);

	// 题122 买卖股票的最佳时机
	int maxProfit(vector<int>& prices);

	// 题55 跳跃游戏
	bool canJump(vector<int>& nums);

	// 题53 最大子数组和
	int maxSubArray(vector<int>& nums);

	// 题45 跳跃游戏II
	int jump(vector<int>& nums);

	// 题1005 K次取反后最大化的数组和
	static bool cmp(int a, int b) {
		return abs(a) > abs(b); //按照绝对值从大到小排序
	}
	int largestSumAfterKNegations(vector<int>& nums, int k);

	// 题134 加油站
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost);

	// 题135 分发糖果
	int candy(vector<int>& ratings);

	// 题860 柠檬水找零
	bool lemonadeChange(vector<int>& bills);

	// 题406 根据身高重建队列
	static bool cmp2(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0]) return a[1] < b[1]; // 身高一样，则k值小的在前
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

	// 题452 用最少数量的箭引爆气球
	static bool cmp3(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	int findMinArrowShots(vector<vector<int>>& points);

	// 题435 无重叠区间
	int eraseOverlapIntervals(vector<vector<int>>& intervals);

	// 题763 划分字母区间
	vector<int> partitionLabels(string s);

	// 题56 合并区间
	vector<vector<int>> merge(vector<vector<int>>& intervals);

	// 题738 单调递增的数字
	int monotoneIncreasingDigits(int n);

	// 题968 监控二叉树
	int res;
	int cameraTraversal(TreeNode* cur);
	int minCameraCover(TreeNode* root);


private:

};



#endif // !_GREEDY_H_

