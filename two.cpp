#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted is lesser, insert in left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert in right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

Node* BST_to_DLL(Node* root,Node* &prev)
{
	if(root==NULL)
	return root;
	Node* head=BST_to_DLL(root->left,prev);
	if(prev==NULL)
	head=root;
	else
	{
	root->left=prev;
	prev->right=root;
	}
	prev=root;
	BST_to_DLL(root->right,prev);
	return head;
}


void print_list(Node* root)
{
	Node* prev=NULL;
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		prev=root;
		root=root->right;
	}
	cout<<endl;
	while(prev!=NULL)
	{
		cout<<prev->data<<" ";
		prev=prev->left;
	}
	cout<<endl;
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	Node* prev = NULL;
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);
	
	Node *head=BST_to_DLL(root,prev);
	print_list(head);


}
