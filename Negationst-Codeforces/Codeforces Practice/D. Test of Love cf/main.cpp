#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,m,k;
string s;

string solve(int i,int d){
    int most = i+m;
    if(most>=n+1) return "YES";
    int pos = i+1;
    while(pos<n){
        if(s[pos]=='L') break;
        pos++;
    }


}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cin >> s;
        cout << solve(0,0) << endl;
    }
    return 0;
}
