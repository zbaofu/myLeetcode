#pragma once
#ifndef BACKTRACKING_H_
#define BACKTRACKING_H_

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class backtrackingSolution {
private:
	// 题17 电话号码的字母组合
	// 数字对应的字母表
	const string letterMap[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkf",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	};


public:
	// 题77 组合
	vector<vector<int>> combineRes;
	vector<int> combinePath;
	void combineBacktracking(int n, int k, int start);
	vector<vector<int>> combine(int n, int k);

	// 题216 组合总和III
	vector<vector<int>> combine3Res;
	vector<int> combine3Path;
	void combine3Backingtracking(int n,int k, int target,int start);
	vector<vector<int>> combinationSum3(int k, int n);

	// 题17 电话号码的字母组合
	vector<string> letterRes;
	string letterPath;
	void lettercombineBacktracking(const string& digits, int index);
	vector<string> letterCombinations(string digits);

	// 题39 组合总和
	vector<vector<int>> combineSumRes;
	vector<int> combineSumPath;
	void combineSumBacktracking(vector<int>& candidates, int target,int sum,int start);
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);

	// 题131 分割回文串
	vector<vector<string>> partRes;
	vector<string> partPath;
	bool isPalindrome(const string& s, int start, int end);
	void partBackingtracking(const string& s, int start);
	vector<vector<string>> partition(string s);

	//题78 子集
	vector<vector<int>> subRes;
	vector<int> subPath;
	void subsetsBacktracking(vector<int>& nums, int start);
	vector<vector<int>> subsets(vector<int>& nums);

	//题46 全排列
	vector<vector<int>> perRes;
	vector<int> perPath;
	void perBacktracking(vector<int>& nums, vector<bool>& used);
	vector<vector<int>> permute(vector<int>& nums);


};



#endif // !BACKTRACKING_H_
