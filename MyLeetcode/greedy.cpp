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

// ��53 ����������
int greedySolution::maxSubArray(vector<int>& nums) {
	int count = 0;
	int res = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		count += nums[i];
		if (res < count) res = count; // ���ϵ�ǰԪ�ش���res�������count
		if (count < 0) count = 0; // ���ϵ�ǰԪ��С��0����count��0
	}
	return res;
}

// ��45 ��Ծ��ϷII
int greedySolution::jump(vector<int>& nums) {
	if (nums.size() == 1) return 0;
	int curDis = 0; // ��ǰ���Ƿ�Χ
	int nextDis = 0;  // ��һ�����Ƿ�Χ
	int res = 0; // ��Ծ����
	for (int i = 0; i < nums.size(); i++) {
		nextDis = max(nums[i] + i,nextDis); // ������һ����Χ

		if (i == curDis) { // �ߵ���ǰ��󸲸Ƿ�Χ
			curDis = nextDis; // ���µ�ǰ���ΧΪ��һ�����Χ
			res++; // ��Ծ������һ
			if (nextDis >= nums.size() - 1) break;
		}
	}
	return res;
}

// ��1005 K��ȡ������󻯵������
int greedySolution::largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end(), cmp); // �Ӵ�С����
	for (int i = 0; i < nums.size(); i++) { // �Ӵ�С����������������ת
		if (nums[i] < 0 && k>0) {
			nums[i] *= -1;
			k--;
		}
	}
	if (k % 2 == 1) nums[nums.size() - 1] *= -1; // �����kֵ���ڷ�ת��Сֵ
	int res = 0;
	for (int a : nums) res += a; // ���
	return res;
}


// ��134 ����վ
int greedySolution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int sum = 0; // ����ȫ������������
	int min = INT_MAX; // ������������Сֵ
	for (int i = 0; i < gas.size(); i++) {
		int rest = gas[i] - cost[i];
		sum += rest;
		if (sum < min) {
			min = sum;
		}
	}
	if (sum < 0) return -1; // ����С��0����϶��ܲ���һȦ
	if (min >= 0) return 0; // ������������Сֵ�����ڵ���0����ֱ�Ӵ�0����
	// ����Сֵ�Ǹ�������Ӻ���ǰ������ֱ���ĸ��ڵ����������ƽ�ø���
	for (int i = gas.size() - 1; i >= 0; i--) {
		int rest = gas[i] - cost[i];
		min += rest;
		if (min >= 0) {
			return i;
		}
	}
	return -1;
}

int greedySolution::canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
	int curSum = 0;
	int totalSum = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++) {
		curSum += gas[i] - cost[i];
		totalSum += gas[i] - cost[i];
		if (curSum < 0) {
			start = i + 1;
			curSum = 0;
		}
	}
	if (totalSum < 0) return -1;
	return start;
}

// ��135 �ַ��ǹ�
int greedySolution::candy(vector<int>& ratings) {
	// ��ʼ���ǹ���������
	vector<int> candyvec(ratings.size(), 1);

	// �����ұ������Һ��Ӵ�������
	for (int i = 0; i < ratings.size() - 1; i++) {
		if (ratings[i + 1] > ratings[i]) {
			candyvec[i + 1] = candyvec[i] + 1;
		}
	}

	// ���ҵ�����������Ӵ����Һ���
	for (int i = ratings.size() - 1; i >= 1; i--) {
		if (ratings[i - 1] > ratings[i]) {
			candyvec[i - 1] = max(candyvec[i - 1], candyvec[i] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < candyvec.size(); i++) {
		res += candyvec[i];
	}
	//for (int a : candyvec) res += a;
	return res;
}

// ��860 ����ˮ����
bool greedySolution::lemonadeChange(vector<int>& bills) {
	int five = 0, ten = 0, twenty = 0;
	for (int bill : bills) {
		// �յ�5Ԫ
		if (bill == 5) five++;

		// �յ�10Ԫ
		if (bill == 10) {
			if (five <= 0) return false;
			five--; // ��5Ԫ
			ten++;
			
		}
		
		// �յ�20Ԫ
		if (bill == 20) {
			if (five>0 && ten > 0) {
				ten--; //��10+5
				five--;
				twenty++;
			}
			else if(five >= 3) {
				five -= 3; //��5+5+5
				twenty++;
			}
			else return false;
		}
	}
	return true;
}

// ��406 ��������ؽ�����
vector<vector<int>> greedySolution::reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), cmp2); // ����ߴӴ�С����
	vector<vector<int>> que;
	for (int i = 0; i < people.size(); i++) {
		int position = people[i][1]; // ��¼����λ��
		que.insert(que.begin() + position, people[i]); // ��people[i]����ָ��kֵ��λ��
	}
	return que;
}

