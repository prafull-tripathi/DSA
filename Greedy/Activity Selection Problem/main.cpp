//Greedy Problem
//Activity Selection

#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(vector<int>s,vector<int>f, int n)
{

	int i, j;
	cout <<"Following activities are selected "<< endl;
	i = 0;
	cout <<" "<< i;
	for (j = 1; j < n; j++)
	{
        if (s[j] >= f[i])
        {
            cout <<" " << j;
            i = j;
        }
	}
}

int main()
{
    //This is alrady in sorted format
	vector<int>s = {1, 3, 0, 5, 8, 5};
    	vector<int>f = {2, 4, 6, 7, 9, 9};
    //if not then we have to firstly sort this vector according to finish vector
	//Which will going to take  O(n log n) as we are sorting
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}

