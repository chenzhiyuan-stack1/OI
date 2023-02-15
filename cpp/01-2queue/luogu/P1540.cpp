# include <bits/stdc++.h>
using namespace std;
queue<int> mem;
int Hash[1003] = {0};
int main()
{
    int m,n; scanf("%d%d", &m, &n);
    int cnt = 0;
    while(n--)
    {
        int en; scanf("%d", &en);
        if(!Hash[en])
        {
            ++cnt;
            mem.push(en);
            Hash[en] = 1;
            while(mem.size() > m)
            {
                Hash[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    printf("%d", cnt);
    return 0;
}