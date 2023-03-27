#include "queue-stack.h"

// ��232 ��ջʵ�ֶ���
// ջ�ṹ���Ƚ������Ҫʵ�ֶ��е��Ƚ��ȳ�������Ҫ������ջ���ݵ������ջ������˳������
int MyQueue::pop() {
	//�����ջΪ�գ�������ջ��������
	if (stackOut.empty()) {
		//������ջ����Ԫ�ص������ջ��ֱ������ջΪ��
		while (!stackIn.empty()) {
			stackOut.push(stackIn.top());
			stackIn.pop();
		}
	}
	int res = stackOut.top();
	stackOut.pop();
	return res;
}

// ��pop�������д��븴��
int MyQueue::peek() {
	int res = this->pop();
	stackOut.push(res);
	return res;
}


// ��225 �ö���ʵ��ջ
int MyStack::pop() {
	int size = myque.size();
	size--;
	// ������ͷ��Ԫ����ӵ�βȻ�󵯳�ԭλ��Ԫ�أ�ֱ�����һ��Ԫ��
	while (size--) {
		myque.push(myque.front());
		myque.pop();
	}
	int res = myque.front();
	myque.pop();
	return res;

}
