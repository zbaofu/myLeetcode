#include "binarytree.h"

/**************
��������creatBintree(int *a, int n, int start) {
���룺���� ���鳤�� ���ڵ�����
��������������ڵ�
���������õݹ齫��������ת������ʽ�������ṹ��Ĭ������˳��ʹ�ò�α������������սڵ�ΪNULL
***************/
TreeNode* creatBintree(int *a, int n, int start) {
	if (a[start]==NULL) return NULL;

	TreeNode* root = new TreeNode(0);
	root->val = a[start];
	root->left = NULL;
	root->right = NULL;

	
	int leftnode = 2 * start + 1;
	int rightnode = 2 * start + 2;
	

	// ��ǰһ���ڵ�Ϊ��ʱ���ӽڵ�λ����������
	if (start > 1 && a[start - 1] == NULL) {
		 leftnode -= 2;
		 rightnode -= 2;
	}
	// �����������ڵ�Ϊ��ʱ�����ӽڵ�λ������������
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
 
// ���غ�nextָ��Ķ�����
nextNode* creatBintree1(int *a, int n, int start) {
	if (a[start] == NULL) return NULL;

	nextNode* root = new nextNode(0);
	root->val = a[start];
	root->left = NULL;
	root->right = NULL;


	int leftnode = 2 * start + 1;
	int rightnode = 2 * start + 2;

	// ��ǰһ���ڵ�Ϊ��ʱ���ӽڵ�λ����������
	if (start > 1 && a[start - 1] == NULL) {
		leftnode -= 2;
		rightnode -= 2;
	}
	// �����������ڵ�Ϊ��ʱ�����ӽڵ�λ������������
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
��������bintreeDisplay(nextNode* node) 
���룺Ҫ��ʾ�Ķ�����
���أ���
������������nextָ��Ķ�������ʾ�ڿ���̨
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
��������preorderTradiaplay(TreeNode* root) 
���룺Ҫ��ʾ�Ķ�����
���أ���
����������������ǰ�������ʾ�ڿ���̨,�ݹ鷨
**************/
void preorderTradiaplay(TreeNode* root) {
	if (root == NULL) return;
	cout << root->val << " ";
	preorderTradiaplay(root->left);
	preorderTradiaplay(root->right);


}


// ��144 ��������ǰ����� �ݹ鷨
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


//������ǰ����� ������
vector<int> bintreeSolution::preorderTraversal2(TreeNode* root) {
	stack<TreeNode*> st; //����ջ������ڵ�
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

//������ǰ����� ͳһ������
vector<int> bintreeSolution::preorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // �������������
			// �����У��սڵ㣩˳����ջ
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
			st.push(node);
			st.push(NULL); //�нڵ���ջ�����սڵ���Ϊ��ǣ����ں�����
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


// ��145 �������ĺ������
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

//������������� ������ ǰ������������ң���������������У�
//����ǰ������Ĵ���õ��������ٽ����鷴ת�ɵ�
vector<int> bintreeSolution::postorderTraversal2(TreeNode* root) {
	stack<TreeNode*> st; //����ջ������ڵ�
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

// �������ĺ������ ͳһ������
vector<int> bintreeSolution::postorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // �������������
			// �� ���սڵ㣩 ����˳����ջ
			st.push(node);
			st.push(NULL); //�нڵ���ջ�����սڵ���Ϊ��ǣ����ں�����
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


// ��94 ���������������
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

// ��������������� ������
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

// ��������������� ͳһ������
vector<int> bintreeSolution::inorderTraversal3(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> st;
	if (root != NULL) st.push(root);
	while (!st.empty()) {
		TreeNode* node = st.top();
		if (node != NULL) {
			st.pop(); // �������������
			// ���� ���սڵ㣩 ��˳����ջ
			if (node->right) st.push(node->right);
			st.push(node);
			st.push(NULL); //�нڵ���ջ�����սڵ���Ϊ��ǣ����ں�����
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


// ��102 �������Ĳ������ ����ʵ��
vector<vector<int>> bintreeSolution::levelOrder(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res; 
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //�洢ÿһ��Ľڵ�
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

// �������Ĳ������ �ݹ鷨
void bintreeSolution::order(TreeNode* cur, vector<vector<int>>& res, int depth) {
	if (cur == NULL) return;
	if (res.size() == depth) res.push_back(vector<int>()); // ��ά�����������
	res[depth].push_back(cur->val); // һ������Ԫ��ֵ
	order(cur->left, res, depth + 1); // ���벢��depth++������δ�ı�depth��ֵ
	order(cur->right, res, depth + 1);
}

vector<vector<int>> bintreeSolution::levelOrder2(TreeNode* root) {
	vector<vector<int>> res;
	int depth = 0;      
	order(root,res,depth);
	return res;
}

// ��107 �������Ĳ������II
vector<vector<int>> bintreeSolution::levelOrderBottom(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //�洢ÿһ��Ľڵ�
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


// ��199 ������������ͼ
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


// ��637 �������Ĳ�ƽ��ֵ
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


// ��429 N�����Ĳ������
vector<vector<int>> bintreeSolution::levelOrder3(Node* root) {
	queue<Node*> que;
	if (root != NULL) que.push(root);
	vector<vector<int>> res;
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec; //�洢ÿһ��Ľڵ�
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

// ��515 ��ÿ�����������ֵ
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

// ��116 ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
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

// ��104.��������������
// ������
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

// �ݹ鷨
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

// ��559 N������������
// �ݹ鷨
int bintreeSolution::maxNdepth(Node* root) {
	if (root == NULL) return 0;
	int depth = 0;
	for (int i = 0; i < root->children.size(); i++) {
		depth = max(depth, maxNdepth(root->children[i]));
	
	}
	return depth + 1;
}
// ������
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

// ��111 ����������С���
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


// ��226 ��ת������ �ݹ鷨
TreeNode* bintreeSolution::invertTree(TreeNode* root) {
	if (root == NULL) return root;
	swap(root->left,root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}


// ��101 �Գƶ����� �ݹ鷨
bool bintreeSolution::compare(TreeNode* left, TreeNode* right) {
	// �ų��սڵ�����
	if (left == NULL && right != NULL) return false;
	else if (left != NULL && right == NULL) return false;
	else if (left == NULL && right == NULL) return true;
	// �ų���ֵ�����
	else if (left->val != right->val) return false;

	// ��ֵ����Ҳ�Ϊ�����������ݹ�
	bool outside = compare(left->left, right->right);
	bool inside = compare(left->right, right->left);
	bool isSame = outside && inside;
	return isSame;
}

bool bintreeSolution::isSymmetric(TreeNode* root) {
	if (root == NULL) return true;
	return compare(root->left, root->right);
}

// �Գƶ����� ������ ����
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

// ��100 ��ͬ����
bool bintreeSolution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q != NULL) return false;
	else if (p != NULL && q == NULL) return false;
	else if (p == NULL && q == NULL) return true;
	else if (p->val != q->val) return false;
	
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// ��572 ��һ����������
/*
���������������
���������
�����������������
�����hi����������
*/
bool bintreeSolution::isSubtree(TreeNode* root, TreeNode* subRoot) {
	if (root == NULL && subRoot == NULL) return true;
	else if (root == NULL && subRoot != NULL) return false;
	//else if (root->val != subRoot->val) return false;

	return isSameTree(root, subRoot)
		|| isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
}

// ��222 ��ȫ�������Ľڵ����
//��Ϊ��ͨ������ �ݹ鷨
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

//��Ϊ��ͨ������ ������
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

//��Ϊ��ȫ������ �ݹ鷨
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

// ��110 ƽ�������
// �ݹ鷨
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

// ��257 ������������·��
// �ݹ鷨
void bintreeSolution::pathtraversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
	path.push_back(cur->val);
	// ���Ӻ��Һ��Ӷ��ǿ�
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


// ��404 ��Ҷ��֮��
// �ݹ鷨
int bintreeSolution::sumOfLeftLeaves1(TreeNode* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 0;

	// ����������Ҷ��
	int leftValue = sumOfLeftLeaves1(root->left);
	// �ж���Ҷ��
	if (root->left && !root->left->left && !root->left->right){
		leftValue = root->left->val;
	}
	int rightValue = sumOfLeftLeaves1(root->right);

	int sum = leftValue + rightValue;
	return sum;
}

// ��513 �������½ǵ�ֵ
// �ݹ鷨
void bintreeSolution::findBottomtraversal(TreeNode* root, int depth) {
	// �ж�Ҷ�ӽڵ�
	if (root->left == NULL && root->right == NULL) {
		// ����������
		if (depth > blmaxDepth) {
			blmaxDepth = depth;
			bottomleftresult = root->val;
		}
		return;
	}
	if (root->left) {
		depth++;
		findBottomtraversal(root->left, depth);
		depth--; //����
	}
	if (root->right) {
		depth++;
		findBottomtraversal(root->right, depth);
		depth--; //����
	
	}
	return;
}
int bintreeSolution::findBottomLeftValue1(TreeNode* root) {
	findBottomtraversal(root, 0);
	return bottomleftresult;
}

// ������ �������
int bintreeSolution::findBottomLeftValue2(TreeNode* root) {
	queue<TreeNode*> que;
	if (root != NULL) que.push(root);
	int result = 0;
	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* node = que.front();
			que.pop();
			if (i == 0) result = node->val; //��һ��Ԫ��ֵ
			if (node->left) que.push(node->left);
			if (node->right) que.push(node->right);
		
		}
	}
	return result;
}

// ��112 ·��֮��I
// �ݹ鷨
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

// ������ ʹ��ջģ��ǰ�����
bool bintreeSolution::hasPathSum2(TreeNode* root, int targetSum) {
	if (root == NULL) return false;
	stack<pair<TreeNode*, int>> st;
	st.push(pair<TreeNode*, int>(root, root->val));
	while (!st.empty()) {
		pair<TreeNode*, int> node = st.top();
		st.pop();
		if (!node.first->left && !node.first->right && targetSum == node.second) return true;
		// �ҽڵ�
		if (node.first->right) {
			st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
		}
		// ��ڵ�
		if (node.first->left) {
			st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
		}	
	}
	return false;
}

// ��113 ·��֮��II
//�ݹ鷨
void bintreeSolution::hpIItraversal(TreeNode* cur, int count) {
	// �ҵ�һ��·��
	if (!cur->left && !cur->right && count == 0) {
		hpIIres.push_back(hpIIpath);
		return;
	}
	// ��Ҷ�ӽڵ㵫�Ͳ�Ϊtarget
	if (!cur->left && !cur->right) {
		return;
	}

	if (cur->left) {
		hpIIpath.push_back(cur->left->val);
		count -= cur->left->val;
		hpIItraversal(cur->left, count);
		count += cur->left->val; //����
		hpIIpath.pop_back();
	}

	if (cur->right) {
		hpIIpath.push_back(cur->right->val);
		count -= cur->right->val;
		hpIItraversal(cur->right, count);
		count += cur->right->val; //����
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

// ��106 �����������������������
// �ݹ鷨
TreeNode* bintreeSolution::btTraversal(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0) return NULL;

	//��������������һ��Ԫ��Ϊ�м�ڵ�
	int rootValue = postorder[postorder.size() - 1];
	TreeNode* root = new TreeNode(rootValue);

	// Ҷ�ӽڵ�
	if (postorder.size() == 1) return root;

	// �ҵ�����ڵ���и��
	int delimiterIndex;
	for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
		if (inorder[delimiterIndex] == rootValue) break;
	}
	// �и���������
	// ����ҿ���[ )
	vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
	vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

	// ������������ĩβԪ��
	postorder.resize(postorder.size() - 1);

	// �и��������
	// ����ҿ� ʹ����������Ĵ�С��Ϊ�и��
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


// ��105 ��������ǰ��������������
// �ݹ鷨 ���±������и�����
TreeNode* bintreeSolution::bt2Traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
	if (preorderBegin == preorderEnd) return NULL;

	int rootValue = preorder[preorderBegin]; // ���ڵ�Ϊǰ����������һ��Ԫ��
	TreeNode* root = new TreeNode(rootValue);

	if (preorderEnd - preorderBegin == 1) return root;


	int delimiterIndex;
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
		if (inorder[delimiterIndex] == rootValue) break;
	}

	// �и���������
	// ���������䣬����ҿ�
	int leftInorderBegin = inorderBegin;
	int leftInorderEnd = delimiterIndex;
	// ���������䣬����ҿ�
	int rightInorderBegin = delimiterIndex + 1;
	int rightInorderEnd = inorderEnd;

	// �и�ǰ������
	// ǰ�������� ����ҿ�
	int leftPreorderBegin = preorderBegin + 1;
	int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
	// ǰ�������䣬����ҿ�
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

// ��654 ��������
// �ݹ�1 ������ָ������սڵ����ݹ�
TreeNode* bintreeSolution::constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode* node = new TreeNode(0);
	// ��Ҷ�ӽڵ�
	if (nums.size() == 1) {
		node->val = nums[0];
		return node;
	}

	//�ҵ������е����ֵ�Ͷ�Ӧ�±�
	int maxValue = 0;
	int maxValueIndex = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > maxValue) {
			maxValue = nums[i];
			maxValueIndex = i;
		}
	}
	// ���ֵΪ���ڵ�
	node->val = maxValue;
	// ���ֵ�±�������� ����������
	// �ж������䲻�ǿ�
	if (maxValueIndex > 0) {
		vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
		node->left = constructMaximumBinaryTree(newVec);
	}
	// ���ֵ�±�������� ����������
	// �ж������䲻�ǿ�
	if (maxValueIndex < (nums.size()-1)) {
		vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
		node->right = constructMaximumBinaryTree(newVec);
	}
	return node;
}


// �ݹ�� ���±�����ֱ�ӷָ����飬����սڵ����ݹ�
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

// ��617 �ϲ�������
// ǰ����� �ݹ� �����µĽڵ�
TreeNode* bintreeSolution::mergeTrees(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL) return root2;
	if (root2 == NULL) return root1;

	TreeNode* root = new TreeNode(0);
	root->val = root1->val + root2->val;

	root->left = mergeTrees(root1->left, root2->left);
	root->right = mergeTrees(root1->right, root2->right);
	return root;
}