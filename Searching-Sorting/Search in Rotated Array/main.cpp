#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(nums[mid] == target)
            return mid;
      
        else if(nums[low]<=nums[mid]){
            
            if(target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
           
            if(target>nums[mid] && target<=nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
   
    return -1;
}

int main()
{
    int n,val;
    cout<<"Size of array?";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    int ele;
    cout<<"Element to be searched: "<<endl;
    cin>>ele;
    int ans=binarySearch(v,ele);
    cout<<"Position: "<<ans;
//    vector<int> nums({4,5,6,7,0,1,2});
//    cout<<binarySearch(nums, 5);
    return 0;
}
