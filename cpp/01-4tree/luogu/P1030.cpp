# include<bits/stdc++.h>
using namespace std;
void head_first(string s1, string s2)
{
    if(s2.length() == 0) return;
    char head = s2[s2.length()-1];
    cout << head;
    if(s2.length() > 1)
    {
        int k = s1.find(head);
        head_first(s1.substr(0,k), s2.substr(0,k));
        head_first(s1.substr(k+1), s2.substr(k,s2.length()-k-1));
    }
    return;
}
int main()
{
    string s1, s2; cin >> s1 >> s2;
    head_first(s1, s2);
    return 0;
}