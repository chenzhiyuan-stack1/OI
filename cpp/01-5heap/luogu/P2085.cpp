# include<bits/stdc++.h>
using namespace std;
int n, m;
int func[10004][4];
struct node
{
    int x, i, val;
    bool operator <(const node &a)const
    {
        return this->val < a.val;
    }
    bool operator >(const node &a)const
    {
        return this->val > a.val;
    }
};
priority_queue< node, vector<node>, greater<node> > q;
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> func[i][1] >> func[i][2] >> func[i][3];
        q.push((node){1, i, func[i][1] + func[i][2] + func[i][3]});
    }
    for(int i=1; i<=m; i++)
    {
        node tmp = q.top();
        q.pop();
        cout << tmp.val << ' ';
        q.push((node){tmp.x + 1, tmp.i, func[tmp.i][1] * (tmp.x + 1) * (tmp.x + 1) + func[tmp.i][2] * (tmp.x + 1) + func[tmp.i][3]});
    }
    return 0;
}