#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    map<int,int> cnt1;
    map<int,int> cnt2;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        cnt1[z]++;
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            int m = cnt1[n]/2;
            cnt1[n]-=m;
            cnt2[n]+=m;
        }
        else if(cnt1[i]>=2){
            int rest = cnt1[i]-2;
            cnt1[i+1]+=rest;
            cnt1[i] = 1;
            cnt2[i] = 1;
        }
    }
    bool win = true;
    for(auto x : cnt1){
        if(cnt2[x.ff]!=x.ss){
            win = false;
        }
    }
    cout << (win?"yes\n":"no\n");
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
