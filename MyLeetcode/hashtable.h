#ifndef _HASHTABLE_H
#define _HSAHTABLE_H
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <unordered_set>
#include <unordered_map>


using namespace std; //#pragma once

class hashtableSolution1 {
public:
	// ��242 ��Ч����ĸ��λ��
	bool isAnagram(string s, string t);
	
	//��349 ��������Ľ���
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

	//��202 ������
	bool isHappy(int n);
	// ��n��λ��ƽ����
	int getSum(int n);

	//��1 ����֮��
	vector<int> twoSum(vector<int>& nums, int target);

	//��454 �������
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

	//��383 �����
	bool canConstruct(string ransomNote, string magazine);

	//��15 ����֮��
	vector<vector<int>> threeSum(vector<int>& nums);

	//��18 ����֮��
	vector<vector<int>> fourSum(vector<int>& nums, int target);

private:

};








#endif
