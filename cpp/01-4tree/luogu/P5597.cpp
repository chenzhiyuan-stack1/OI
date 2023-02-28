# include<bits/stdc++.h>
using namespace std;
struct node
{
    int l, r;
}tre1[3000], tre2[3000];

int size1 = 0, size2 = 0;
int pos1, pos2;
int ans = 1e9;

int input()
{
    char c = getchar();
    int u = ++size1;
    if(c == '0') {tre1[u].l = 0; tre1[u].r = 0;}
    if(c == '1') {tre1[u].l = input(); tre1[u].r = 0;}
    if(c == '2') {tre1[u].l = 0; tre1[u].r = input();}
    if(c == '3') {tre1[u].l = input(); tre1[u].r = input();}
    return u;
}

void compare(int u, int v)
{
    if(u == pos1) {pos2 = v; v = 1;} // the first time reach pos1 in tre1, should set pos2
    if(v == pos2) {v = 1;}
    if(tre1[u].l)
    {
        if(!tre2[v].l) tre2[v].l = ++size2;
        compare(tre1[u].l, tre2[v].l);
    }
    if(tre1[u].r)
    {
        if(!tre2[v].r) tre2[v].r = ++size2;
        compare(tre1[u].r, tre2[v].r);
    }
}

void find_u(int u, int depth)
{
    memset(tre2,0,sizeof tre2);//清空
    pos1 = u; // the end of the node to be compared in tre1
    pos2 = 0; // the end of the node to be compared in tre2(now this is unknowwn, set to 0)
    size2 = 1;
    compare(1, 1);
    ans = min(ans, 2*size2-2-depth);
    if(tre1[u].l) find_u(tre1[u].l, depth+1);
    if(tre1[u].r) find_u(tre1[u].r, depth+1);
}

int main()
{
    input();
    find_u(1, 0);
    cout << ans << endl;
    return 0;
}