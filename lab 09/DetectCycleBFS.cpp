#include <bits/stdc++.h>   
using namespace std; 
vector<int> graph[1000];
bool visited[1000];
  
bool IsCycle(int x) 
{ 
    queue<pair<int,int> > q; 
  
    q.push({x,-1}); //Marking -1 as x has no parent
    visited[x] = true; 
  
    while (!q.empty()) 
    {   
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : graph[node]) 
        { 
            if (!visited[it]) { 
                q.push({it,node}); 
                visited[it] = true;
            }
            else if(parent != it)
                return true;
        }    
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
            if(IsCycle(i))
                frog=true;
        }
    }
    if(frog) cout<<"Cycle is present\n";
    else cout<<"Cycle is not present\n";
}