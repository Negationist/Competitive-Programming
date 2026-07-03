
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

bool check(int k, vector<int> &a){
    int split;
    if(a.size()%2==0){
        for(int i=0;i<a.size();i+=2){
            if(a[i+1]-a[i]>k) return false;
        }
        return true;
    } else{
        for(int i=0;i<a.size();i+=2){
            if(i==a.size()-1){
                return true;
            }
            if(a[i+1]-a[i]>k){
                split = i;
                break;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<=split;i+=2){
        if(a[i+1] - a[i]>k){
            cnt++;
            i--;
        }
    }
    for(int i=split+1;i<a.size();i+=2){
        if(a[i+1] - a[i]>k){
            cnt++;
            i--;
        }
    }
    if(cnt>1){
        return false;
    } else{
        return true;
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l=1, r= 1e18;
    while(l<=r){
        int mid = l+(r-l)/2;
        bool good = check(mid, a);
        if(good){
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout << l << "\n";
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
