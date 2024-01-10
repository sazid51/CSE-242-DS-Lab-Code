//Counting Sort
#include<bits/stdc++.h>
using namespace std;
int mx;
void counting_sort(int *a, int n)
{
    int count[mx+1]  ={0};

    for(int i=0;i<n;i++)
        ++count[a[i]];

    for(int i=1;i<=mx;i++)
        count[i]= count[i]+ count[i-1];

    int b[n];
    for(int i=n-1;i>=0;i--)
        b[--count[a[i]]]=a[i];

    for(int i=0;i<n;i++)
        a[i] = b[i];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    counting_sort(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\n\n";
}