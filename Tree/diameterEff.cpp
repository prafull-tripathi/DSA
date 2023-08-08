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

int max_dia=0;

int height(Node* root)
{
	if(!root)
        return 0;

    int lc_dia=height(root->left);
    int rc_dia=height(root->right);

    max_dia=max(max_dia,1+lc_dia+rc_dia);

    return 1+max(lc_dia,rc_dia);

}


int main() {
	
	root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->right->left=new Node(4);
	root->right->right=new Node(5);
	
	// cout << "\nThe Inorder is : ";
	// inorder(root);
	// cout << "\nThe Postorder is : ";
	// postorder(root);
	// cout << "\nThe Preorder is : ";
	// preorder(root);

    cout<<"Diameter is: "<<height(root);

}