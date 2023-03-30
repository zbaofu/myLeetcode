#include "binarytree.h"

/**************
函数名：creatBintree(int *a, int n, int start) {
输入：数组 数组长度 根节点坐标
输出：二叉树根节点
描述：利用递归将有序数组转化成链式二叉树结构
***************/
TreeNode* creatBintree(int *a, int n, int start) {
	if (a[start]==NULL) return NULL;

	TreeNode* root = new TreeNode(0);
	root->val = a[start];
	root->left = NULL;
	root->right = NULL;

	int leftnode = 2 * start + 1;
	int rightnode = 2 * start + 2;
	
	if (leftnode > n - 1) root->left = NULL;
	else root->left = creatBintree(a, n, leftnode);

	if (rightnode > n - 1) root->right = NULL;
	else root->right = creatBintree(a, n, rightnode);

	return root;
}


// 题144 二叉树的前序遍历
void bintreeSolution::fronttraversal(TreeNode* node, vector<int>& vec) {
	if (node == NULL) return;
	vec.push_back(node->val);
	fronttraversal(node->left,vec);
	fronttraversal(node->right,vec);
}


vector<int> bintreeSolution::preorderTraversal(TreeNode* root) {
	vector<int> res;
	fronttraversal(root,res);
	return res;
}



// 题145 二叉树的后序遍历
void bintreeSolution::backtraversal(TreeNode* node, vector<int>& vec) {
	if (node == NULL) return;
	
	backtraversal(node->left, vec);
	backtraversal(node->right, vec);
	vec.push_back(node->val);
}

vector<int> bintreeSolution::postorderTraversal(TreeNode* root) {
	vector<int> res;
	backtraversal(root, res);
	return res;
}



// 题94 二叉树的中序遍历
void bintreeSolution::midtraversal(TreeNode* node, vector<int>& vec) {
	if (node == NULL) return;
	
	midtraversal(node->left, vec);
	vec.push_back(node->val);
	midtraversal(node->right, vec);

}
vector<int> bintreeSolution::inorderTraversal(TreeNode* root) {
	vector<int> res;
	midtraversal(root, res);
	return res;

}