#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qe;
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.push(5);

    while(!qe.empty())
    {
        cout<<qe.front()<<" ";
        qe.pop();
    }

}