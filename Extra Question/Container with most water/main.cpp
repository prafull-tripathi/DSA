#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height)
{
        int i=0,j=height.size()-1;
        int res=0;
        while(i<j)
        {
            cout<<"i: "<<i<<"j: "<<j<<"\n";
            cout<<"res: "<<res;
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]>height[j])
                j--;
            else if(height[i]<height[j])
                i++;
            else
            {
                i++;
                j--;
            }
        }
        return res;

}
int main()
{
    int val,n;
    cout<<"How many Elements you want to insert?\n";
    cin>>n;
    vector<int>hp;
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        hp.push_back(val);
    }
    int ans=maxArea(hp);
    cout<<"Ans: "<<ans;
    return 0;
}
