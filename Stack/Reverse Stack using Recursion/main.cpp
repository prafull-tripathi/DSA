#include <bits/stdc++.h>
using namespace std;

stack<int>st;

void insert_at_bottom(int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int a=st.top();
    st.pop();
    insert_at_bottom(x);

    st.push(a);
}

void reverse()
{
    while(st.empty())
    {
        int x=st.top();
        st.pop();
        reverse();

        insert_at_bottom(x);
    }
}

int main()
{
    int n,val;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>val;
        st.push(val);
    }
    reverse();
    cout<<"Reversed Stack is: \n";

   while(!st.empty())
   {
       cout<<st.top()<<" ";
       st.pop();
   }

	return 0;
}  // } Driver
