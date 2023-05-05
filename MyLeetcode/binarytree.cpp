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
// 迭代法
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

// 递归法
int bintreeSolution::getdepth(TreeNode* node) {
	if (node == NULL) return 0;
	int leftdepth = getdepth(node->left);
	int rightdepth = getdepth(node->right);
	int depth = 1 + max(leftdepth,rightdepth);
	return depth;
}

int bintreeSolution::maxDepth1(TreeNode* root) {
	return getdepth(root);

}

// 题559 N叉树的最大深度
// 递归法
int bintreeSolution::maxNdepth(Node* root) {
	if (root == NULL) return 0;
	int depth = 0;
	for (int i = 0; i < root->children.size(); i++) {
		depth = max(depth, maxNdepth(root->children[i]));
	
	}
	return depth + 1;
}
// 迭代法
int bintreeSolution::maxNdepth2(Node* root) {
	queue<Node*> que;
	if (root != NULL) que.push(root);
	int depth = 0;
	while (!que.empty()) {
		int size = que.size();
		depth++;
		for (int i = 0; i < size; i++) {
			Node* node = que.front();
			que.pop();
			for (int j = 0; j < node->children.size(); j++) {
				if (node->children[j]) que.push(node->children[j]);
			
			}
		
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

// 题222 完全二叉树的节点个数
//作为普通二叉树 递归法
int bintreeSolution::getNodesNum(TreeNode* cur) {
	if (cur == NULL)return 0;
	int leftNum = getNodesNum(cur->left);
	int rightNum = getNodesNum(cur->right);
	int treeNum = leftNum + rightNum + 1;
	return treeNum;
}

int bintreeSolution::countNodes(TreeNode* root) {
	return getNodesNum(root);

}

//作为普通二叉树 迭代法
int bintreeSolution::countNodes2(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int res = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			res++;
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		}
	}
	return res;
}

//作为完全二叉树 递归法
int bintreeSolution::countNodes3(TreeNode* root) {
	if (root == NULL) return 0;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	int leftDepth = 0;
	int rightDepth = 0;
	while (left) {
		left = left->left;
		leftDepth++;
	}
	while (right) {
		right = right->right;
		rightDepth++;
	}
	if (leftDepth == rightDepth) {
		return (2 << leftDepth) - 1;
	
	}
	return countNodes3(root->left) + countNodes3(root->right);
}

// 题110 平衡二叉树
// 递归法
int bintreeSolution::getHeight(TreeNode* node) {
	if (node == NULL) {
		return 0;
	}
	int leftHeight = getHeight(node->left);
	if (leftHeight == -1) return -1;
	int rightHeight = getHeight(node->right);
	if (rightHeight == -1)  return -1;
	return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);

}


bool bintreeSolution::isBalanced(TreeNode* root) {
	return getHeight(root) == -1 ? false : true;
}

// 题257 二叉树的所有路径
// 递归法
void bintreeSolution::pathtraversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
	path.push_back(cur->val);
	// 左孩子和右孩子都是空
	if (cur->left == NULL && cur->right == NULL) {
		string sPath;
		for (int i = 0; i < path.size() - 1; i++) {
			sPath += to_string(path[i]);
			sPath += "->";
		}
		sPath += to_string(path[path.size() - 1]);
		res.push_back(sPath);
		return;
	}
	if (cur->left) {
		pathtraversal(cur->left, path, res);
		path.pop_back();
	
	}
	if (cur->right) {
		pathtraversal(cur->right, path, res);
		path.pop_back();
	}
}

vector<string> bintreeSolution::binaryTreePaths(TreeNode* root) {
	vector<string> res;
	vector<int> path;
	if (root == NULL) return res;
	pathtraversal(root, path, res);
	return res;
}


// 题404 左叶子之和
// 递归法
int bintreeSolution::sumOfLeftLeaves1(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 0;

	// 左子树的左叶子
	int leftValue = sumOfLeftLeaves1(root->left);
	// 判断左叶子
	if (root->left && !root->left->left && !root->left->right){
		leftValue = root->left->val;
	}
	int rightValue = sumOfLeftLeaves1(root->right);

	int sum = leftValue + rightValue;
	return sum;
}

// 题513 找树左下角的值
// 递归法
void bintreeSolution::findBottomtraversal(TreeNode* root, int depth) {
	// 判断叶子节点
	if (root->left == NULL && root->right == NULL) {
		// 更新最大深度
		if (depth > blmaxDepth) {
			blmaxDepth = depth;
			bottomleftresult = root->val;
		}
		return;
	}
	if (root->left) {
		depth++;
		findBottomtraversal(root->left, depth);
		depth--; //回溯
	}
	if (root->right) {
		depth++;
		findBottomtraversal(root->right, depth);
		depth--; //回溯
	
	}
	return;
}
int bintreeSolution::findBottomLeftValue1(TreeNode* root) {
	findBottomtraversal(root, 0);
	return bottomleftresult;
}

