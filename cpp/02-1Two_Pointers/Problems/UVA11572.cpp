# include<bits/stdc++.h>
using namespace std;
int a[1000005], last[1000005];
unordered_map<int, int> vis;
int main()
{
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++)
        {
            if(!vis[a[i]]) last[i] = -1;
            else last[i] = vis[a[i]];
            vis[a[i]] = i;
        }
        int l = 1, r = 1, ans = -1e9;
        while(r <= n)
        {
            while(r <= n && l > last[r]) r++;
            ans = max(ans, r - l);
            l++;
        }
        cout << ans << endl;
        vis.clear();
    }
    return 0;
}