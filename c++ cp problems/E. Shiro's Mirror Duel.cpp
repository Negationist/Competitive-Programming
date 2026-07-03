#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

pii guess(int x, int y){
    cout << "? " << x+1 << " " << y+1 << "\n";
    cout.flush();
    int a,b; cin >> a >> b;
    return {min(a,b)-1, max(a,b)-1};
}

void solve(){
    int n; cin >> n;
    vi p(n), pos(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    for(int i=0;i<n/2;i++){
        while(true){
            pii temp;
            if(p[i]!=i){
                temp = guess(i, pos[i]);
            } else if(p[n-i-1]!=n-i-1){
                temp = guess(n-i-1, pos[n-i-1]);
            } else{
                break;
            }
            pos[p[temp.ff]] = temp.ss;
            pos[p[temp.ss]] = temp.ff;
            swap(p[temp.ff], p[temp.ss]);
        }
    }
    cout << "!\n";
    cout.flush();
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