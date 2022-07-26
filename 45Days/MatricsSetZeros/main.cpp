#include <bits/stdc++.h>

using namespace std;

void setZeros(int arr[3][2])
{
    vector<int>dummy1(3,-1), dummy2(2,-1);
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
        {
            if(arr[i][j]==0)
            {
                dummy1[i]=0;
                dummy2[j]=0;
            }
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(dummy1[i]==0 || dummy2[j]==0)
                arr[i][j]=0;
        }
    }
}

int main()
{
    int arr [3][2] = {{1,2}, {1,0 }, {9,5}};
    setZeros(arr);

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
            cout<<arr[i][j]<<" ";

        cout<<"\n";
    }
    return 0;
}
