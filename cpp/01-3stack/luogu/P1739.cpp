# include<bits/stdc++.h>
using namespace std;
int main()
{
    char op;
    stack<char> st;
    while((op = getchar()) != '@')
    {
        if(op == '(') st.push('1');
        if(op == ')')
        {
            if(!st.empty()) st.pop();
            else{cout << "NO"; return 0;}
        }
    }
    if(!st.empty()) cout << "NO";
    else cout << "YES";
    return 0;
}