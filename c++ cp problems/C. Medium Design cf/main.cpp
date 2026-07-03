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
    int n,m;
    cin >> n >> m;
    vi f;
    vii i;
    bool extendo = false;
    while(n--){
        int l,r;
        cin >> l >> r;
        if(r==m) extendo = true;
        f.pb(l);
        f.pb(-1*(r+1));
        i.pb({l,r});
    }
    sort(f.begin(),f.end(),[](int a,int b){
        return abs(a)<abs(b);
    });
    int mx = -1;
    int sum = 0;
    int pos;
    for(int i=0;i<f.size();i++){
        if(f[i]>0){
            sum++;
        } else{
            sum--;
        }
        if(i!=f.size()-1 && abs(f[i])==abs(f[i+1])) continue;
        if(sum>mx){
            mx = sum;
            pos = abs(f[i]);
        }
    }
    f.clear();
    for(auto x : i){
        if(pos>=x.first && pos<=x.second){
            f.pb(x.first);
            if(x.second==m) continue;
            f.pb(-1*x.second-1);
        }
    }
    sort(f.begin(),f.end(),[](int a,int b){
        return abs(a)<abs(b);
    });
    int mn = LLONG_MAX;
    sum=0;
    for(int j=0;j<f.size();j++){
        sum+=(f[j]>0 ? 1 : -1);
        if(j==f.size()-1 || abs(f[j])!=abs(f[j+1])) mn = min(mn,sum);
    }
    if(f[0]!=1) mn=0;
    if(!extendo)mn = 0;
    cout << mx-mn << "\n";
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
