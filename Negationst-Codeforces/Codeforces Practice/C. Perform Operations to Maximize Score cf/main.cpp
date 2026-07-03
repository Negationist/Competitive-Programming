#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int inf = 1LL<<60;
void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int mx1 = -inf;
    int mx2 = -inf;
    int index = -1;
    for(int i=0;i<n;i++){
        cin >> b[i];
        mx1 = max(mx1, a[i]);
        if(b[i]){
            if(a[i]>mx2){
                mx2 = a[i];
                index = i;
            }
        }
    }
    if(mx2==-inf){
        sort(a.begin(),a.end());
        int ans = a[n-1]+a[(n/2)-1];
        cout << ans << "\n";
        return;
    }
    //case 1, we use ops on increasing the max
    auto c = a;
    c[index]+=k;
    sort(c.begin(),c.end());
    int ans1 = c[n-1]+c[n/2-1];
    //now binary search on the median, O(n) selection and sim
    vi p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),[&](int i, int j){
            return a[i]<a[j];
        });
    int l = 0, r = mx1;
    int goal = n/2;
    while(l<=r){
        int num = k;
        int mid = l+(r-l)/2;
        int cnt = 0;
        vector<int> mine;
        for(int i=0;i<n;i++){
            cnt++;
            int j = p[i];
            if(b[j]==1) mine.pb(a[j]);
            if(i+1==n || a[p[i+1]]>=mid) break;
        }
        for(int i=mine.size()-1;i>=0;i--){
            int diff = mid-mine[i];
            num-=diff;
            if(num>=0) cnt--;
        }
        if(cnt<goal){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    int ans2 = r+mx1;
    cout << max(ans1, ans2) << "\n";
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
