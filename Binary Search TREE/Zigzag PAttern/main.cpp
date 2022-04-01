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
node *deletenode(node *, int );
node *searchnode(node *, int );
void zigZagTraversal(node*);
void inorder(node *);

int main()
{
    int op,val;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary search tree\n 2. In-order Traversal\n 3. Delete a node\n";
        cout<<" 4. Search in Tree\n 5. ZigZag Pattern\n";
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
                        root=deletenode(root,val);
                        //cout<<"Value "<<val<<" deleted successfully"<<"\n";
                    }
                    break;
//            case 4: system("cls");
//                    {
//                        cout<<"Value you need to find?\n";
//                        cin>>val;
//                        root=searchnode(root,val);
//                    }
//                    break;

            case 5: system("cls");
                    {

                        zigZagTraversal(root);
                    }
                    break;

            default:cout<<"Wrong input\n";break;

        }
    }while(op!=6);
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


node *deletenode(node *root, int k)
{
    if(!root)
    {
         cout<<"Either tree is Empty or Value couldn't be found\n";
         return root;

    }

    if(root->data>k)
    {

        root->l=deletenode(root->l,k);
        return root;
    }
    else if(root->data<k)
    {
        root->r=deletenode(root->r,k);
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
void zigZagTraversal(node* root)
    {

        vector <int> res;

    	if (!root)
            return;

    	stack<struct node*> currentlevel;
    	stack<struct node*> nextlevel;


    	currentlevel.push(root);
    	bool lefttoright = true;

    	while (!currentlevel.empty())
    	{

    		node* temp = currentlevel.top();
    		currentlevel.pop();


    		if (temp)
    		{
    			cout<<temp->data<<" ";


    			if (lefttoright)
    			{
    				if (temp->l)
    					nextlevel.push(temp->l);
    				if (temp->r)
    					nextlevel.push(temp->r);
    			}
    			else
    			{
    				if (temp->r)
    					nextlevel.push(temp->r);
    				if (temp->l)
    					nextlevel.push(temp->l);
    			}
    		}


    		if (currentlevel.empty())
    		{
    			lefttoright = !lefttoright;
    			swap(currentlevel, nextlevel);
    		}
    	}
    }

void inorder(struct node *root) {
  if (root != NULL) {

        inorder(root->l);
        cout<<root->data<<" ";
        inorder(root->r);
  }
}
