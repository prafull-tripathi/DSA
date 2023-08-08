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


int max_left_level_visited=0;
int max_right_level_visited=0;


void leftView(Node* root, int curr_level)
{
	if(root)
	{
		if(max_left_level_visited<curr_level)
		{
			cout<<root->data<<" ";
			max_left_level_visited=curr_level;
		}

		leftView(root->left,curr_level+1);
		leftView(root->right,curr_level+1);
	}
}

void rightView(Node* root, int curr_level)
{
	if(root)
	{
		if(max_right_level_visited<curr_level)
		{
			cout<<root->data<<" ";
			max_right_level_visited=curr_level;
		}

		rightView(root->right,curr_level+1);
		rightView(root->left,curr_level+1);
		
	}
}

void leftViewItr(Node *root)
{
	if(!root)
		return;

	queue<Node*>q;
	q.push(root);

	while(!q.empty())
	{
		int n=q.size();

		while(n--)
		{
			Node* x = q.front();
            q.pop();

			if(n==0)
				cout<<x->data<<" ";

			if(x->right)
				q.push(x->right);

			if(x->left)
				q.push(x->left);

		}
	}
}


void rightViewItr(Node *root)
{
	if(!root)
		return;

	queue<Node*>q;
	q.push(root);

	while(!q.empty())
	{
		int n=q.size();

		while(n--)
		{
			Node* x = q.front();
            q.pop();

			if(n==0)
				cout<<x->data<<" ";

			if(x->left)
				q.push(x->left);

			if(x->right)
				q.push(x->right);

		}
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

    leftView(root,1);
	cout<<"\n";
	rightView(root,1);
	cout<<"\n";
	leftViewItr(root);
	cout<<"\n";
	rightViewItr(root);

}