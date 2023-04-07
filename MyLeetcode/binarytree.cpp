#include "binarytree.h"

/**************
函数名：creatBintree(int *a, int n, int start) {
输入：数组 数组长度 根节点坐标
输出：二叉树根节点
描述：利用递归将有序数组转化成链式二叉树结构，默认数组顺序使用层次遍历二叉树，空节点为NULL
***************/
TreeNode* creatBintree(int *a, int n, int start) {
	if (a[start]==NULL) return NULL;

	TreeNode* root = new TreeNode(0);
	root->val = a[start];
	root->left = NULL;
	root->right = NULL;

	
	int leftnode = 2 * start + 1;
	int rightnode = 2 * start + 2;
	
	// 当前一个节点为空时，子节点位置左移两格
	if (start > 1 && a[start - 1] == NULL) {
		 leftnode -= 2;
		 rightnode -= 2;
	}
	// 当连续两个节点为空时，则子节点位置再左移两格
	if (start > 2 && a[start - 2] == NULL) {
		leftnode -= 2;
		rightnode -= 2;
	}


	if (leftnode > n - 1) root->left = NULL;
	else root->left = creatBintree(a, n, leftnode);
	

	if (rightnode > n - 1) root->right = NULL;
	else root->right = creatBintree(a, n, rightnode);

	return root;
}
 
// 返回含next指针的二叉树
nextNode* creatBintree1(int *a, int n, int start) {
	if (a[start] == NULL) return NULL;

	nextNode* root = new nextNode(0);
	root->val = a[start];
	root->left = NULL;
	root->right = NULL;


	int leftnode = 2 * start + 1;
	int rightnode = 2 * start + 2;

	// 当前一个节点为空时，子节点位置左移两格
	if (start > 1 && a[start - 1] == NULL) {
		leftnode -= 2;
		rightnode -= 2;
	}
	// 当连续两个节点为空时，则子节点位置再左移两格
	if (start > 2 && a[start - 2] == NULL) {
		leftnode -= 2;
		rightnode -= 2;
	}

	if (leftnode > n - 1) root->left = NULL;
	else root->left = creatBintree1(a, n, leftnode);

	if (rightnode > n - 1) root->right = NULL;
	else root->right = creatBintree1(a, n, rightnode);

	return root;

}

/*************
函数名：bintreeDisplay(nextNode* node) 
输入：要显示的二叉树
返回：无
描述：将含有next指针的二叉树显示在控制台
**************/
void bintreeDisplay(nextNode* node) {
	if (node == nullptr)return;
	cout << "[ ";
	while (node != nullptr) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << "] " << endl;
}
/*************
函数名：preorderTradiaplay(TreeNode* root) 
输入：要显示的二叉树
返回：无
描述：将二叉树按前序遍历显示在控制台,递归法
**************/
void preorderTradiaplay(TreeNode* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorderTradiaplay(root->left);
	preorderTradiaplay(root->right);


}


// 题144 二叉树的前序遍历 递归法
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


//二叉树前序遍历 迭代法
vector<int> bintreeSolution::preorderTraversal2(TreeNode* root) {
	stack<TreeNode*> st; //定义栈存放树节点
	vector<int> res;
	if (root == NULL) return res;
	st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		st.pop();
		res.push_back(node->val);
		if (node->right) st.push(node->right);
		if (node->left) st.push(node->left);
	}
	return res;
}

//二叉树前序遍历 统一迭代法
vector<int> bintreeSolution::preorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // 后面再重新添加
			// 右左中（空节点）顺序入栈
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
			st.push(node);
			st.push(NULL); //中节点入栈后加入空节点作为标记，用于后序处理
		}
		else {
			st.pop();
			node = st.top();
			st.pop();
			res.push_back(node->val);
		}

	}
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

//二叉树后序遍历 迭代法 前序遍历是中左右，后序遍历是左右中，
//则按照前序遍历的代码得到中右左，再将数组反转可得
vector<int> bintreeSolution::postorderTraversal2(TreeNode* root) {
	stack<TreeNode*> st; //定义栈存放树节点
	vector<int> res;
	if (root == NULL) return res;
	st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		st.pop();
		res.push_back(node->val);
		if (node->left) st.push(node->left);
		if (node->right) st.push(node->right);
	}
	reverse(res.begin(),res.end());
	return res;
}

// 二叉树的后序遍历 统一迭代法
vector<int> bintreeSolution::postorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // 后面再重新添加
			// 中 （空节点） 右左顺序入栈
			st.push(node);
			st.push(NULL); //中节点入栈后加入空节点作为标记，用于后序处理
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
		}
		else {
			st.pop();
			node = st.top();
			st.pop();
			res.push_back(node->val);
		}

	}
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

// 二叉树的中序遍历 迭代法
vector<int> bintreeSolution::inorderTraversal2(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur != NULL || !st.empty()) {
		if (cur != NULL) {
			st.push(cur);
			cur = cur->left;
		
		}
		else {
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}
	}
	return res;
}

// 二叉树的中序遍历 统一迭代法
vector<int> bintreeSolution::inorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // 后面再重新添加
			// 右中 （空节点） 左顺序入栈
			if (node->right) st.push(node->right);
			st.push(node);
			st.push(NULL); //中节点入栈后加入空节点作为标记，用于后序处理
			if (node->left) st.push(node->left);
		}
		else {
			st.pop();
			node = st.top();
			st.pop();
			res.push_back(node->val);
		}

	}
	return res;
}


