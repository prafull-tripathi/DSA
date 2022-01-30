#include<bits/stdc++.h>
using namespace std;


int countSquares(int N) {
        // code here
        int x=floor(sqrt(N));
        int count=0;
        for(int i=1;i<=x;i++)
        {
            if(i*i<N)
                count++;
        }
        return count;
    }

int main()
{
    int n,val;
    cout<<"Enter Number: ";
    cin>>n;
    val=countSquares(n);
    cout<<"Total values whose Square root is less than "<<n<<" is: "<<val;

    return 0;
}
