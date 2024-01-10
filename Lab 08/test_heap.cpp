//Max Heap and its Operation
#include<bits/stdc++.h>
using namespace std;
int size=0;
vector<int> heap;

int parent(int i){
    return (i-1)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+1;
}

void insert(int val)
{
    size++;
    int i= size-1;
    heap[i] = val;

    while((i != 0) && (heap[parent(i)] < heap[i]))
    {
        swap(heap[i], heap[parent(i)]);
        i=parent(i);
    }
}

void heapify(int i)
{
    int l=left(i);
    int r=right(i);
    int largest=i;

    if((l<size) && (heap[l]>heap[largest]))
        largest = l;
    if((r<size) && (heap[r]>heap[largest]))
        largest=r;

    if(largest!=i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void Delete_top()
{
    if(size==0){
        cout<<"Heap is Empty\n";
        return;
    }

    else if(size==1){
        size--;
        return;
    }
    
    else{
        heap[0]=heap[size-1];
        size--;
        heapify(0);
    }
}

void DispalyHeap()
{
    int power = 0;
    int value = 1;
    for(int i = 0; i < size; i++){
        // if(i == value){
        //     cout << endl;
        //     power += 1;
        //     value += (1 << power);
        // }
        cout << heap[i] << "  ";
    }
    cout << endl;
}

int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==-1) break;
        insert(n);
    }

    DispalyHeap();
    cout<<endl;
    //Delete_top();
    //DispalyHeap();
}
