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
    vi a(n),b(n);
    vector<vi> top(n+1);
    vector<vi> bot(n+1);
    vector<vi> toppref(n+1);
    vector<vi> botpref(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(top[a[i]].size()==0){
            top[a[i]].pb(0);
            toppref[a[i]].pb(0);
        }
        if(bot[a[i]].size()==0){
            bot[a[i]].pb(0);
            botpref[a[i]].pb(0);
        }
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(top[b[i]].size()==0){
            top[b[i]].pb(0);
            toppref[b[i]].pb(0);
        }
        if(bot[b[i]].size()==0){
            bot[b[i]].pb(0);
            botpref[b[i]].pb(0);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int dist = n-i;
        int l = 0, r = bot[a[i]].size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(bot[a[i]][mid]<dist){ //find highest with lower tolerance
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        //cout << "for top " << a[i] << " we got to " << r << " on bottom " << "\n";
        int res1 = botpref[a[i]][r]+(bot[a[i]].size()-r-1)*dist;
        l = 0;
        r = top[b[i]].size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(top[b[i]][mid]<dist){ //find highest with lower tolerance
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        //cout << "for bottom " << b[i] << " we got to " << r << " on top " << "\n";
        int res2 = toppref[b[i]][r]+(top[b[i]].size()-r-1)*dist;
        top[a[i]].pb(i+1);
        toppref[a[i]].pb(toppref[a[i]].back()+i+1);
        bot[b[i]].pb(i+1);
        botpref[b[i]].pb(botpref[b[i]].back()+i+1);
        ans+=res1;
        ans+=res2;
        //cout << "top adds " << res1 << ". bottom adds " << res2 << "\n";
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) continue;
        int left = i;
        int right = n-left-1;
        int dist = min(i+1,n-i);
        int res1 = (left*(left+1))/2;
        int res2 = (right*(right+1))/2;
        ans+=res1;
        ans+=res2;
        ans+=dist;
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
