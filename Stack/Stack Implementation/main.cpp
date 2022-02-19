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

    void pop() {

        if(top >=0 ) {

            int ele=arr[top];
            cout<<"Popped element is: "<<ele;
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }
    void display()
    {
        if(top==-1){
            cout<<"Stack is empty";
            return;
        }
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
    }

//    bool isEmpty() {
//        if( top == -1) {
//            return true;
//        }
//        else{
//            return false;
//        }
//    }

};
int main()
{
    int n,ch,ele;
    cout<<"Size of Stack\n";
    cin>>n;
    Stack st(5);
    do{
        cout<<"\nMain Menu:\n";
    cout<<"0. Exit\n";
    cout<<"1. Push into Stack\n";
    cout<<"2. Pop from Stack\n";
    cout<<"3. Peek in Stack\n";
    cout<<"4. Display Stack\n";
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
                cout<<"Top Element in Stack\n";
                ele=st.peek();
                cout<<"Top Element in Stack is: "<<ele;
                break;
            case 4:
                system("cls");
                cout<<"Stack is:\n ";
                st.display();
                break;
            default:
                system("cls");
                cout<<"Wrong Option\n";
                break;
        }
    }while(ch!=0);
    return 0;
}
