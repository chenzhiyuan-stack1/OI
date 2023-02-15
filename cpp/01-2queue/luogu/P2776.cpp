# include <bits/stdc++.h>
using namespace std;
int a[100000];
queue<int> q[300];
queue<int> p;
string str,pu="push",po="pop";
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int T; scanf("%d", &T);
    while(T--)
    {
        cin >> str;
        if(str == pu)
        {
            int num; scanf("%d", &num);
            if(q[a[num]].empty()) p.push(a[num]);
            q[a[num]].push(num);
        }
        else if(str == po)
        {
            int head;
            if(!p.empty())
            {
                head = p.front();
                if(!q[head].empty()) 
                {
                    printf("%d\n", q[head].front());
                    q[head].pop();
                    if(q[head].empty()) p.pop();
                }
            }     
        }
    }
}