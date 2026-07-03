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
    int n,m,L;
    cin >> n >> m >> L;
    vii mx;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        mx.pb({l-1, r-l+2});
    }
    for(int i=1;i<n;i++){
        mx[i].second = max(mx[i].second,mx[i-1].second);
    }
    vii pw;
    priority_queue<int> usable;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(a==1) usable.push(b);
        else pw.pb({a,b});
    }
    int power = 1;
    int cnt = 0;
    int j=0;
    for(int i=0;i<n;i++){
        while(j<pw.size() && pw[j].first<=mx[i].first){
            usable.push(pw[j].second);
            j++;
        }
        if(power>=mx[i].second) continue;
        else{
            while(power<mx[i].second && !usable.empty()){
                power+=usable.top();
                usable.pop();
                cnt++;
            }
            if(power>=mx[i].second) continue;
            else{
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << cnt << "\n";
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
