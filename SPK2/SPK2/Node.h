#pragma once

class Node {
public:
	int key;
	Node* llink;
	Node* rlink;

	Node(int a) {
		this->key = a;
		this->llink = nullptr;
		this->rlink = nullptr;
	}
};