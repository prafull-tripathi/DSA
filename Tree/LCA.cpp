//! LCA using efficient method
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
}*root=NULL, *nn;

int findSize(Node* root)
{
	
	if(root)
    {
        return (1+findSize(root->left)+findSize(root->right));
    }
    return 0;
}

Node *getLCA(Node *root, int val1, int val2)
{
	if(!root)
		return NULL;

	if(root->data==val1 || root->data==val2)
		return root;

	Node *lca_left=getLCA(root->left,val1,val2);
	Node *lca_right=getLCA(root->right,val1,val2);

	if(lca_left && lca_right)
		return root;

	return (lca_left)?lca_left:lca_right;

}

int main() {
	
	Node *root=new Node(70);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(75);
	root->left->right=new Node(10);
	root->left->left->left=new Node(60);
	root->left->left->right=new Node(40);
	root->left->left->left->left=new Node(90);
	root->left->left->right->right=new Node(110);
	root->left->right->right=new Node(80);
	root->left->right->right->right=new Node(100);

	Node *ans=getLCA(root,90,110);
    cout<<"Lca is: "<<ans->data;

}