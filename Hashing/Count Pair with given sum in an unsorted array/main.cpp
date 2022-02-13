#include <bits/stdc++.h>

using namespace std;

int countPairs(vector<int>v,int n, int k)
{
    unordered_map<int, int>mp;

    int ans=0;
    for(int i=0;i<n;i++)
    {
       int b=k-v[i];
       if(mp[b])
       {
           ans+=mp[b];
       }
       mp[b]++;
    }

    return ans;

}

int main()
{
    int n;
    cout<<"Size of 1 Array?\n";
    cin>>n;

    vector<int>v1;
    int val;
    for(int i=0;i<n;i++)
    {
        cout<<"Values?";
        cin>>val;
        v1.push_back(val);
    }
    int k;
    cout<<"given sum: ";
    cin>>k;
    int ans=countPairs(v1,n,k);
    cout<<"Pairs are: ";
    cout<<ans;
    return 0;
}
