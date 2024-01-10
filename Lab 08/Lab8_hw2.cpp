//Max Heap and its Operation
#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    int size=0;
    vector<int> heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
public:
    MaxHeap(int capacity);
    void insert(int val);
    void Delete_top();
    void heapify(int i);
    void DispalyHeap();
    void get_top();
};

MaxHeap::MaxHeap(int capacity)
{
    heap.resize(capacity);
}

void MaxHeap::insert(int val)
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

void MaxHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if((l < size) && (heap[l] > heap[largest]))
        largest = l;
    
    if((r < size) && (heap[r] > heap[largest]))
        largest = r;
    

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void MaxHeap::Delete_top()
{
    if(size==0){
        cout<<"Heap is Empty\n";
    }

    else if(size==1){
        size--;
    }
    
    else{
        heap[0]=heap[size-1];
        size--;
        heapify(0);
    }
}

void MaxHeap::DispalyHeap()
{
    int power = 0;
    int value = 1;
    for(int i = 0; i < size; i++){
        if(i == value){
            cout << endl;
            power++;
            value += pow(2,power);
        }
        cout << heap[i] << "  ";
    }
    cout << endl;
}

void MaxHeap::get_top()
{
    cout<<"Top value of the heap is: "<<heap[0]<<endl;
}

int main()
{
    int n;
    cout<<"Enter Number of Values: ";
    cin>>n;
    MaxHeap h(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h.insert(x);
    }

    h.DispalyHeap();
    h.get_top();
    cout<<endl;
    h.Delete_top();
    cout<<"Heap after Delete top:\n";
    h.DispalyHeap();
    h.get_top();
}
