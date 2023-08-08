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

int Height(Node *root)
{
    if(root)
    {
        int lh=Height(root->left);
        int rh=Height(root->right);

        if(lh>rh)
            return lh+1;
        return rh+1;

    }
    return 0;
    /*
    * in single sentance =>  return(1+ max(height(root->left),height(root->right)))
    */
}

int heightItr(Node *root)
{
    if(!root)
        return 0;
    
    
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    int count=1;

    while(!q.empty()){

        Node *temp=q.front();
        q.pop();

        if(temp!=NULL)
        {
            if((!temp->left) && (!temp->right))
                return count;
            
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
            
        }
        else
        {
            if(!q.empty())
            {
                count++;
                q.push(NULL);
            }
        }

    }
    return count;

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

    cout<<"height of tree: "<<Height(root);

}