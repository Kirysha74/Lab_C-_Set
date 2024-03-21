#pragma once
#include <iostream>

using namespace std;

namespace set {
	struct Node {
		int _key;
		Node* _left;
		Node* _right;
		Node() : _left(nullptr), _right(nullptr) {};
		Node(int key) : _key(key), _left(nullptr), _right(nullptr) {};
	};

	void print(Node* ptr) {
		if (ptr) {
			print(ptr->_left);
			cout << ptr->_key << " ";
			print(ptr->_right);
		}
	}

	class Set {
	private:
		Node* _head;
	public:
		Node* copy_set(Node* root) {
			if (!root) {
				return nullptr;
			}

			Node* new_node = new Node(root->_key);
			new_node->_left = copy_set(root->_left);
			new_node->_right = copy_set(root->_right);

			return new_node;
		}

		Set() : _head(nullptr) {};
		Set(const Set& other) {
			_head = copy_set(other._head);
		}

		void print_set() const {
			print(_head);
		}
		bool insert(int key) {
			if (!_head) {
				_head = new Node(key);
				return true;
			}
			Node* ptr = _head;
			while (ptr) {
				if (key < ptr->_key && ptr->_left == nullptr) {
					ptr->_left = new Node(key);
					return true;
				}
				if (key > ptr->_key && ptr->_right == nullptr) {
					ptr->_right = new Node(key);
					return true;
				}
				if (key < ptr->_key) {
					ptr = ptr->_left;
				}
				else {
					ptr = ptr->_right;
				}
			}
		}
		bool contains(int key) {
			Node* ptr = _head;
			while (ptr && ptr->_key != key) {
				if (ptr && ptr->_key != key) {
					if (key < ptr->_key) {
						ptr = ptr->_left;
					}
					else {
						ptr = ptr->_right;
					}
				}
			}
			return ptr != nullptr;
		}
		bool erase(int key) {
			Node* ptr = _head, *pre_ptr;
			while (ptr && ptr->_key != key) {
				pre_ptr = ptr;
				if (ptr && ptr->_key != key) {
					if (key < ptr->_key) {
						ptr = ptr->_left;
					}
					else {
						ptr = ptr->_right;
					}
				}
			}

			if (ptr == nullptr) { return false; }

			if (ptr->_left == nullptr) {
				if (pre_ptr->_left == ptr) {
					pre_ptr->_left = ptr->_right;
				}
				if (pre_ptr->_right == ptr) {
					pre_ptr->_right = ptr->_right;
				}
				delete ptr;
				return true;
			}

			if (ptr->_right == nullptr) {
				if (pre_ptr->_left == ptr) {
					pre_ptr->_left = ptr->_left;
				}
				if (pre_ptr->_right == ptr) {
					pre_ptr->_right = ptr->_left;
				}
				delete ptr;
				return true;
			}

			Node* ptr1 = ptr->_right;
			while (ptr1->_left) {
				ptr1 = ptr1->_left;
			}
			ptr->_key = ptr1->_key;
			delete ptr1;
		}
	};
}