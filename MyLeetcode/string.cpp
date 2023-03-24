#include "string.h"

//题344 反转字符串 双指针法
vector<char> stringSolution::reverseString(vector<char>& s) {
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
		swap(s[i], s[j]);	
	}
	return s;


}


//题541 反转字符串II
string stringSolution::reverseStr(string s, int k) {
	
	for (int i = 0; i < s.size(); i += 2*k) {
		
		//情况一 大于(2n+1)*k，小于(2n+2)*k
		if (i + k < s.size()) {
			// 调用库函数 原理与上述函数相同
			reverse(s.begin() + i, s.begin() + i + k);
		
		}
		//情况二 小于(2n+1)*k,大于2n*k
		else {
			reverse(s.begin() + i, s.end());
		
		}
	}
	return s;
}




//剑指offer 05. 替换空格
string stringSolution::replaceSpace(string s) {
	int count = 0; // 空格计数
	int oldSize = s.size();

	// 计算空格数
	for (int i = 0; i < oldSize; i++) {
		if (s[i] == ' ') {
			count++;
		}
	}

	// 扩充后的数组大小
	int newSize = oldSize + count * 2;
	s.resize(newSize);

	// 双指针 i指向新长度的末尾，j指向旧长度的末尾。
	for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
		if (s[j] != ' ') s[i] = s[j];
		else {
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			i -= 2;
		}	
	}
	return s;
}


//题151 反转字符串中的单词
// 去除多余空格 双指针法 时间复杂度O(n)
void stringSolution::removeExtraSpaces(string& s) {
	int fastIndex = 0, slowIndex = 0;

	// 去除字符串头部的空格，快指针指向第一个非空格字符
	while (s.size() > 0 && s[fastIndex] == ' '&&fastIndex < s.size()) {
		fastIndex++;
	}

	// 去除字符串中间的多余连续空格 包括末尾的重复空格
	for (; fastIndex < s.size(); fastIndex++) {
		// 连续空格跳过
		if (s[fastIndex] == ' '&&s[fastIndex] == s[fastIndex - 1] && fastIndex > 1) {
			continue;
		
		}
		// 其他情况赋值给慢指针
		else {
			s[slowIndex++] = s[fastIndex]; //这里++在后面
		}
	}
	// 去除字符串末尾的空格
	if (s[slowIndex - 1] == ' ') {
		s.resize(slowIndex - 1);
	}
	else {
		s.resize(slowIndex); //重新设置字符串大小
	}

}

string stringSolution::reverseWords(string s) {
	removeExtraSpaces(s);
	reverse(s.begin(), s.end());
	cout << s << endl;

	int start = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == ' ') {
			reverse(s.begin() + start, s.begin() + i);
			start = i + 1;
		
		}
	
	}
	return s;
}



//剑指offer58 左旋转字符串
string stringSolution::reverseLeftWords(string s, int n) {
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());
	return s;

}


//题28 找出字符串中第一个匹配项的下标
// KMP法模式匹配 
// 构造next数组（前缀表统一减一）
void stringSolution::getNext(int *next, const string& s) {
	int j = -1; //前缀末尾，初始为 0-1
	next[0] = j; // 前缀表第一个元素为 0-1
	for (int i = 1; i < s.size(); i++) {
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j]; // 前后缀不同时，回退到前缀表前一位
		}
		if (s[i] == s[j + 1]) { // 前后缀相同时，前缀加一
			j++;
		}
		next[i] = j;
		//cout << next[i] << ' ';

	}
	//cout << endl;
}

int stringSolution::strStr(string haystack, string needle) {
	if (needle.size() == 0) {
		return 0;
	}

	int mysize = needle.size() ;
	// cout << mysize << endl;
	//int next[mysize];
	int* next = new int[mysize];// 动态分配内存

	//int next[mysize]; //  数组无法用变量来分配内存

	//int* nexttest = new int(5)

	getNext(next,needle); // 

	int j = -1; //前缀表统一减一
	for (int i = 0; i < haystack.size(); i++) {
		while (j >= 0 && haystack[i] != needle[j + 1]) { // 模式串与文本串不匹配
			j = next[j]; // 回退前缀表前一位
		}
		if (haystack[i] == needle[j + 1]) { // 匹配时，j向后移动
			j++;
		}
		if (j == (needle.size() - 1)) {
			delete[] next; //收回堆上的内存
			return (i - needle.size() + 1);
		}
	}
	delete[] next;
	return -1;

}

//题459 重复的子字符串
//KMP算法
bool stringSolution::repeatedSubstringPattern(string s) {
	if (s.size() == 0) {
		return false;
	}      

	int mysize = s.size();
	int* next = new int[mysize];

	getNext(next,s);

	//最长相同前后缀正好不包括一个可重复的子串
	if (next[mysize - 1] !=-1 && mysize % (mysize - (next[mysize - 1] + 1)) == 0) {
		delete[] next;
		return true;
	}

	delete[] next;
	return false;

}