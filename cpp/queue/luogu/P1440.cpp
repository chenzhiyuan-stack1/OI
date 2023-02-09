# include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int s[2000001];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%d", &s[i]);
    for(int i=1; i<=n; i++)
    {
        while(!dq.empty() && dq.front() < i-m) dq.pop_front();
        if(dq.empty()) printf("0\n");
        else printf("%d\n", s[dq.front()]);
        while(!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
    }
    return 0;
}
