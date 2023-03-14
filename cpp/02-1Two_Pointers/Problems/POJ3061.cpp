# include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int t; cin >> t;
    for(int i=1; i<=t; i++)
    {
        int N, S; cin >> N >> S;
        for(int j=1; j<=N; j++) cin >> a[j];
        int ans = N + 1;
        int j = 1, k = 1;
        int sum = a[1];
        while(j<=N)
        {
            if(sum < S)
            {
                if(k+1 <= N) {k++; sum += a[k];}
                else break;
            }
            else
            {
                ans = min(ans, k-j+1);
                sum -= a[j];
                j++;
            }
        }
        if(ans == N+1) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}