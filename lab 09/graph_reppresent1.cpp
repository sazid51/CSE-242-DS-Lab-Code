#include<bits/stdc++.h>
using namespace std;
int main()
{
    int src, dest, vertics,edges;
    vector <int> adj[100];
    cin>>vertics>>edges;

    for(int i=0;i<edges;++i)
    {
        cin>>src>>dest;
        adj[src].push_back(dest); 
        adj[dest].push_back(src);
    }

    for(int i=0;i<vertics;++i)
    {   
        cout<<"Adjacency list of vertex "<<i;
        for(int j=0;j<adj[i].size();++j)
            cout<<"--> "<<adj[i][j];

        cout<<endl;
    }
    return 0;
}