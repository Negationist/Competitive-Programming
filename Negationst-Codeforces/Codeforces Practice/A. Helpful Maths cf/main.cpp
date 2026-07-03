#include <bits/stdc++.h>
using namespace std;



int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    s.erase(0,s.size()/2);
    for (int i=1;i<s.size();i+=2)s.insert(i,"+");
    cout << s;
}
