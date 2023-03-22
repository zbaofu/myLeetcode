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
	string reverseWords(string s);

};





#endif