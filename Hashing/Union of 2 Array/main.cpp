#include <bits/stdc++.h>

using namespace std;

vector<int> intersectionOfArray(vector<int>v1,int n, vector<int>v2, int m)
{
    unordered_set<int>s;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        s.insert(v1[i]);
    }


    for(int i=0;i<m;i++)
    {
        s.insert(v2[i]);
    }

    for(auto x:s)
        v.push_back(x);
    return v;

}

int main()
{
    int n,m;
    cout<<"Size of 1 Array?\n";
    cin>>n;

    vector<int>v1,v2;
    int val;
    for(int i=0;i<n;i++)
    {
        cout<<"Values?";
        cin>>val;
        v1.push_back(val);
    }
    cout<<"Size of 2 Array?\n";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cout<<"Values?";
        cin>>val;
        v2.push_back(val);
    }
    vector<int>v=intersectionOfArray(v1,n,v2,m);
    cout<<"Union of 2 Arrays are: ";
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}
