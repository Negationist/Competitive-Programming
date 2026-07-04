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
    vi a(n);
    map<int,int> cnt;
    set<int> eq;
    int mx = -1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ++cnt[a[i]];
        if(cnt[a[i]]>1){
            eq.insert(-a[i]);
        }
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        int y = a[i+1] - a[i];
        //cout << "y is " << y << "\n";
        --cnt[a[i+1]];
        --cnt[a[i]];
        for(int x : eq){
            if(y>=-2*x){
                break;
            } else{
                if(y<-2*x){
                    //cout << "trying " << x << "\n";
                    if(cnt[-x]>1){
                        cout << a[i] << " " << a[i+1] << " " << -x << " " << -x << "\n";
                        return;
                    }
                }
            }
        }
        ++cnt[a[i+1]];
        ++cnt[a[i]];
    }
    cout << "-1\n";
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
