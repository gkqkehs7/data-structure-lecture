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

	void deleteChild(node* chi) {
		for (int i = 0; i < this->child.size(); i++) {
			if (this->child[i] == chi) {
				this->child.erase(this->child.begin() + i);
				break;
			}
		}
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
	}

	void insertNode(int parent_data, int data) {
		node* temp = findNode(parent_data);
		node* newNode = new node(data);
		newNode->parent = temp;

		temp->insertChild(newNode);
		node_list.push_back(newNode);
	}

	void printChild(int data) {
		node* temp = findNode(data);

		for (int i = 0; i < temp->child.size(); i++) {
			cout << temp->child[i]->data << " ";
		}
		cout << "\n";
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
		} else {
			int data;
			cin >> data;
			t.printChild(data);
		}
	}
}