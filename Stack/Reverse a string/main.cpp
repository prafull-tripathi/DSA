#include <bits/stdc++.h>

using namespace std;

string reverse(string x)
{
        // Your code here
    stack<char>st;

    for(int i=0;i<x.size();i++)
    {
        st.push(x[i]);
    }
    for(int i=0;i<x.size();i++)
    {
        x[i]=st.top();
        st.pop();
    }
    return x;
}

int main()
{
    string str;
    cout<<"Enter String\n";
    cin>>str;
    string ans=reversestr);
    cout<<ans;
    return 0;
}
