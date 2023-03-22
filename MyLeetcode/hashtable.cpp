#include "hashtable.h"


// ��242 ��Ч����ĸ��λ��
bool hashtableSolution1::isAnagram(string s, string t) {
	int record[26] = {0};
	for (int i = 0; i < s.size(); i++) {
		record[s[i] - 'a']++;
	
	}
	for (int i = 0; i < t.size(); i++) {
		record[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (record[i] != 0) return false;
	}
	return true;
}

//��349 ��������Ľ���
vector<int> hashtableSolution1::intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> result_set;
	unordered_set<int> nums_set(nums1.begin(),nums1.end());
	unordered_set<int>::iterator i;

	for (int num : nums2) {
		i = nums_set.find(num);
		if (nums_set.find(num) != nums_set.end()) {
			result_set.insert(num);
		
		}
	
	}
	return vector<int>(result_set.begin(),result_set.end());
}

//��202 ������
int hashtableSolution1::getSum(int n) {
	int sum = 0;
	while (n) {
		sum += (n % 10)*(n % 10);
		n = n / 10;
	
	}
	return sum;
}

bool hashtableSolution1::isHappy(int n) {
	unordered_set<int> nums;
	while (true) {
		int sum = getSum(n);
		if (sum == 1) {
			return true;
		}
		// ��sum���ֹ���������ѭ�������ǿ�����
		if (nums.find(sum) != nums.end()) {
			return false;
		}
		else {
			nums.insert(sum);
		}
		n = sum;
	}
}

// ��1 ����֮��
vector<int> hashtableSolution1::twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> resnum;

	for (int i = 0; i < nums.size(); i++) {
		auto iter = resnum.find(target - nums[i]);
		if (iter != resnum.end()) {
			return { iter->second,i };
		}
		resnum.insert(pair<int, int>(nums[i], i));
	}
	return {};

}

//��454 �������
int hashtableSolution1::fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
	unordered_map<int, int> map;

	// ��¼a+b���ֵĴ���
	for (int a : nums1) {
		for (int b : nums2) {
			map[a + b]++;
		}
	}

	int count = 0;
	// ��map��Ѱ�ҵ���-��c+d����keyֵ�����Ѷ�Ӧ��value�����ִ������ӵ�count
	for (int c : nums3) {
		for (int d : nums4) {
			if (map.find(0 - (c + d)) != map.end()) {
				count = count + map[0 - (c + d)];
			}
		
		}
	
	}
	return count;
}

//��383 �����
bool hashtableSolution1::canConstruct(string ransomNote, string magazine) {
	int record[26] = { 0 };
	for (int i = 0; i < magazine.size(); i++) {
		record[magazine[i] - 'a']++;
	}

	for (int i = 0; i < ransomNote.size(); i++) {
		record[ransomNote[i] - 'a']--;	
	
	}
	for (int i = 0; i < 26; i++) {
		if (record[i] < 0) {
			return false;
		}
	
	}

	return true;
}

//��15 ����֮�� ˫ָ�뷨 
vector<vector<int>> hashtableSolution1::threeSum(vector<int>& nums) {
	vector<vector<int>>  result;
	// �������������
	sort(nums.begin(),nums.end());

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			return result;
		}
		
		// ��aȥ��
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;

		while (left < right) {
			if (nums[i] + nums[left] + nums[right] > 0) right--;
			else if (nums[i] + nums[left] + nums[right] < 0) left++;
			else {
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				// �� b,cȥ��
				while (left < right&&nums[left] == nums[left + 1]) left++;
				while (left < right&&nums[right] == nums[right - 1]) right--;
				right--;
				left++;
			
			}

		}

	}
	return result;


}

//��18 ����֮�� ˫ָ�뷨 ��������Ѱ��a + b + c + d = target
vector<vector<int>> hashtableSolution1::fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	sort(nums.begin(),nums.end());

	// a = nums[k] һ��ѭ��
	for (int k = 0; k < nums.size(); k++) {
		// ��֦  [-7 -6 -5 6 ..] target = -7 
		if (nums[k] > target && nums[k] >= 0) {
			break;
		}
		// aȥ��
		if (k > 0 && nums[k] == nums[k - 1]) {
			continue;
		}
		//b = nums[i] ����ѭ��
		for (int i = k + 1; i < nums.size(); i++) {
			// ������֦ ԭ����������ͬ
			if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
				break;
			}
		    
			// bȥ��
			if (i > k+1 && nums[i] == nums[i - 1]) {
				continue;
			}
		
			// left��right˫ָ�� c = nums[left] d = nums[right]
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right) {
				if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
				else if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
				else {
					result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
					// �� c,dȥ��
					while (left < right&&nums[left] == nums[left + 1]) left++;
					while (left < right&&nums[right] == nums[right - 1]) right--;

					right--;
					left++;
				}
			}
		}
	
	}
	return result;

}