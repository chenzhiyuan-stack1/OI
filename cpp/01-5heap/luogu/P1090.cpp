# include<bits/stdc++.h>
using namespace std;
priority_queue < int, vector<int>, greater<int> > q;
int ans = 0;
int main()
{
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int x; scanf("%d", &x);
        q.push(x);
    }
    while(q.size() >= 2)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans = ans + x + y;
        q.push(x+y);
    }
    printf("%d", ans);
    return 0;
}