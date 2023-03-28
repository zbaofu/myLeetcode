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


// ��20 ��Ч������
bool queueSolution::isValid(string s) {
	if (s.size() % 2)  return false ;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		// ����������ʱ����Ӧ�����Ž�ջ
		if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		else if (s[i] == '(') st.push(')');

		// ���������� ����ջΪ�ջ�ջ��Ԫ�ز����Ϸ���false
		else if (st.empty() || st.top() != s[i]) return false;

		// ������� ����������ջ��Ԫ����s[i] �򵯳�ջ��Ԫ�� 
		else st.pop();
	
	}
	//������� ��ջΪ���򷵻�true����Ϊ����˵����������ûƥ��
	return st.empty();
}

// ��1047 ɾ���ַ��������е������ظ���
// ���Զ���ջ������Ҳ����ֱ�����ַ�����Ϊջ������ʡȥת�����ַ����ͷ�ת
string queueSolution::removeDuplicates(string s) {
	stack<char> st;
	
	for (char str : s) {
		if (st.empty() || str != st.top()) {
			st.push(str);
		}
		else {
			st.pop();
		}
	}

	// ת�����ַ������
	string res = "";
	while (!st.empty()) {
		//������res=res+st.top()�������Ĳ�����ͨ������ +=���ϸ�ֵ���������������������
		res += st.top(); 
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

// ��150 �沨�����ʽ��ֵ
int queueSolution::evalRPN(vector<string>& tokens) {
	stack<long> st;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			long num1 = st.top();
			st.pop();
			long num2 = st.top();
			st.pop();
			if (tokens[i] == "+") st.push(num1 + num2);
			if (tokens[i] == "-") st.push(num2 - num1);
			if (tokens[i] == "*") st.push(num1 * num2);
			if (tokens[i] == "/") st.push(num2 / num1);
		}
		else {
			st.push(stol(tokens[i])); //stol�������ַ���ת����long int 
		}
	}
	int res = st.top();
	st.pop();
	return res;
}

// ��239 �����������ֵ
// �Զ��嵥������ �洢ά�������п��ܵ����ֵ
class queueSolution::myQueue {
	public:
		deque<int> que;

		//����ʱ�Ƚϵ���ֵ�Ƿ�Ͷ��г��ڣ����ֵ����ȣ�����򵯳�������������
		void pop(int val) {
			if (!que.empty() && val == que.front()) {
				que.pop_front();
			}
		}

		// �������¼����Ԫ��push�����У�����ֵ���ڶ������е�ֵ��
		// �򽫶��к��ֵ������ֱ��push��ֵС�ڵ��ڶ���ֵ
		void push(int val) {
			while (!que.empty() && val > que.back()) {
				que.pop_back();
			}
			que.push_back(val);
		}

		int front() {
			return que.front();		
		}
};
// ���������������ֵ
vector<int> queueSolution::maxSlidingWindow(vector<int>& nums, int k) {
	myQueue que;
	vector<int> res; //��¼���ֵ
	for (int i = 0; i < k; i++) {
		que.push(nums[i]);
	}
	res.push_back(que.front());
	for (int i = k; i < nums.size(); i++) {
		que.pop(nums[i - k]);
		que.push(nums[i]);
		res.push_back(que.front());
	}
	return res;
}


// ��347 ǰK����ƵԪ��

//С���� ��д���ȼ����еıȽϷ���
class queueSolution::mycomparison {
public:
	bool operator()(const pair<int, int>& lh, const pair<int, int>& rh) {
		return lh.second > rh.second;
	}
};

vector<int> queueSolution::topKFrequent(vector<int>& nums, int k) {
	// ��ϣ���map�ṹͳ��Ԫ�س���Ƶ��
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]]++;
	}

	// ��Ƶ�ʽ�������
	// �����СΪk��С����
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> prique;

	// ��map���Ԫ�ش浽С���ѽ�������,С���Ѵ�СΪk 
	for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
		prique.push(*it);
		if (prique.size() > k) {
			prique.pop();
		}
	
	}

	// ��С���ѵ�k����ƵԪ����������� С�����ȵ�����С�ģ����Ե������
	vector<int> res(k);
	for (int i = k - 1; i >= 0; i--) {
		res[i] = prique.top().first;
		prique.pop();
	}
	return res;
}