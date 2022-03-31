#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
} *root=NULL, *nn;

struct node * create(int);
struct node * insert_data(struct node *, int key);
node *deleteNode(node *, int );
node *searchNode(node *, int );
int minimumElement(node *);
int maximumElement(node *);
void inorder(node *);

int main()
{
    int op,val;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary search tree\n 2. In-order Traversal\n 3. Delete a node\n";
        cout<<" 4. Search in Tree\n 5. Minimum Element in BST\n 6. Maximum Element in BST\n";
        cin>>op;
        switch(op)
        {
            case 0: exit(0);break;
            case 1: system("cls");
                    {
                        int val;
                        cout<<"Value to be inserted?\n";
                        cin>>val;
                        root=insert_data(root,val);
                    }
                    break;
            case 2: system("cls");
                    {
                        cout<<"In-order Traversal"<<"\n";
                        inorder(root);
                    }
                    break;
            case 3: system("cls");
                    {
                        cout<<"Value you want to delete?\n";
                        cin>>val;
                        root=deleteNode(root,val);
                        //cout<<"Value "<<val<<" deleted successfully"<<"\n";
                    }
                    break;
            case 4: system("cls");
                    {
                        cout<<"Value you want to delete?\n";
                        cin>>val;
                        root=deleteNode(root,val);
                    }
                    break;

            case 5: system("cls");
                    {

                        val=minimumElement(root);
                        if(val!=-1)
                            cout<<"Minimum value in BST is: "<<val<<"\n";
                        else
                            cout<<"Couldn't find\n";
                    }
                    break;
            case 6: system("cls");
                    {
                        val=maximumElement(root);
                        if(val!=-1)
                            cout<<"Minimum value in BST is: "<<val<<"\n";
                        else
                            cout<<"Couldn't find\n";
                    }
                    break;
            default:cout<<"Wrong input\n";break;

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

node *insert_data(struct node *node, int key) {

  if (node == NULL)
    return create(key);


  if (key < node->data)
    node->l = insert_data(node->l, key);
  else
    node->r = insert_data(node->r, key);

  return node;
};


node *deleteNode(node *root, int k)
{
    if(!root)
    {
         cout<<"Either tree is Empty or Value couldn't be found\n";
         return root;

    }

    if(root->data>k)
    {

        root->l=deleteNode(root->l,k);
        return root;
    }
    else if(root->data<k)
    {
        root->r=deleteNode(root->r,k);
        return root;
    }


    if(root->l==NULL)
        {
            node *temp=root->r;
            delete root;
            return temp;
        }
        else if(root->r==NULL)
        {
            node *temp=root->l;
            delete root;
            return temp;
        }

        else
        {
            node *succParent=root;
            node *succ=root->r;
            while(succ->l!=NULL)
            {
                succParent=succ;
                succ=succ->l;
            }
            if (succParent != root)
                succParent->l = succ->r;
            else
                succParent->r = succ->r;

            root->data=succ->data;
            delete succ;
            return root;
    }

}
int minimumElement(node* root) {
    // Code here
    if(!root)
        return -1;
    int val=INT_MAX;
    while(root)
    {
        val=min(root->data,val);
        root=root->l;
    }
    return val;
}

int maximumElement(node* root) {
    // Code here
    if(!root)
        return -1;
    int val=INT_MIN;
    while(root)
    {
        val=max(root->data,val);
        root=root->r;
    }
    return val;
}
node *ceil(node *root, int k)
{
    node *res=NULL;
    while(root!=NULL)
    {
        if(root->data==k)
            return root;
        else if(root->data<k)
            root=root->r;
        else
        {
            res=root;
            root=root->l;
        }
    }
    return res;
}

node *searchNode(node *root, int k)
{
    if(!root)
    {
        cout<<"Either Tree is empty or Couldn't find value\n";
        return root;
    }

    if(root->data==k)
    {
        cout<<"Found value " <<k<<"\n";
        return root;
    }

    else if(root->data>k)
        searchNode(root->l,k);
    else
        searchNode(root->r,k);

}

void inorder(struct node *root) {
  if (root != NULL) {

        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
  }
}
