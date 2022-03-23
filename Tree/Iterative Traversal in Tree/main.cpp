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
void inOrder(node *);
void preOrder(node *);
void postorder(node *);


int main()
{
    int op;
    do
    {
        cout<<"\nMenu\n 0. Exit\n";
        cout<<" 1. Insert in binary tree\n 2. Iterative In-order Traversal\n 3. Iterative Pre-order Traversal\n 4. Post-order Traversal\n";
        cin>>op;
        switch(op)
        {
            case 0: exit(0);break;
            case 1: system("cls");insert_data();break;
            case 2: system("cls");
                    {
                        cout<<"In-order Traversal"<<"\n";
                        inOrder(root);
                    }
                    break;
            case 3: system("cls");
                    {
                        cout<<"Pre-order Traversal"<<"\n";
                        preOrder(root);
                    }
                    break;
            case 4: system("cls");
                    {
                        cout<<"Post-order Traversal"<<"\n";
                        postorder(root);
                    }
                    break;
            default: cout<<"Wrong Option\n";
                        break;
        }
    }while(op!=5);
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
    cout<<"Value to be entered: (-1) for null\n";
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
        {
            if(temp->l->data!=-1)
                q.push(temp->l);
        }

        else
        {
            if(val==-1)
            {
                temp->l=create(val);
                return root;
            }
            temp->l=create(val);
            return root;
        }

        if(temp->r!=NULL)
        {
            if(temp->r->data!=-1)
                q.push(temp->r);
        }

        else
        {
            if(val==-1)
            {
                temp->r=create(val);
                return root;
            }
            temp->r=create(val);
            return root;
        }
    }
    return 0;
};

void inOrder(node *root)
{
    stack<node*> stack;
    node* curr = root;
    while (!stack.empty() || curr != NULL)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->l;
        }
        else {

            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->r;
        }
    }
}

void preOrder(node *root)
{

    if(!root){
        cout<<"Empty Tree\n";
        return;
    }

    stack<node *>st;
    st.push(root);
    while(!st.empty())
    {
        node *curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->r!=NULL)
            st.push(curr->r);
        if(curr->l!=NULL)
            st.push(curr->l);
    }
}

void postorder(node *root)
{
    if(!root){
        cout<<"Empty Tree\n";
        return;
    }

    stack<node *>st;
    st.push(root);
    while(!st.empty())
    {
        node *curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->l!=NULL)
            st.push(curr->l);
        if(curr->r!=NULL)
            st.push(curr->r);

    }
}