// 迭代法 层序遍历
int bintreeSolution::findBottomLeftValue2(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int result = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == 0) result = node->val; //第一个元素值
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		
		}
	}
	return result;
}

// 题112 路径之和I
// 递归法
bool bintreeSolution::hpTraversal(TreeNode* cur, int count) {
	if (!cur->left && !cur->right&&count == 0) return true;
	if (!cur->left && !cur->right) return false;

	if (cur->left) {
		count -= cur->left->val;
		if (hpTraversal(cur->left, count)) return true;
		count += cur->left->val;
	}
	if (cur->right) {
		count -= cur->right->val;
		if (hpTraversal(cur->right, count)) return true;
		count += cur->right->val;
	}
	return false;
}

bool bintreeSolution::hasPathSum(TreeNode* root, int targetSum) {
	if (root == NULL) return false;
	return hpTraversal(root, targetSum - root->val);
}

// 迭代法 使用栈模拟前序遍历
bool bintreeSolution::hasPathSum2(TreeNode* root, int targetSum) {
	if (root == NULL) return false;
	stack<pair<TreeNode*, int>> st;
	st.push(pair<TreeNode*, int>(root, root->val));
	while (!st.empty()) {
		pair<TreeNode*, int> node = st.top();
		st.pop();
		if (!node.first->left && !node.first->right && targetSum == node.second) return true;
		// 右节点
		if (node.first->right) {
			st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
		}
		// 左节点
		if (node.first->left) {
			st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
		}	
	}
	return false;
}

// 题113 路径之和II
//递归法
void bintreeSolution::hpIItraversal(TreeNode* cur, int count) {
	// 找到一条路径
	if (!cur->left && !cur->right && count == 0) {
		hpIIres.push_back(hpIIpath);
		return;
	}
	// 到叶子节点但和不为target
	if (!cur->left && !cur->right) {
		return;
	}

	if (cur->left) {
		hpIIpath.push_back(cur->left->val);
		count -= cur->left->val;
		hpIItraversal(cur->left, count);
		count += cur->left->val; //回溯
		hpIIpath.pop_back();
	}

	if (cur->right) {
		hpIIpath.push_back(cur->right->val);
		count -= cur->right->val;
		hpIItraversal(cur->right, count);
		count += cur->right->val; //回溯
		hpIIpath.pop_back();
	}
	return;

}
vector<vector<int>> bintreeSolution::pathsum(TreeNode* root, int targetSum) {
	hpIIpath.clear();
	hpIIres.clear();
	if (root == NULL) return hpIIres;
	hpIIpath.push_back(root->val);
	hpIItraversal(root, targetSum - root->val);
	return hpIIres;
}

// 题106 从中序与后序遍历构造二叉树
// 递归法
TreeNode* bintreeSolution::btTraversal(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0) return NULL;

	//后序遍历数组最后一个元素为中间节点
	int rootValue = postorder[postorder.size() - 1];
	TreeNode* root = new TreeNode(rootValue);

	// 叶子节点
	if (postorder.size() == 1) return root;

	// 找到中序节点的切割点
	int delimiterIndex;
	for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
		if (inorder[delimiterIndex] == rootValue) break;
	}
	// 切割中序数组
	// 左闭右开：[ )
	vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
	vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

	// 后序数组舍弃末尾元素
	postorder.resize(postorder.size() - 1);

	// 切割后序数组
	// 左闭右开 使用中序数组的大小作为切割点
	vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
	vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

	root->left = btTraversal(leftInorder, leftPostorder);
	root->right = btTraversal(rightInorder, rightPostorder);

	return root;
}

TreeNode* bintreeSolution::buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.size() == 0 || postorder.size() == 0) return NULL;
	return btTraversal(inorder, postorder);
}


