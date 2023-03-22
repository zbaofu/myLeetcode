#ifndef _ARRAY_H
#define _ARRAY_H
#include <vector>
#include <iostream>
#include<algorithm>//����algorithm��

using namespace std;

// ���ֲ��� 1 
class Solution {
public:
	int search(vector<int>& nums, int target);
};



class Solution2 {
public:
	// ���ֲ��� 2 ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
   // ���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
	int search(vector<int>& nums, int target);
	//���ֲ��ұ��� ����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
	int mySqrt(int x);
	//���ֲ��ұ��� ��367 ����һ�������� num ����� num ��һ����ȫƽ�������򷵻� true �����򷵻� false 
	bool isPerfectSquare(int num);


};

// ���ֲ��� 3 ������34. �����������в���Ԫ�صĵ�һ�������һ��λ��
class Solution3 {
public:
	vector<int> searchRange(vector<int>& nums, int target);

private:
	int getRightBorder(vector<int>& nums, int target);
	int getLeftBorder(vector<int>& nums, int target);
};


class Solution4 {
public:
	//Ԫ���Ƴ� ��27 ����һ������ nums ��һ��ֵ val��
	//ԭ���Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
	int removeElement(vector<int>& nums, int val);

	//Ԫ���Ƴ� ��26 ���ܳ��������ظ���Ԫ��
	int removeDuplicates(vector<int>& nums);

	void moveZeroes(vector<int>& nums);

	// ��977�����������ƽ��
	vector<int> sortedSquares(vector<int>& nums);

	// ��209 ������С�������飬��������
	int minSubArrayLen(int target, vector<int>& nums);

	// ��904 ˮ������
	int totalFruit(vector<int>& fruits);
	
	// ��59 ��������II
	vector<vector<int>> generateMatrix(int n);
	// ��54 ��������I
	vector<int> spiralOrder(vector<vector<int>>& matrix);

};


#endif // _BINSEARCH_H

