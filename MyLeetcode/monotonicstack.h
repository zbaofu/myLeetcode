#ifndef _MONOTONICSTACK_H
#define _MONOTONICSTACK_H

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class monstack {
public:
	// 题739 每日温度
	vector<int> dailyTemperatures(vector<int>& temperatures);

	// 题496 下一个更大元素
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);




};



#endif // !_MONOTONICSTACK_H
#pragma once
