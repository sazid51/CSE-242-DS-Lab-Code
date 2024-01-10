#include <bits/stdc++.h>   
using namespace std; 
vector<int> graph[1000];
bool visited[1000]; 
  
void bfs(int x) 
{ 
    queue<int> q; 
  
    q.push(x); 
    visited[x] = true; 
  
    while (!q.empty()) 
    {   
        cout<<q.front()<<" "; 
        for (auto it : graph[q.front()]) 
        { 
            if (!visited[it]) { 
                q.push(it); 
                visited[it] = true;
            } 
        }
        q.pop();
    }
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
  
    for (int i=0;i<n;i++) { 
        if (!visited[i]) 
            bfs(i); 
    }
    cout<<endl;
}