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
��������outputVector(vector<int>& nums)
���룺Ҫ��ʾ������
�������
����������̨��ʾ�����vector��������
***************/
void outputVector(vector<int>& nums) {
	int mySize = nums.size();
	cout << "[ ";
	for (int i = 0; i < mySize; i++) {
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
}
// �������� ��ʾ�ַ�����
void outputVector(vector<char>& nums) {
	int mySize = nums.size();
	cout << "[ ";
	for (int i = 0; i < mySize; i++) {
		cout << nums[i] << " ";
	}
	cout << "]" << endl;
}

/***************
��������output2Dvector(vector<vector<int>> nums)
���룺Ҫ��ʾ�Ķ�ά����
�������
����������̨��ʾ����Ķ�ά��������
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

	/*******************************����*******************************/
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
//	vector<int> result = element.sortedSquares(nums); //�ǳ������õĳ�ʼֵ��������ֵ
	//outputVector(result);

	//cout << element.minSubArrayLen(25, nums) << endl;
	//cout << element.totalFruit(numstest) << endl;

	// ��59 ��������II
	// vector<vector<int>> result;
	// result = element.generateMatrix(4);
	// output2Dvector(result);

	// ��54 
	//vector<int> res;
	//res = element.spiralOrder(matrix);
	//outputVector(res);

	/*********************************����**********************************/
	listSolution1 listTest; // �������
//	int head[7] = { 1, 2, 6, 3, 4, 5, 6 };
	//int val = 6;
	//int size = sizeof(head) / sizeof(head[0]);
	//ListNode *p = createList_array(head, size); //����ת��������

	//listDisplay(p); //��ʾԭ����


	// ��203 �Ƴ�����Ԫ��
	/*
	int head[7] = {1, 2, 6, 3, 4, 5, 6};
	int val = 6;
	int size = sizeof(head)/sizeof(head[0]);

	ListNode *p = createList_array(head, size);
	listDisplay(p);
	listSolution1 listTest;
	listDisplay(listTest.removeElements2(p, val));
	*/

	// ��707 �������
	/*
	MyLinkedList* myList = new MyLinkedList();
	myList->addAtHead(1);
	myList->addAtTail(3);
	myList->addAtIndex(1,2);

	myList->get(1);
	myList->deleteAtIndex(1);
	myList->get(1);
	*/

	// ��206 ��ת����

	//listDisplay(listTest.reverseList2(p));

	// ��24 ����������
	/*listDisplay(listTest.swapPairs(p));*/

	//��19 ɾ����������N���ڵ�
	//listDisplay(listTest.removeNthFromEnd(p, 1));


	// ������ 02.07 �����ཻ
	/*
	int	listA[] = { 4, 1};
	int listB[] = { 5, 0, 1, 7};
	int listC[] = { 8, 4, 5 };
	ListNode* headA = createList_array(listA,2);
	ListNode* headB = createList_array(listB,4);
	ListNode* intersection = createList_array(listC,3);
	// ʹ�����ཻ
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

	// ��142 ��������
	// ���컷������
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

	/********************************��ϣ��********************************/
	hashtableSolution1 hashTest;
	vector<int>nums1 = { 1, 0, -1, 0, -2, 2 };
	vector<int>nums2 = { -2,3,-3,-1,2,-1,1};

	// ��242 ��Ч����ĸ��λ��	
	//string s = "aee";
	//string t = "eae";
	//cout << hashTest.isAnagram(s,t);

	// ��349 ��������Ľ��� 
	//vector<int> output = hashTest.intersection(nums1, nums2);
	//outputVector(output);

	//��202 ������
	//cout << hashTest.isHappy(20);

	//��1 ����֮��
	/*
	vector<int>nums = { 5,7,8,1,9 };
	int target = 12;
	vector<int> res = hashTest.twoSum(nums, target);
	outputVector(res);
	*/

	//��454 �������
	/*
	vector<int>A = { 1,2};
	vector<int>B = { 2,3};
	vector<int>C = { -1,-2};
	vector<int>D = { 2,-3 };
	cout << hashTest.fourSumCount(A, B, C, D);
	*/

	//��383 �����
	/*
	string a = "a",b = "ab";
	cout << hashTest.canConstruct(a, b);
	*/

	//��15 ����֮��
	/*
	vector<vector<int>> res;
	res = hashTest.threeSum(nums2);
	output2Dvector(res);
	*/

	//��18 ����֮��
	/*
	vector<vector<int>> res;
	res = hashTest.fourSum(nums1, 0);
	output2Dvector(res);
	*/

	/**********************************�ַ���*********************************/
	stringSolution stringtest;
	vector<char> s = { 'h','e','l','l','o' };
	string m = " we are  happy ";
	

	//��344 ��ת�ַ��� ˫ָ�뷨
	/*
	vector<char> res = stringtest.reverseString(s);
	outputVector(res);
	*/

	//��541 ��ת�ַ���II
	//cout << stringtest.reverseStr("hduiacbuiabwucb",4) << endl;

	//��ָoffer 05. �滻�ո�
	//cout << stringtest.replaceSpace("We are happy.") << endl;

	//��151 ��ת�ַ����еĵ���
	/*
	stringtest.removeExtraSpaces(m);
	cout << m << endl;
	cout << stringtest.reverseWords(m) << endl;
	*/

	//��ָoffer58 ����ת�ַ���
	//cout << stringtest.reverseLeftWords(m,5) << endl;

	//��28 �ҳ��ַ����е�һ��ƥ������±�
	/*
	string  haystack = "leetcode", needle = "leeto";
	cout << stringtest.strStr(haystack, needle) << endl;
	*/

	//��459 �ظ������ַ���
	/*
	string q = "aa";
	cout << stringtest.repeatedSubstringPattern(q) << endl;
	*/

	/********************************ջ�Ͷ���********************************/
	queueSolution queTest;
	// ��232 ��ջʵ�ֶ���
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

	// ��225 �ö���ʵ��ջ
	/*
	MyStack stackTest;
	stackTest.push(25);
	stackTest.push(15);
	cout << stackTest.top() << endl;
	stackTest.pop();
	cout << stackTest.top() << endl;
	cout << stackTest.empty() << endl;
	*/

	// ��20 ��Ч������
	
	/*
	string x = "(){[]{}";
	cout << queTest.isValid(x) << endl;
	*/

	// ��1047 ɾ���ַ��������е������ظ���
	/*
	string w = "abbacv";
	cout << queTest.removeDuplicates(w) << endl;
	*/
	// ��150 �沨�����ʽ��ֵ
	/*
	vector<string> w = { "4", "13", "5", "/", "+" };
	cout << queTest.evalRPN(w) << endl;
	*/

	// ��239 �����������ֵ
	/*
	vector<int> queres = queTest.maxSlidingWindow(nums1, 2);
	outputVector(queres);
	*/

	// ��347 ǰK����ƵԪ��
	vector<int> quenum = { 1,1,1,2,2,3 };
	vector<int> res1 = queTest.topKFrequent(quenum, 2);
	outputVector(res1);

	return 0;
}
