#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    vii a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        a[i] = {z,0};
    }
    int ans = 0;
    bool in = false;
    int cur;
    vector<tuple<int,int,int>>segs;
    int l;
    for(int i=0;i<n;i++){
        if(!in && a[i].ff!=0){
            in = true;
            cur = a[i].ff;
            l = i;
        } else if(in && a[i].ff==0){
            segs.pb({l,i-1,cur});
            in = false;
        } else if (in && a[i].ff!=0){
            cur = max(a[i].ff,cur);
        }
    }
    if(in){
        segs.pb({l,n-1,cur});
    }
    for(int i=0;i<segs.size();i++){
        ans++;
        int left = get<0>(segs[i]);
        int right = get<1>(segs[i]);
        int mx = get<2>(segs[i]);
        if(mx==2){
            if(left-1>=0){
                a[left-1].ss = 1;
            }
            if(right+1<n){
                a[right+1].ss = 1;
            }
        } else{
            if(left-1>=0 && a[left-1].ss == 0){
                a[left-1].ss = 1;
            } else{
                if(right+1<n){
                    a[right+1].ss = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i].ff==0 && a[i].ss==0){
            ans++;
        }
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
