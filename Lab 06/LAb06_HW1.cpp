// Round-Robin CPU scheduling using Queue
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,t,c;
    cin>>n>>t>>c;
    queue<int>qe;
    for(int i=0;i<n;++i) qe.push(t);

    int process_number=0; 
    int count=0; 
    t=t-c;
    while(qe.front()>0)  
    {
       count++;
       qe.pop();
       qe.push(t);
       if(count==n)
       {
            process_number++;
            t=t-c;
            count=0;
       }

    }
    cout<<"Total umber of Process Required: "<<process_number<<endl;
    cout<<"\n\n";
}