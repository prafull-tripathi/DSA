#include<bits/stdc++.h>
using namespace std;


void result(vector<int>v)
{
    int n=v.size();
    int sumA=0;
    int sum= n*(n+1)/2;	//find the sum of n element
    for(int i=0;i<n;i++)		// find the total sum of Array
    {
        sumA+=v[i];
    }
    cout<<"missing number in Array is: "<<sumA-sum;
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

    result(v);
    return 0;
}
