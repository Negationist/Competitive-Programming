#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int>n;
    string s;
    cin >> s;
    for (int i=0; i<s.size();i++){
        n.insert(s[i]);
    }
    if (n.size()%2==1){
        cout << "IGNORE HIM!";
    } else{
        cout << "CHAT WITH HER!";
    }
    return 0;
}
