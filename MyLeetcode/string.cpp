#include"string.h"

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

