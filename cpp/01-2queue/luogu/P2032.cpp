# include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int s[2000001];
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &s[i]);
    for(int i=1; i<=n; i++)
    {
        while(!dq.empty() && dq.front() <= (i-k)) dq.pop_front();
        while(!dq.empty() && s[dq.back()] < s[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k) printf("%d\n", s[dq.front()]);
    }
    return 0;
}