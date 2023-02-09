# include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main()
{
    int t; cin >> t;
    for(int i=1; i<=t; i++)
    {
        int n; cin >> n;
        int maxsum = -INF;
        int start = 1, end = 1, p = 1;
        int sum = 0;
        for(int j=1; j<=n; j++)
        {
            int a; cin >> a; sum += a;
            if(sum > maxsum){maxsum = sum; start = p; end = j;}
            if(sum < 0){sum = 0; p = j + 1;}
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n", maxsum, start, end);
        if(i != t) cout << endl;
    }
}