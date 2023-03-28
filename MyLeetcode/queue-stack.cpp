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


// 题20 有效的括号
bool queueSolution::isValid(string s) {
	if (s.size() % 2)  return false ;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		// 遇到左括号时，对应右括号进栈
		if (s[i] == '{') st.push('}');
		else if (s[i] == '[') st.push(']');
		else if (s[i] == '(') st.push(')');

		// 遇到右括号 ，若栈为空或栈顶元素不符合返回false
		else if (st.empty() || st.top() != s[i]) return false;

		// 其余情况 遇到右括号栈顶元素与s[i] 则弹出栈顶元素 
		else st.pop();
	
	}
	//遍历完后 若栈为空则返回true，不为空则说明有左括号没匹配
	return st.empty();
}

// 题1047 删除字符串中所有的相邻重复项
// 可以定义栈来做，也可以直接用字符串作为栈来做，省去转化成字符串和翻转
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

	// 转换成字符串输出
	string res = "";
	while (!st.empty()) {
		//不能用res=res+st.top()，过长的测试例通不过， +=复合赋值运算符可以扩大数据类型
		res += st.top(); 
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

// 题150 逆波兰表达式求值
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
			st.push(stol(tokens[i])); //stol函数将字符串转换成long int 
		}
	}
	int res = st.top();
	st.pop();
	return res;
}

// 题239 滑动窗口最大值
// 自定义单调队列 存储维护滑窗中可能的最大值
class queueSolution::myQueue {
	public:
		deque<int> que;

		//弹出时比较弹出值是否和队列出口（最大值）相等，相等则弹出，否则不做操作
		void pop(int val) {
			if (!que.empty() && val == que.front()) {
				que.pop_front();
			}
		}

		// 将窗口新加入的元素push进队列，若新值大于队列已有的值，
		// 则将队列后端值弹出，直到push的值小于等于队列值
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
// 搜索滑动窗口最大值
vector<int> queueSolution::maxSlidingWindow(vector<int>& nums, int k) {
	myQueue que;
	vector<int> res; //记录最大值
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


// 题347 前K个高频元素

//小顶堆 重写优先级队列的比较法则
class queueSolution::mycomparison {
public:
	bool operator()(const pair<int, int>& lh, const pair<int, int>& rh) {
		return lh.second > rh.second;
	}
};

vector<int> queueSolution::topKFrequent(vector<int>& nums, int k) {
	// 哈希表的map结构统计元素出现频率
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]]++;
	}

	// 对频率进行排序
	// 定义大小为k的小顶堆
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> prique;

	// 将map里的元素存到小顶堆进行排序,小顶堆大小为k 
	for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
		prique.push(*it);
		if (prique.size() > k) {
			prique.pop();
		}
	
	}

	// 将小顶堆的k个高频元素输出到数组 小顶堆先弹出最小的，所以倒序输出
	vector<int> res(k);
	for (int i = k - 1; i >= 0; i--) {
		res[i] = prique.top().first;
		prique.pop();
	}
	return res;
}