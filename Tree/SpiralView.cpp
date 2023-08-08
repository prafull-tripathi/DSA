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

void sipralOrder(Node* root)
{
	if(!root)
        return;

    queue<Node *>q;
    stack<Node *>st;
    int left_to_right=true;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            Node *temp=q.front();
            q.pop();

            if(left_to_right)
                cout<<temp->data<<" ";
            else
                st.push(temp);

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);

        }
        if(!left_to_right)
        {
            while(!st.empty())
            {
                Node* x=st.top();
                st.pop();
                cout<<x->data<<" ";
            }
        }
        left_to_right=!left_to_right;
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

    sipralOrder(root);

}