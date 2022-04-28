//Greedy Problem
#include <bits/stdc++.h>

using namespace std;

void coinSaver(vector<int>v,int n, int amt)
{
    unordered_map<int, int>mp;
    int res=0;
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n;i++)
    {
        if(v[i]<=amt)
        {
            int c=floor(amt/v[i]);
            mp.insert({v[i],c});
            res+=c;
            amt-=c*v[i];
        }
        if(amt==0)
            break;
    }
    cout<<"total coins:\t"<<res<<"\n";
    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        cout<<i->second<<" coins of "<<i->first<<"\n";
    }
}

int main()
{
    int n,val;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int amount;
    cout<<"Amount?\n";
    cin>>amount;
    coinSaver(v,n,amount);
    return 0;
}
