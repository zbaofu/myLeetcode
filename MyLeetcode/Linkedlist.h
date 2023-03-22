#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	// ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 数组转换链表
ListNode *createList_array(int *a,int n);
// 链表显示
void listDisplay(ListNode* node);



class listSolution1 {
public:
	// 题203 移除链表元素
	// 原链表操作
	ListNode* removeElements(ListNode* head, int val);
	// 虚拟头节点操作
	ListNode* removeElements2(ListNode* head, int val);

	// 题 206 反转链表
	ListNode* reverseList(ListNode* head);
	// 递归反转链表 用函数的嵌套思想完成
	ListNode* reverse(ListNode* pre, ListNode* cur);
	ListNode* reverseList2(ListNode* head);

	//题24 两两交换链表中的交点
	ListNode* swapPairs(ListNode* head);

	//题19 删除链表倒数第N个节点
	ListNode* removeNthFromEnd(ListNode* head, int n);

	// 面试题 02.07 链表相交
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

	// 题142 环形链表
	ListNode *detectCycle(ListNode *head);
};


// 题707 设计链表 
class MyLinkedList {
public:
	// 初始化 MyLinkedList 对象。
	MyLinkedList();

	// 获取链表中下标为index的节点的值，下标无效则返回-1
	int get(int index);

	// 将一个值为val的节点插入到链表中第一个元素之前，插入完成后，新节点成为第一个节点
	void addAtHead(int val);

	// 将一个值为val的节点追加到链表中作为链表最后一个元素
	void addAtTail(int val);

	// 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，
	// 那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将不会插入到链表中。
	void addAtIndex(int index, int val);

	// 若下标有效则删除下标为index的节点
	void deleteAtIndex(int index);

private:
	ListNode* dummyhead;
	int size;

};



#endif 
