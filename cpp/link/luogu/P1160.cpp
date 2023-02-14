# include <bits/stdc++.h>
using namespace std;
struct T
{
    int l, r, d;
}t[100001] = {0};
int main()
{
    int N; scanf("%d", &N);
    int head = 1;
    t[1].l = -1;
    t[1].r = -1;
    t[1].d = 1;
    for(int i=2; i<=N; i++)
    {
        int k, p; scanf("%d%d", &k, &p);
        t[i].d = 1;
        if(p == 0)
        {
            int l = t[k].l;
            t[i].r = k;
            t[i].l = l;
            t[k].l = i;
            if(l == -1) head = i;
            else t[l].r = i;
        }
        else if(p == 1)
        {
            int r = t[k].r;
            t[i].l = k;
            t[i].r = r;
            t[k].r = i;
            if(r != -1) t[r].l = i;
        }
    }
    int M; scanf("%d", &M);
    for(int i=1; i<=M; i++)
    {
        int x; scanf("%d", &x);
        if(t[x].d != 1) continue;
        t[x].d = 0;
        int l = t[x].l;
        int r = t[x].r;
        if(l == -1 && r == -1) head = -1;
        else if(l == -1 && r != -1)
        {
            head = r;
            t[r].l = l;
        }
        else if(l != -1 && r == -1) t[l].r = r;
        else
        {
            t[l].r = r;
            t[r].l = l; 
        }
    }
    int cur = head;
    while(cur != -1)
    {
        cout << cur << " ";
        cur = t[cur].r;
    }
    return 0;
}