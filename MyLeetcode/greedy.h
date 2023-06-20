#pragma once
#ifndef _GREEDY_H_
#define _GREEDY_H_
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include "binarytree.h"

using namespace std;



class greedySolution
{
public:
	// ��455 �ַ�����
	int findContentChildren(vector<int>& g, vector<int>& s);

	// ��376 �ڶ�����
	int wiggleMaxLength(vector<int>& nums);

	// ��122 ������Ʊ�����ʱ��
	int maxProfit(vector<int>& prices);

	// ��55 ��Ծ��Ϸ
	bool canJump(vector<int>& nums);

	// ��53 ����������
	int maxSubArray(vector<int>& nums);

	// ��45 ��Ծ��ϷII
	int jump(vector<int>& nums);

	// ��1005 K��ȡ������󻯵������
	static bool cmp(int a, int b) {
		return abs(a) > abs(b); //���վ���ֵ�Ӵ�С����
	}
	int largestSumAfterKNegations(vector<int>& nums, int k);

	// ��134 ����վ
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost);

	// ��135 �ַ��ǹ�
	int candy(vector<int>& ratings);

	// ��860 ����ˮ����
	bool lemonadeChange(vector<int>& bills);

	// ��406 ��������ؽ�����
	static bool cmp2(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0]) return a[1] < b[1]; // ���һ������kֵС����ǰ
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people);

	// ��452 �����������ļ���������
	static bool cmp3(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	int findMinArrowShots(vector<vector<int>>& points);

	// ��435 ���ص�����
	int eraseOverlapIntervals(vector<vector<int>>& intervals);

	// ��763 ������ĸ����
	vector<int> partitionLabels(string s);

	// ��56 �ϲ�����
	vector<vector<int>> merge(vector<vector<int>>& intervals);

	// ��738 ��������������
	int monotoneIncreasingDigits(int n);

	// ��968 ��ض�����
	int res;
	int cameraTraversal(TreeNode* cur);
	int minCameraCover(TreeNode* root);


private:

};



#endif // !_GREEDY_H_

