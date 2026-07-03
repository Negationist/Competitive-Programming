#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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



int ask(vi &a){
    cout << "? " << (int)(a.size()) << " ";
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}

void guess(string s){
    cout << "! " << s << "\n";
    cout.flush();
}

void solve(){
    int n;
    cin >> n;
    vi start;
    for(int i=1;i<=n;i++) start.pb(i);
    if(!ask(start)){
        int lo = 1, hi = n-1;
        while(lo<=hi){
            vi cur;
            int mid = (lo+hi)/2;
            cur.pb(n); cur.pb(mid); 
            if(ask(cur)){ //this is a ')'
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        string out;
        for(int i=0;i<hi;i++){
            out.pb(')');
        }
        for(int i=0;i<n-hi;i++){
            out.pb('(');
        }
        guess(out);
    } else{
        int lo = 2, hi = n;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            vi out;
            for(int i=1;i<=mid;i++){
                out.pb(i);
            }
            if(ask(out)){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        int open = lo-1, close = lo;
        string ans;
        for(int i=1;i<=n;i+=2){
            vi out;
            if(i==n){
                out.pb(open);
                out.pb(n);
                if(ask(out)){
                    ans.pb(')');
                } else{
                    ans.pb('(');
                }
                break;
            }
            out.pb(open);
            out.pb(open);
            out.pb(i);
            out.pb(i+1);
            out.pb(open);
            out.pb(close);
            int z = ask(out);
            if(z==1){
                ans.pb('(');
                ans.pb('(');
            } else if(z==2){
                ans.pb(')');
                ans.pb('(');
            } else if(z==3){
                ans.pb('(');
                ans.pb(')');
            } else{
                ans.pb(')');
                ans.pb(')');
            }
        }
        guess(ans);
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