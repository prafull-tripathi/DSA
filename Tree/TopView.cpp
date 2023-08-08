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

void topView(Node *root)
{
    if(!root)
        return;
    
    map<int,int>m;
    queue<pair<Node*, int>>q;
    //vector<int>v;

    q.push({root,0});
    while(!q.empty())
    {
        Node *temp=q.front().first;
        int h=q.front().second;
        q.pop();

        if(!m[h])
            m[h]=temp->data;

        if(temp->left)
            q.push({temp->left,h-1});
        
        if(temp->right)
            q.push({temp->right, h+1});

    }

    for(auto x:m)
        cout<<x.second<<" ";

}

void bottomView(Node *root) {
        // Your Code Here
        
        map<int,int>m;
        vector<int>v;
        if(!root)
            return v;
            
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            Node *temp=q.front().first;
            int h=q.front().second;
            q.pop();
            m[h]=temp->data;
    
            if(temp->left)
                q.push({temp->left,h-1});

            if(temp->right)
                q.push({temp->right,h+1});
        
        }

    for(auto x:m)
        cout<<x.second<<" ";
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

    topView(root);
    bottomView(root);
}