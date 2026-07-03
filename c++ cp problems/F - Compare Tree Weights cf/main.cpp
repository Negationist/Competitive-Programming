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
using ld = long double;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    auto cmp = [&](int a, int b){
        return (a>b);
    };
    int ans = 0;
    vi idxs;
    auto inc = [&]()->void{
        for(int x : idxs){
            cout << x+1 << " ";
        }
        cout << "\n";
        int z = (int)idxs.size()-1;
        ans+=(idxs[z-1]-idxs[z-2]);
    };
    int j = 0;
    while(j<n-1 && a[j]>a[j+1]) ++j;
    idxs.pb(j);
    ++j;
    while((int)idxs.size()<3 && j<n-1){
        if(cmp(a[j],a[j+1])!=cmp(a[j-1],a[j])){
            idxs.pb(j);
        }
        ++j;
    }
    if((int)idxs.size()>=3) inc();
    while(j<n-1){
        if(cmp(a[j],a[j+1]!=cmp(a[j-1],a[j]))){
            idxs.pb(j);
        }
        if((int)idxs.size()%2==1) inc();
        ++j;
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
