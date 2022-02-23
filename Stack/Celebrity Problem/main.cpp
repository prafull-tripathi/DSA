
#include<bits/stdc++.h>
using namespace std;



    bool knows(vector<vector<int> >& M, int a, int b, int n) {
       return M[a][b];
    }


    int celebrity(vector<vector<int> >& M, int n)
        {
        stack<int> s;

        for(int i=0; i<n; i++) {
            s.push(i);
        }



        while(s.size() > 1) {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();

        int zeroCount = 0;

        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }


        if(zeroCount != n)
            return -1;


        int oneCount = 0;

        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }

        if(oneCount != n-1)
            return -1;

        return ans;

    }




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"size:";
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }

        cout<<"Celebrity is: "<<celebrity(M,n)<<endl;

    }
}
