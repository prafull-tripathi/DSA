#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}


void quicksort(int arr[], int low, int high)
{
    // base condition
    if (low >= high) {
        return;
    }

    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot);
    quicksort(arr, pivot + 1, high);
}


// Print the array
void printArray(int v[], int size) {
  for (int i = 0; i < size; i++)
    cout << v[i] << " ";
  cout << endl;
}


int main() {

    int n;
    cout<<"Size of Array?\n";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);

    cout << "Sorted array: \n";
    printArray(arr, n);


    return 0;
}
