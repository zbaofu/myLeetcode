#pragma once
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>//����algorithm��
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

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
void bintreeDisplay(nextNode* node); //��ʾ����nextָ��Ķ�����
void preorderTradiaplay(TreeNode* root); // ����������ǰ�������ʾ

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
	int maxDepth(TreeNode* root); //������
	int maxDepth1(TreeNode* root); //�ݹ鷨
	int getdepth(TreeNode* node);

	// ��559 N������������
	int maxNdepth(Node* root); //�ݹ鷨
	int maxNdepth2(Node* root); //������

	// ��111 ����������С���
	int minDepth(TreeNode* root);

	// ��226 ��ת������
	TreeNode* invertTree(TreeNode* root);

	// ��101 �Գƶ�����
	// �ݹ鷨
	bool compare(TreeNode* left, TreeNode* right);
	bool isSymmetric(TreeNode* root);
	// ���е�����
	bool isSymmetric2(TreeNode* root);

	// ��100 ��ͬ����
	bool isSameTree(TreeNode* p, TreeNode* q);
	
	// ��572 ��һ����������
	bool isSubtree(TreeNode* root, TreeNode* subRoot);

	// ��222 ��ȫ�������Ľڵ����
	int getNodesNum(TreeNode* cur); //��Ϊ��ͨ������ �ݹ鷨
	int countNodes(TreeNode* root);
	int countNodes2(TreeNode* cur); //��Ϊ��ͨ������ ������
	int countNodes3(TreeNode* root); //��Ϊ��ȫ������ �ݹ鷨

	// ��110 ƽ�������
	// �ݹ鷨
	int getHeight(TreeNode* node);
	bool isBalanced(TreeNode* root);

	// ��257 ������������·��
	// �ݹ鷨
	void pathtraversal(TreeNode* cur,vector<int>& path,vector<string>& res); //�ݹ麯��
	vector<string> binaryTreePaths(TreeNode* root);

	// ��404 ��Ҷ��֮��
	int sumOfLeftLeaves1(TreeNode* root); // �ݹ鷨

	// ��513 �������½ǵ�ֵ
	int blmaxDepth = INT_MIN;
	int bottomleftresult;
	int findBottomLeftValue1(TreeNode* root); // �ݹ�
	void findBottomtraversal(TreeNode* root, int depth);

	int findBottomLeftValue2(TreeNode* root); // ������

	// ��112 ·��֮��I
	// �ݹ鷨
	bool hpTraversal(TreeNode* cur, int count);
	bool hasPathSum(TreeNode* root, int targetSum);

	// ������
	bool hasPathSum2(TreeNode* root, int targetSum);

	// ��113 ·��֮��II
	//�ݹ鷨
	vector<vector<int>> hpIIres; // ��ά���� ��¼����·��
	vector<int> hpIIpath; // ��¼����·��
	void hpIItraversal(TreeNode* cur, int count);
	vector<vector<int>> pathsum(TreeNode* root, int targetSum);

	// ��106 �����������������������
	// �ݹ鷨
	TreeNode* btTraversal(vector<int>& inorder, vector<int>& postorder);
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

	// ��105 ��������ǰ��������������
	// �ݹ鷨
	TreeNode* bt2Traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
		vector<int>& preorder, int preorderBegin, int preorderEnd);
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder);

	// ��654 ��������
	// �ݹ�1 ������ָ������սڵ����ݹ�
	TreeNode* constructMaximumBinaryTree(vector<int>& nums);
	// �ݹ�� ���±�����ֱ�ӷָ����飬����սڵ����ݹ�
	TreeNode* cmTraversal(vector<int> nums,int left,int right);
	TreeNode* constructMaximumBinaryTree2(vector<int>& nums);

	// ��617 �ϲ�������
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

	// ��700 �����������е�����
	// �ݹ鷨
	TreeNode* searchBST(TreeNode* root, int val);
	// ������
	TreeNode* searchBST2(TreeNode* root, int val);

	// ��98 ��֤����������
	// �ݹ鷨һ ���������������ת�������� ���ж������Ƿ��ǵ�����
	vector<int> BSTvec;
	void BSTtraversal(TreeNode* root);
	bool isValidBST(TreeNode* root);
	// �ݹ鷨�� �������ֱ�ӱȽ�ǰ��ڵ�ֵ�Ƿ��ǵ���
	TreeNode* pre = NULL; // ����ǰһ���ڵ�
	bool isValidBST2(TreeNode* root);

	// ��530 ��������������С����ֵ
	// �ݹ鷨һ ���������������ת����������������Ԫ�ز����Сֵ ֱ������һ��ĵݹ麯��
	int getMinimumDifference(TreeNode* root);
	// �ݹ鷨�� �������ʱֱ�ӱȽ�����Ԫ�صĴ�С
	TreeNode* pre2 = NULL;
	int MDres = INT_MAX;
	int getMinimumDifference2(TreeNode* root);

	// ��501 �����������е�����
	// �ݹ�һ ��Ϊ��ͨ������ ������¼ÿ��Ԫ�س��ֵĴ���
	void findmodeBST(TreeNode* root, unordered_map<int, int>& map);
	vector<int> findMode(TreeNode* root);
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
	// �ݹ�� ��Ϊ�������������� 
	int maxCount = 0; // ���Ƶ��
	int count = 0; // ͳ��Ƶ��
	TreeNode* findmodePre = NULL;
	vector<int> findmodeRes;
	void findmodeBST2(TreeNode* root);
	vector<int> findMode2(TreeNode* root);

	// ��236 �������������������
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	// ��235 �����������������������
	// �ݹ鷨
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);
	// ������
	TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q);

	// ��701 �����������Ĳ������
	// �ݹ鷨
	TreeNode* insertIntoBST(TreeNode* root, int val);
	// ������
	TreeNode* insertIntoBST2(TreeNode* root, int val);

	// ��450 ɾ�������������еĽڵ�
	TreeNode* deleteNode(TreeNode* root, int key);

	// ��669 �޼�����������
	// �ݹ鷨
	TreeNode* trimBST(TreeNode* root, int low, int high);
	// ������
	TreeNode* trimBST2(TreeNode* root, int low, int high);

	//��108 ����������ת���ɶ���������
	// �ݹ鷨
	TreeNode* sortBSTtraversal(vector<int>& nums, int left, int right);
	TreeNode* sortedArrayToBST(vector<int>& nums);

	// ��538 �Ѷ���������ת�����ۼ���
	// �ݹ鷨
	int convertPre = 0;
	TreeNode* convertBST(TreeNode* root);
	// ������
	int convertBSTPre = 0;
	TreeNode* convertBST2(TreeNode* root);


};


#endif