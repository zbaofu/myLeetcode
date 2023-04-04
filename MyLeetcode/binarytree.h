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

// ����N�����Ľڵ�
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

// �������ڵ㶨�� ����nextָ��
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



// ����������ת���ɶ������ṹ
TreeNode* creatBintree(int *a,int n, int start); 
nextNode* creatBintree1(int *a, int n, int start);

// ��������ʾ
void bintreeDisplay(nextNode* node);

class bintreeSolution {
public:
	// ��144 ��������ǰ����� �����ݹ鷨
	void fronttraversal(TreeNode* node,vector<int>& vec);
	vector<int> preorderTraversal(TreeNode* root);
	//������ǰ����� ������
	vector<int> preorderTraversal2(TreeNode* root);
	//������ǰ����� ͳһ������
	vector<int> preorderTraversal3(TreeNode* root);



	// ��145 �������ĺ������ �ݹ鷨
	void backtraversal(TreeNode* node, vector<int>& vec);
	vector<int> postorderTraversal(TreeNode* root);
	// �������ĺ������ ������
	vector<int> postorderTraversal2(TreeNode* root);
	// �������ĺ������ ͳһ������
	vector<int> postorderTraversal3(TreeNode* root);



	// ��94 ��������������� �ݹ鷨
	void midtraversal(TreeNode* node, vector<int>& vec);
	vector<int> inorderTraversal(TreeNode* root);
	// ��������������� ������
	vector<int> inorderTraversal2(TreeNode* root);
	// ��������������� ͳһ������
	vector<int> inorderTraversal3(TreeNode* root);


	// ��102 �������Ĳ������
	vector<vector<int>> levelOrder(TreeNode* root);
	// ������������� �ݹ鷨
	void order(TreeNode* cur, vector<vector<int>>& res, int depth);
	vector<vector<int>> levelOrder2(TreeNode* root);

	// ��107 �������Ĳ������ II
	vector<vector<int>> levelOrderBottom(TreeNode* root);

	// ��199 ������������ͼ
	vector<int> rightSideView(TreeNode* root);

	// ��637 �������Ĳ�ƽ��ֵ
	vector<double> averageOfLevels(TreeNode* root);

	// ��429 N�����Ĳ������
	vector<vector<int>> levelOrder3(Node* root);

	// ��515 ��ÿ�����������ֵ
	vector<int> largestValues(TreeNode* root);

	// ��116 ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
	nextNode* connect(nextNode* root);

	// ��104.��������������
	int maxDepth(TreeNode* root);

	// ��111 ����������С���
	int minDepth(TreeNode* root);

};


#endif