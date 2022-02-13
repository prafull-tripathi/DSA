#include <bits/stdc++.h>

using namespace std;

void countFrequency(vector<int>v,int n)
{
    unordered_map<int, int>s;
    for(int i=0;i<n;i++)
    {
        s[v[i]]++;
    }

    for(auto i:s)
        cout<<i.first<<" "<<i.second<<endl;


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
    return 0;
}
