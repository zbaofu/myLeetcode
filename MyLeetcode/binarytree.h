#pragma once
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <vector>
#include <iostream>
#include <algorithm>//调用algorithm库
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

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
void bintreeDisplay(nextNode* node); //显示含有next指针的二叉树
void preorderTradiaplay(TreeNode* root); // 将二叉树按前序遍历显示

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
	int maxDepth(TreeNode* root); //迭代法
	int maxDepth1(TreeNode* root); //递归法
	int getdepth(TreeNode* node);

	// 题559 N叉树的最大深度
	int maxNdepth(Node* root); //递归法
	int maxNdepth2(Node* root); //迭代法

	// 题111 二叉树的最小深度
	int minDepth(TreeNode* root);

	// 题226 翻转二叉树
	TreeNode* invertTree(TreeNode* root);

	// 题101 对称二叉树
	// 递归法
	bool compare(TreeNode* left, TreeNode* right);
	bool isSymmetric(TreeNode* root);
	// 队列迭代法
	bool isSymmetric2(TreeNode* root);

	// 题100 相同的树
	bool isSameTree(TreeNode* p, TreeNode* q);
	
	// 题572 另一棵树的子树
	bool isSubtree(TreeNode* root, TreeNode* subRoot);

	// 题222 完全二叉树的节点个数
	int getNodesNum(TreeNode* cur); //作为普通二叉树 递归法
	int countNodes(TreeNode* root);
	int countNodes2(TreeNode* cur); //作为普通二叉树 迭代法
	int countNodes3(TreeNode* root); //作为完全二叉树 递归法

	// 题110 平衡二叉树
	// 递归法
	int getHeight(TreeNode* node);
	bool isBalanced(TreeNode* root);

	// 题257 二叉树的所有路径
	// 递归法
	void pathtraversal(TreeNode* cur,vector<int>& path,vector<string>& res); //递归函数
	vector<string> binaryTreePaths(TreeNode* root);

	// 题404 左叶子之和
	int sumOfLeftLeaves1(TreeNode* root); // 递归法

	// 题513 找树左下角的值
	int blmaxDepth = INT_MIN;
	int bottomleftresult;
	int findBottomLeftValue1(TreeNode* root); // 递归
	void findBottomtraversal(TreeNode* root, int depth);

	int findBottomLeftValue2(TreeNode* root); // 迭代法

	// 题112 路径之和I
	// 递归法
	bool hpTraversal(TreeNode* cur, int count);
	bool hasPathSum(TreeNode* root, int targetSum);

	// 迭代法
	bool hasPathSum2(TreeNode* root, int targetSum);

	// 题113 路径之和II
	//递归法
	vector<vector<int>> hpIIres; // 二维数组 记录所有路径
	vector<int> hpIIpath; // 记录单次路径
	void hpIItraversal(TreeNode* cur, int count);
	vector<vector<int>> pathsum(TreeNode* root, int targetSum);

	// 题106 从中序与后序遍历构造二叉树
	// 递归法
	TreeNode* btTraversal(vector<int>& inorder, vector<int>& postorder);
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

	// 题105 从中序与前序遍历构造二叉树
	// 递归法
	TreeNode* bt2Traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
		vector<int>& preorder, int preorderBegin, int preorderEnd);
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder);

	// 题654 最大二叉树
	// 递归1 用数组分割，不允许空节点进入递归
	TreeNode* constructMaximumBinaryTree(vector<int>& nums);
	// 递归二 用下标索引直接分割数组，允许空节点进入递归
	TreeNode* cmTraversal(vector<int> nums,int left,int right);
	TreeNode* constructMaximumBinaryTree2(vector<int>& nums);

	// 题617 合并二叉树
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

	// 题700 二叉搜索树中的搜索
	// 递归法
	TreeNode* searchBST(TreeNode* root, int val);
	// 迭代法
	TreeNode* searchBST2(TreeNode* root, int val);

	// 题98 验证二叉搜索树
	// 递归法一 中序遍历将二叉树转换成数组 再判断数组是否是递增的
	vector<int> BSTvec;
	void BSTtraversal(TreeNode* root);
	bool isValidBST(TreeNode* root);
	// 递归法二 中序遍历直接比较前后节点值是否是递增
	TreeNode* pre = NULL; // 定义前一个节点
	bool isValidBST2(TreeNode* root);

	// 题530 二叉搜索树的最小绝对值
	// 递归法一 中序遍历将二叉树转换成数组再求相邻元素差的最小值 直接用上一题的递归函数
	int getMinimumDifference(TreeNode* root);
	// 递归法二 中序遍历时直接比较相邻元素的大小
	TreeNode* pre2 = NULL;
	int MDres = INT_MAX;
	int getMinimumDifference2(TreeNode* root);

	// 题501 二叉搜索树中的众数
	// 递归一 作为普通二叉树 遍历记录每个元素出现的次数
	void findmodeBST(TreeNode* root, unordered_map<int, int>& map);
	vector<int> findMode(TreeNode* root);
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
	// 递归二 作为二叉搜索树来做 
	int maxCount = 0; // 最大频率
	int count = 0; // 统计频率
	TreeNode* findmodePre = NULL;
	vector<int> findmodeRes;
	void findmodeBST2(TreeNode* root);
	vector<int> findMode2(TreeNode* root);

	// 题236 二叉树的最近公共祖先
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

	// 题235 二叉搜索树的最近公共祖先
	// 递归法
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);
	// 迭代法
	TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q);

	// 题701 二叉搜索树的插入操作
	// 递归法
	TreeNode* insertIntoBST(TreeNode* root, int val);
	// 迭代法
	TreeNode* insertIntoBST2(TreeNode* root, int val);

	// 题450 删除二叉搜索树中的节点
	TreeNode* deleteNode(TreeNode* root, int key);

	// 题669 修剪二叉搜索树
	// 递归法
	TreeNode* trimBST(TreeNode* root, int low, int high);
	// 迭代法
	TreeNode* trimBST2(TreeNode* root, int low, int high);

	//题108 将有序数组转换成二叉搜索树
	// 递归法
	TreeNode* sortBSTtraversal(vector<int>& nums, int left, int right);
	TreeNode* sortedArrayToBST(vector<int>& nums);

	// 题538 把二叉搜索树转换成累加树
	// 递归法
	int convertPre = 0;
	TreeNode* convertBST(TreeNode* root);
	// 迭代法
	int convertBSTPre = 0;
	TreeNode* convertBST2(TreeNode* root);


};


#endif