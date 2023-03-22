#ifndef _ARRAY_H
#define _ARRAY_H
#include <vector>
#include <iostream>
#include<algorithm>//调用algorithm库

using namespace std;

// 二分查找 1 
class Solution {
public:
	int search(vector<int>& nums, int target);
};



class Solution2 {
public:
	// 二分查找 2 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
   // 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
	int search(vector<int>& nums, int target);
	//二分查找变形 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
	int mySqrt(int x);
	//二分查找变形 题367 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 
	bool isPerfectSquare(int num);


};

// 二分查找 3 力扣题34. 在排序数组中查找元素的第一个和最后一个位置
class Solution3 {
public:
	vector<int> searchRange(vector<int>& nums, int target);

private:
	int getRightBorder(vector<int>& nums, int target);
	int getLeftBorder(vector<int>& nums, int target);
};


class Solution4 {
public:
	//元素移除 题27 给你一个数组 nums 和一个值 val，
	//原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
	int removeElement(vector<int>& nums, int val);

	//元素移除 题26 不能出现连续重复的元素
	int removeDuplicates(vector<int>& nums);

	void moveZeroes(vector<int>& nums);

	// 题977，有序数组的平方
	vector<int> sortedSquares(vector<int>& nums);

	// 题209 长度最小的子数组，滑动窗口
	int minSubArrayLen(int target, vector<int>& nums);

	// 题904 水果成篮
	int totalFruit(vector<int>& fruits);
	
	// 题59 螺旋矩阵II
	vector<vector<int>> generateMatrix(int n);
	// 题54 螺旋矩阵I
	vector<int> spiralOrder(vector<vector<int>>& matrix);

};


#endif // _BINSEARCH_H

