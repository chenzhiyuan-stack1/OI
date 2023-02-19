# include<bits/stdc++.h>
using namespace std;
stack<int> num, data2;
stack<char> op, data;
int check(char a)
{
    switch(a)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        case ')': return 0;
        default: return -1;
    }
}
int js(int a, int b, char c)
{
    switch(c)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
        default: return -0x3f3f3f3f;
    }
}
void change(string s)
{
    int len = s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9') data.push(s[i]);
        else if(s[i] == '(') op.push('(');
        else if(s[i] == ')')
        {
            while(!op.empty() && op.top() != '('){data.push(op.top()); op.pop();}
            if(!op.empty()) op.pop();
        }
        else if(check(s[i]) >=1 && check(s[i]) <=2)
        {
            while(!op.empty() && check(op.top()) >= check(s[i])){data.push(op.top()); op.pop();}
            op.push(s[i]);
        }
        else if(check(s[i]) == 3) op.push(s[i]);
    }
    while(!op.empty())
    {
        data.push(op.top());
        op.pop();
    }
    while(!data.empty())
    {
        op.push(data.top());
        data.pop();
    }
    while(!op.empty())
    {
        data.push(op.top());
        cout << op.top() << ' ';
        op.pop();
    }
    cout<<endl;
}
void calc()
{
    while(!data.empty()){op.push(data.top()); data.pop();}
    while(!op.empty())
    {
        char cur = op.top();
        op.pop();
        if(cur >= '0' && cur <= '9') num.push(cur - '0');
        else
        {
            int x = num.top();
            num.pop();
            int y = num.top();
            num.pop();
            num.push(js(y,x,cur));
            while(!num.empty())
			{
				data2.push(num.top());
				num.pop();
			}
            while(!data2.empty())
            {
                num.push(data2.top());
                cout << data2.top() << ' ';
                data2.pop();
            }
            while(!op.empty())
			{
				data.push(op.top());
				cout<<op.top()<<' ';
				op.pop();
			}
			while(!data.empty())
			{
				op.push(data.top());
				data.pop();
			}
			cout<<endl;
        }
    }
}
int main()
{   
    string s;
	cin>>s;   
	change(s);
	calc();
	return 0;
}