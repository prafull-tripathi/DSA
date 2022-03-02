#include <bits/stdc++.h>
using namespace std;

class Stack
{
    public:

    vector<long long> nextLargerElement(vector<long long> arr, int n){

        stack<long long > s;
        vector<long long > res;
        for (int i = n-1; i >= 0; i--)
        {
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            if (s.empty ())
                res[i] = -1;
            else
                res[i] = s.top ();

            s.push (arr[i]);
        }
        return res;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Stack s;
    vector <long long> res = s.nextLargerElement(arr, n);
    for (long long i : res)
        cout << i << " ";

    return 0;
}  
