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

// 题40 组合总和II
void backtrackingSolution::combineSumBacktracking2(vector<int>& candidates, int target,
	int sum, int start, vector<bool>& used) {
	//终止条件
	if (sum == target) {
		combineSumRes2.push_back(combineSumPath2);
		return;
	}

	// 单层搜索
	for (int i = start; i < candidates.size() && sum +candidates[i]<= target; i++) {
		// 判断同一层数据是否重复，重复则跳过 先确定 i > 0，否则i-1越界
		if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
			continue;
		}
		sum += candidates[i];
		combineSumPath2.push_back(candidates[i]);
		used[i] = true;
		combineSumBacktracking2(candidates, target, sum, i + 1, used);
		sum -= candidates[i]; // 回溯
		combineSumPath2.pop_back();
		used[i]= false;
	}
}

vector<vector<int>> backtrackingSolution::combinationSum2(vector<int>& candidates, int target) {
	combineSumRes2.clear();
	combineSumPath2.clear();
	vector<bool> used(candidates.size(),false);// 定义used数组，记录是否遍历
	sort(candidates.begin(), candidates.end()); //排序
	combineSumBacktracking2(candidates, target, 0, 0, used);
	return combineSumRes2;
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




//题93 复原IP地址
vector<string> IPres;
// 判断当前子串是否是有效的地址
bool backtrackingSolution::isValid(const string& s, int start, int end) {
	// 
	if (start > end) return false;
	
	// 有前导0 并且不是仅有一位0
	if (s[start] == '0' && start != end) return false;

	// 判断是否有违法字符和超过255
	int num = 0;
	for (int i = start; i <= end; i++) {
		if (s[i] > '9' || s[i] < '0') return false;
		num = num * 10 + (s[i] - '0');
		if (num > 255) return false;
	}
	return true;

}
void backtrackingSolution::IPbacktracking(string& s, int start, int pointNum) {
	// 终止条件
	if (pointNum == 3) {
		if (isValid(s, start, s.size() - 1)) {
			IPres.push_back(s);
		}
		return;
	}

	// 单层回溯判断
	for (int i = start; i < s.size(); i++) {
		if (isValid(s, start, i)) {
			pointNum++;
			s.insert(s.begin() + i + 1, '.'); // 插入逗点表示分割
			IPbacktracking(s, i + 2, pointNum); // 从i+2起始 多一个逗点
			pointNum--;        // 回溯
			s.erase(s.begin() + i + 1);
		}
		else break;
	}
}

vector<string> backtrackingSolution::restoreIpAddresses(string s) {
	IPres.clear();
	IPbacktracking(s, 0, 0);
	return IPres;
}


//题90 子集II
vector<vector<int>> subResII;
vector<int> subPathII;
void backtrackingSolution::subsetsBacktrackingII(vector<int>& nums, 
	int start, vector<bool>& used) {

	// 收集所有节点
	subResII.push_back(subPathII);

	// 单层回溯判断
	for (int i = start; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}

		used[i] = true;
		subPathII.push_back(nums[i]);
		subsetsBacktrackingII(nums, i + 1, used);
		used[i] = false; //回溯
		subPathII.pop_back();
	
	}
}
vector<vector<int>> backtrackingSolution::subsetsWithDup(vector<int>& nums) {
	
	subResII.clear();
	subPathII.clear();
	vector<bool> used(nums.size(), false);
	sort(nums.begin(),nums.end()); // 去重要先排序
	subsetsBacktrackingII(nums, 0, used);
	return subResII;
}


//题491 递增子序列
vector<vector<int>> subsequenceRes;
vector<int> subsequencePath;
void backtrackingSolution::subsequenceBacktracking(vector<int>& nums, int start) {
	// 收集所有大于2的节点
	if (subsequencePath.size() >= 2) {
		subsequenceRes.push_back(subsequencePath);
	}

	// 单层回溯判断
	unordered_set<int> uset; //无法原数组进行排序，使用哈希表做去重
	for (int i = start; i < nums.size(); i++) {
		if ((!subsequencePath.empty() && nums[i] < subsequencePath.back()) //当前元素小于数组最后一位
			|| uset.find(nums[i]) != uset.end()) { //当前层有重复元素 跳过
			continue;
		}
		uset.insert(nums[i]);
		subsequencePath.push_back(nums[i]);
		subsequenceBacktracking(nums, i + 1);
		subsequencePath.pop_back();// 回溯，这里uset不用回溯，因为在每一层会重新定义
	
	}
}

vector<vector<int>> backtrackingSolution::findSubsequences(vector<int>& nums) {
	subsequencePath.clear();
	subsequenceRes.clear();
	subsequenceBacktracking(nums, 0);
	return subsequenceRes;
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


//题47 全排列II
vector<vector<int>> perResII;
vector<int> perPathII;
void backtrackingSolution::perBacktrackingII(vector<int>& nums, vector<bool>& used) {
	// 终止条件 叶子节点
	if (perPathII.size() == nums.size()) {
		perResII.push_back(perPathII);
		return;
	}
	// 单层回溯判断
	for (int i = 0; i < nums.size(); i++) {
		//先判断同一层是否重复
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}
		if (used[i] == true) continue; // 同一枝上已经遍历过
		used[i] = true;
		perPathII.push_back(nums[i]);
		perBacktrackingII(nums, used);
		used[i] = false; // 回溯
		perPathII.pop_back();
	}

}

vector<vector<int>> backtrackingSolution::permuteUnique(vector<int>& nums) {
	perPathII.clear();
	perResII.clear();
	sort(nums.begin(), nums.end());
	vector<bool> used(nums.size(), false);
	perBacktrackingII(nums, used);
	return perResII;
}

//题332 重新安排行程
// unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtrackingSolution::fIbacktracking(int ticketNum, vector<string>& res) {
	// 终止条件
	if (res.size() == ticketNum + 1) {
		return true;
	}

	for (pair<const string, int>& target : targets[res[res.size() - 1]]) {
		if (target.second > 0) {
			res.push_back(target.first);
			target.second--;
			if (fIbacktracking(ticketNum, res)) return true;
			res.pop_back();
			target.second++;
		}
	
	}
	return false;
}

vector<string> backtrackingSolution::findItinerary(vector<vector<string>>& tickets) {
	targets.clear();
	vector<string> res;
	for (const vector<string>& vec : tickets) {
		targets[vec[0]][vec[1]]++;
	}
	res.push_back("JFK");
	fIbacktracking(tickets.size(), res);
	return res;
}