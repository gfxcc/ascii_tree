//
// Created by Yong Cao at Dec/26/2017
//

#include "ascii_tree.h"
#include <string>
#include <vector>

using namespace std;
//using namespace AsciiTree;

class BTNode {
public:
	BTNode(string data) : data(data) {
		left = right = nullptr;
	}
	BTNode* left, * right;
	string data;
};

class TNode {
public:
	TNode(string data) : data(data) {

	}

	vector<TNode*> children;
	string data;
};


class Tree {
public:
	void build_binary_tree(const vector<int>& nums) {
		btroot = new BTNode(to_string(nums[0]));
		for (int i = 1; i < nums.size(); i++)
			push(nums[i]);
	}

	// build tree from binary tree.
	void build_tree() {
		troot = new TNode(btroot->data);
		build_tree(btroot, troot);
	}

	// root of binary tree
	BTNode* btroot;
	// root of tree (with children)
	TNode* troot;

private:
	void push(int num) {
		BTNode* cur = btroot;
		while (cur) {
			if (num < stoi(cur->data)) {
				if (cur->left)
					cur = cur->left;
				else {
					cur->left = new BTNode(to_string(num));
					return;
				}
			} else {
				if (cur->right)
					cur = cur->right;
				else {
					cur->right = new BTNode(to_string(num));
					return;
				}
			}
		}
	}

	void build_tree(BTNode* btnode, TNode* tnode) {
		if (btnode->right) {
			tnode->children.push_back(new TNode(btnode->right->data));
			build_tree(btnode->right, tnode->children.back());
		}
		if (btnode->left) {
			tnode->children.push_back(new TNode(btnode->left->data));
			build_tree(btnode->left, tnode->children.back());
		}

	}
};

int main() {

    Tree tree;

    tree.build_binary_tree({5,2,6,1,9,2,5});
    tree.build_tree();

    AsciiTree::Tree atree;
    atree.load_binary_tree(tree.btroot);
    atree.print_tree();

    atree.load_tree(tree.troot);
    atree.print_tree();


    
    return 0;
}
