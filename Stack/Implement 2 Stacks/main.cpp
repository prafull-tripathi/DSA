#include <bits/stdc++.h>

using namespace std;

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n)  // constructor
   {
       size = n;
       arr = new int[n];
       top1 = -1;
       top2 = size;
   }

   // Method to push an element x to stack1
   void push1(int x)
   {
       // There is at least one empty space for new element
       if (top1 < top2 - 1)
       {
           top1++;
           arr[top1] = x;
       }
       else
       {
           cout << "Stack Overflow";
           exit(1);
       }
   }

   // Method to push an element x to stack2
   void push2(int x)
   {
       // There is at least one empty space for new element
       if (top1 < top2 - 1)
       {
           top2--;
           arr[top2] = x;
       }
       else
       {
           cout << "Stack Overflow";
           exit(1);
       }
   }

   // Method to pop an element from first stack
   int pop1()
   {
       if (top1 >= 0 )
       {
          int x = arr[top1];
          top1--;
          return x;
       }
       else
       {
           cout << "Stack UnderFlow";
           exit(1);
       }
   }

   // Method to pop an element from second stack
   int pop2()
   {
       if (top2 < size)
       {
          int x = arr[top2];
          top2++;
          return x;
       }
       else
       {
           cout << "Stack UnderFlow";
           exit(1);
       }
   }
    void display1()
    {
        if(top1==-1){
            cout<<"Stack is empty";
            return;
        }
        cout<<"Stack 1 is:\n";
        for(int i=top1;i>=0;i--){

            cout<<arr[i]<<" ";
        }

    }
     void display2(int n)
    {
        if(top2==-1){
            cout<<"Stack is empty";
            return;
        }
        cout<<"Stack 2 is:\n";
        for(int i=top2;i<n;i++){

            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n,ch,ele;
    cout<<"Size of Stack\n";
    cin>>n;
    twoStacks st(n);
    do{
        cout<<"\nMain Menu:\n";
    cout<<"0. Exit\n";
    cout<<"1. Push into Stack1\n";
    cout<<"2. Pop from Stack1\n";
    cout<<"3. Push into Stack2\n";
    cout<<"4. Pop from Stack2\n";

    cout<<"5. Display Stack1\n";
    cout<<"6. Display Stack2\n";
    cin>>ch;

        switch(ch)
        {
            case 0:
                exit(0);
                break;

            case 1:
                system("cls");
                cout<<"Enter element you want to insert into stack1\n";
                cin>>ele;
                st.push1(ele);
                break;
            case 2:
                system("cls");
                ele=st.pop1();
                cout<<"Popped element of Stack 1 is: "<<ele<<"\n";

                break;
            case 3:
                system("cls");
                cout<<"Enter element you want to insert into stack2\n";
                cin>>ele;
                st.push2(ele);

                break;
            case 4:
                system("cls");
                ele=st.pop2();
                cout<<"Popped element of Stack 2 is: "<<ele<<"\n";
                break;
            case 5:
                st.display1();
                break;
            case 6:
                st.display2(n);
                break;

            default:
                system("cls");
                cout<<"Wrong Option\n";
                break;
        }
    }while(ch!=0);
    return 0;
}
