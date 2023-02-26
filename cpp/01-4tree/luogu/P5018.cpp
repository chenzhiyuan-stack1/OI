# include<bits/stdc++.h>
using namespace std;
struct node
{
    int l, r;
    int v;
};
node t[1000001];
bool judge(int head1, int head2)
{
    if(head1 == -1 && head2 == -1) return true;
    else if(head1 == -1 || head2 == -1) return false;
    if(t[head1].v != t[head2].v) return false;
    else return(judge(t[head1].l, t[head2].r) && judge(t[head1].r, t[head2].l));
}
int count(int head)
{
    if(head == -1) return 0;
    else return 1 + count(t[head].l) + count(t[head].r);
}
int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i].v;
    for(int i=1; i<=n; i++) cin >> t[i].l >> t[i].r;
    int ans = 1;
    for(int i=1; i<=n; i++)
    {
        if(t[i].l == -1 && t[i].r == -1) ans = max(ans, 1);
        else if(judge(t[i].l, t[i].r)) ans = max(ans, count(i));
    }
    cout << ans;
    return 0;
}