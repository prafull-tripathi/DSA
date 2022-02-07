
#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>arr, int sum)
	{
	    int n=arr.size();
	    sort(arr.begin(),arr.end());
	    long long ans = 0;
	    for (int i = 0; i < n - 2; i++)
	    {
	        int j = i + 1, k = n - 1;
	        while (j < k)
	        {
	            if (arr[i] + arr[j] + arr[k] >= sum)
	                k--;
	            else
	            {
	                ans += (k - j);
	                j++;
	            }
	        }
	    }
	    return ans;
	}
int main()
{
	int n, i,val;
    cin >> n;
    vector<int>v;

    for (i = 0; i < n; i++) {
            cin>>val;
        v.push_back(val);
    }
    int sum;
    cout<<"Find sum equal to?";
    cin>>sum;
    int result=countTriplets(v,sum);
    cout<<result;
    return 0;
}
