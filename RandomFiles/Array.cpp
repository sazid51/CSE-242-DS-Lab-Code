#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"Insert\n";
    int x,k;
    cin>>x>>k;
    for(int i=n-1;i>=k;i--)
        a[i+1]=a[i];

    a[k] = x;
    n++;

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"Delete\n";

    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            if(i==n-1)
                --n;
            else
            {
                for(int j=i;j<n-1;j++)
                {
                    a[j]=a[j+1];
                }
                --n;
            }

        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cin>>k;
    if(k==n-1) --n;
    else 
    {
        for(int i=k;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        --n;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}