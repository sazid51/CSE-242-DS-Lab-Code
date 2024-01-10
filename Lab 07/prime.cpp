#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"2 3 ";
    for(int i=5;i<=n;i+=2)
    {
        bool flag=false; 
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<i<<" ";
    }
    cout<<"\n\n";
}