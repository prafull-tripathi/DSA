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
void leftView(node *, int, int * );
void rightView(node *, int, int * );
void view(node *, int);
void topView(node *);
void bottomView(node *);

int main()
{
    int op;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary tree\n 2. Level order Traversal\n 3. Left View\n";
        cout<<" 4. Right View\n 5. Top View of Tree\n 6. Bottom View of Tree\n";
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
                        cout<<"Left View of Tree is:\n";
                        view(root,op);
                    }
                    break;
            case 4:system("cls");
                    {
                        cout<<"Right View of Tree is:\n";
                        view(root,op);
                    }
                    break;
            case 5: system("cls");
                    {
                        cout<<"Top View of Tree is:\n";
                        topView(root);
                    }
                    break;
            case 6: system("cls");
                    {
                        cout<<"Bottom View of Tree is:\n";
                        bottomView(root);
                    }
                    break;
            default: cout<<"Wrong option\n";break;
        }
    }while(op!=7);
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
void view(node *root, int op)
{
    int maxLevel=0;
    switch(op)
    {
        case 3: leftView(root, 1, &maxLevel);
                break;
        case 4: rightView(root, 1, &maxLevel);
                break;
        default: cout<<"Wrong Option\n";
                break;
    }
}

void leftView(node *root, int level, int *maxLevel)
{
    if(root==NULL){
        return;
    }
    if(*maxLevel<level)
    {
        cout<<root->data<<" ";
        *maxLevel=level;
    }

    leftView(root->l,level+1, maxLevel);
    leftView(root->r,level+1, maxLevel);
}

void rightView(node *root, int level, int *maxLevel)
{

    if(root== NULL){
        return;
    }
    if(*maxLevel<level)
    {
        cout<<root->data<<" ";
        *maxLevel=level;
    }

    rightView(root->r,level+1, maxLevel);
    rightView(root->l,level+1, maxLevel);

}

void topView(node *root)
{
    map<int,int>m;
    queue<pair<node*,int>>q;
    if(!root){
        return;
    }
    q.push({root,0});
    while(!q.empty())
    {
        node *temp=q.front().first;
        int h=q.front().second;
        q.pop();
        if(!m[h])
            m[h]=temp->data;

        if(temp->l)
            q.push({temp->l,h-1});
        if(temp->r)
            q.push({temp->r,h+1});
    }

    for(auto x:m)
        cout<<x.second<<" ";
}

void bottomView(node *root)
{
    map<int,int>m;
    queue<pair<node*,int>>q;
    if(!root){
        return;
    }
    q.push({root,0});
    while(!q.empty())
    {
        node *temp=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h]=temp->data;

        if(temp->l)
            q.push({temp->l,h-1});
        if(temp->r)
            q.push({temp->r,h+1});
    }

    for(auto x:m)
        cout<<x.second<<" ";
}
