//Binary search tree
//Implementation

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode; 
}

void Insert(node*& root, int data){
	if(root == NULL){
		root = getNewNode(data);
	}
	else if(root->data <= data){
		Insert(root->left, data);
	}
	else{
		Insert(root->right, data);
	}
}

bool search(node* root, int data){
	if(root==NULL)
		return false;
	else if(root->data == data) 
		return true;
	else if(root->data < data)
		return search(root->left, data);
	else
		return search(root->right, data);
}

int main(){
	node* root = NULL;

	Insert(root, 10);
	Insert(root, 5);
	Insert(root, 20);
	Insert(root, 25);
	Insert(root, 6);

	int n;
	cout << "Enter -1 to exit.\n";

	while(true){
		cout << "Search for: ";
		cin >> n;
		if(n == -1) break;

		if(search(root, n))
			cout << "Found!\n";
		else
			cout << "Not Found :-(\n";
	}

	return 0;
}
