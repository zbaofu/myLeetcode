#include "Linkedlist.h"


/*************
��������listnode *createlist_array(int *a, int n)
���룺���� �����С
���أ�����
�����������������ת��������

���£�ԭ������δ�����鳤��=1ʱ��������е���˵��
���£�����Ҫ���������С��ֱ���ں����л�ȡ���鳤��  �޷�ʵ�֣����鴫�ݸ�����ʱ�˻���ָ��
      sizeof()ֻ�ܵõ�ָ������Ĵ�С 8�ֽڣ�64λƽ̨�ϣ�
**************/
ListNode *createList_array(int *a,int n) {
	//int n = sizeof(a);
	//int m =	sizeof(a[0]); // ��ȡ���鳤��
	ListNode *root = new ListNode();
	ListNode *pnode = root;

	// �Ľ� ��n = 1ʱ��ԭ������޷���������forѭ������������
	if (n == 1) {
		pnode->val = a[0];
		return pnode;
	}

	for (int i = 0; i < n-1; ++i) {
		root->val = a[i];//��ǰ�ڵ�
		root->next = nullptr;

		ListNode *p = new ListNode();//��һ�����
		p->val = a[i + 1];
		p->next = nullptr;

		root->next = p;// ���� ��ǰ�ڵ� �� ��һ�����
		root = root->next;
	}
	root->next = nullptr;//��һ�� ����Ҫ����
	return pnode;
}


/*************
��������void disp(ListNode* node)
���룺Ҫ��ʾ������
���أ���
������������������ʾ�ڿ���̨
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


// ԭ������в���
ListNode* listSolution1::removeElements(ListNode* head, int val) {
	//ɾ��ͷ�ڵ�
	while (head != NULL && head->val == val) {
		ListNode* temp = head;
		head = head->next;
		delete(temp);
	}

	//ɾ�������ڵ�
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

// ����ͷ�ڵ���в���
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

// ��707 �������
// ��������ڵ�����������
// ��ʼ������
MyLinkedList::MyLinkedList() {
	dummyhead = new ListNode(0);
	// dummyhead->next = nullptr;
	size = 0;
}

// ��ȡ�������±�Ϊindex�Ľڵ��ֵ���±���Ч�򷵻�-1 ,index��0��ʼ
int MyLinkedList::get(int index) {
	if (index > (size - 1) || index < 0) {
		return -1;
	}
	ListNode* cur = dummyhead->next;
	// ��λ��index��λ��
	while (index--) {
		cur = cur->next;
	}
	cout << cur->val << endl;
	return cur->val;
	
}

// ��������ǰ�����ڵ㣬�²���Ľڵ���Ϊ�µ�ͷ�ڵ�
void MyLinkedList::addAtHead(int val) {
	ListNode* p = new ListNode(val); // ��ʼ���µĽڵ㲢��ֵ
	p->next = dummyhead->next; // ���½ڵ����dummyhead��dummyhead->next֮��
	dummyhead->next = p;

	/*****************
	dummyhead->next = p;  // ���½ڵ����dummyhead��dummyhead->next֮��
	p->next = dummyhead->next;
	BUG�γ���ѭ�� p->next = p
	***********************/
	size++;
	listDisplay(dummyhead);

}

// �������������µĽڵ�
void MyLinkedList::addAtTail(int val) {
	ListNode* p = new ListNode(val);
	ListNode* cur = dummyhead;
	// ��λ������β��
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = p;
	size++;
	listDisplay(dummyhead);
}

// ��һ��ֵΪ val �Ľڵ���뵽�������±�Ϊ index �Ľڵ�֮ǰ����� index ��������ĳ��ȣ�
// ��ô�ýڵ�ᱻ׷�ӵ������ĩβ����� index �ȳ��ȸ��󣬸ýڵ㽫������뵽�����С�
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



// ���±���Ч��ɾ���±�Ϊindex�Ľڵ� ��index���ڵ����������򷵻ؿ� index��0��ʼ
void MyLinkedList::deleteAtIndex(int index) {
	if (index >= size||index < 0) return;

	ListNode* cur = dummyhead;
	// ��λ��indexǰһλ
	while (index--) {
		cur = cur->next;
	}
	ListNode* temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
	size--;
	listDisplay(dummyhead);
}

// �� 206 ��ת����
// ˫ָ�뷨
ListNode* listSolution1::reverseList(ListNode* head) {
	ListNode* pre = nullptr; // ��һ����ת�Ľڵ�����ʼ����NULL����Ϊ��ʼ�ڵ�ǰһ���ڵ�
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


// �ݹ鷨��ת���� �ú�����Ƕ��˼�����
ListNode* listSolution1::reverse(ListNode* pre, ListNode* cur) {
	if (cur == NULL) return pre;
	ListNode* temp = cur->next;
	cur->next = pre;

	return reverse(cur,temp);

}

ListNode* listSolution1::reverseList2(ListNode* head) {
	return reverse(NULL, head);
}

//��24 �������������еĽ���
ListNode* listSolution1::swapPairs(ListNode* head) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	
	ListNode* cur = dummyhead; //��ǰ�ڵ�
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


//��19 ɾ����������N���ڵ�
ListNode* listSolution1::removeNthFromEnd(ListNode* head, int n) {
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;
	ListNode* fast = dummyhead;
	ListNode* slow = dummyhead; //������һ�ж���
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

	// return head;  // ����
	return dummyhead->next;


}

// ������ 02.07 �����ཻ
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

// ��142 ��������
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


