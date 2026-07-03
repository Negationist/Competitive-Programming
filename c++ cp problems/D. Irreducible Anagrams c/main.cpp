#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    s = '+'+s;
    int cnt[n+1][26] = {};
    for(int i=1;i<=n;i++){
        int x = (int)(s[i]-'a');
        for(int j=0;j<26;j++){
            cnt[i][j] = cnt[i-1][j]+(x==j);
        }
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        int num = 0;
        for(int i=0;i<26;i++){
            num+=(cnt[r][i]-cnt[l-1][i]>0);
        }
        if(s[l]!=s[r] || r==l || num>2){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
