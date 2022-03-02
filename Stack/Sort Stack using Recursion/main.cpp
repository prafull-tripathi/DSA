#include <bits/stdc++.h>
using namespace std;

stack<int>st;

void sortedInsert(stack<int> &s, int x)
{
	if(s.empty() or x>s.top())
	{
		s.push(x);
		return;
	}
	int temp = s.top();
	s.pop();
	sortedInsert(s,x);
	s.push(temp);
}

void sort()
{
	if(!st.empty())
	{
		int x = st.top();
		st.pop();
		sort();
		sortedInsert(st,x);
	}
}

int main()
{
    int n,val;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>val;
        st.push(val);
    }
    sort();
    cout<<"Sorted Stack is: \n";

   while(!st.empty())
   {
       cout<<st.top()<<" ";
       st.pop();
   }

	return 0;
}  // } Driver