// 题105 从中序与前序遍历构造二叉树
// 递归法 用下标索引切割数组
TreeNode* bintreeSolution::bt2Traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
	if (preorderBegin == preorderEnd) return NULL;

	int rootValue = preorder[preorderBegin]; // 根节点为前序遍历数组第一个元素
	TreeNode* root = new TreeNode(rootValue);

	if (preorderEnd - preorderBegin == 1) return root;


	int delimiterIndex;
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
		if (inorder[delimiterIndex] == rootValue) break;
	}

	// 切割中序数组
	// 中序左区间，左闭右开
	int leftInorderBegin = inorderBegin;
	int leftInorderEnd = delimiterIndex;
	// 中序右区间，左闭右开
	int rightInorderBegin = delimiterIndex + 1;
	int rightInorderEnd = inorderEnd;

	// 切割前序数组
	// 前序左区间 左闭右开
	int leftPreorderBegin = preorderBegin + 1;
	int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
	// 前序右区间，左闭右开
	int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
	int rightPreorderEnd = preorderEnd;

	root->left = bt2Traversal(inorder, leftInorderBegin, leftInorderEnd, 
		preorder, leftPreorderBegin, leftPreorderEnd);
	root->right = bt2Traversal(inorder, rightInorderBegin, rightInorderEnd,
		preorder, rightPreorderBegin, rightPreorderEnd);

	return root;

}

TreeNode* bintreeSolution::buildTree2(vector<int>& preorder, vector<int>& inorder) {
	if (inorder.size() == 0 || preorder.size() == 0) return NULL;

	return bt2Traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
}

// 题654 最大二叉树
// 递归1 用数组分割，不允许空节点进入递归
TreeNode* bintreeSolution::constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode* node = new TreeNode(0);
	// 到叶子节点
	if (nums.size() == 1) {
		node->val = nums[0];
		return node;
	}

	//找到数组中的最大值和对应下标
	int maxValue = 0;
	int maxValueIndex = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > maxValue) {
			maxValue = nums[i];
			maxValueIndex = i;
		}
	}
	// 最大值为根节点
	node->val = maxValue;
	// 最大值下标的左区间 构造左子树
	// 判断左区间不是空
	if (maxValueIndex > 0) {
		vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
		node->left = constructMaximumBinaryTree(newVec);
	}
	// 最大值下标的右区间 构造右子树
	// 判断右区间不是空
	if (maxValueIndex < (nums.size()-1)) {
		vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
		node->right = constructMaximumBinaryTree(newVec);
	}
	return node;
}


// 递归二 用下标索引直接分割数组，允许空节点进入递归
TreeNode* bintreeSolution::cmTraversal(vector<int> nums, int left, int right) {
	
	if (left >= right) return NULL;

	int maxValueIndex = left;
	for (int i = left+1; i < right; i++) {
		if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
	}

	TreeNode* root = new TreeNode(nums[maxValueIndex]);

	root->left = cmTraversal(nums, left, maxValueIndex);
	root->right = cmTraversal(nums, maxValueIndex + 1, right);

	return root;
}

TreeNode* bintreeSolution::constructMaximumBinaryTree2(vector<int>& nums) {
	return cmTraversal(nums, 0, nums.size());
}

// 题617 合并二叉树
// 前序遍历 递归 定义新的节点
TreeNode* bintreeSolution::mergeTrees(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL) return root2;
	if (root2 == NULL) return root1;

	TreeNode* root = new TreeNode(0);
	root->val = root1->val + root2->val;

	root->left = mergeTrees(root1->left, root2->left);
	root->right = mergeTrees(root1->right, root2->right);
	return root;
}

// 题700 二叉搜索树中的搜索
// 递归 
TreeNode* bintreeSolution::searchBST(TreeNode* root, int val) {
	if (root == NULL || root->val == val) return root;
	TreeNode* res = NULL;
	if (root->val > val) res = searchBST(root->left, val);
	if (root->val < val) res = searchBST(root->right, val);
	return res;
}

// 迭代法
TreeNode* bintreeSolution::searchBST2(TreeNode* root, int val) {
	while (root) {
		if (root->val > val) root = root->left;
		else if (root->val < val) root = root->right;
		else return root;
	}
	return NULL;
}

// 题98 验证二叉搜索树
// 递归法一 中序遍历将二叉树转换成数组
void bintreeSolution::BSTtraversal(TreeNode* root) {
	if (root == NULL) return;
	BSTtraversal(root->left);
	BSTvec.push_back(root->val);
	BSTtraversal(root->right);
}

bool bintreeSolution::isValidBST(TreeNode* root) {
	BSTvec.clear();
	BSTtraversal(root);
	for (int i = 1; i < BSTvec.size(); i++) {
		if (BSTvec[i] <= BSTvec[i - 1]) return false;
	}
	return true;

}

// 递归法二 中序遍历直接比较前后节点值是否是递增
bool bintreeSolution::isValidBST2(TreeNode* root) {
	if (root == NULL) return true;

	bool left = isValidBST2(root->left);

	if (pre != NULL && pre->val >= root->val) return false;
	pre = root;

	bool right = isValidBST2(root->right);
	return left && right;
}

