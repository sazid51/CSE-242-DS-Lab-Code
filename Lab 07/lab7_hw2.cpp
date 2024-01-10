//Radix Sort
#include<bits/stdc++.h>
using namespace std;
int mx;
void CountSort(int *a, int n, int pos)
{
    int count[10]={0};
    for(int i=0;i<n;i++)
        ++count[(a[i]/pos)%10];

    for(int i=1;i<10;i++)
        count[i] = count[i] + count[i-1];

    int b[n];
    for(int i=n-1;i>=0;i--)
        b[--count[(a[i]/pos)%10]] = a[i];

    for(int i=0;i<n;i++)
        a[i] = b[i];
}

void RadixSort(int *a, int n)
{
    for(int pos=1; mx/pos>0; pos*=10)
        CountSort(a, n, pos);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    mx=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        mx= max(mx, a[i]);
    }
    RadixSort(a, n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n\n";

}
