//
// Created by Yong Cao at Dec/26/2017
//

#include "ascii_tree.h"
#include <string>

using namespace std;
//using namespace AsciiTree;

class TNode {
public:
	TNode(string data) : data(data) {
		left = right = nullptr;
	}
	TNode* left, * right;
	string data;
};

class Tree {
public:
	void build_tree(const vector<int>& nums) {
		root = new TNode(to_string(nums[0]));
		for (int i = 1; i < nums.size(); i++)
			push(nums[i]);
	}

	void push(int num) {
		TNode* cur = root;
		while (cur) {
			if (num < stoi(cur->data)) {
				if (cur->left)
					cur = cur->left;
				else {
					cur->left = new TNode(to_string(num));
					return;
				}
			} else {
				if (cur->right)
					cur = cur->right;
				else {
					cur->right = new TNode(to_string(num));
					return;
				}
			}
		}
	}

	TNode* root;
};

int main() {

    Tree tree;

    tree.build_tree({5,2,6,1,9,2,5});

    AsciiTree::Tree atree;
    atree.load_binary_tree(tree.root);
    atree.print_tree();
    
    return 0;
}
