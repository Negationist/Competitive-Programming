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
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i]!=b[i]){
            m[b[i]].insert(i);
        }
    }
    for(auto it = m.begin();it!=m.end();it++){ //O(n)
        int l = *(it->second.begin());
        int r = *(it->second.rbegin());
        int goal = b[l];
        bool found = false;
        for(int i=l+1;i<r;i++){
            if(a[i]>goal){
                cout << "NO\n";
                return;
            }
            if(a[i]==goal){
                found = true;
            }
        }
        if(!found){
            int ltest = l;
            int rtest = r;
            while(ltest>=0 || rtest<n){
                ltest--;
                rtest++;
                if(ltest>=0){
                    if(a[ltest]==goal){
                        l = ltest;
                        found = true;
                        break;
                    }
                    if(a[ltest]>goal){
                        ltest = -1;
                    }
                }
                if(rtest<n){
                    if(a[rtest]==goal){
                        r = rtest;
                        found = true;
                        break;
                    }
                    if(a[rtest]>goal){

                       rtest = n;
                    }
                }
            }
        }
        if(!found){
            cout << "NO\n";
            return;
        }
        for(int i=l;i<=r;i++){
            a[i] = goal;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            cout << "NO\n";
            return;
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
