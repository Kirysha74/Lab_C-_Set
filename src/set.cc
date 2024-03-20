#pragma once
#include <iostream>

namespace set {
	struct Node {
		int _key;
		Node* _left;
		Node* _right;
		Node() : _left(nullptr), _right(nullptr) {};
		Node(int key) : _key(key), _left(nullptr), _right(nullptr) {};
	};

	class Set {
	private:
		Node* _head;
	public:
	};
}