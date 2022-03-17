#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
} *root=NULL, *nn;

struct node * create(int);
struct node * insert_data();
void levelOrder(node *);
int heightOfTree (node *);
void nodeAtDistanceK(node *, int);
//from root node

int main()
{
    int op;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary tree\n 2. Level order Traversal\n 3. Node at K Distance from Root Node\n";
        cin>>op;
        switch(op)
        {
            case 0: exit(0);break;
            case 1: system("cls");insert_data();break;
            case 2: system("cls");
                    {
                        cout<<"Level order Traversal"<<"\n";
                        levelOrder(root);
                    }
                    break;
            case 3: system("cls");
                    {
                        int k;
                        cout<<"Enter Distance where you would like to print the nodes:\n";
                        cin>>k;
                        nodeAtDistanceK(root,k);
                    }
                    break;
        }
    }while(op!=4);
    return 0;
}

struct node * create(int val){
    nn=new node();
    if(!nn)
    {
        cout << "Memory error\n";
        return NULL;
    }
    nn->data=val;
    nn->l = nn->r = NULL;
    return nn;
};

struct node * insert_data()
{
    int val;
    cout<<"Value to be entered\n";
    cin>>val;
    if(root==NULL)
    {
        root=create(val);
        return root;
    }
    queue< node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(temp->l!=NULL)
            q.push(temp->l);
        else
        {
            temp->l=create(val);
            return root;
        }

        if(temp->r!=NULL)
            q.push(temp->r);
        else
        {
            temp->r=create(val);
            return root;
        }
    }
    return 0;
};

void levelOrder(node * root)
{
    if(root== NULL)
    {
        cout<<"Empty Tree\n";
        return;
    }
    queue< node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->l!=NULL)
            q.push(temp->l);

        if(temp->r!=NULL)
            q.push(temp->r);

    }
}

int heightOfTree (node * root)
{
    if(!root){
        return 0;
    }
    int lh=heightOfTree(root->l);
    int rh=heightOfTree(root->r);

    if(lh>rh)
        return lh+1;
    return rh+1;
}

void nodeAtDistanceK(node *root, int k)
{
    if(!root)
        return;

    if(k>heightOfTree(root))
    {
        cout<<"Distance exceeds the height of tree\n";
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    if(root->l)
        nodeAtDistanceK(root->l,k-1);

    if(root->r)
        nodeAtDistanceK(root->r,k-1);

}
