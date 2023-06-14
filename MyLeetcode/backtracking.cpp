#include "backtracking.h"

// ��77 ���
void backtrackingSolution::combineBacktracking(int n, int k, int start) {
	//��ֹ����
	if (combinePath.size() == k) {
		combineRes.push_back(combinePath);
		return;
	
	}

	// forѭ���ӵݹ�
	// for (int i = start; i <= n; i++)
	for (int i = start; i <= n - (k - combinePath.size()) + 1; i++)  //�Ż�
	{
		combinePath.push_back(i); // ���ڵ����path
		combineBacktracking(n, k, i + 1);
		combinePath.pop_back(); //���ݣ���������Ľڵ�
	}
}


vector<vector<int>> backtrackingSolution::combine(int n, int k) {
	combinePath.clear();
	combineRes.clear();
	combineBacktracking(n, k, 1);
	return combineRes;
}

// ��216 ����ܺ�III
void backtrackingSolution::combine3Backingtracking(int n, int k, int sum, int start) {
	// ��֦����
	if (sum > n) {
		return;
	}

	// ��ֹ����
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
		combine3Path.pop_back(); // ����
		sum -= i; // ����
	}
}


vector<vector<int>> backtrackingSolution::combinationSum3(int k, int n) {
	combine3Path.clear();
	combine3Res.clear();
	combine3Backingtracking(n, k, 0, 1);
	return combine3Res;

}


