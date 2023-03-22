#include"string.h"

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