#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],mx1,mx2;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    sort(a, a+n);
    int k;
    cin>>k;
    cout<<a[(n-1)-k]<<" "<<a[k-1]<<endl;
}