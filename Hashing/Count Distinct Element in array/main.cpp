#include <bits/stdc++.h>

using namespace std;

int distinctElement(vector<int>v,int n)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
        s.insert(v[i]);

    return s.size();

}

int main()
{
    int n;
    cout<<"Size of Array?\n";
    cin>>n;
    vector<int>v;
    int val;
    for(int i=0;i<n;i++)
    {
        cout<<"Values?";
        cin>>val;
        v.push_back(val);
    }
    int count=distinctElement(v,n);
    cout<<"Distinct Element are: "<<count;
}
