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

    cout<<"Size is: "<<findSize(root);

}