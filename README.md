# ascii_tree
Printing Pretty Ascii Trees


## Motivation

To create a C++ library used to print tree in ascii character.

## Sample output

```
(E)
 `--(E+T)
     `--(E)
     |   `--(E+T)
     |       `--(E)
     |       |   `--(E+T)
     |       |       `--(E)
     |       |       |   `--(T)
     |       |       |       `--[a]
     |       |       `--[+]
     |       |       `--(T)
     |       |           `--(T*a)
     |       |               `--(T)
     |       |               |   `--(T*a)
     |       |               |       `--(T)
     |       |               |       |   `--[a]
     |       |               |       `--[*]
     |       |               |       `--[a]
     |       |               `--[*]
     |       |               `--[a]
     |       `--[+]
     |       `--(T)
     |           `--[a]
     `--[+]
     `--(T)
         `--[a]
``` 


## Usage

Please find sample project [here](https://github.com/gfxcc/algorithms/tree/master/parser/unger)

```cpp
// Binary Tree Node need contains left, right, data
class BTNode {
public:
	BTNode(string data) : data(data) {
		left = right = nullptr;
	}
	BTNode* left, * right;
	string data;
};

// Tree Node need contains vector<Node*> children, data;
class TNode {
public:
	TNode(string data) : data(data) {

	}

	vector<TNode*> children;
	string data;
};

// 1. include head file
#include "ascii_tree.h"

int main() {

	...
	...

	AsciiTree::Tree atree;
    atree.load_binary_tree(root_of_binary_tree);
    atree.print_tree();

    atree.load_binary_tree(root_of_tree);
    atree.print_tree();

  }
```