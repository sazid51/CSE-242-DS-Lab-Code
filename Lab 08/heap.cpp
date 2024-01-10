//Max Heap and its Operation
#include<bits/stdc++.h>
using namespace std;

int size=0;
vector<int> heap;
int parent(int i){return (i-1)/2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}

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

void heapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if((l < size) && (heap[l] > heap[largest])){
        largest = l;
    }if((r < size) && (heap[r] > heap[largest])){
        largest = r;
    }

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void Delete_top()
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

void DispalyHeap()
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

void get_top()
{
    cout<<"Top value of the heap is: "<<heap[0]<<endl;
}

int main()
{
    int n;
    cout<<"Enter Number of Values: ";
    cin>>n;
    heap.resize(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }

    DispalyHeap();
    get_top();
    cout<<endl;
    Delete_top();
    cout<<"Heap after Delete top:\n";
    DispalyHeap();
    get_top();
}
