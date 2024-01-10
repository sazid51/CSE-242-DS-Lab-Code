#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int i,j,k;
    queue<int> qe;
    while(1)
    {
        int choice,x;
        cout<<"Enter Choice: ";
        cin>>choice;
        if(choice==1){
            cin>>x;
            qe.push(x);
        }
        else if(choice == -1)
            qe.pop();
        
        else cout<<qe.front()<<endl;
    }
}