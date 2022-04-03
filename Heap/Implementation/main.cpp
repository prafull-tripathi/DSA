#include <bits/stdc++.h>

using namespace std;

//vector<int>heap;

class BinaryHeap{
public:
    //int hpsize;
    vector<int>hp;

    BinaryHeap()
    {

    }
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

    void insertData(int k);
    void insertKey(int k);
    void dispalyHeap();

};

void BinaryHeap::insertKey(int k)
{
    hp.push_back(k);
    int i = hp.size()-1;
    cout<<"i: "<<i<<"\n";
    while (i != 0 && hp[BinaryHeap::parent(i)] > hp[i]) {

        swap(hp[BinaryHeap::parent(i)], hp[i]);
        i = BinaryHeap::parent(i);
    }
}

void BinaryHeap::insertData(int k)
{
    hp.push_back(k);
}

void BinaryHeap::dispalyHeap()
{
    if(!hp.size())
    {
        cout<<"Empty Heap\n";
        return;
    }
    for(auto i:hp)
        cout<<i<<" ";
    cout<<"\n";
}
int main()
{
    BinaryHeap heap;
    int val,n,op;
    cout<<"Elements you want to insert?\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        heap.insertData(val);
    }
    do
    {
        cout<<"Menu\n";
        cout<<" 0. Exit\n 1. Insert into heap\n 2. Display Heap\n";
        cin>>op;
        switch(op)
        {
            case 0:exit(0);break;
            case 1:system("cls");
            {
                cout<<"Elements you want to insert?\n";
                cin>>val;
                heap.insertKey(val);
            }
            break;
            case 2:system("cls");
            {
                cout<<"Data in Heap is:\n";
                heap.dispalyHeap();
            }
            default:
            {
                cout<<"Wrong Option\n";
            }
            break;
        }
    }
    while(op=3);

    return 0;
}
