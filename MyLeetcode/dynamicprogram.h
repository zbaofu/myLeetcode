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

	// �����������
	void test_wei_bag_problem(); // ��άdp����
	void test_1_wei_bag_problem(); // һάdp����

	// ��416 �ָ�Ⱥ��Ӽ�
	bool canPartition(vector<int>& nums);

	// ��494 Ŀ���
	int findTargetSumWays(vector<int>& nums, int target);




};



#endif // !_DYNAMICPROGRAM_H_
#pragma once
