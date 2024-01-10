#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int precedence(char c)
{
    if( c== '^') return 3;
    else if(c == '*' || c=='/')
        return 2;
    else if(c== '+' || c=='-')
        return 1;
    else return 0;

}

int Operation(int a, int b, char c)
{
        if (c== '+') return a+b;
        else if(c=='-') return a-b;
        else if(c=='*') return a*b;
        else if(c=='/') return a/b;
        else if(c=='^') return pow(a,b);
}
int EvalutionInfix (string s)
{
    stack <int> value;
    stack <char> oprtr;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            int val = 0;
            while(i<s.size() && isdigit(s[i]))
            {
                val = (val*10) + (s[i]-'0');
                i++;
            }
            value.push(val);
            i--;
        }

        else if(s[i] == '(')
            oprtr.push(s[i]);
         
        else if(s[i]==')')
        {
            while(oprtr.top() != '(' && !oprtr.empty())
            {
                int val2 = value.top();
                value.pop();
                int val1 = value.top();
                value.pop();

                char op = oprtr.top();
                oprtr.pop();

                value.push(Operation(val1, val2, op));
            }
            if(!oprtr.empty())
                oprtr.pop();
        }

        else{
            while( !oprtr.empty() && precedence(s[i]) <= precedence(oprtr.top()))
            {
                int val2 = value.top();
                value.pop();
                int val1 = value.top();
                value.pop();

                char op = oprtr.top();
                oprtr.pop();

                value.push(Operation(val1, val2, op));
            }
            oprtr.push(s[i]);  
        } 
    }

    while(!oprtr.empty())
    {
        int val2 = value.top();
        value.pop();
        int val1 = value.top();
        value.pop();

        char op = oprtr.top();
        oprtr.pop();

        value.push(Operation(val1, val2, op));
    }

    return value.top();
}

int main()
{
    string X;
    cin>>X;
    cout<<EvalutionInfix(X)<<endl;
}