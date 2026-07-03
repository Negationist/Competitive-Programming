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
    vii points(n);
    for(int i=0;i<n;i++){
        cin >> points[i].ff >> points[i].ss;
    }
    sort(points.begin(),points.end());
    vi x(n),y(n);
    for(int i=0;i<n;i++){
        x[i] = points[i].ff;
        y[i] = points[i].ss;
    }
    int ans = 0;
    pii d = {0,0};
    multiset<int> left,right;
    int l = 1, r= n/4;
    while(l<=r){
        int mid = l+(r-l)/2;
        bool found = false;
        right.clear();
        left.clear();
        for(int i=0;i<n;i++){
            right.insert(y[i]);
        }
        for(int i=0;i<n;i++){
            left.insert(y[i]);
            right.erase(right.find(y[i]));
            while(i+1<n && x[i+1]==x[i]){
                left.insert(y[i+1]);
                right.erase(right.find(y[i+1]));
                i++;
            }
            if(left.size()<2*mid || right.size()<2*mid) continue;
            int u1,d1,u2,d2;
            int lo = *(left.begin()), hi = *(--left.end());
            while(lo<=hi){
                int _mid = lo+(hi-lo)/2;
                auto prev = left.lower_bound(_mid);
                int num = distance(left.begin(),prev)+1;
                if(num>=mid && left.size()-num>=mid){
                    prev++;
                    d1 = *prev;
                    hi = _mid-1;
                } else{
                    lo = _mid+1;
                }
            }
            lo = *(left.begin()); hi = *(--left.end());
            while(lo<=hi){
                int _mid = lo+(hi-lo)/2;
                auto prev = left.upper_bound(_mid);
                int num = distance(prev,left.end());
                if(num>=mid && left.size()-num>=mid){
                    lo = _mid+1;
                    u1 = *prev;
                } else{
                    hi = _mid-1;
                }
            }
            lo = *(right.begin()), hi = *(--right.end());
            while(lo<=hi){
                int _mid = lo+(hi-lo)/2;
                auto prev = right.lower_bound(_mid);
                int num = distance(right.begin(),prev)+1;
                if(num>=mid && right.size()-num>=mid){
                    prev++;
                    d2 = *prev;
                    hi = _mid-1;
                } else{
                    lo = _mid+1;
                }
            }
            lo = *(right.begin()); hi = *(--right.end());
            while(lo<=hi){
                int _mid = lo+(hi-lo)/2;
                auto prev = right.lower_bound(_mid);
                int num = distance(prev,right.end());
                if(num>=mid){
                    if(right.size()-num>=mid){
                        u2 = *prev;
                    }
                    lo = _mid+1;
                } else{
                    hi = _mid-1;
                }
            }
            int top = min(u1,u2), bottom = max(d1,d2);
            if(top>=bottom){
                found = true;
                if(mid>ans){
                    ans = mid;
                    d = {x[i]+1,top};
                }
                break;
            }
        }
        if(found){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << ans << "\n" << d.ff << " " << d.ss << "\n";
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