// ��17 �绰�������ĸ���
void backtrackingSolution::lettercombineBacktracking(const string& digits, int index) {
	// ��ֹ���� �������ַ�
	if (index == digits.size()) {
		letterRes.push_back(letterPath);
		return;
	}

	int digit = digits[index] - '0';
	string letters = letterMap[digit];
	for (int i = 0; i < letters.size(); i++) {
		letterPath.push_back(letters[i]);
		lettercombineBacktracking(digits, index + 1); //���ﲻ��i+1��������һ������
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


// ��39 ����ܺ�
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

// ��40 ����ܺ�II
void backtrackingSolution::combineSumBacktracking2(vector<int>& candidates, int target,
	int sum, int start, vector<bool>& used) {
	//��ֹ����
	if (sum == target) {
		combineSumRes2.push_back(combineSumPath2);
		return;
	}

	// ��������
	for (int i = start; i < candidates.size() && sum +candidates[i]<= target; i++) {
		// �ж�ͬһ�������Ƿ��ظ����ظ������� ��ȷ�� i > 0������i-1Խ��
		if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
			continue;
		}
		sum += candidates[i];
		combineSumPath2.push_back(candidates[i]);
		used[i] = true;
		combineSumBacktracking2(candidates, target, sum, i + 1, used);
		sum -= candidates[i]; // ����
		combineSumPath2.pop_back();
		used[i]= false;
	}
}

vector<vector<int>> backtrackingSolution::combinationSum2(vector<int>& candidates, int target) {
	combineSumRes2.clear();
	combineSumPath2.clear();
	vector<bool> used(candidates.size(),false);// ����used���飬��¼�Ƿ����
	sort(candidates.begin(), candidates.end()); //����
	combineSumBacktracking2(candidates, target, 0, 0, used);
	return combineSumRes2;
}

// ��131 �ָ���Ĵ�
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
	// �ж���ֹ�ݹ�
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

//��78 �Ӽ�
vector<vector<int>> subRes;
vector<int> subPath;
void backtrackingSolution::subsetsBacktracking(vector<int>& nums, int start) {
	subRes.push_back(subPath);
	//��ֹ����
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




//��93 ��ԭIP��ַ
vector<string> IPres;
// �жϵ�ǰ�Ӵ��Ƿ�����Ч�ĵ�ַ
bool backtrackingSolution::isValid(const string& s, int start, int end) {
	// 
	if (start > end) return false;
	
	// ��ǰ��0 ���Ҳ��ǽ���һλ0
	if (s[start] == '0' && start != end) return false;

	// �ж��Ƿ���Υ���ַ��ͳ���255
	int num = 0;
	for (int i = start; i <= end; i++) {
		if (s[i] > '9' || s[i] < '0') return false;
		num = num * 10 + (s[i] - '0');
		if (num > 255) return false;
	}
	return true;

}
void backtrackingSolution::IPbacktracking(string& s, int start, int pointNum) {
	// ��ֹ����
	if (pointNum == 3) {
		if (isValid(s, start, s.size() - 1)) {
			IPres.push_back(s);
		}
		return;
	}

	// ��������ж�
	for (int i = start; i < s.size(); i++) {
		if (isValid(s, start, i)) {
			pointNum++;
			s.insert(s.begin() + i + 1, '.'); // ���붺���ʾ�ָ�
			IPbacktracking(s, i + 2, pointNum); // ��i+2��ʼ ��һ������
			pointNum--;        // ����
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


//��90 �Ӽ�II
vector<vector<int>> subResII;
vector<int> subPathII;
void backtrackingSolution::subsetsBacktrackingII(vector<int>& nums, 
	int start, vector<bool>& used) {

	// �ռ����нڵ�
	subResII.push_back(subPathII);

	// ��������ж�
	for (int i = start; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}

		used[i] = true;
		subPathII.push_back(nums[i]);
		subsetsBacktrackingII(nums, i + 1, used);
		used[i] = false; //����
		subPathII.pop_back();
	
	}
}
vector<vector<int>> backtrackingSolution::subsetsWithDup(vector<int>& nums) {
	
	subResII.clear();
	subPathII.clear();
	vector<bool> used(nums.size(), false);
	sort(nums.begin(),nums.end()); // ȥ��Ҫ������
	subsetsBacktrackingII(nums, 0, used);
	return subResII;
}


//��491 ����������
vector<vector<int>> subsequenceRes;
vector<int> subsequencePath;
void backtrackingSolution::subsequenceBacktracking(vector<int>& nums, int start) {
	// �ռ����д���2�Ľڵ�
	if (subsequencePath.size() >= 2) {
		subsequenceRes.push_back(subsequencePath);
	}

	// ��������ж�
	unordered_set<int> uset; //�޷�ԭ�����������ʹ�ù�ϣ����ȥ��
	for (int i = start; i < nums.size(); i++) {
		if ((!subsequencePath.empty() && nums[i] < subsequencePath.back()) //��ǰԪ��С���������һλ
			|| uset.find(nums[i]) != uset.end()) { //��ǰ�����ظ�Ԫ�� ����
			continue;
		}
		uset.insert(nums[i]);
		subsequencePath.push_back(nums[i]);
		subsequenceBacktracking(nums, i + 1);
		subsequencePath.pop_back();// ���ݣ�����uset���û��ݣ���Ϊ��ÿһ������¶���
	
	}
}

vector<vector<int>> backtrackingSolution::findSubsequences(vector<int>& nums) {
	subsequencePath.clear();
	subsequenceRes.clear();
	subsequenceBacktracking(nums, 0);
	return subsequenceRes;
}

//��46 ȫ����
vector<vector<int>> perRes;
vector<int> perPath;
void backtrackingSolution::perBacktracking(vector<int>& nums, vector<bool>& used) {
	//��ֹ
	if (perPath.size() == nums.size()) {
		perRes.push_back(perPath);
		return;
	}

	//�����ж�
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


//��47 ȫ����II
vector<vector<int>> perResII;
vector<int> perPathII;
void backtrackingSolution::perBacktrackingII(vector<int>& nums, vector<bool>& used) {
	// ��ֹ���� Ҷ�ӽڵ�
	if (perPathII.size() == nums.size()) {
		perResII.push_back(perPathII);
		return;
	}
	// ��������ж�
	for (int i = 0; i < nums.size(); i++) {
		//���ж�ͬһ���Ƿ��ظ�
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
			continue;
		}
		if (used[i] == true) continue; // ͬһ֦���Ѿ�������
		used[i] = true;
		perPathII.push_back(nums[i]);
		perBacktrackingII(nums, used);
		used[i] = false; // ����
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

//��332 ���°����г�
// unordered_map<��������, map<�������, �������>> targets
unordered_map<string, map<string, int>> targets;
bool backtrackingSolution::fIbacktracking(int ticketNum, vector<string>& res) {
	// ��ֹ����
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