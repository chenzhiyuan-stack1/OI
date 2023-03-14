# include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node
{
    int c;
    long long n;
} a[100005];

bool com(node const a, node const b)
{
    return a.n < b.n;
}

int main()
{
    while(true)
    {
        int n, k; cin >> n >> k;
        if(n == 0 && k == 0) break;
        a[0].n = 0; a[0].c = 0;
        for(int i=1; i<=n; i++) {cin >> a[i].n; a[i].c = i;}
        for(int i=2; i<=n; i++) {a[i].n = a[i].n + a[i-1].n;}
        sort(a,a+1+n, com); // 从小到大
        for(int i=1; i<=k; i++)
        {
            long long t; cin >> t;
            int j = 0, k = 1;
            long long ans = inf;
            long long result = a[1].n - a[0].n;
            int l = 1, r = a[1].c;
            long long sum;
            while(j<=n)
            { 
                sum = a[k].n - a[j].n;
                if(sum < t)
                {
                    if(ans > t - sum)
                    {
                        ans = t - sum; 
                        l = min(a[j].c, a[k].c) + 1; 
                        r = max(a[j].c, a[k].c);
                        result = sum;
                    }
                    if(k+1 <= n) k++;
                    else break;
                }
                else if(sum == t)
                {
                    ans = 0;
                    l = min(a[j].c, a[k].c) + 1; 
                    r = max(a[j].c, a[k].c);
                    result = sum;
                    break;
                }
                else
                {
                    if(ans > sum - t)
                    {
                        ans = sum - t;
                        l = min(a[j].c, a[k].c) + 1; 
                        r = max(a[j].c, a[k].c);
                        result = sum;
                    }
                    j++;
                    if(j>=k) k=j+1;
                    if(k>n) break;
                }
            }
            cout << result << ' ' << l << ' ' << r << '\n';
        }
    }
    return 0;
}