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

void solve(){
    char z;
    cin >> z;
    string line;
    cin.ignore();
    getline(cin, line);
    int n = line.size();
    int a_m1 = 96;
    vi vals;
    for(int i=0;i<n;i++){
        char x = line[i];
        if(x == ' '){
            vals.pb(0);
        } else{
            vals.pb((int)(x) - a_m1);
        }
    }
    // for(int x : vals){
    //     cout << x << " ";
    // }
    // cout << '\n';
    if(z=='d'){ 
        for(int i=n-1;i>0;i--){
            vals[i] = (vals[i] - vals[i-1] + 27) % 27;
        }
    } else{
        for(int i=1;i<n;i++){
            vals[i]+=vals[i-1];
            vals[i] = (vals[i]) % 27;
        }
    }
    // for(int x : vals){
    //     cout << x << " ";
    // }
    for(int x : vals){
        if(x==0){
            cout << ' ';
        } else{
            cout << (char)(a_m1+x);
        }
    }
    cout << "\n";
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