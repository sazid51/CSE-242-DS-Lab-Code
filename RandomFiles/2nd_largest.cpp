#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100],mx1,mx2;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    if(a[0]>a[1]){
        mx1=a[0]; mx2=a[1];
    }
    else{
        mx1=a[1]; mx2=a[0];
    }

    for(int i=2;i<n;i++)
    {
        if(a[i]>mx1)
        {
            mx2=mx1;
            mx1=a[i];
        }
        else if(a[i]>mx2)
        {
            mx2 = a[i];
        }
    }

    cout<<"First & Second largest element of Array: "<<mx1<<" & "<<mx2<<endl;
}