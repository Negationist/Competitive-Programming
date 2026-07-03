#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    string s;
    cin >> s;
    FOR (i,s.size()){
        if (s[i] == '0'){
          s.erase(i,1) ;
          cout << s;
          return 0;
        }
    }
    s.erase(1,1);
    cout << s;

    return 0;
}
