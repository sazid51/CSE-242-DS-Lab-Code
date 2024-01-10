#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,t=0;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int num;
    cin>>num;
    for(int i=0;i<n;i++)
    {
        if(v[i]==num)
        {
            cout<<"Found"<<endl;
            t++;
            break;
        }
        
    }
    if(t==0)
        cout<<"Not Found"<<endl;
}