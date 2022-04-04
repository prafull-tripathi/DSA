#include <bits/stdc++.h>

using namespace std;


int parent(int i)
{
    return ((i-1)/2);
}
int left(int i)
{
    return ((2*i)+1);
}
int right(int i)
{
    return ((2*i)+2);
}

void dispalyHeap(vector<int>&heap)
{

    for(auto i:heap)
        cout<<i<<" ";
    cout<<"\n";
}

void heapify(vector<int>&arr, int n, int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);


	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i)
    {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}


void heapSort(vector<int>&arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
    {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
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
    cout<<"Main loop n: "<<n<<"\n";
    cout<<hp.size()<<"\n";
    heapSort(hp,hp.size());

    cout<<"Sorted Heap is:\n";
    dispalyHeap(hp);


    return 0;
}
