#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(!s.empty() && s.top() >= curr)
        {
            s.pop();
        }
        if(s.empty())
            ans[i]=-1;
        else
            ans[i] = s.top();

        s.push(curr);
    }
    return ans;
}

int main()
{
    int n,val;
    cout<<"Size:\n";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }

    vector <int> res = nextSmallerElement(arr, n);
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";

    return 0;
}
