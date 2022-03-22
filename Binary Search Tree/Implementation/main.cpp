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
void inorder(node *);

int main()
{
    int op;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary tree\n 2. In-order Traversal\n";
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

        }
    }while(op!=3);
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


void inorder(struct node *root) {
  if (root != NULL) {
        cout<<root->data<<" ";
        inorder(root->l);

        inorder(root->r);
  }
}
