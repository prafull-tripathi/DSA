#include <iostream>
#include<math.h>
using namespace std;

int binarySearch(int arr[], int n, int val){

    int flag=0,l=0,h=n-1,mid;
    int pos=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr[mid]==val)
        {
            flag=1;
            pos=mid;
            h=mid-1;
        }
        else if(arr[mid]>val)
            h=mid-1;
        else
            l=mid+1;
    }
    if(flag==0)
        return -1;
    return pos;

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ele;
    cout<<"Element to be searched: "<<endl;
    cin>>ele;
    int ans=binarySearch(arr,n,ele);
    cout<<"Position: "<<ans;
    return 0;
}
