#ifndef _HASHTABLE_H
#define _HSAHTABLE_H
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <unordered_set>
#include <unordered_map>


using namespace std; //#pragma once

class hashtableSolution1 {
public:
	// 题242 有效的字母异位词
	bool isAnagram(string s, string t);
	
	//题349 两个数组的交集
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

	//题202 快乐数
	bool isHappy(int n);
	// 求n各位的平方和
	int getSum(int n);

	//题1 两数之和
	vector<int> twoSum(vector<int>& nums, int target);

	//题454 四数相加
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

	//题383 赎金信
	bool canConstruct(string ransomNote, string magazine);

	//题15 三数之和
	vector<vector<int>> threeSum(vector<int>& nums);

	//题18 四数之和
	vector<vector<int>> fourSum(vector<int>& nums, int target);

private:

};








#endif
