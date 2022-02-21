#include <bits/stdc++.h>

using namespace std;


class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    int pop() {

        if(top >=0 ) {

            int ele=arr[top--];
            return ele;

        }
        else{
            cout << "Stack UnderFlow" << endl;
            return 0;
        }
    }


    void display()
    {
        if(top==-1){
            cout<<"Stack is empty";
            return;
        }
        cout<<"Stack is: \n";
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};

int main()
{
    int n,ch,ele;
    cout<<"Size of Stack\n";
    cin>>n;
    Stack st(n);
    do
    {
        cout<<"\nMain Menu:\n";
        cout<<"0. Exit\n";
        cout<<"1. Push into Stack\n";
        cout<<"2. Pop from Stack\n";
        cout<<"3. Display Stack\n";
        cout<<"4. Minimum in Stack\n";

        cin>>ch;

        switch(ch)
        {
            case 0:
                exit(0);
                break;

            case 1:
                {
                    system("cls");
                    cout<<"Enter element you want to insert into stack\n";
                    cin>>ele;
                    st.push(ele);
                }
                break;
            case 2:
                {
                    system("cls");
                    ele=st.pop();
                    cout<<"Popped element is: "<<ele;
                }

                break;
            case 3:
                {
                    st.display();
                }

                break;
            case 4:
                {
                    system("cls");
                    int m=st.pop();
                    while(!st.isEmpty()){
                        int n=st.pop();
                        if(n<m)
                        {
                            m=n;
                        }
                    }
                cout<<"Minimum Element in Stack is: "<<m;
                }

                break;

            default:
                {
                    system("cls");
                    cout<<"Wrong Option\n";
                }
                break;
        }
    }while(ch!=0);
    return 0;
}
