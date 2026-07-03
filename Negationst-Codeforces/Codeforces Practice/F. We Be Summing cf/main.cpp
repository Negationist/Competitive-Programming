#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    vector<int> pos[n+1];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    vii mnseg(n,{0,n-1});
    vii mxseg(n,{0,n-1});
    stack<int> mnstack;
    stack<int> mxstack;
    for(int i=n-1;i>=0;i--){
        while(mnstack.size() && a[i]<=a[mnstack.top()]){
            mnseg[mnstack.top()].ff = i+1;
            mnstack.pop();
        }
        while(mxstack.size() && a[i]>=a[mxstack.top()]){
            mxseg[mxstack.top()].ff = i+1;
            mxstack.pop();
        }
        mnstack.push(i);
        mxstack.push(i);
    }
    while(mnstack.size()) mnstack.pop();
    while(mxstack.size()) mxstack.pop();
    for(int i=0;i<n;i++){
        while(mnstack.size() && a[i]<a[mnstack.top()]){
            mnseg[mnstack.top()].ss = i-1;
            mnstack.pop();
        }
        while(mxstack.size() && a[i]>a[mxstack.top()]){
            mxseg[mxstack.top()].ss = i-1;
            mxstack.pop();
        }
        mnstack.push(i);
        mxstack.push(i);
    }
    vector<int> suff[n+1];
    for(int i=0;i<=n;i++){
        int z = pos[i].size();
        if(!z){
            continue;
        }
        suff[i].resize(z);
        suff[i][z-1] = n-1-mxseg[pos[i][z-1]].ss;
        //cout << "suff " << i << " " << z-1 << " is " << suff[i][z-1] << "\n";
        for(int j=z-2;j>=0;j--){
            if(mxseg[pos[i][j]].ss>=mxseg[pos[i][j+1]].ff){
                suff[i][j] = suff[i][j+1];
            } else{
                int res = mxseg[pos[i][j+1]].ff - mxseg[pos[i][j]].ss-1;
                suff[i][j] = res+suff[i][j+1];
            }
            //cout << "suff " << i << " " << j << " is " << suff[i][j] << "\n";
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        //cout << i << ": ";
        int goal = k-a[i];
        if(goal<0 || goal>n){
            //cout << "\n";
            continue;
        }
        int stretch = mnseg[i].ss;
        int lo = 0, hi = pos[goal].size()-1;
        bool good = false;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int cur = pos[goal][mid];
            if(cur<=i){
                lo = mid+1;
                continue;
            }
            if(mxseg[cur].ff-1<=stretch){
                good = true;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        if(!good){
            //cout << "\n";
            continue;
        }
        //cout << "hi is " << hi << "\n";
        int last = pos[goal][hi];
        //cout << "last is " << last << "\n";
        auto it = upper_bound(pos[goal].begin(),pos[goal].end(),i);
        int p = it-pos[goal].begin();
        //cout << "p is " << p << "\n";
        //cout << "it is " << *it << "\n";
        ll space = mxseg[last].ss-*(it)+1;
        //cout << "space is " << space << "\n";
        ll loss = suff[goal][p]-suff[goal][hi];
        //cout << "loss is " << loss << "\n";
        ll res = space-loss;
        //cout << res << "!\n";
        ll fnal = (i-mnseg[i].ff+1)*res;
        //cout << fnal << "\n";
        ans+=fnal;
    }
    cout << ans << "\n";
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
