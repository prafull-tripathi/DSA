#include <bits/stdc++.h>

using namespace std;


int main()
{
    int ch,ele;

    stack<int>st;
    do{
        cout<<"\nMain Menu:\n";
    cout<<"0. Exit\n";
    cout<<"1. Push into Stack\n";
    cout<<"2. Pop from Stack\n";
    cout<<"3. Size of Stack\n";
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
                cout<<"Popped element is: "<<st.top();
                st.pop();
                break;
            case 3:
                system("cls");
                cout<<"Size of Stack: "<<st.size();
                break;
            case 4:
                system("cls");
                cout<<"Stack is:\n ";

                while(!st.empty()){//stack not empty
                    cout<<"top element is:"<<st.top()<<endl;//print top element
                    st.pop();                }

            default:
                system("cls");
                cout<<"Wrong Option\n";
                break;
        }
    }while(ch!=0);
    return 0;
}
