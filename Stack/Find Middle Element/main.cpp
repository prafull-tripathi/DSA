/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

class myStack
{
	struct Node
	{
		int num;
		Node *next;
		Node *prev;

		Node(int num)
		{
			this->num = num;
		}
	};

	//Members of stack
	Node *head = NULL;
	Node *mid = NULL;
	int size = 0;

public:
	void push(int data)
	{
		Node *temp = new Node(data);
		if (size==0)
		{
			head = temp;
			mid = temp;
			head->prev=NULL;
			size++;
			return;
		}

		head->next = temp;
		temp->prev = head;

		//update the pointers
		head = head->next;

		if (size%2==1)
		{


			mid = mid->next;
		}
		size++;
	}

	void pop()
	{
		if (size!=0)
		{
			if (size==1)
			{
				head = NULL;
				mid = NULL;
			}
			else
			{
			    Node *ptr=head;
                cout<<"Deleted element is: "<<ptr->num<<"\n";
				head = head->prev;
				head->next = NULL;
				if (size%2==0)
				{
					mid = mid->prev;
				}
			}
			size--;
		}
	}
	void display()
	{
	    if (head == NULL){
            cout << "NULL\n";
            return;
	    }

	    Node *ptr=head;

	    while(ptr!=NULL)
        {
            cout<<ptr->num<<" ";
            ptr=ptr->prev;
        }

	}

	int findMiddle()
	{
		if (size==0)
		{
			return -1;
		}
		return mid->num;
	}

	void deleteMiddle()
	{
		if (size!=0)
		{
			if (size==1)
			{
				head = NULL;
				mid = NULL;
			}
			else if (size==2)
			{
			    Node *ptr=head;
                cout<<"Deleted element is: "<<ptr->num<<"\n";
				head = head->prev;
				mid = mid->prev;
				head->next =NULL;
			}
			else
			{
                cout<<"Deleted element is: "<<mid->num<<"\n";
				mid->next->prev = mid->prev;
				mid->prev->next = mid->next;
				if (size%2==0)
				{
					mid = mid->prev;
				}
				else
				{
					mid = mid->next;
				}
			}
			size--;
		}
	}
};


int main()
{
    int ch,ele;

    myStack st;
    do{
        cout<<"\nMain Menu:\n";
        cout<<"0. Exit\n";
        cout<<"1. Push into Stack\n";
        cout<<"2. Pop from Stack\n";
        cout<<"3. Display Stack\n";
        cout<<"4. Find Middle Element in Stack\n";
        cout<<"5. Delete Middle Element\n";
        cin>>ch;
        switch(ch)
        {
            case 0:
                exit(0);
                break;

            case 1:
                system("cls");
                cout<<"Enter element you want to insert into stack\n";
                cin>>ele;
                st.push(ele);
                break;
            case 2:
                system("cls");
                st.pop();
                break;
            case 3:
                system("cls");
                cout<<"Stack is:\n ";
                st.display();
                break;
            case 4:
                system("cls");
                ele=st.findMiddle();
                cout<<"Middle Element is: "<<ele;
                break;
            case 5:
                system("cls");
                st.deleteMiddle();
                break;
            default:
                system("cls");
                cout<<"Wrong Option\n";
                break;
        }
    }while(ch!=0);
    return 0;
}
// This code is contributed by Nikhil Goswami
