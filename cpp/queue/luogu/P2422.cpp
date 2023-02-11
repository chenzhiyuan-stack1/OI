# include <bits/stdc++.h>
using namespace std;
deque<int> dq;
long long s[100001];
long long sum[100001];
int l[100001];
int r[100001];
int main()
{
    int N; scanf("%d", &N);
    int tmp;
    for(int i=1; i<=N; i++) scanf("%lld", &s[i]);
    for(int i=1; i<=N; i++) sum[i] = s[i];
    for(int i=1; i<N; i++) sum[i+1] = sum[i+1] + sum[i];
    sum[0] = 0;
    // find left
    for(int i=1; i<=N; i++)
    {
        while(!dq.empty() && s[dq.back()] > s[i])
        {
            tmp = dq.back();
            dq.pop_back();
        }
        if(dq.empty()) l[i] = 0;
        else l[i] = dq.back();
        dq.push_back(i);
    }

    while(!dq.empty()) dq.pop_back();

    // find right
    for(int i=N; i>=1; i--)
    {
        while(!dq.empty() && s[dq.back()] > s[i])
        {
            tmp = dq.back();
            dq.pop_back();
        }
        if(dq.empty()) r[i] = N + 1;
        else r[i] = dq.back();
        dq.push_back(i);
    }
    long long ans = 0;
    for(int i=1; i<=N; i++) ans = max(ans, (sum[r[i] - 1] - sum[l[i]]) * s[i]);
    printf("%lld", ans);
    return 0;
}