#ifndef _STRING_H
#define _STRING_H

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>

using namespace std;

class stringSolution {
public:
	//题 反转字符串
	vector<char> reverseString(vector<char>& s);

	//题541 反转字符串II
	string reverseStr(string s, int k);

	//剑指offer 05. 替换空格
	string replaceSpace(string s);

	//题151 反转字符串中的单词
	void removeExtraSpaces(string& s); //去除多余空格
	string reverseWords(string s); 

	//剑指offer58 左旋转字符串
	string reverseLeftWords(string s, int n);

	//题28 找出字符串中第一个匹配项的下标
	void getNext(int *next, const string& s); // 构造next数组（前缀表）
	int strStr(string haystack, string needle);

	//题459 重复的子字符串
	bool repeatedSubstringPattern(string s);
};





#endif