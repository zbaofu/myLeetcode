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

	// 背包问题测试
	void test_wei_bag_problem(); // 二维dp数组
	void test_1_wei_bag_problem(); // 一维dp数组

	// 题416 分割等和子集
	bool canPartition(vector<int>& nums);

	// 题494 目标和
	int findTargetSumWays(vector<int>& nums, int target);




};



#endif // !_DYNAMICPROGRAM_H_
#pragma once
