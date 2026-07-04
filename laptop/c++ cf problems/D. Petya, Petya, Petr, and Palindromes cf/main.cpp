#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    if(k==1){
        cout << 0 << "\n";
        return;
    }
    int link[n][2];
    map<int,vi> pos_even,pos_odd;
    auto establish = [&]()->void{
        map<int,int> pos;
        pos_even.clear();
        pos_odd.clear();
        for(int i=0;i<n;i++){
            if(i&1){
               pos_odd[a[i]].pb(i);
            } else{
               pos_even[a[i]].pb(i);
            }
            link[i][0] = pos[a[i]]-1;
            pos[a[i]] = i+1;
        }
        pos.clear();
        for(int i=n-1;i>=0;i--){
            link[i][1] = pos[a[i]]-1;
            pos[a[i]] = i+1;
        }
    };
    auto getnum = [&](int left, int right, int x, int p)->int{
        if(p&1){
            auto pos1 = lower_bound(pos_odd[x].begin(),pos_odd[x].end(),left);
            if(pos1==pos_odd[x].end()) return 0;
            int l_end = pos1-pos_odd[x].begin();
            int lo = l_end, hi = pos_odd[x].size()-1;
            bool flag = false;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(pos_odd[x][mid]<=right){
                    flag = true;
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
            }
            if(flag){
                return hi-l_end+1;
            }
            return 0;
        } else{
            auto pos1 = lower_bound(pos_even[x].begin(),pos_even[x].end(),left);
            if(pos1==pos_even[x].end()) return 0;
            int l_end = pos1-pos_even[x].begin();
            int lo = l_end, hi = pos_even[x].size()-1;
            bool flag = false;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(pos_even[x][mid]<=right){
                    flag = true;
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
            }
            if(flag){
                return hi-l_end+1;
            }
            return 0;
        }
    };
    establish();
    int ans = 0;
    for(int i=0;i<n;i++){
        int left = LLONG_MAX, right = LLONG_MIN;
        if(k&1){
            int lo = 0, hi = n;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int index = i+2*mid;
                int len = index-i+1;
                if(index>=n || len>k){
                    hi = mid-1;
                    continue;
                }
                int l = i-(k-len)/2;
                if(l>=0){
                    left = min(left,index);
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            lo = 0; hi = n;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int index = i+2*mid;
                int len = index-i+1;
                if(index>=n || len>k){
                    hi = mid-1;
                    continue;
                }
                int r = index+(k-len)/2;
                if(r<n){
                    right = max(right,index);
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
            }
        } else{
            int lo = 0, hi = n;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int index = i+2*mid+1;
                int len = index-i+1;
                if(index>=n || len>k){
                    hi = mid-1;
                }
                int r = index+(k-len)/2;
                if(r<n){
                    left = min(left,index);
                    hi = mid-1;
                } else{
                    lo = mid+1;
                }
            }
            lo = 0; hi = n;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                int index = i+2*mid+1;
                int len = index-i+1;
                if(index>=n || len>k){
                    hi = mid-1;
                }
                int r = index+(k-len)/2;
                if(r<n){
                    right = max(right,index);
                    lo = mid+1;
                } else{
                    hi = mid-1;
                }
            }
            right = hi;
        }
        if(left==LLONG_MAX || right==LLONG_MAX || left>right) continue;
        int num = (right-left)/2+1;
        int z;
        if(k&1){
            z = getnum(left,right,a[i],i&1);
        } else{
            z = getnum(left,right,a[i],!(i&1));
        }
        ans+=(num-z);
    }
    reverse(a.begin(),a.end());
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
