#ifndef _OTHERS_H_
#define _OTHERS_H_
#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class otherSolution {
public:
	// 题657 机器人能否返回原点
	bool judgeCircle(string moves);


	// 题200 岛屿数量
	void numIslandsDfs(vector<vector<char>>& grid,int r,int c);
	int numIslands(vector<vector<char>>& grid);


};




#endif // !_OTHERS_H_
#pragma once
