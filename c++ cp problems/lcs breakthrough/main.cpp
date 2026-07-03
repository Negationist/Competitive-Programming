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
    int n;
    cin >> n;
    vi a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    map<int,vi> weight;
    int val = 1;
    for(int i=0;i<n;i++){
        weight[b[i]].pb(val);
        ++val;
    }
    vi temp;
    map<int,int> pointer;
    for(int i=0;i<n;i++){
        if(pointer[a[i]]==weight[a[i]].size()){
            continue;
        } else{
            temp.pb(weight[a[i]][pointer[a[i]]]);
            ++pointer[a[i]];
        }
    }
    auto lis = [&](vi &a)->int{
        vi dp;
        int len = a.size();
        for(int i=0;i<len;i++){
            int pos = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            if(pos==dp.size()){
                dp.pb(a[i]);
            } else{
                dp[pos] = a[i];
            }
        }
        return dp.size();
    };
    for(int x : temp){
        cout << x << " ";
    }
    cout << "\n";
    cout << lis(temp) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
