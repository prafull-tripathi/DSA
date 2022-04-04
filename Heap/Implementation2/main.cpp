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

void insertKey(vector<int>&heap,int k)
{
    int i = heap.size()-1;
    cout<<"i: "<<i<<"\n";
    while (i != 0 && heap[parent(i)] > heap[i]) {

        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}
void dispalyHeap(vector<int>&heap)
{
    if(!heap.size())
    {
        cout<<"Empty Heap\n";
        return;
    }
    for(auto i:heap)
        cout<<i<<" ";
    cout<<"\n";
}

void minheapify(vector<int>&heap,int i)
{
    int lt=left(i);
    int rt=right(i);
    int smallest=i;
    int hpsize=heap.size();
    if(lt<hpsize && heap[lt]<heap[smallest])
        smallest=lt;
    if(rt<hpsize && heap[rt]<heap[smallest])
        smallest=rt;

    if(smallest!=i)
    {
        swap(heap[i],heap[smallest]);
        minheapify(heap,smallest);
    }
}

void maxheapify(vector<int>&heap,int i)
{
    int lt=left(i);
    int rt=right(i);
    int largest=i;
    int hpsize=heap.size();
    if(lt<hpsize && heap[lt]>heap[largest])
        largest=lt;
    if(rt<hpsize && heap[rt]>heap[largest])
        largest=rt;

    if(largest!=i)
    {
        swap(heap[i],heap[largest]);
        maxheapify(heap,largest);
    }
}

int extractMin(vector<int>&heap)
{
    int minVal=heap[0];
    heap[0]=heap[heap.size()];
    cout<<"Min VAl: "<<minVal<<"\n";
    cout<<"heap[0]: "<<heap[0]<<"\n";
    heap.pop_back();

    minheapify(heap,0);
    dispalyHeap(heap);
    return minVal;

}

int extractMax(vector<int>&heap)
{
    int maxVal=heap[0];
    heap[0]=heap[heap.size()];
    heap.pop_back();

    maxheapify(heap,0);
    return maxVal;

}


int main()
{
    int val,n,op;
    cout<<"Elements you want to insert?\n";
    cin>>n;
    vector<int>hp;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        hp.push_back(val);
    }
    do
    {
        cout<<"Menu\n";
        cout<<" 0. Exit\n 1. Insert into heap\n 2. Display Heap\n";
        cout<<" 3. Build Min-Heapify\n 4. Max-Heapify\n 5. Extract Minimum\n 6. Extract Maximum\n";
        cin>>op;
        switch(op)
        {
            case 0:exit(0);break;

            case 1:system("cls");
            {
                cout<<"Elements you want to insert?\n";
                cin>>val;
                insertKey(hp,val);
            }
            break;

            case 2:system("cls");
            {
                cout<<"Data in Heap is:\n";
                dispalyHeap(hp);
            }
            break;

            case 3:system("cls");
            {
                for(int i=(hp.size()-1)/2;i>=0;i--)
                    minheapify(hp,i);
                cout<<"Min-Heapify is:\n";
                dispalyHeap(hp);

            }
            break;

            case 4:system("cls");
            {
                for(int i=(hp.size()-1)/2;i>=0;i--)
                    maxheapify(hp,i);
                cout<<"Max-Heapify is:\n";
                dispalyHeap(hp);

            }
            break;

            case 5:system("cls");
            {
                int ans=extractMin(hp);
                cout<<"Minimum value Extracted from heap is: "<<ans<<"\n";

            }
            break;

            case 6:system("cls");
            {
                int ans=extractMax(hp);
                cout<<"Maximum value Extracted from heap is: "<<ans<<"\n";

            }
            break;

            default:
            {
                cout<<"Wrong Option\n";
            }
            break;
        }
    }
    while(op!=6);

    return 0;
}
