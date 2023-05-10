#ifndef _GREEDY_H_
#define _GREEDY_H_
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

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

private:

};



#endif // !_GREEDY_H_
#pragma once
