# include<bits/stdc++.h>
using namespace std;
int p[1000001];
void findsum(int *a, int n, int s)
{
    int i = 0, j = 0;
    int sum = a[0];
    while(j < n)
    {
        if(sum >= s)
        {
            if(sum == s) printf("%d %d\n", i, j);
            sum -= a[i];
            i++;
            if(i>j) j++;
        }
        if(sum < s){j++; sum += a[j];}
    }
}
int main()
{
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    int s; cin >> s;
    findsum(p, n, s);
    return 0;
}