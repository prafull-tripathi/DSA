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

int height(Node *root)
{
    if(root)
		return max(height(root->left),height(root->right))+1;
	return 0;
}

int diameter(Node* root)
{
	
	if(!root)
        return 0;

    int p_dia=1+height(root->left)+height(root->right);
	int lc_dia=diameter(root->left);
	int rc_dia=diameter(root->right);
	return max(p_dia,max(lc_dia,rc_dia));

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

    cout<<"Diameter is: "<<diameter(root);

}