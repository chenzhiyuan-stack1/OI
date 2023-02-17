# include<bits/stdc++.h>
using namespace std;
int main()
{
    char op;
    int now = 0;
    bool times = false;
    stack<int> st;
    while(true)
    {
        op = getchar();
        if(op >= '0' && op <= '9')
        {
            now = now * 10 + op - '0';
            continue;
        }
        st.push(now);
        now = 0;
        if(times == true)
        {
            int l = st.top();
            st.pop();
            int r = st.top();
            st.pop();
            st.push((l * r) % 10000);
            times = false;
        }
        if(op == '*') times = true;
        if(op == '\n') break;
    }
    while(!st.empty())
    {
        int l = st.top();
        st.pop();
        if(st.empty())
        {
            printf("%d", l % 10000);
            return 0;
        }
        else
        {
            int r = st.top();
            st.pop();
            st.push((l + r) % 10000);
        }
    }
    return 0;
}