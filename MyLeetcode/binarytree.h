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

// 定义N叉树的节点
class Node {
public:
	int val;
	vector<Node*> children;
	Node() {}
	Node(int _val) {
		val = _val;
	}
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

// 二叉树节点定义 增加next指针
class nextNode {
public:
	int val;
	nextNode* left;
	nextNode* right;
	nextNode* next;

	nextNode() : val(0), left(NULL), right(NULL), next(NULL) {}
	nextNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	nextNode(int _val, nextNode* _left, nextNode* _right, nextNode* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};



// 将有序数组转化成二叉树结构
TreeNode* creatBintree(int *a,int n, int start); 
nextNode* creatBintree1(int *a, int n, int start);

// 二叉树显示
void bintreeDisplay(nextNode* node);

class bintreeSolution {
public:
	// 题144 二叉树的前序遍历 函数递归法
	void fronttraversal(TreeNode* node,vector<int>& vec);
	vector<int> preorderTraversal(TreeNode* root);
	//二叉树前序遍历 迭代法
	vector<int> preorderTraversal2(TreeNode* root);
	//二叉树前序遍历 统一迭代法
	vector<int> preorderTraversal3(TreeNode* root);



	// 题145 二叉树的后序遍历 递归法
	void backtraversal(TreeNode* node, vector<int>& vec);
	vector<int> postorderTraversal(TreeNode* root);
	// 二叉树的后序遍历 迭代法
	vector<int> postorderTraversal2(TreeNode* root);
	// 二叉树的后序遍历 统一迭代法
	vector<int> postorderTraversal3(TreeNode* root);



	// 题94 二叉树的中序遍历 递归法
	void midtraversal(TreeNode* node, vector<int>& vec);
	vector<int> inorderTraversal(TreeNode* root);
	// 二叉树的中序遍历 迭代法
	vector<int> inorderTraversal2(TreeNode* root);
	// 二叉树的中序遍历 统一迭代法
	vector<int> inorderTraversal3(TreeNode* root);


	// 题102 二叉树的层序遍历
	vector<vector<int>> levelOrder(TreeNode* root);
	// 二叉树层序遍历 递归法
	void order(TreeNode* cur, vector<vector<int>>& res, int depth);
	vector<vector<int>> levelOrder2(TreeNode* root);

	// 题107 二叉树的层序遍历 II
	vector<vector<int>> levelOrderBottom(TreeNode* root);

	// 题199 二叉树的右视图
	vector<int> rightSideView(TreeNode* root);

	// 题637 二叉树的层平均值
	vector<double> averageOfLevels(TreeNode* root);

	// 题429 N叉树的层序遍历
	vector<vector<int>> levelOrder3(Node* root);

	// 题515 在每个树行找最大值
	vector<int> largestValues(TreeNode* root);

	// 题116 填充每个节点的下一个右侧节点指针
	nextNode* connect(nextNode* root);

	// 题104.二叉树的最大深度
	int maxDepth(TreeNode* root);

	// 题111 二叉树的最小深度
	int minDepth(TreeNode* root);

};


#endif