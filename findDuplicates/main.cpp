#include <bits/stdc++.h>
using namespace std;

// Function that returns 0 if a pair
// is found unsorted
vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>v;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.find(arr[i])!=s.end())
            {
                v.push_back(arr[i]);
            }
            else
            {
                s.insert(arr[i]);
            }
        }
        sort(v.begin(),v.end());
        if(v.empty())
            v.push_back(-1);
        return v;
    }
// Driver code
int main()
{

    int n;
    cout<<"Enter Size of Array";
    cin>>n;
    int arr[n];
    cout<<"Enter values in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>ans=duplicates( arr, n );
    cout<<"Duplicates value in Array: "
    for(auto ip:ans)
        cout<<ip<<" ";
    return 0;
}

