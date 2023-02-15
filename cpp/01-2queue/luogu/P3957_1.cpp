# include <bits/stdc++.h>
using namespace std;
long long f[500005],a[500005][2],n,d,k,ok,lpos,rpos;

// check if money g is ok
bool check(int g)
{
    deque<int> dq;
    lpos = d - g;
    rpos = d + g;
    if(lpos <= 0) lpos = 1;
    memset(f,-127,sizeof(f));
    f[0] = 0;
    a[0][0] = 0;
    int cur = 0;
    // go to i and find if score is greater than k 
    for(int i=1; i<=n; i++)
    {
        while(a[i][0] - a[cur][0] >= lpos)
        {
            while(!dq.empty() && f[dq.back()] < f[cur]) dq.pop_back();
            dq.push_back(cur);
            cur++;
        }

        while(!dq.empty() && (a[i][0] - a[dq.front()][0]) > rpos) dq.pop_front();

        if(!dq.empty()) f[i] = a[i][1] + f[dq.front()];
        else f[i] = -999999999999;
        if(f[i] >= k) return 1;
    }
    return 0;
}

int main()
{
    int i,ans=-1,l,r,m;
    scanf("%lld%lld%lld", &n, &d, &k);
    for(i=1; i<=n; i++) scanf("%lld%lld", &a[i][0], &a[i][1]);
    l = 0;
    r = 1005;
    m = (l + r) / 2;
    while(l <= r)
    {
        if(check(m))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
        m = (l + r) / 2;
    }
    cout << ans;
    return 0;
}