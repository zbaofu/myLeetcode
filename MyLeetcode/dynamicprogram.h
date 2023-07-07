#ifndef _DYNAMICPROGRAM_H_
#define _DYNAMICPROGRAM_H_
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class dpSolution {
public:
	// ��509 쳲���������
	int fib(int n);

	// ��70 ��¥��
	int climbStairs(int n);

	// ��746 ʹ����С������¥��
	int minCostClimbingStairs(vector<int>& cost);

	// �����������
	void test_wei_bag_problem(); // ��άdp����
	void test_1_wei_bag_problem(); // һάdp����

	// ��416 �ָ�Ⱥ��Ӽ�
	bool canPartition(vector<int>& nums);

	// ��494 Ŀ���
	int findTargetSumWays(vector<int>& nums, int target);

	// ��62 ��ͬ·��
	int uniquePaths(int m, int n);

	// ��64 ��С·����
	int minPathSum(vector<vector<int>>& grid);

	// ��63 ��ͬ·��II
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

	// ��343 �������
	int integerBreak(int n);

	// ��96 ��ͬ�Ķ���������
	int numTrees(int n);


	// ��1049 ���һ��ʯͷ������
	int lastStoneWeightII(vector<int>& stones);

	// ��474 һ����
	int findMaxForm(vector<string>& strs, int m, int n);


};



#endif // !_DYNAMICPROGRAM_H_
#pragma once
