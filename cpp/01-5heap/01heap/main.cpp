# include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int heap[N], len = 0;

void push(int x)
{
    heap[++len] = x;
    int i = len;
    while(i > 1 && heap[i] < heap[i/2])
    {
        swap(heap[i], heap[i/2]);
        i /= 2;
    }
}

void pop()
{
    heap[1] = heap[len--];
    int i = 1;
    while(i * 2 <= len)
    {
        int son = 2 * i;
        if(son < len && heap[son + 1] < heap[son]) son++;
        if(heap[son] < heap[i])
        {
            swap(heap[i], heap[son]);
            i = son;
        }
        else break;
    }
}

int main()
{
    int n; scanf("%d", &n);
    while(n--)
    {
        int op; scanf("%d", &op);
        if(op == 1){int x; scanf("%d", &x); push(x);}
        else if(op == 2) printf("%d\n", heap[1]);
        else pop();
    }
    return 0;
}