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
    else return -1;

}
string InfixToPostfix (string s)
{
    string result="";
    stack<char>st;
    st.push('(');
    s+=')';
    int pos =0;
    while( !st.empty())
    {
        char ch = s[pos];
        if(ch >= '0' && ch <= '9')
            result+=ch;

        else if(ch == '(')
            st.push('(');
         
        else if(ch==')'){
            while(st.top() != '('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while( !st.empty() && precedence(ch) <= precedence(st.top())){
                result+=st.top();
                st.top();
            }
            st.push(ch);  
        } 

        pos++;
    }
    return result;
}

int main()
{
    string X;
    cin>>X;
    cout<<InfixToPostfix(X)<<endl;
}