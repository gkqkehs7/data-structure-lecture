#include <iostream>
#include <string>
#include <vector>
using namespace std;


class node {
public:
	int data;
	node* parent;
	vector<node*> child;

	node(int data) {
		this->data = data;
		this->parent = NULL;
	}


	void insertChild(node* chi) {
		this->child.push_back(chi);
		return;
	}
};

class tree {
public:
	node* root;
	vector<node*> node_list;

	tree() {
		root = new node(1);
		node_list.push_back(root);
	}

	node* findNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) {
				return node_list[i];
			}
		}

		return NULL;
	}

	void insertNode(int parent_data, int data) {
		node* temp = findNode(parent_data);

		if (temp == NULL) {
			cout << -1 << "\n";
		}
		else {
			node* newNode = new node(data);
			newNode->parent = temp;

			temp->insertChild(newNode);
			node_list.push_back(newNode);
		}
	}

	void printChild(int data) {
		node* temp = findNode(data);

		if (temp == NULL) {
			cout << -1;
		}
		else if (temp->child.size() == 0) {
			cout << 0;
		}
		else {
			for (int i = 0; i < temp->child.size(); i++) {
				cout << temp->child[i]->data << " ";
			}
		}
		cout << "\n";
	}


	int getDepth(node* temp) {
		if (temp == NULL) {
			return -1;
		}
		else {
			int depth = 0;

			while (temp->parent != NULL) {
				temp = temp->parent;
				depth++;
			}

			return depth;
		}
	}

};

int main() {
	tree t;

	int n;
	cin >> n;

	while (n--) {
		string command;
		cin >> command;

		if (command == "insert") {
			int parent_data;
			int data;

			cin >> parent_data >> data;
			t.insertNode(parent_data, data);
		}
		else if (command == "printDepth") {
			int data;
			cin >> data;
			node* temp = t.findNode(data);
			cout << t.getDepth(temp) << "\n";
		}
		else {
			int data;
			cin >> data;
			t.printChild(data);
		}
	}

	return 0;
}