#ifndef _GREEDY_H_
#define _GREEDY_H_
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

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

private:

};



#endif // !_GREEDY_H_
#pragma once
