class BSTIterator {
public:
	BSTIterator(TreeNode* root) : i(0) {
		this->dfs(root);
	}

	int next() {
		return seq[i++]->val;
	}

	bool hasNext() {
		return i < seq.size();
	}

	void dfs(TreeNode* root) {
		if (root == nullptr) return ;
		if (root->left) dfs(root->left);
		seq.push_back(root);
		if (root->right) dfs(root->right);
	}

private:
	int i;
	vector<TreeNode*> seq;
};

