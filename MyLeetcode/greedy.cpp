#include "greedy.h"


// ��455 �ַ�����
int greedySolution::findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int res = 0;
	int index = s.size() - 1;
	for (int i = g.size() - 1; i >= 0; i--) {
		if (index >= 0 && s[index] >= g[i] ) { // ���ж�index���ڵ���0
			index--;
			res++;
		}
	}
	return res;

}

// ��376 �ڶ�����
int greedySolution::wiggleMaxLength(vector<int>& nums) {
	if (nums.size() <= 1) return nums.size();

	int prediff = 0; // ��ǰһ�����ֵĲ�ֵ
	int curdiff = 0; // ���һ�����ֵĲ�ֵ
	int res = 1; // ��¼��ֵ������Ĭ���������ұ���һ����ֵ
	for (int i = 0; i < nums.size()-1; i++) {

		curdiff = nums[i + 1] - nums[i];
		// ���ַ�ֵ
		if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0)) {
			res++;
			prediff = curdiff; //ֻ�ڰڶ��仯ʱ������ǰһ����ֵ
		}
	}
	return res;
}

// ��122 ������Ʊ�����ʱ��
int greedySolution::maxProfit(vector<int>& prices) {
	int res = 0; //��¼����
	int diff = 0;
	for (int i = 0; i < prices.size()-1; i++) {
		diff = prices[i + 1] - prices[i];
		if (diff > 0) {
			res += diff;
		}
	}
	return res;
}

// ��55 ��Ծ��Ϸ
bool greedySolution::canJump(vector<int>& nums) {
	if (nums.size() == 1) return true;
	int cover = 0;

	for (int i = 0; i <= cover; i++) {
		cover = max(i + nums[i], cover);
		if (cover >= nums.size()-1) return true;
	}
	return false;

}