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

	int size(Node* ptr) {
		if (ptr == nullptr) {
			return 0;
		}
		return 1 + size(ptr->_left) + size(ptr->_right);
	}



	class Set {
	private:
		Node* _head;
	public:
		Node* get_head() const {
			return _head;
		}
		int set_size() {
			return size(_head);
		}
		Node* copy_set(Node* root) {
			if (!root) {
				return nullptr;
			}

			Node* new_node = new Node(root->_key);
			new_node->_left = copy_set(root->_left);
			new_node->_right = copy_set(root->_right);

			return new_node;
		}

		void delete_nodes(Node*& root) {
			if (root == nullptr) {
				return;
			}
			delete_nodes(root->_left);
			delete_nodes(root->_right);
			delete root;
			root = nullptr;
		}

		~Set() {
			delete_nodes(_head);
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
			if (this->contains(key)) {
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
		bool contains(int key) const {
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
			Node* ptr = _head, *pre_ptr = nullptr;
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

			if (ptr->_left == nullptr && ptr->_right == nullptr) {
				if (ptr != _head) {
					if (pre_ptr->_left == ptr) {
						pre_ptr->_left = nullptr;
					}
					else {
						pre_ptr->_right = nullptr;
					}
				}
				else {
					_head = nullptr;
				}
				delete ptr;
				return true;
			}

			if (ptr->_left == nullptr) {
				if (ptr == _head) {
					_head = _head->_right;
					delete ptr;
					return true;
				}
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
				if (ptr == _head) {
					_head = _head->_left;
					delete ptr;
					return true;
				}
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

	void sub_uni(Node* ptr, Set& c) {
		if (ptr == nullptr) {
			return;
		}
		c.insert(ptr->_key);
		sub_uni(ptr->_left, c);
		sub_uni(ptr->_right, c);
	};

	void sub_simmetrical_difference(Node* ptr, const Set& b, Set& c) {
		if (ptr == nullptr) {
			return;
		}
		if (!b.contains(ptr->_key)) {
			c.insert(ptr->_key);
		}
		sub_simmetrical_difference(ptr->_left, b, c);
		sub_simmetrical_difference(ptr->_right, b, c);
	};

	Set uni(const Set& a, const Set& b) {
		Set c(b);
		sub_uni(a.get_head(), c);
		return c;
	}

	Set simmetrical_difference(const Set& a, const Set& b) {
		Set c;
		sub_simmetrical_difference(a.get_head(), b, c);
		sub_simmetrical_difference(b.get_head(), a, c);
		return c;
	}

	size_t lcg() {
		static size_t x = 0;
		x = (1021 * x + 24631) % 116640;
		return x;
	}

}