// 题102 二叉树的层序遍历 队列实现
vector<vector<int>> bintreeSolution::levelOrder(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res; 
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //存储每一层的节点
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		res.push_back(vec);
	}
	return res;
}

// 二叉树的层序遍历 递归法
void bintreeSolution::order(TreeNode* cur, vector<vector<int>>& res, int depth) {
	if (cur == NULL) return;
	if (res.size() == depth) res.push_back(vector<int>()); // 二维数组出现新行
	res[depth].push_back(cur->val); // 一层层添加元素值
	order(cur->left, res, depth + 1); // 输入并非depth++，本层未改变depth的值
	order(cur->right, res, depth + 1);
}

vector<vector<int>> bintreeSolution::levelOrder2(TreeNode* root) {
	vector<vector<int>> res;
	int depth = 0;      
	order(root,res,depth);
	return res;
}

// 题107 二叉树的层序遍历II
vector<vector<int>> bintreeSolution::levelOrderBottom(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //存储每一层的节点
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		res.push_back(vec);
	}
	reverse(res.begin(), res.end());
	return res;
}


// 题199 二叉树的右视图
vector<int> bintreeSolution::rightSideView(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<int> res;
	//vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		//vector<int> vec;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == size - 1) res.push_back(node->val);
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return res;
}


// 题637 二叉树的层平均值
vector<double> bintreeSolution::averageOfLevels(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<double> res;
	//vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		double sum = 0;
		//vector<int> vec;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			sum += node->val;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		res.push_back(sum / size);
	}
	return res;

}


// 题429 N叉树的层序遍历
vector<vector<int>> bintreeSolution::levelOrder3(Node* root) {
	queue<Node*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //存储每一层的节点
		for (int i = 0; i < size; i++) {
			Node* node = que.front();
			que.pop();
			vec.push_back(node->val);
			for (int i = 0; i < node->children.size(); i++) {
				if (node->children[i]) que.push(node->children[i]);
			}
		}
		res.push_back(vec);
	}
	return res;
}

// 题515 在每个树行找最大值
vector<int> bintreeSolution::largestValues(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<int> res;
	//vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		//vector<int> vec;
		int max = INT_MIN;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			max = max > node->val ? max : node->val;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		res.push_back(max);
	}
	return res;

}

// 题116 填充每个节点的下一个右侧节点指针
nextNode* bintreeSolution::connect(nextNode* root) {
	queue<nextNode*> que;
	if (root != NULL) que.push(root);
	while (!que.empty()) {
		int size = que.size();
		nextNode* nodePre(0);
		nextNode* node(0);
		for (int i = 0; i < size; i++) {
			if (i == 0) {
				nodePre = que.front();
				que.pop();
				node = nodePre;
			}
			else {
				node = que.front();
				que.pop();
				nodePre->next = node;
				nodePre = nodePre->next;
			}
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
		nodePre->next = NULL;
	}
	return root;

}

// 题104.二叉树的最大深度
int bintreeSolution::maxDepth(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int depth = 0;
	while (!que.empty()) {
		int size = que.size();
		depth++;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();

			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return depth;
}


// 题111 二叉树的最小深度
int bintreeSolution::minDepth(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int depth = 0;
	while (!que.empty()) {
		int size = que.size();
		depth++;
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();

			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
			if ((node->left == NULL) && (node->right == NULL)) return depth;
		}
	}
	return depth;

}


// 题226 翻转二叉树 递归法
TreeNode* bintreeSolution::invertTree(TreeNode* root) {
	if (root == NULL) return root;
	swap(root->left,root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}


// 题101 对称二叉树 递归法
bool bintreeSolution::compare(TreeNode* left, TreeNode* right) {
	// 排除空节点的情况
	if (left == NULL && right != NULL) return false;
	else if (left != NULL && right == NULL) return false;
	else if (left == NULL && right == NULL) return true;
	// 排除数值不相等
	else if (left->val != right->val) return false;

	// 数值相等且不为空则向下做递归
	bool outside = compare(left->left, right->right);
	bool inside = compare(left->right, right->left);
	bool isSame = outside && inside;
	return isSame;
}

bool bintreeSolution::isSymmetric(TreeNode* root) {
	if (root == NULL) return true;
	return compare(root->left, root->right);
}

// 对称二叉树 迭代法 队列
bool bintreeSolution::isSymmetric2(TreeNode* root) {
	if (root == NULL) return true;
	queue<TreeNode*> que;
	que.push(root->left);
	que.push(root->right);
	while (!que.empty()) {
		TreeNode* leftnode = que.front(); que.pop();
		TreeNode* rightnode = que.front(); que.pop();
		if (!leftnode && !rightnode) {
			continue;
		}		
		if ((!leftnode || !rightnode || (leftnode->val != rightnode->val))) {
			return false;
		}	
		que.push(leftnode->left);
		que.push(rightnode->right);
		que.push(leftnode->right);
		que.push(rightnode->left);
	}
	return true;
}

// 题100 相同的树
bool bintreeSolution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q != NULL) return false;
	else if (p != NULL && q == NULL) return false;
	else if (p == NULL && q == NULL) return true;
	else if (p->val != q->val) return false;
	
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 题572 另一棵树的子树
/*
子树的三种情况：
两个树相等
这个树是左树的子树
这个树hi右树的子树
*/
bool bintreeSolution::isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (root == NULL && subRoot == NULL) return true;
	else if (root == NULL && subRoot != NULL) return false;
	//else if (root->val != subRoot->val) return false;

	return isSameTree(root, subRoot)
		|| isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
}