// 题530 二叉搜索树的最小绝对差
// 递归法一 中序遍历将二叉树转换成数组再求相邻元素差的最小值 直接用上一题的递归函数
int bintreeSolution::getMinimumDifference(TreeNode* root) {
	BSTvec.clear();
	BSTtraversal(root);
	int res = INT_MAX;
	for (int i = 1; i < BSTvec.size(); i++) {
		res = min(res, BSTvec[i] - BSTvec[i - 1]);
	}
	return res;
}

// 递归法二 中序遍历时直接比较相邻元素的差值的大小
int bintreeSolution::getMinimumDifference2(TreeNode* root) {

	if (root == NULL) return MDres;
	MDres = getMinimumDifference2(root->left);

	if (pre2 != NULL) {
		MDres = min(MDres, root->val - pre2->val);
	}
	pre2 = root;

	MDres = getMinimumDifference2(root->right);
	return MDres;
}

// 题501 二叉搜索树中的众数
// 递归一 作为普通二叉树 遍历记录每个元素出现的次数
void bintreeSolution::findmodeBST(TreeNode* root, unordered_map<int, int>& map) {
	if (root == NULL) return;
	map[root->val]++;
	findmodeBST(root->left, map);
	findmodeBST(root->right, map);
}

vector<int> bintreeSolution::findMode(TreeNode* root) {
	unordered_map<int, int> map;
	vector<int> res;
	if (root == NULL) return res;
	findmodeBST(root, map);
	// 哈希表不能对value排序，转换成vector再用sort排序
	vector<pair<int, int>> vec(map.begin(),map.end());

	sort(vec.begin(), vec.end(), cmp);
	res.push_back(vec[0].first);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
	}

	return res;
}

// 递归二 作为二叉搜索树来做 中序遍历 左中右
void bintreeSolution::findmodeBST2(TreeNode* root) {
	if (root == NULL) return;
	findmodeBST2(root->left);
	if (findmodePre == NULL) {
		count = 1;
	}
	else if (findmodePre->val == root->val) {
		count++;
	}
	else {
		count = 1;
	}
	findmodePre = root;
	if (count == maxCount) {
		findmodeRes.push_back(root->val);
	}
	if (count > maxCount) {
		maxCount = count;
		findmodeRes.clear();
		findmodeRes.push_back(root->val);
	}

	findmodeBST2(root->right);
	return;
}

vector<int> bintreeSolution::findMode2(TreeNode* root) {
	count = 0;
	maxCount = 0;
	findmodeRes.clear();

	findmodeBST2(root);
	return findmodeRes;
}

// 题236 二叉树的最近公共祖先
// 递归法 后序遍历左右中 回溯
TreeNode* bintreeSolution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	// 终止条件
	if (root == p || root == q || root == NULL) return root;
	// 递归遍历左右子树
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);

	// 处理中间节点
	if (left != NULL && right != NULL) return root;
	if (left == NULL && right != NULL) return right;
	else if (left != NULL && right == NULL) return left;
	else { // 左右都为NULL
		return NULL;
	}
}

// 题235 二叉搜索树的最近公共祖先
// 递归法
TreeNode* bintreeSolution::lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL) return root;
	if (root->val > p->val && root->val > q->val) {
		TreeNode* left = lowestCommonAncestor2(root->left, p, q);
		if (left) return left;
	}
	if (root->val < p->val&&root->val < q->val) {
		TreeNode* right = lowestCommonAncestor2(root->right, p, q);
		if (right) return right;
	}
	else return root;

}

// 迭代法
TreeNode* bintreeSolution::lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {
	while (root) {
		if (root->val > p->val&&root->val > q->val) {
			root = root->left;
		}
		else if (root->val < p->val&&root->val < q->val) {
			root = root->right;
		}
		else return root;
	}
	return NULL;
}

// 题701 二叉搜索树的插入操作
// 递归法 直接遍历 有返回值
TreeNode* bintreeSolution::insertIntoBST(TreeNode* root, int val) {
	// 终止条件
	if (root == NULL) {
		TreeNode* cur = new TreeNode(val);
		return cur;
	}
	// 遍历左右子树
	if (root->val > val) root->left = insertIntoBST(root->left, val);
	else if (root->val < val) root->right = insertIntoBST(root->right, val);
	return root;

}

