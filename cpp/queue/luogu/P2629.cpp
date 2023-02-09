# include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int s[2000001];
bool flag[20000001];
int main()
{
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &s[i]);
        flag[i] = true;
    }
    for(int i=1; i<=n; i++) s[i+n] = s[i];
    for(int i=1; i<(2*n); i++) s[i+1] = s[i] + s[i+1];
    for(int i=n; i>=1; i--)
    {
        while(!dq.empty() && s[dq.back()] >= s[i+n]) dq.pop_back();
        dq.push_back(i+n);
    }
    for(int i=n; i>=1; i--)
    {
        while(!dq.empty() && dq.front() > i+n) dq.pop_front();
        if(!dq.empty() && (s[dq.front()] - s[i]) < 0) flag[(i % n) + 1] = false;
        while(!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(flag[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}