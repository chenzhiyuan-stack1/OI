# include<bits/stdc++.h>
using namespace std;
char maketree(string s)
{
    if(s.length() == 1)
    {
        if(s == "0") return 'B';
        else return 'I';
    }
    else
    {
        cout << maketree(s.substr(0, s.length()/2));
        cout << maketree(s.substr(s.length()/2, s.length()/2));
        if (s == string(s.length(), '0')) return 'B';
	    if (s == string(s.length(), '1')) return 'I';
	    return 'F';
    }
}
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    cout << maketree(s);
    return 0;
}