#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    map<int,set<int>> m;
    bool fail = false;
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i]!=b[i]){
            m[b[i]].insert(i);
        }
        if(a[i]>b[i]){
            fail = true;
        }
    }
    if(fail){
        cout << "NO\n";
        return;
    }
    for(auto it = m.begin();it!=m.end();it++){
        for(int x : it->second){
            int goal = b[x];
            int l = x;
            int r = x;
            while(l>=0 || r<n){
                l--;
                r++;
                if(l>=0){
                    if(a[l]==goal){
                        r = x;
                        break;
                    }
                    if(a[l]>goal || b[l]<goal){
                        l = -1;
                    }
                }
                if(r<n){
                    if(a[r]==goal){
                        l = x;
                        break;
                    }
                    if(a[r]>goal || b[r]<goal){
                        r = n;
                    }
                }
            }
            if(l<0 || r>=n){
                cout << "NO\n";
                return;
            }
            for(int i=l;i<=r;i++){
                a[i] = goal;
            }
        }
    }
    cout << "YES\n";
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
