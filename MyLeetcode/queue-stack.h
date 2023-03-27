#pragma once
#ifndef _QUEUESTACK_H
#define _QUEUESTACK_H

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>

using namespace std;

// 题232 用栈实现队列
class MyQueue {
public:
	//定义两个输入输出栈
	stack<int> stackIn;
	stack<int> stackOut;

	MyQueue() {

	}
	//  将一个元素放入队列的尾部。
	void push(int x) {
		stackIn.push(x);
	}

	// 从队列首部移除元素。
	int pop();

	//  返回队列首部的元素。
	int peek();

	// 返回队列是否为空。
	bool empty() {
		return stackIn.empty() && stackOut.empty();
	}
};

// 题225 用队列实现栈
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



#endif
