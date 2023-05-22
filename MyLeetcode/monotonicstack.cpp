#include "monotonicstack.h"


// 题739 每日温度
vector<int> monstack::dailyTemperatures(vector<int>& temperatures) {
	// 递增栈
	stack<int> st; // 存放元素下标
	vector<int> res(temperatures.size(), 0);
	st.push(0);

	for (int i = 0; i < temperatures.size(); i++) {
		// 情况一： 当前遍历的元素小于栈顶元素
		if (temperatures[i] < temperatures[st.top()]) {
			st.push(i);
		}
		// 情况二： 当前遍历的元素等于栈顶元素
		else if (temperatures[i] == temperatures[st.top()]) {
			st.push(i);
		}
		else {
			while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
				res[st.top()] = i - st.top();
				st.pop();
			}
			st.push(i);
		}
	}
	return res;
}

// 题496 下一个更大元素
vector<int> monstack::nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> st;
	vector<int> res(nums1.size(), -1);
	if (nums1.size() == 0) return res;

	unordered_map<int, int> umap; // 存储nums1数组的元素和下标 key：元素，value：下标
	for (int i = 0; i < nums1.size(); i++) {
		umap[nums1[i]] = i;
	}

	st.push(0);
	for (int i = 0; i < nums2.size(); i++) {
		if (nums2[i] <= nums2[st.top()]) {
			st.push(i);
		}
		else {
			while (!st.empty()&&nums2[i]>nums2[st.top()]){
				if (umap.count(nums2[st.top()]) > 0) { // 看map中是否有这个元素
					int index = umap[nums2[st.top()]];
					res[index] = nums2[i];
				}
				st.pop();
			}
			st.push(i);
		}
	}
	return res;
}

