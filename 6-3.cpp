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


    void pre_order(node* temp) {
        if(temp->child.size() !=0){
            cout << temp->data << " ";
            for(int i=0; i<temp->child.size(); i++) {
                pre_order(temp->child[i]);
            }
        } else {
            cout << temp->data << " ";
        }
    }



    void post_order(node* temp) {
        if(temp->child.size() !=0){
            for(int i=0; i<temp->child.size(); i++) {
                pre_order(temp->child[i]);
            }
            cout << temp->data << " ";
        } else {
            cout << temp->data << " ";
        }
    }

	

};

int main() {

	int n;
	cin >> n;

	while (n--) {

        int tree_num;
        cin >> tree_num;
        tree t;
        while(tree_num--){
            int parent_data;
            int data;

            cin >> parent_data >> data;

            t.insertNode(parent_data,data);
        }
        t.pre_order(t.root);
        cout << "\n";
        t.post_order(t.root);

	}

	return 0;
}