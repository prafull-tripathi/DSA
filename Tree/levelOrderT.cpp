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

void printLevelOrder(Node *root)
{
    if (root == NULL)  return;
        
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }

}
/*
    ? 1
    ? 2 3
    ? 4 5 6
*/
void levelOrderTraversal(Node *root)
{
    if(!root){
        cout<<"Empty Tree\n";
        return;
    }
    queue<Node *>q;
    q.push(root);
    vector<Node *>v;

    while(!q.empty())
    {
        Node *temp=q.front();
        v.push_back(temp);
        q.pop();

        if(temp!=NULL)
        {
            if((!temp->left) && (!temp->right))
                return;

            if(temp->left)
                q.push(temp->left);
        
            if(temp->right)
                q.push(temp->right);

        }
        else
        {
            for(auto i:v)
                cout<<i->data<<" ";
            v.clear();
            q.push(NULL);
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

    levelOrderTraversal(root);

}