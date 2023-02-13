# include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int f[200001]; // f[i] when reaching i, the maximum score
int a[200001]; // a[i] the score at i
int main()
{
    int N, L, R; scanf("%d%d%d", &N, &L, &R);
    for(int i=0; i<=N; i++) scanf("%d", &a[i]);
    memset(f,-127,sizeof(f));
    f[0] = 0;
    dq.push_back(0);
    int ans = -10000;
    for(int i=L; i<=N; i++)
    {
        // find the maximum f bewteen [i-R, i-L]
        while(!dq.empty() && dq.front() < i-R) dq.pop_front();
        while(!dq.empty() && f[dq.back()] < f[i-L]) dq.pop_back();
        dq.push_back(i-L);
        f[i] = a[i] + f[dq.front()];
        if(i + R > N) ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}