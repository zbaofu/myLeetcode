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
