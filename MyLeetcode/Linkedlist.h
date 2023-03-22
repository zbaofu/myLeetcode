#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	// ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ����ת������
ListNode *createList_array(int *a,int n);
// ������ʾ
void listDisplay(ListNode* node);



class listSolution1 {
public:
	// ��203 �Ƴ�����Ԫ��
	// ԭ�������
	ListNode* removeElements(ListNode* head, int val);
	// ����ͷ�ڵ����
	ListNode* removeElements2(ListNode* head, int val);

	// �� 206 ��ת����
	ListNode* reverseList(ListNode* head);
	// �ݹ鷴ת���� �ú�����Ƕ��˼�����
	ListNode* reverse(ListNode* pre, ListNode* cur);
	ListNode* reverseList2(ListNode* head);

	//��24 �������������еĽ���
	ListNode* swapPairs(ListNode* head);

	//��19 ɾ����������N���ڵ�
	ListNode* removeNthFromEnd(ListNode* head, int n);

	// ������ 02.07 �����ཻ
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

	// ��142 ��������
	ListNode *detectCycle(ListNode *head);
};


// ��707 ������� 
class MyLinkedList {
public:
	// ��ʼ�� MyLinkedList ����
	MyLinkedList();

	// ��ȡ�������±�Ϊindex�Ľڵ��ֵ���±���Ч�򷵻�-1
	int get(int index);

	// ��һ��ֵΪval�Ľڵ���뵽�����е�һ��Ԫ��֮ǰ��������ɺ��½ڵ��Ϊ��һ���ڵ�
	void addAtHead(int val);

	// ��һ��ֵΪval�Ľڵ�׷�ӵ���������Ϊ�������һ��Ԫ��
	void addAtTail(int val);

	// ��һ��ֵΪ val �Ľڵ���뵽�������±�Ϊ index �Ľڵ�֮ǰ����� index ��������ĳ��ȣ�
	// ��ô�ýڵ�ᱻ׷�ӵ������ĩβ����� index �ȳ��ȸ��󣬸ýڵ㽫������뵽�����С�
	void addAtIndex(int index, int val);

	// ���±���Ч��ɾ���±�Ϊindex�Ľڵ�
	void deleteAtIndex(int index);

private:
	ListNode* dummyhead;
	int size;

};



#endif 
