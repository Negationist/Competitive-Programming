#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int sum = 0;
    int n;
    cin >> n;
    vector<string> s(2);
    FOR(i,2){
        string str;
        cin >> str;
        s[i] = str;
    }
    for(int i=1;i<n-1;i++){
            bool add = true;
            add &= (s[0][i] == '.' && s[1][i] == '.');
            add &= (s[0][i-1] != s[1][i-1]);
            add &= (s[0][i+1] != s[1][i+1]);
            add &= (s[0][i-1] == s[0][i+1]);
            sum+= add;
    }
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
