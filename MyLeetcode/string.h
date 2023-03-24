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
	void removeExtraSpaces(string& s); //ȥ������ո�
	string reverseWords(string s); 

	//��ָoffer58 ����ת�ַ���
	string reverseLeftWords(string s, int n);

	//��28 �ҳ��ַ����е�һ��ƥ������±�
	void getNext(int *next, const string& s); // ����next���飨ǰ׺��
	int strStr(string haystack, string needle);

	//��459 �ظ������ַ���
	bool repeatedSubstringPattern(string s);
};





#endif