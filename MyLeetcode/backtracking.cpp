#include "backtracking.h"

// 题77 组合
void backtrackingSolution::combineBacktracking(int n, int k, int start) {
	//终止条件
	if (combinePath.size() == k) {
		combineRes.push_back(combinePath);
		return;
	
	}

	// for循环加递归
	// for (int i = start; i <= n; i++)
	for (int i = start; i <= n - (k - combinePath.size()) + 1; i++)  //优化
	{
		combinePath.push_back(i); // 将节点加入path
		combineBacktracking(n, k, i + 1);
		combinePath.pop_back(); //回溯，撤销加入的节点
	}
}


vector<vector<int>> backtrackingSolution::combine(int n, int k) {
	combinePath.clear();
	combineRes.clear();
	combineBacktracking(n, k, 1);
	return combineRes;
}

// 题216 组合总和III
void backtrackingSolution::combine3Backingtracking(int n, int k, int sum, int start) {
	// 剪枝操作
	if (sum > n) {
		return;
	}

	// 终止条件
	if (combine3Path.size() == k) {
		if (sum == n) {
			combine3Res.push_back(combine3Path);
		}
		return;
	}

	for (int i = start; i <= 9; i++) {
		sum += i; 
		combine3Path.push_back(i);
		combine3Backingtracking(n, k, sum, i + 1);
		combine3Path.pop_back(); // 回溯
		sum -= i; // 回溯
	}
}


vector<vector<int>> backtrackingSolution::combinationSum3(int k, int n) {
	combine3Path.clear();
	combine3Res.clear();
	combine3Backingtracking(n, k, 0, 1);
	return combine3Res;

}


// 题17 电话号码的字母组合
void backtrackingSolution::lettercombineBacktracking(const string& digits, int index) {
	// 终止条件 遍历完字符
	if (index == digits.size()) {
		letterRes.push_back(letterPath);
		return;
	}

	int digit = digits[index] - '0';
	string letters = letterMap[digit];
	for (int i = 0; i < letters.size(); i++) {
		letterPath.push_back(letters[i]);
		lettercombineBacktracking(digits, index + 1); //这里不是i+1，而是下一个数字
		letterPath.pop_back();
	}
}

vector<string> backtrackingSolution::letterCombinations(string digits) {
	letterPath.clear();
	letterRes.clear();
	if (digits.size() == 0) return letterRes;
	lettercombineBacktracking(digits,0);
	return letterRes;
}


// 题39 组合总和
void backtrackingSolution::combineSumBacktracking(vector<int>& candidates, int target, int sum, int start) {
	if (sum > target) return;
	if (sum == target) {
		combineSumRes.push_back(combineSumPath);
		return;
	}

	for (int i = start; i < candidates.size(); i++) {
		sum += candidates[i];
		combineSumPath.push_back(candidates[i]);
		combineSumBacktracking(candidates, target, sum, i);
		sum -= candidates[i];
		combineSumPath.pop_back();
	
	}

}
vector<vector<int>> backtrackingSolution::combinationSum(vector<int>& candidates, int target) {
	combineSumRes.clear();
	combineSumPath.clear();
	combineSumBacktracking(candidates, target, 0, 0);
	return combineSumRes;

}

// 题131 分割回文串
vector<vector<string>> partRes;
vector<string> partPath;
bool backtrackingSolution::isPalindrome(const string& s, int start, int end) {
	for (int i = start, j = end; i < j; i++, j--) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}
void backtrackingSolution::partBackingtracking(const string& s, int start) {
	// 判断终止递归
	if (start >= s.size()) {
		partRes.push_back(partPath);
		return;
	}

	for (int i = start; i < s.size(); i++) {
		if (isPalindrome(s, start, i)) {
			string str = s.substr(start, i - start + 1);
			partPath.push_back(str);
		}
		else {
			continue;
		}
		partBackingtracking(s, i + 1);
		partPath.pop_back();
	}
}
vector<vector<string>> backtrackingSolution::partition(string s) {
	partRes.clear();
	partPath.clear();
	partBackingtracking(s, 0);
	return partRes;
}

//题78 子集
vector<vector<int>> subRes;
vector<int> subPath;
void backtrackingSolution::subsetsBacktracking(vector<int>& nums, int start) {
	subRes.push_back(subPath);
	//终止条件
	if (start > nums.size()) {
		return;
	}

	for (int i = start; i < nums.size(); i++) {
		subPath.push_back(nums[i]);
		subsetsBacktracking(nums, i + 1);
		subPath.pop_back();
	}
}

vector<vector<int>> backtrackingSolution::subsets(vector<int>& nums) {
	subPath.clear();
	subRes.clear();
	subsetsBacktracking(nums, 0);
	return subRes;
}


//题46 全排列
vector<vector<int>> perRes;
vector<int> perPath;
void backtrackingSolution::perBacktracking(vector<int>& nums, vector<bool>& used) {
	//终止
	if (perPath.size() == nums.size()) {
		perRes.push_back(perPath);
		return;
	}

	//单层判断
	for (int i = 0; i < nums.size(); i++) {
		if (used[i] == true) continue;
		used[i] = true;
		perPath.push_back(nums[i]);
		perBacktracking(nums, used);
		used[i] = false;
		perPath.pop_back();
	}
}

vector<vector<int>> backtrackingSolution::permute(vector<int>& nums) {
	perPath.clear();
	perRes.clear();
	vector<bool> used(nums.size(), false);
	perBacktracking(nums, used);
	return perRes;
}