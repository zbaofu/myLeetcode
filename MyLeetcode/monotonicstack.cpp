#include "monotonicstack.h"


// ��739 ÿ���¶�
vector<int> monstack::dailyTemperatures(vector<int>& temperatures) {
	// ����ջ
	stack<int> st; // ���Ԫ���±�
	vector<int> res(temperatures.size(), 0);
	st.push(0);

	for (int i = 0; i < temperatures.size(); i++) {
		// ���һ�� ��ǰ������Ԫ��С��ջ��Ԫ��
		if (temperatures[i] < temperatures[st.top()]) {
			st.push(i);
		}
		// ������� ��ǰ������Ԫ�ص���ջ��Ԫ��
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

// ��496 ��һ������Ԫ��
vector<int> monstack::nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> st;
	vector<int> res(nums1.size(), -1);
	if (nums1.size() == 0) return res;

	unordered_map<int, int> umap; // �洢nums1�����Ԫ�غ��±� key��Ԫ�أ�value���±�
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
				if (umap.count(nums2[st.top()]) > 0) { // ��map���Ƿ������Ԫ��
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

