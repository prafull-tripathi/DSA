#include <bits/stdc++.h>
using namespace std;

//Implemented Moore's Algorithm

int findPeakElement(vector<int>& nums) {
         int left = 0,  right = nums.size() - 1;

        while(left + 1 < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[mid-1]){
                right = mid;
            }else if(nums[mid] < nums[mid+1]){
                left = mid;
            }else{
                return mid;
            }
        }

        if(nums[left] > nums[right]){
            return left;
        }else{
            return right;
        }
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

    int ans=findPeakElement(v);
    cout<<"\nMajority Element is: "<<ans;
    return 0;
}
