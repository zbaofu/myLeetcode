#ifndef _OTHERS_H_
#define _OTHERS_H_
#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class otherSolution {
public:
	// ��657 �������ܷ񷵻�ԭ��
	bool judgeCircle(string moves);


	// ��200 ��������
	void numIslandsDfs(vector<vector<char>>& grid,int r,int c);
	int numIslands(vector<vector<char>>& grid);


};




#endif // !_OTHERS_H_
#pragma once
