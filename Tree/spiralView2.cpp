//! spiral View using 2 stacks

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

void spiralView(Node *root)
{
    if(!root)
        return;

    stack<Node *>st1,st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty())
    {
        while(!st1.empty())
        {
            Node *temp=st1.top();
            st1.pop();
            cout<<temp->data<<" ";

            if(temp->left)
                st2.push(temp->left);

            if(temp->right)
                st2.push(temp->right);
        }
        cout<<"\n";
        while(!st2.empty())
        {
            Node *temp=st2.top();
            st2.pop();
            cout<<temp->data<<" ";

            

            if(temp->right)
                st1.push(temp->right);

            if(temp->left)
                st1.push(temp->left);
        }
        cout<<"\n";
    }
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

    spiralView(root);

}