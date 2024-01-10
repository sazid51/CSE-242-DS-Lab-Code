#include <bits/stdc++.h>   
using namespace std; 
vector<int> graph[1000];
bool visited[1000];
  
bool IsCycle(int x,int parent) 
{
    visited[x] = true;
    for(auto it:graph[x])
    {
        if(!visited[it])
        {
            if(IsCycle(it,x))
                return true;
        }
        else if(it!=parent)
            return true;
    }
    
    return false;
}

int main() 
{ 
    int n, e;
    cout<<"Number of Nodes and Edges: "; 
    cin>>n>>e;
    int a, b; 
    for (int i=0;i<e;i++) { 
        cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    bool frog;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(IsCycle(i,-1))
                frog=true;
        }
    }
    if(frog) cout<<"Cycle is present\n";
    else cout<<"Cycle is not present\n";
}