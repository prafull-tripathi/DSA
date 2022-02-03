#include <bits/stdc++.h>
using namespace std;

//Used Moore's Algorithm

int majorityElement(vector<int>&a) {
        int count=0;
        int ele=0;	
        for(int i: a)
        {
            if(count==0)
                ele=i;
            if(ele==i)
                count+=1;
            else
                count-=1;
        }
        return ele;
    }

int main() {

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
    int ans=majorityElement(v);
    cout<<"\nMajority Element is: "<<ans;
    return 0;
}
