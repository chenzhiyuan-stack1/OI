# include<bits/stdc++.h>
using namespace std;
priority_queue< int, vector<int>, less<int> > l;
priority_queue< int, vector<int>, greater<int> > r;
int main()
{
    int N; cin >> N;
    int mid; cin >> mid; cout << mid << '\n';
    l.push(0); r.push(1e9);
    for(int i=2; i<=(N+1)/2; i++)
    {
        int x, y; cin >> x >> y;
        if(x <= mid && y >= mid) {l.push(x); r.push(y);}
        else if(x <= mid && y < mid)
        {
            r.push(mid);
            int tmp = l.top();
            l.pop();
            mid = max(max(tmp, x), y);
            int small = min(min(tmp, x), y);
            l.push(small);
            l.push(tmp + x + y - small - mid);
        }
        else if(x > mid && y <= mid) {l.push(y); r.push(x);}
        else
        {
            l.push(mid);
            int tmp = r.top();
            r.pop();
            mid = min(min(tmp, x), y);
            int big = max(max(tmp, x), y);
            r.push(big);
            r.push(tmp + x + y - mid - big);
        }
        cout << mid << '\n';
    }
    if(N%2 == 0) cin >> mid;
    return 0;
}
