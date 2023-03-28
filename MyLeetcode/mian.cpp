#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <ctime>
#include <chrono>
#include "array.h"
#include "Linkedlist.h"
#include "hashtable.h"
#include "string.h"
#include "queue-stack.h"

using namespace std;


/**************
函数名：outputVector(vector<int>& nums)
输入：要显示的数组
输出：无
描述：控制台显示输入的vector整形数组
***************/
void outputVector(vector<int>& nums) {
	int mySize = nums.size();
	cout << "[ ";
	for (int i = 0; i < mySize; i++) {
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
}
// 函数重载 显示字符数组
void outputVector(vector<char>& nums) {
	int mySize = nums.size();
	cout << "[ ";
	for (int i = 0; i < mySize; i++) {
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
}

/***************
函数名：output2Dvector(vector<vector<int>> nums)
输入：要显示的二维数组
输出：无
描述：控制台显示输入的二维整型数组
*************/
void output2Dvector(vector<vector<int>> nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] <<" ";
		}
		cout << endl;
	}
}



void test_arr() {
	int array[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};
	cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl;
	cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl;
}



int main() {

	/*******************************数组*******************************/
	//Solution3 Sol;
	//vector<int>nums = { 5,7,8,9,9,9,12,9 };
	//vector<int>numstest = { 3,3,3,1,2,1,1,2,3,3,4 };
	//int target = 9;
	//vector<vector<int>> matrix;
	//matrix = { {1, 2, 3},
	//			{4, 5, 6 },
	//			{7, 8, 9} };

	//vector<int>output = Sol.searchRange(nums, target);
	//cout << "[ ";
	//for (int i = 0; i < output.size(); i++) {
	//	cout << output[i]<< " ";
	//}
	//cout << "] " << endl;	
	//Solution2 Sqrt;
	//cout << Sqrt.isPerfectSquare(16) << endl;

	//Solution4 element;
	//cout << element.removeElement(nums, target) << endl;


	//element.moveZeroes(nums);
	//outputVector(nums);
//	vector<int> result = element.sortedSquares(nums); //非常量引用的初始值必须是左值
	//outputVector(result);

	//cout << element.minSubArrayLen(25, nums) << endl;
	//cout << element.totalFruit(numstest) << endl;

	// 题59 螺旋矩阵II
	// vector<vector<int>> result;
	// result = element.generateMatrix(4);
	// output2Dvector(result);

	// 题54 
	//vector<int> res;
	//res = element.spiralOrder(matrix);
	//outputVector(res);

	/*********************************链表**********************************/
	listSolution1 listTest; // 定义对象
//	int head[7] = { 1, 2, 6, 3, 4, 5, 6 };
	//int val = 6;
	//int size = sizeof(head) / sizeof(head[0]);
	//ListNode *p = createList_array(head, size); //数组转化成链表

	//listDisplay(p); //显示原链表


	// 题203 移除链表元素
	/*
	int head[7] = {1, 2, 6, 3, 4, 5, 6};
	int val = 6;
	int size = sizeof(head)/sizeof(head[0]);

	ListNode *p = createList_array(head, size);
	listDisplay(p);
	listSolution1 listTest;
	listDisplay(listTest.removeElements2(p, val));
	*/

	// 题707 设计链表
	/*
	MyLinkedList* myList = new MyLinkedList();
	myList->addAtHead(1);
	myList->addAtTail(3);
	myList->addAtIndex(1,2);

	myList->get(1);
	myList->deleteAtIndex(1);
	myList->get(1);
	*/

	// 题206 反转链表

	//listDisplay(listTest.reverseList2(p));

	// 题24 交换链表交点
	/*listDisplay(listTest.swapPairs(p));*/

	//题19 删除链表倒数第N个节点
	//listDisplay(listTest.removeNthFromEnd(p, 1));


	// 面试题 02.07 链表相交
	/*
	int	listA[] = { 4, 1};
	int listB[] = { 5, 0, 1, 7};
	int listC[] = { 8, 4, 5 };
	ListNode* headA = createList_array(listA,2);
	ListNode* headB = createList_array(listB,4);
	ListNode* intersection = createList_array(listC,3);
	// 使链表相交
	ListNode* curA = headA;
	while (curA->next != nullptr) {
		curA = curA->next;
	}
	curA->next = intersection;
	ListNode* curB = headB;
	while (curB->next != nullptr) {
		curB = curB->next;
	}
	curB->next = intersection;

	listDisplay(headA);
	listDisplay(headB);
	listDisplay(listTest.getIntersectionNode(headA, headB));
	*/

	// 题142 环形链表
	// 构造环形链表
	/*
	int array[] = { 1, 2, 6, 3, 4, 5, 6 };
	ListNode* list = createList_array(array,7);
	ListNode* cur = list;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = list->next->next->next;
	cout << listTest.detectCycle(list)->val << endl;
	*/

	/********************************哈希表********************************/
	hashtableSolution1 hashTest;
	vector<int>nums1 = { 1, 0, -1, 0, -2, 2 };
	vector<int>nums2 = { -2,3,-3,-1,2,-1,1};

	// 题242 有效的字母异位词	
	//string s = "aee";
	//string t = "eae";
	//cout << hashTest.isAnagram(s,t);

	// 题349 两个数组的交集 
	//vector<int> output = hashTest.intersection(nums1, nums2);
	//outputVector(output);

	//题202 快乐数
	//cout << hashTest.isHappy(20);

	//题1 两数之和
	/*
	vector<int>nums = { 5,7,8,1,9 };
	int target = 12;
	vector<int> res = hashTest.twoSum(nums, target);
	outputVector(res);
	*/

	//题454 四数相加
	/*
	vector<int>A = { 1,2};
	vector<int>B = { 2,3};
	vector<int>C = { -1,-2};
	vector<int>D = { 2,-3 };
	cout << hashTest.fourSumCount(A, B, C, D);
	*/

	//题383 赎金信
	/*
	string a = "a",b = "ab";
	cout << hashTest.canConstruct(a, b);
	*/

	//题15 三数之和
	/*
	vector<vector<int>> res;
	res = hashTest.threeSum(nums2);
	output2Dvector(res);
	*/

	//题18 四数之和
	/*
	vector<vector<int>> res;
	res = hashTest.fourSum(nums1, 0);
	output2Dvector(res);
	*/

	/**********************************字符串*********************************/
	stringSolution stringtest;
	vector<char> s = { 'h','e','l','l','o' };
	string m = " we are  happy ";
	

	//题344 反转字符串 双指针法
	/*
	vector<char> res = stringtest.reverseString(s);
	outputVector(res);
	*/

	//题541 反转字符串II
	//cout << stringtest.reverseStr("hduiacbuiabwucb",4) << endl;

	//剑指offer 05. 替换空格
	//cout << stringtest.replaceSpace("We are happy.") << endl;

	//题151 反转字符串中的单词
	/*
	stringtest.removeExtraSpaces(m);
	cout << m << endl;
	cout << stringtest.reverseWords(m) << endl;
	*/

	//剑指offer58 左旋转字符串
	//cout << stringtest.reverseLeftWords(m,5) << endl;

	//题28 找出字符串中第一个匹配项的下标
	/*
	string  haystack = "leetcode", needle = "leeto";
	cout << stringtest.strStr(haystack, needle) << endl;
	*/

	//题459 重复的子字符串
	/*
	string q = "aa";
	cout << stringtest.repeatedSubstringPattern(q) << endl;
	*/

	/********************************栈和队列********************************/
	queueSolution queTest;
	// 题232 用栈实现队列
	/*
	MyQueue queueTest;
	cout << queueTest.empty() << endl;
	queueTest.push(4);
	queueTest.push(5);
	cout << queueTest.pop() << endl;
	queueTest.push(45);
	queueTest.push(15);
	cout << queueTest.pop() << endl;
	cout << queueTest.pop() << endl;
	cout << queueTest.peek() << endl;
	cout << queueTest.empty() << endl;
	*/

	// 题225 用队列实现栈
	/*
	MyStack stackTest;
	stackTest.push(25);
	stackTest.push(15);
	cout << stackTest.top() << endl;
	stackTest.pop();
	cout << stackTest.top() << endl;
	cout << stackTest.empty() << endl;
	*/

	// 题20 有效的括号
	
	/*
	string x = "(){[]{}";
	cout << queTest.isValid(x) << endl;
	*/

	// 题1047 删除字符串中所有的相邻重复项
	/*
	string w = "abbacv";
	cout << queTest.removeDuplicates(w) << endl;
	*/
	// 题150 逆波兰表达式求值
	/*
	vector<string> w = { "4", "13", "5", "/", "+" };
	cout << queTest.evalRPN(w) << endl;
	*/

	// 题239 滑动窗口最大值
	/*
	vector<int> queres = queTest.maxSlidingWindow(nums1, 2);
	outputVector(queres);
	*/

	// 题347 前K个高频元素
	vector<int> quenum = { 1,1,1,2,2,3 };
	vector<int> res1 = queTest.topKFrequent(quenum, 2);
	outputVector(res1);

	return 0;
}
