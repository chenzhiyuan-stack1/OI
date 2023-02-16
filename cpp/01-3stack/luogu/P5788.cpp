# include<bits/stdc++.h>
using namespace std;
int a[3000001];
int ans[3000001];
stack<int> st;
int main()
{
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=n; i>=1; i--)
    {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = 0;
        st.push(i);
    }
    for(int i=1; i<=n; i++) printf("%d ",ans[i]);
    return 0;
}