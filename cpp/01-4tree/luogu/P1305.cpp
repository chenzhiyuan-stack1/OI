# include<bits/stdc++.h>
using namespace std;
struct node
{
    char lc, rc;
};
node tree[1000];
void work(char s)
{
    printf("%c", s);
    if(tree[s].lc != '*') work(tree[s].lc);
    if(tree[s].rc != '*') work(tree[s].rc);
    return;
}
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    char head = s[0];
    tree[head].lc = s[1];
    tree[head].rc = s[2];
    for(int i=2; i<=n; i++)
    {
        cin >> s;
        tree[s[0]].lc = s[1];
        tree[s[0]].rc = s[2];
    }
    work(head);
    return 0;
}