#pragma once
#include "Node.h"
#include <iostream>

class BTree{
public:
	Node* root;

	BTree() {
		root = nullptr;
	}

	void insert(int item) {
		Node* p = new Node(item);
		if (this->root == nullptr)
			this->root = p;
		else {
			Node* parent = nullptr;
			Node* node = root;
			while (node) {
				parent = node;
				if (p->key < node->key)
					node = node->llink;
				else node = node->rlink;

			}
			if (p->key < parent->key)
				parent->llink = p;
			else parent->rlink = p;
		}
	}

	void traversal(Node* p) {
		if (p) {
			std::cout << p->key << "||";
			traversal(p->llink);
			traversal(p->rlink);
		}
	}
	
	int deleteRightLeaves(Node* p) {
		int result = 0;
		if (!p) return 0;
		if (!p->llink && !p->rlink) return 0;
		if (p->rlink) 
			if (!p->rlink->llink && !p->rlink->rlink) {
				delete[] p->rlink;
				p->rlink = nullptr;
				result++;
			}
		result += deleteRightLeaves(p->llink);
		result += deleteRightLeaves(p->rlink);
		return result;
	}

};