// 迭代法
TreeNode* bintreeSolution::insertIntoBST2(TreeNode* root, int val) {
	if (root == NULL) {
		TreeNode* node = new TreeNode(val);
		return node;
	}
	TreeNode* cur = root;
	TreeNode* parent = root;
	while (cur) {
		parent = cur;
		if (cur->val > val) cur = cur->left;
		else if (cur->val < val) cur = cur->right;
		
	}
	TreeNode* node = new TreeNode(val);
	if (parent->val > val) parent->left = node;
	else if (parent->val < val) parent->right = node;
	return root;
}


// 题450 删除二叉搜索树中的节点
// 递归法
TreeNode* bintreeSolution::deleteNode(TreeNode* root, int key) {
	// 终止
	if (root == NULL) return NULL; // 情况一：不存在等于key的节点
	if (root->val == key) { //找到要删除的节点
		// 情况二：key节点为叶子节点
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		// 情况三：key节点的左孩子为空
		else if (root->left == NULL) {
			TreeNode* tmp = root->right;
			//root = root->right;
			delete root; //释放内存
			return tmp;
		}
		// 情况四： key节点的右孩子为空
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			//root = root->left;
			delete root;
			return tmp;
		}
		// 情况五：左右孩子都不为空
		else {
			// 将root的左子树放到右子树的最左节点的左孩子位置（二叉搜索树的特性）
			TreeNode* cur = root->right;
			while (cur->left) { //找到右子树的最左节点
				cur = cur->left;
			}
			cur->left = root->left;
			TreeNode* tmp = root;
			root = root->right;
			delete tmp;
			return root;		
		}
	}
	// 遍历左右子树
	if (root->val > key) root->left = deleteNode(root->left, key);
	if (root->val < key) root->right = deleteNode(root->right, key);
	return root;

}

// 题669 修剪二叉搜索树
// 递归法
TreeNode* bintreeSolution::trimBST(TreeNode* root, int low, int high) {
	// 终止条件
	if (root == NULL) return NULL;
	// 小于low,则递归右子树 返回右子树根节点，相当于将root替换成root的右子树
	if (root->val < low) {
		TreeNode* right = trimBST(root->right, low, high);
		return right;
	}
	// 大于high，则递归左子树
	if (root->val > high) {
		TreeNode* left = trimBST(root->left, low, high);
		return left;
	}
	// 遍历左右子树
	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);
	return root;
}

// 迭代法
TreeNode* bintreeSolution::trimBST2(TreeNode* root, int low, int high) {
	if (!root) return NULL;

	// 将root移动到[low,high]之间，然后在修剪左右区间外的节点
	while (root && (root->val<low||root->val>high)) {
		if (root->val < low) root = root->right;
		else root = root->left;
	}
	TreeNode* cur = root;
	// 向左处理左孩子小于low的情况
	while (cur) {
		while (cur->left && cur->left->val < low) {
			cur->left = cur->left->right;
		}
		cur = cur->left;
	}
	cur = root;
	while (cur) {
		while (cur->right && cur->right->val > high) {
			cur->right = cur->right->left;
		}
		cur = cur->right;
	
	}
	return root;
}

//题108 将有序数组转换成二叉搜索树
// 递归法
TreeNode* bintreeSolution::sortBSTtraversal(vector<int>& nums, int left, int right) {
	// 终止
	if (left > right) return NULL;

	int mid = left + ((right - left) / 2);
	TreeNode* root = new TreeNode(nums[mid]);
	// TreeNode rot(nums[mid]); 定义对象而不是指针

	root->left = sortBSTtraversal(nums, left, mid - 1);
	root->right = sortBSTtraversal(nums, mid + 1, right);
	return root;

}

TreeNode* bintreeSolution::sortedArrayToBST(vector<int>& nums) {
	TreeNode* root = NULL;
	root = sortBSTtraversal(nums, 0, nums.size() - 1);
	return root;
}

// 题538 把二叉搜索树转换成累加树
// 递归法
TreeNode* bintreeSolution::convertBST(TreeNode* root) {
	// 终止
	if (root == NULL) return NULL;

	// 右中左遍历
	convertBST(root->right);

	root->val += convertPre;
	convertPre = root->val;

	convertBST(root->left);
	return root;

}

// 迭代法
TreeNode* bintreeSolution::convertBST2(TreeNode* root) {
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur != NULL || !st.empty()) {
		if (cur != NULL) {
			st.push(cur); 
			cur = cur->right; //遍历右子树
		}
		else {
			//处理中间节点
			cur = st.top();
			st.pop();
			cur->val += convertBSTPre;
			convertBSTPre = cur->val;
			cur = cur->left; // 遍历左子树
		}
	}
	return root;
}


