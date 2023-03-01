# include<bits/stdc++.h>
using namespace std;
struct node
{
    long long w, h;
    node(){w=0; h=0;}
    node(long long w, long long h):w(w), h(h){}
    bool operator <(const node &a)const
    {
        if(a.w == w) return a.h < h;
        else return a.w < w;
    }
};

long long ans;

priority_queue<node> q;

int main()
{
    long long n, k;
    ans = 0;
    scanf("%lld%lld",&n,&k);
    for(int i=1; i<=n; i++)
    {
        long long w;
        scanf("%lld",&w);
        q.push(node(w, 1));
    }
    while((q.size() - 1) % (k-1) != 0) q.push(node(0, 1));
    while(q.size() >= k)
    {
        long long h = -1, w = 0;
        for(int i=1; i<=k; i++)
        {
            w += q.top().w;
            h = max(h, q.top().h);
            q.pop();
        }
        ans += w;
        q.push(node(w, h+1));
    }
    printf("%lld\n%lld\n",ans,q.top().h-1);
    return 0;
}