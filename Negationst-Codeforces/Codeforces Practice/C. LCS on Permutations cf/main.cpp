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
    //manip b to be increasing
    int val = 1;
    map<int,int> c;
    for(int i=0;i<n;i++){
        if(c[b[i]]==0){
            c[b[i]] = val;
            ++val;
        }
    }
    //remove extraneous elements from a
    vi temp;
    for(int i=0;i<n;i++){
        if(c[a[i]]){
            temp.pb(c[a[i]]);
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
    cout << lis(temp) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
