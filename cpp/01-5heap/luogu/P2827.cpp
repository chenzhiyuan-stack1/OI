# include<bits/stdc++.h>
using namespace std;

int a1[7000005], a2[7000005], a3[7000005];
int offset = 0;

priority_queue<int>ans;

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int n, m, q, u, v, t;
    cin >> n >> m >> q >> u >> v >> t;
    double p = (double)u / v;
    int tail1 = n, tail2 = 0, tail3 = 0;
    int head1 = 1, head2 = 1, head3 = 1;
    for(int i=1; i<=n; i++) cin >> a1[i];
    sort(a1+1,a1+n+1,cmp); // 大到小
    for(int i=1; i<=m; i++)
    {
        int length = 0;
        if(head1 > tail1)
        {
            if(a2[head2] > a3[head3])
            {
                length = a2[head2] + offset;
                head2++;
            }
            else
            {
                length = a3[head3] + offset;
                head3++;
            }
        }
        else if(a1[head1] >= a2[head2] && a1[head1] >= a3[head3])
        {
            length = a1[head1] + offset;
            head1++;
        }
        else if(a2[head2] > a3[head3])
        {
            length = a2[head2] + offset;
            head2++;
        }
        else
        {
            length = a3[head3] + offset;
            head3++;
        }
        int tmp1 = floor(p * (double)length);
        int tmp2 = length - tmp1;
        a2[++tail2] = tmp1 - q - offset;
        a3[++tail3] = tmp2 - q - offset;
        offset += q;
        if(i % t == 0) cout << length << ' ';
    }
    cout << '\n';
    for(int i=head1; i<=tail1; i++) ans.push(a1[i]);
    for(int i=head2; i<=tail2; i++) ans.push(a2[i]);
    for(int i=head3; i<=tail3; i++) ans.push(a3[i]);
    for(int i=1; !ans.empty(); i++)
    {
        if(i % t == 0) cout << ans.top() + offset << ' ';
        ans.pop();
    }
    return 0;
}