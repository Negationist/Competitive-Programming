#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int sum = 0;
    for(int i=0;i<n;i++) {cin >> a[i]; sum+=a[i];}
    int avg = sum/n;
    //cout << avg << "!\n";
    multiset<int> give,take;
    for(int i=0;i<n;i++){
        if(a[i]==avg) continue;
        bool f = (a[i]<avg);
        int diff = a[i]-avg;
        if(f){
            diff*=-1;
        }
        vi set;
        for(int j=0;j<63;j++){
            if(diff&&(1LL<<j)){
                set.pb(j);
            }
        }
        int lo = set[0], hi = set.back();
        if((int)set.size()!=hi-lo+1){
            cout << "NO\n";
            return;
        } else{
            if(f){
                give.insert(lo);
                take.insert(hi+1);
            } else{
                take.insert(lo);
                give.insert(hi+1);
            }
        }
        //cout << "for " << a[i] << ". lo is " << lo << ". hi is " << hi << "\n";
        //cout << "diff is " << diff << "\n";
    }
    give.erase(0);
    take.erase(0);
    cout << (give==take?"YES":"NO") << "\n";
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