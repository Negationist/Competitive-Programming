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
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]+=(n-i);
    }
    vi b(k);
    for(int i=0;i<k;i++){
        cin >> b[i];
        --b[i];
    }
    bool win = true;
    for(int i=0;i<k-1;i++){
        if(a[b[i+1]]<a[b[i]]){
            win = false;
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
    if(!win){
        cout << -1 << "\n";
        return;
    } else if(k==0){
        cout << n-lis(a) << "\n";
        return;
    }
    int ans = n-k;
    if(b[0]>0){
        vi temp;
        for(int i=0;i<b[0];i++){
            if(a[i]<=a[b[0]]) temp.pb(a[i]);
        }
        ans-=lis(temp);
    }
    for(int i=0;i<k-1;i++){
        vi temp;
        for(int j=b[i]+1;j<b[i+1];j++){
            if(a[j]>=a[b[i]] && a[j]<=a[b[i+1]]) temp.pb(a[j]);
        }
        ans-=lis(temp);
    }
    if(b[k-1]<n-1){
        vi temp;
        for(int j=b[k-1]+1;j<n;j++){
            if(a[j]>=a[b[k-1]])
            temp.pb(a[j]);
        }
        ans-=lis(temp);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
