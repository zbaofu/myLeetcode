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

