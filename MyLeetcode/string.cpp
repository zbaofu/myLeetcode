#include "string.h"

//��344 ��ת�ַ��� ˫ָ�뷨
vector<char> stringSolution::reverseString(vector<char>& s) {
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
		swap(s[i], s[j]);	
	}
	return s;


}


//��541 ��ת�ַ���II
string stringSolution::reverseStr(string s, int k) {
	
	for (int i = 0; i < s.size(); i += 2*k) {
		
		//���һ ����(2n+1)*k��С��(2n+2)*k
		if (i + k < s.size()) {
			// ���ÿ⺯�� ԭ��������������ͬ
			reverse(s.begin() + i, s.begin() + i + k);
		
		}
		//����� С��(2n+1)*k,����2n*k
		else {
			reverse(s.begin() + i, s.end());
		
		}
	}
	return s;
}




//��ָoffer 05. �滻�ո�
string stringSolution::replaceSpace(string s) {
	int count = 0; // �ո����
	int oldSize = s.size();

	// ����ո���
	for (int i = 0; i < oldSize; i++) {
		if (s[i] == ' ') {
			count++;
		}
	}

	// �����������С
	int newSize = oldSize + count * 2;
	s.resize(newSize);

	// ˫ָ�� iָ���³��ȵ�ĩβ��jָ��ɳ��ȵ�ĩβ��
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


//��151 ��ת�ַ����еĵ���
// ȥ������ո� ˫ָ�뷨 ʱ�临�Ӷ�O(n)
void stringSolution::removeExtraSpaces(string& s) {
	int fastIndex = 0, slowIndex = 0;

	// ȥ���ַ���ͷ���Ŀո񣬿�ָ��ָ���һ���ǿո��ַ�
	while (s.size() > 0 && s[fastIndex] == ' '&&fastIndex < s.size()) {
		fastIndex++;
	}

	// ȥ���ַ����м�Ķ��������ո� ����ĩβ���ظ��ո�
	for (; fastIndex < s.size(); fastIndex++) {
		// �����ո�����
		if (s[fastIndex] == ' '&&s[fastIndex] == s[fastIndex - 1] && fastIndex > 1) {
			continue;
		
		}
		// ���������ֵ����ָ��
		else {
			s[slowIndex++] = s[fastIndex]; //����++�ں���
		}
	}
	// ȥ���ַ���ĩβ�Ŀո�
	if (s[slowIndex - 1] == ' ') {
		s.resize(slowIndex - 1);
	}
	else {
		s.resize(slowIndex); //���������ַ�����С
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



//��ָoffer58 ����ת�ַ���
string stringSolution::reverseLeftWords(string s, int n) {
	reverse(s.begin(), s.begin() + n);
	reverse(s.begin() + n, s.end());
	reverse(s.begin(), s.end());
	return s;

}


//��28 �ҳ��ַ����е�һ��ƥ������±�
// KMP��ģʽƥ�� 
// ����next���飨ǰ׺��ͳһ��һ��
void stringSolution::getNext(int *next, const string& s) {
	int j = -1; //ǰ׺ĩβ����ʼΪ 0-1
	next[0] = j; // ǰ׺���һ��Ԫ��Ϊ 0-1
	for (int i = 1; i < s.size(); i++) {
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j]; // ǰ��׺��ͬʱ�����˵�ǰ׺��ǰһλ
		}
		if (s[i] == s[j + 1]) { // ǰ��׺��ͬʱ��ǰ׺��һ
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
	int* next = new int[mysize];// ��̬�����ڴ�

	//int next[mysize]; //  �����޷��ñ����������ڴ�

	//int* nexttest = new int(5)

	getNext(next,needle); // 

	int j = -1; //ǰ׺��ͳһ��һ
	for (int i = 0; i < haystack.size(); i++) {
		while (j >= 0 && haystack[i] != needle[j + 1]) { // ģʽ�����ı�����ƥ��
			j = next[j]; // ����ǰ׺��ǰһλ
		}
		if (haystack[i] == needle[j + 1]) { // ƥ��ʱ��j����ƶ�
			j++;
		}
		if (j == (needle.size() - 1)) {
			delete[] next; //�ջض��ϵ��ڴ�
			return (i - needle.size() + 1);
		}
	}
	delete[] next;
	return -1;

}

//��459 �ظ������ַ���
//KMP�㷨
bool stringSolution::repeatedSubstringPattern(string s) {
	if (s.size() == 0) {
		return false;
	}      

	int mysize = s.size();
	int* next = new int[mysize];

	getNext(next,s);

	//���ͬǰ��׺���ò�����һ�����ظ����Ӵ�
	if (next[mysize - 1] !=-1 && mysize % (mysize - (next[mysize - 1] + 1)) == 0) {
		delete[] next;
		return true;
	}

	delete[] next;
	return false;

}