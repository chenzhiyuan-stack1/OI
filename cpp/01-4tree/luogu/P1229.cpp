# include<bits/stdc++.h>
using namespace std;
int cal(string s1, string s2)
{
    if(s1.length() == 0) return 2;
    if(s1.length() == 1) return 1;
    char lhead = s1[1];
    int k = s2.find(lhead);
    string ls1 = s1.substr(1, k+1);
    string ls2 = s2.substr(0, k+1);
    string rs1 = s1.substr(k+2, s1.length()-k-2);
    string rs2 = s2.substr(k+1, s1.length()-k-2);
    return cal(ls1, ls2) * cal(rs1, rs2);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    printf("%d", cal(s1, s2));
    return 0;
}