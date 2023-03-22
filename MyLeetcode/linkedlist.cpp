#include "Linkedlist.h"


/*************
函数名：listnode *createlist_array(int *a, int n)
输入：数组 数组大小
返回：链表
描述：将输入的数组转换成链表

更新：原程序中未对数组长度=1时的情况进行单独说明
更新：不需要输入数组大小，直接在函数中获取数组长度  无法实现，数组传递给函数时退化成指针
      sizeof()只能得到指针变量的大小 8字节（64位平台上）
**************/
ListNode *createList_array(int *a,int n) {
	//int n = sizeof(a);
	//int m =	sizeof(a[0]); // 求取数组长度
	ListNode *root = new ListNode();
	ListNode *pnode = root;

	// 改进 当n = 1时，原版代码无法进入下文for循环，单独处理
	if (n == 1) {
		pnode->val = a[0];
		return pnode;
	}

	for (int i = 0; i < n-1; ++i) {
		root->val = a[i];//当前节点
		root->next = nullptr;

		ListNode *p = new ListNode();//下一个结点
		p->val = a[i + 1];
		p->next = nullptr;

		root->next = p;// 连接 当前节点 与 下一个结点
		root = root->next;
	}
	root->next = nullptr;//这一句 最重要！！
	return pnode;
}


/*************
函数名：void disp(ListNode* node)
输入：要显示的链表
返回：无
描述：将输入链表显示在控制台
**************/
void listDisplay(ListNode* node) {
	if (node == nullptr)return;
	while (node != nullptr) {
		cout << node->val;
		if (node->next)	cout << "->";
		node = node->next;
	}
	cout << endl;
}


// 原链表进行操作
ListNode* listSolution1::removeElements(ListNode* head, int val) {
	//删除头节点
	while (head != NULL && head->val == val) {
		ListNode* temp = head;
		head = head->next;
		delete(temp);
	}

	//删除其他节点
	ListNode* cur = head;
	while (cur != NULL && cur->next != NULL) {
		if (cur->next->val == val) {
			ListNode* temp = cur->next;
			cur->next = cur->next->next;
			delete(temp);
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}

// 虚拟头节点进行操作
ListNode* listSolution1::removeElements2(ListNode* head, int val) {
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;
	ListNode* cur = dummyHead;
	while (cur->next != NULL) {
		if (cur->next->val == val) {
			ListNode* temp = cur->next;
			cur->next = cur->next->next;
			delete(temp);
		}
		else {
			cur = cur->next;
		}
	}
	head = dummyHead->next;
	delete dummyHead;
	return head;


}

// 题707 设计链表
// 设置虚拟节点进行链表操作
// 初始化链表
MyLinkedList::MyLinkedList() {
	dummyhead = new ListNode(0);
	// dummyhead->next = nullptr;
	size = 0;
}

// 获取链表中下标为index的节点的值，下标无效则返回-1 ,index从0开始
int MyLinkedList::get(int index) {
	if (index > (size - 1) || index < 0) {
		return -1;
	}
	ListNode* cur = dummyhead->next;
	// 定位到index的位置
	while (index--) {
		cur = cur->next;
	}
	cout << cur->val << endl;
	return cur->val;
	
}

// 在链表最前面插入节点，新插入的节点作为新的头节点
void MyLinkedList::addAtHead(int val) {
	ListNode* p = new ListNode(val); // 初始化新的节点并赋值
	p->next = dummyhead->next; // 将新节点插入dummyhead和dummyhead->next之间
	dummyhead->next = p;

	/*****************
	dummyhead->next = p;  // 将新节点插入dummyhead和dummyhead->next之间
	p->next = dummyhead->next;
	BUG形成死循环 p->next = p
	***********************/
	size++;
	listDisplay(dummyhead);

}

// 在链表最后添加新的节点
void MyLinkedList::addAtTail(int val) {
	ListNode* p = new ListNode(val);
	ListNode* cur = dummyhead;
	// 定位到链表尾部
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = p;
	size++;
	listDisplay(dummyhead);
}

// 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，
// 那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将不会插入到链表中。
void MyLinkedList::addAtIndex(int index, int val) {
	if (index > size) return;
	if (index < 0) index = 0;
	ListNode* NewNode = new ListNode(val);
	ListNode* cur = dummyhead;
	while (index--) {
		cur = cur->next;
	}
	NewNode->next = cur->next;
	cur->next = NewNode;
	size++;
	listDisplay(dummyhead);
}



// 若下标有效则删除下标为index的节点 若index大于等于链表长度则返回空 index从0开始
void MyLinkedList::deleteAtIndex(int index) {
	if (index >= size||index < 0) return;

	ListNode* cur = dummyhead;
	// 定位到index前一位
	while (index--) {
		cur = cur->next;
	}
	ListNode* temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
	size--;
	listDisplay(dummyhead);
}

// 题 206 反转链表
// 双指针法
ListNode* listSolution1::reverseList(ListNode* head) {
	ListNode* pre = nullptr; // 第一个反转的节点必须初始化成NULL，作为初始节点前一个节点
	ListNode* cur = head;
	ListNode* temp;
	while (cur) {
		temp = cur->next;
		cur->next = pre;

		pre = cur;
		cur = temp;
	}
	return pre;
}


// 递归法反转链表 用函数的嵌套思想完成
ListNode* listSolution1::reverse(ListNode* pre, ListNode* cur) {
	if (cur == NULL) return pre;
	ListNode* temp = cur->next;
	cur->next = pre;

	return reverse(cur,temp);

}

ListNode* listSolution1::reverseList2(ListNode* head) {
	return reverse(NULL, head);
}

//题24 两两交换链表中的交点
ListNode* listSolution1::swapPairs(ListNode* head) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	
	ListNode* cur = dummyhead; //当前节点
	while (cur->next != nullptr && cur->next->next != nullptr) {
		ListNode* temp1 = cur->next;
		ListNode* temp2 = cur->next->next->next;

		cur->next = cur->next->next;
		cur->next->next = temp1;
		cur->next->next->next = temp2;

		cur = cur->next->next;
	
	}
	return dummyhead->next;
}


//题19 删除链表倒数第N个节点
ListNode* listSolution1::removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	ListNode* fast = dummyhead;
	ListNode* slow = dummyhead; //不能做一行定义
	while ((n--) + 1 && fast != nullptr) {
		fast = fast->next;
	}

	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* temp = slow->next;
	slow->next = slow->next->next;
	delete(temp);

	// return head;  // 报错
	return dummyhead->next;


}

// 面试题 02.07 链表相交
ListNode* listSolution1::getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode* curA = headA;
	ListNode* curB = headB;
	int lenA = 0, lenB = 0;

	while (curA != NULL) {
		lenA++;
		curA = curA->next;
	}

	while (curB != NULL) {
		lenB++;
		curB = curB->next;
	}
	curA = headA;
	curB = headB;

	if (lenA < lenB) {
		swap(lenA, lenB);
		swap(curA, curB);
	}

	int gap = lenA - lenB;

	while (gap--) {
		curA = curA->next;
	}

	while (curA != NULL) {
		if (curA == curB) {
			return curA;
		
		}
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;

}

// 题142 环形链表
ListNode* listSolution1::detectCycle(ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			ListNode* temp = head;
			ListNode* temp1 = fast;
			while (temp != temp1) {
				temp = temp->next;
				temp1 = temp1->next;
			}
			return temp1;
		}
	}
	return NULL;
}


