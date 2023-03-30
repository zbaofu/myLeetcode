#pragma once
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>

using namespace std;

// 定义二叉树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// 将有序数组转化成二叉树结构
TreeNode* creatBintree(int *a,int n, int start); 


class bintreeSolution {
public:
	// 题144 二叉树的前序遍历
	void fronttraversal(TreeNode* node,vector<int>& vec);
	vector<int> preorderTraversal(TreeNode* root);

	// 题145 二叉树的后序遍历
	void backtraversal(TreeNode* node, vector<int>& vec);
	vector<int> postorderTraversal(TreeNode* root);

	// 题94 二叉树的中序遍历
	void midtraversal(TreeNode* node, vector<int>& vec);
	vector<int> inorderTraversal(TreeNode* root);


};


#endif