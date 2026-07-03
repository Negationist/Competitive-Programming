#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n,q;
    cin >> n >> q;
    vi a(n+2);
    a[0] = -inf;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n+1] = -inf;
    int sum = 0;
    auto check = [&](int x)->int{
        if(x<1 || x>n) return 0;
        if(a[x-1]<a[x] && a[x+1]<a[x]){
            return a[x];
        } else if(a[x-1]>a[x] && a[x+1]>a[x]){
            return -a[x];
        }
        return 0;
    };
    for(int i=1;i<=n;i++){
        sum+=check(i);
    }
    cout << sum << "\n";
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        set<int> temp;
        temp.insert(l-1);
        temp.insert(l);
        temp.insert(l+1);
        temp.insert(r-1);
        temp.insert(r);
        temp.insert(r+1);
        for(int x : temp){
            sum-=check(x);
        }
        swap(a[l],a[r]);
        for(int x : temp){
            sum+=check(x);
        }
        cout << sum << "\n";
    }
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
