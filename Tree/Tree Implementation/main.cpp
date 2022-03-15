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
node *deleteNode(node *, int );
void deleteDeepestRoot(node *, node *);
int height(struct node *root);
void inOrder(node* );
void preOrder(node *);
void postOrder(node *);
void levelOrder(node *);

int main()
{
    int op;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary tree\n 2. Pre-order Traversal\n 3. In-Order Traversal\n";
        cout<<" 4. Post- Order Traversal\n 5. Level Order Traversal\n 6. Delete a Node\n 7. Height of Tree\n";
        cin>>op;
        switch(op)
        {
            case 0: exit(0);break;
            case 1: system("cls");insert_data();break;
            case 2: system("cls");
                    {
                        cout<<"Pre-order Traversal"<<"\n";
                        preOrder(root);
                    }
                    break;
            case 3: system("cls");
                    {
                        cout<<"In-order Traversal"<<"\n";
                        inOrder(root);
                    }
                    break;
            case 4: system("cls");
                    {
                        cout<<"Post-order Traversal"<<"\n";
                        postOrder(root);
                    }
                    break;
            case 5: system("cls");
                    {
                        cout<<"Level-order Traversal"<<"\n";
                        levelOrder(root);
                    }
                    break;
            case 6: system("cls");
                    {
                        int val;
                        cout<<"Data You want to delete?"<<"\n";
                        cin>>val;
                        deleteNode(root,val);
                    }
                    break;
            case 7: system("cls");
                    {
                        cout<<"Height is: "<< height(root) <<endl;
                        break;
                    }
            default: cout<<"Wrong option\n";break;
        }
    }while(op!=8);
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

node *deleteNode(node * root, int key)
{
    if(root==NULL)
    {
        cout<<"Empty Tree\n";
        return NULL;
    }
    if(root->l==NULL && root->r==NULL)
    {
        if(root->data==key)
        {
            delete(root);
            return NULL;
        }

        else{
            cout<<key<<" is not found\n";
            return root;
        }

    }

    node* key_node=NULL;
    node* temp;
    node* last;
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==key)
            key_node=temp;
        if(temp->l)
        {
            last=temp;
            q.push(temp->l);
        }
        if(temp->r)
        {
            last=temp;
            q.push(temp->r);
        }
    }
    if(key_node!=NULL)
    {
        cout<<"Deleted Element is: "<<key_node->data<<"\n";
        key_node->data=temp->data;
        if(last->r==temp)
            last->r=NULL;
        else
            last->l=NULL;
        delete(temp);
     }else{
        cout<<key<<" is not found\n";
     }
    return root;
}

void preOrder(node * head)
{
    if(head!=NULL)
    {
        cout<<head->data<< " ";
        preOrder(head->l);
        preOrder(head->r);
    }
}

void inOrder(node *head)
{
    if(head!=NULL)
    {
        inOrder(head->l);
        cout<<head->data<< " ";
        inOrder(head->r);
    }
}

void postOrder(node *head)
{
    if(head!=NULL)
    {
        postOrder(head->l);
        postOrder(head->r);
        cout<<head->data<< " ";
    }
}

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

int height(node *root)
{
    int lh,rh;
    if(root==NULL)
        return 0;
    lh=height(root->l);
    rh=height(root->r);
    if(lh>rh)
        return (lh+1);
    else
        return (rh+1);
}


