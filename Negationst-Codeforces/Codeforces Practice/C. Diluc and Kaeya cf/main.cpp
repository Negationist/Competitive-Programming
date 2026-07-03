#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pii,int> cnt;
    pii cur = {0,0};
    for(int i=0;i<n;i++){
        if(s[i]=='D'){
            cur.ff++;
        } else cur.ss++;
        int x = cur.ff;
        int y = cur.ss;
        int z = gcd(x,y);
        x/=z;
        y/=z;
        cout << ++cnt[{x,y}] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
