#include <bits/stdc++.h>

using namespace std;

bool ispar(string x)
{
        // Your code here
    stack<char>st;
    for(int i=0;i<x.size();i++)
    {
        char top=(st.empty()?'#':st.top());

        if(top=='{' && x[i]=='}')
            st.pop();
        else if(top=='[' && x[i]==']')
            st.pop();
        else if(top=='(' && x[i]==')')
            st.pop();
        else
            st.push(x[i]);
    }
    return st.empty();
}

int main()
{
    string str;
    cout<<"Enter String\n";
    cin>>str;
    bool ans=ispar(str);
    if(ans)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
