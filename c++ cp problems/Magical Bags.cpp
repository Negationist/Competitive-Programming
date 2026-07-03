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
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int inf = 1e10;

void solve(){
    int n;
    cin >> n; 
    vi color(n,2); //0,1,2 ;  white, black, uncolored
    vector<pair<pii,set<int>>> b(n);
    set<int> openings, closings, i_whites;
    for(int i=0;i<n;i++){
        int z; cin >> z;
        while(z--){
            int cur; cin >> cur;
            b[i].ss.insert(cur);
        }
        b[i].ff.ff = *(b[i].ss.begin());
        b[i].ff.ss = *(b[i].ss.rbegin());
        if((int)(b[i].ss.size())==1){
            color[i] = 0;
            i_whites.insert(b[i].ff.ff);
        }
    }
    i_whites.insert(-inf);
    i_whites.insert(inf);
    for(int i=0;i<n;i++){
        //cout << b[i].ff.ff << " " << b[i].ff.ss << "\n";
        if(color[i]==2){
            auto it = i_whites.lower_bound(b[i].ff.ff);
            if(it!=i_whites.end() && *it<b[i].ff.ss){
                color[i] = 1;
            } else{
                openings.insert(b[i].ff.ff);
                closings.insert(b[i].ff.ss);
            }
        }
    }
    set<pii> can_be; map<pii,int> m;
    for(int i=0;i<n;i++){
        //cout << b[i].ff.ff << " " << b[i].ff.ss << "!!!\n";
        if(color[i]==2){
            int first_closing = *closings.upper_bound(b[i].ff.ff);
            int last_opening =  *(--openings.lower_bound(b[i].ff.ss));
            //cout << "first closing is " << first_closing << "\n";
            //cout << "last_opening is " << last_opening << "\n";
            bool no_close = (first_closing==b[i].ff.ss), no_open = (last_opening==b[i].ff.ff);
            //cout << "no close is " << no_close << "\n";
            //cout << "no open is " << no_open << "\n";
            if(!no_close && !no_open){
                auto lo = *b[i].ss.lower_bound(last_opening);
                if(lo<=first_closing){
                    can_be.insert(b[i].ff);
                    m[b[i].ff] = i;
                } else{
                    color[i] = 1;
                }
            } else{
                can_be.insert(b[i].ff);
                m[b[i].ff] = i;
            }
        }
    }
    // for(auto [l,r] : can_be){
    //     cout << l << " " << r << "!!!!!\n"; 
    // }
    while(can_be.size()){
        pii cur = *can_be.begin();
        can_be.erase(cur);
        color[m[cur]] = 0;
        //cout << cur.ff << " " << cur.ss << "!!!\n";
        while(true){
            auto it = can_be.lower_bound(cur);
            if(it==can_be.end()) break;
            else{
                if(it->ff>cur.ss){
                    break;
                } else{
                    color[m[*it]] = 1;
                    can_be.erase(it);
                    //cout << (*it).ff << " " << (*it).ss << "is gone!\n";
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=(color[i]+1);
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