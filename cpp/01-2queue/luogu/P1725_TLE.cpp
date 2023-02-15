# include <bits/stdc++.h>
using namespace std;
int f[200001]; // f[i] when reaching i, the maximum score
int a[200001]; // a[i] the score at i
int main()
{
    int N, L, R; scanf("%d%d%d", &N, &L, &R);
    for(int i=0; i<=N; i++) scanf("%d", &a[i]);
    memset(f,-127,sizeof(f));
    f[0] = 0;
    int ans = -10000;
    for(int i=1; i<=N; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(j + L > i) continue;
            else if(j + R < i) break;
            f[i] = max(f[i], f[j] + a[i]);
        }
        if((i + R) > N) ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}