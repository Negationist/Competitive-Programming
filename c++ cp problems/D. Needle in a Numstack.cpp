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

//int base[] = {1, 3, 2, 4, 1, 3, 4, 2, 1, 3, 4, 2};

int ask(int x){
    cout << "? " << x+1 << '\n';
    cout.flush();
    int z;
    cin >> z;
    return z;
    //return base[x];
}

void solve(){
    int n,k;
    cin >> n >> k;
    if(2*k == n){
        cout << "! " << k << " " << k << "\n";
        cout.flush();
        return;
    }
    vi a(k), b(k);
    for(int i=0;i<k;i++){
        a[i] = ask(i);
    }
    int mark;
    for(int i=0;i<k;i++){
        int idx = n-1-(k-1)+i;
        b[i] = ask(idx);
        if(idx % k == 0){
            mark = i;
        }
    }
    int key = -1;
    for(int i=0;i<k;i++){
        if(a[i] != b[(mark+i)%k]){
            key = i;
        }
    }
    if(key==-1){
        cout << "! -1" << "\n";
        cout.flush();
        return;
    }
    // for(int x : a){
    //     cout << x << " ";
    // }
    // cout << "!\n";
    // for(int x : b){
    //     cout << x << " ";
    // }
    // cout << "!\n";
    // cout << mark << "!!\n";
    // cout << key << "!!\n";
    int lo = 0, hi = (n-1-key)/k;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(ask(key + mid * k) == a[key]){
            lo = mid+1;
        } else{
            hi = mid-1;
        }
    }
    // cout << hi << "!!!\n";
    int start = key + hi * k;
    vi decide(k+1); //first is A, last is B
    for(int i=0;i<=k;i++){
        decide[i] = ask(start+i);
    }
    // for(int x : decide){
    //     cout << x << " ";
    // }
    // cout << " !!!\n";
    map<vi, vi> m; //vector to first index of B
    for(int i=1;i<=k;i++){
        if(start+i<k) continue; //not a valid place for B to be (b to b. ha!)
        if(n-1-(start+i)+1<k) continue;
        vi temp;
        for(int j=0;j<=k;j++){
            int mod = (start+j) % k;
            if(j<i){
                temp.pb(a[mod]);
            } else{
                temp.pb(b[(mark + mod)%k]);
            }
        }
        m[temp].pb(start+i);
    }
    vi cands = m[decide];
    if(sz(cands) == 1){
        cout << "! " << cands[0] << " " << n-cands[0] << "\n";
        cout.flush();
    } else{
        // for(int x : cands){
        //     cout << x << " ";
        // }
        // cout << "!\n";
        cout << "! -1" << "\n";
        cout.flush();
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