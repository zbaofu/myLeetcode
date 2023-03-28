#pragma once
#ifndef _QUEUESTACK_H
#define _QUEUESTACK_H

#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

// ��232 ��ջʵ�ֶ���
class MyQueue {
public:
	//���������������ջ
	stack<int> stackIn;
	stack<int> stackOut;

	MyQueue() {

	}
	//  ��һ��Ԫ�ط�����е�β����
	void push(int x) {
		stackIn.push(x);
	}

	// �Ӷ����ײ��Ƴ�Ԫ�ء�
	int pop();

	//  ���ض����ײ���Ԫ�ء�
	int peek();

	// ���ض����Ƿ�Ϊ�ա�
	bool empty() {
		return stackIn.empty() && stackOut.empty();
	}
};

// ��225 �ö���ʵ��ջ
class MyStack {
public:
	queue<int> myque;

	MyStack() {

	}

	void push(int x) {
		myque.push(x);
	}

	int pop();

	int top() {
		return myque.back();
	}

	bool empty() {
		return myque.empty();
	}
};

class queueSolution {
public:
	// ��20 ��Ч������
	bool isValid(string s);

	// ��1047 ɾ���ַ��������е������ظ���
	string removeDuplicates(string s);

	// ��150 �沨�����ʽ��ֵ
	int evalRPN(vector<string>& tokens);

	// ��239 �����������ֵ
	class myQueue; // �Զ��嵥������
	vector<int> maxSlidingWindow(vector<int>& nums, int k);

	// ��347 ǰK����ƵԪ��
	//С���� ��д���ȼ����еıȽϷ���
	class mycomparison;
	vector<int> topKFrequent(vector<int>& nums, int k);
};


#endif
