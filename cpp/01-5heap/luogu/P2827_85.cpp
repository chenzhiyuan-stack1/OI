# include<bits/stdc++.h>
using namespace std;
priority_queue< int, vector<int>, less<int> > mq;
int a[100001];
int offset = 0;
int main()
{
    int n, m, q, u, v, t;
    cin >> n >> m >> q >> u >> v >> t;
    double p = (double)u / v;
    for(int i=1; i<=n; i++) {cin >> a[i]; mq.push(a[i]);}
    for(int i=1; i<=m; i++)
    {
        int length = mq.top() + offset;
        mq.pop();
        if(i % t == 0) cout << length << ' ';
        int length1 = floor(p * (double)length);
        int length2 = length - length1;
        mq.push(length1 - offset - q);
        mq.push(length2 - offset - q);
        offset += q;
    }
    cout << '\n';
    int cur = 1;
    while(!mq.empty())
    {
        int length = mq.top();
        mq.pop();
        if(cur % t == 0) cout << length + offset << ' ';
        cur++;
    }
    return 0;
}