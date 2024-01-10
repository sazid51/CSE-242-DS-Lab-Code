#include <bits/stdc++.h>   
using namespace std; 
vector<int> graph[1000];
bool visited[1000];

void dfs(int x)
{
    cout<<x<<" ";
    visited[x] = true;
    for(auto it: graph[x])
    {
        if(!visited[it])
            dfs(it);
    }
}

int main() 
{ 
    int n, e;
    cout<<"Number of Nodes and Edges: "; 
    cin>>n>>e;
    int a, b; 
    for (int i = 0; i < e; i++) { 
        cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a); 
    } 
  
    for (int i = 0; i < n; i++) { 
        if (!visited[i]) 
            dfs(i); 
    }
    cout<<endl;
}