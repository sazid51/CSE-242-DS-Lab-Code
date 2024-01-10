#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    int C[100]={0};
    for(int i=0;i<n;i++)
        ++C[a[i]];

    bool f[100];
    for(int i=0;i<n;i++)
    {
        if(f[a[i]]==true) continue;
        cout<<a[i]<<": "<<C[a[i]]<<endl;
        f[a[i]]=true;
    }
}