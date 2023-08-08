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


void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);    
    }
}  

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);    
    }
}  

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right); 
        cout<<root->data<<" ";   
    }
}  

int printKdist(Node *root,int k)
{
   if(root)
   {
        if(k==0)
            cout<<root->data<<" ";

        printKdist(root->left,k-1);
        printKdist(root->right,k-1);
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

    printKdist(root,1);

}