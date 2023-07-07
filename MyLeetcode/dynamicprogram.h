#ifndef _DYNAMICPROGRAM_H_
#define _DYNAMICPROGRAM_H_
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class dpSolution {
public:
	// 题509 斐波那契数列
	int fib(int n);

	// 题70 爬楼梯
	int climbStairs(int n);

	// 题746 使用最小花费爬楼梯
	int minCostClimbingStairs(vector<int>& cost);

	// 背包问题测试
	void test_wei_bag_problem(); // 二维dp数组
	void test_1_wei_bag_problem(); // 一维dp数组

	// 题416 分割等和子集
	bool canPartition(vector<int>& nums);

	// 题494 目标和
	int findTargetSumWays(vector<int>& nums, int target);

	// 题62 不同路径
	int uniquePaths(int m, int n);

	// 题64 最小路径和
	int minPathSum(vector<vector<int>>& grid);

	// 题63 不同路径II
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	// 题343 整数拆分
	int integerBreak(int n);

	// 题96 不同的二叉搜索树
	int numTrees(int n);


	// 题1049 最后一块石头的重量
	int lastStoneWeightII(vector<int>& stones);

	// 题474 一和零
	int findMaxForm(vector<string>& strs, int m, int n);


};



#endif // !_DYNAMICPROGRAM_H_
#pragma once
