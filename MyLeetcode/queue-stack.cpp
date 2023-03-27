#include "queue-stack.h"

// 题232 用栈实现队列
// 栈结构是先进后出，要实现队列的先进先出，则需要将输入栈数据导入输出栈，调整顺序后输出
int MyQueue::pop() {
	//若输出栈为空，则从输出栈导入数据
	if (stackOut.empty()) {
		//将输入栈顶的元素导入输出栈，直到输入栈为空
		while (!stackIn.empty()) {
			stackOut.push(stackIn.top());
			stackIn.pop();
		}
	}
	int res = stackOut.top();
	stackOut.pop();
	return res;
}

// 对pop函数进行代码复用
int MyQueue::peek() {
	int res = this->pop();
	stackOut.push(res);
	return res;
}


// 题225 用队列实现栈
int MyStack::pop() {
	int size = myque.size();
	size--;
	// 将队列头的元素添加到尾然后弹出原位置元素，直到最后一个元素
	while (size--) {
		myque.push(myque.front());
		myque.pop();
	}
	int res = myque.front();
	myque.pop();
	return res;

}
