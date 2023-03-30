#pragma once
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>

using namespace std;

// ����������ڵ�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// ����������ת���ɶ������ṹ
TreeNode* creatBintree(int *a,int n, int start); 


class bintreeSolution {
public:
	// ��144 ��������ǰ�����
	void fronttraversal(TreeNode* node,vector<int>& vec);
	vector<int> preorderTraversal(TreeNode* root);

	// ��145 �������ĺ������
	void backtraversal(TreeNode* node, vector<int>& vec);
	vector<int> postorderTraversal(TreeNode* root);

	// ��94 ���������������
	void midtraversal(TreeNode* node, vector<int>& vec);
	vector<int> inorderTraversal(TreeNode* root);


};


#endif