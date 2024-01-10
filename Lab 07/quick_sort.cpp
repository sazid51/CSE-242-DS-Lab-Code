#include<bits/stdc++.h>
using namespace std;
int a[1000];

void QuickSort(int left, int right)
{
    if(left>right) return;

    int pivot= left + rand()%(right-left+1);
    swap(a[pivot],a[left]);
    pivot = left;

    int l= left +1, r=right;
    while(l<=r)
    {
        if(a[l]<=a[pivot])
            l++;
        else if(a[r]>a[pivot])
            r--;
        else swap(a[l],a[r]);
    }
    swap(a[pivot],a[l-1]);

    pivot = l-1;
    QuickSort(left, pivot-1);
    QuickSort(pivot+1, right);
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    QuickSort(0,n-1);
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
    cout<<endl;
}