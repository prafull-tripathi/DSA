#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[9]={1,0,1,1,1,1,0,1,1};

    int countV=0, maxV=0;
    for(int i=0;i<9;i++)
    {
        if(arr[i]!=1)
            countV=0;
        else{
            countV+=1;
            maxV=max(countV,maxV);
        }

    }
    cout<<"Conservative 1's are: "<<maxV;
    return 0;
}
