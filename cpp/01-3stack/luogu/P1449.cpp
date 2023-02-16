# include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    char op;
    int now = 0;
    while((op = getchar()) != '@')
    {
        if(op >= '0' && op <= '9') now = now * 10 + (op - '0');
        else if(op == '.')
        {
            st.push(now);
            now = 0;
        }
        else if(op == '+')
        {
            int l=0, r=0;
            if(!st.empty()) {r = st.top();st.pop();}
            if(!st.empty()) {l = st.top();st.pop();}
            st.push(l+r);
        }
        else if(op == '*')
        {
            int l=0, r=0;
            if(!st.empty()) {r = st.top();st.pop();}
            if(!st.empty()) {l = st.top();st.pop();}
            st.push(l*r);
        }
        else if(op == '-')
        {
            int l=0, r=0;
            if(!st.empty()) {r = st.top();st.pop();}
            if(!st.empty()) {l = st.top();st.pop();}
            st.push(l-r);
        }
        else if(op == '/')
        {
            int l=0, r=0;
            if(!st.empty()) {r = st.top();st.pop();}
            if(!st.empty()) {l = st.top();st.pop();}
            st.push(l/r);
        }
    }
    int ans = 0;
    if(!st.empty()) ans = st.top();
    printf("%d", ans);
    return 0;
}