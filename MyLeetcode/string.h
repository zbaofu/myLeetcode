#ifndef _STRING_H
#define _STRING_H

#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>

using namespace std;

class stringSolution {
public:
	//�� ��ת�ַ���
	vector<char> reverseString(vector<char>& s);

	//��541 ��ת�ַ���II
	string reverseStr(string s, int k);

	//��ָoffer 05. �滻�ո�
	string replaceSpace(string s);

	//��151 ��ת�ַ����еĵ���
	string reverseWords(string s);

};





#endif