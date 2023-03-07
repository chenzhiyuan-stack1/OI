# include<bits/stdc++.h>
using namespace std;

priority_queue< int, vector<int>, greater<int> > q1;
priority_queue< pair<int, int>, vector< pair<int, int> >,  greater< pair<int, int> > > q2, q3;
bool flag[50010];

struct Node
{
    int p, c;
}a[50010];

bool cmp(Node a, Node b)
{
    return a.c < b.c;
}

int main()
{
    int N, K; long long M; cin >> N >> K >> M;
    for(int i=1; i<=N; i++) cin >> a[i].p >> a[i].c;
    sort(a+1, a+N+1, cmp); // 小到大
    long long cur = 0;
    for(int i=1; i<=K; i++)
    {
        cur += a[i].c;
        if(cur > M){cout << i-1 << '\n'; return 0;}
        q1.push(a[i].p - a[i].c);
    }
    if(K == N){cout << N << '\n'; return 0;}
    for(int i=K+1; i<=N; i++)
    {
        q2.push(make_pair(a[i].c, i));
        q3.push(make_pair(a[i].p, i));
    }
    int ans = K;
    for(int i=K+1; i<=N; i++)
    {
        while(flag[q2.top().second]) q2.pop();
        while(flag[q3.top().second]) q3.pop();
        int p1 = q2.top().second;
        int p2 = q3.top().second;
        int tmp1 = q2.top().first + q1.top();
        int tmp2 = q3.top().first;
        if(tmp1 < tmp2)
        {
            cur += tmp1;
            q1.pop(); q2.pop();
            q1.push(a[p1].p - a[p1].c);
            flag[p1] = true;
        }
        else
        {
            cur += tmp2;
            q3.pop();
            flag[p2] = true;
        }
        ans++;
        if(cur > M){cout << ans - 1 << '\n'; return 0;}
    }
    cout << ans << '\n';
    return 0;
}