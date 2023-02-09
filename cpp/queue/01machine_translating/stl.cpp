# include <bits/stdc++.h>
using namespace std;
int Hash[1003]={0};
queue<int> mem;
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    int cnt = 0;
    while (n--)
    {
        int en; scanf("%d", &en);
        int cnt = 0;
        while (!Hash[en])
        {
            ++cnt;
            mem.push(en);
            Hash[en] = 1;
            while(mem.size()>m)
            {
                Hash[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}