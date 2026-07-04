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
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    bool done = false;
    while(!done){
        done = true;
        int mn = LLONG_MAX;
        vi pos;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) continue;
            if(a[i] > b[i]){
                cout << "NO\n";
                return;
            } else if(b[i]<mn){
                done=false;
                pos.clear();
                mn = b[i];
                pos.pb(i);
            } else if(b[i]==mn){
                done=false;
                pos.pb(i);
            }
        }
        if(done){
            cout << "YES\n";
            return;
        }
        for(int x : pos){
            bool found = false;
            int goal = b[x];
            int index1 = x-1;
            int index2 = x+1;
            while(!found){
                if(index1<0 && index2 >=n) break;
                if(index1>=0){
                    if(a[index1] == b[x]){
                        found = true;
                        for(int i=index1; i<=x;i++){
                            a[i] = goal;
                        }
                    }
                }
                if(index2<n){
                    if(a[index2] == b[x] && !found){
                        found = true;
                        for(int i=x; i<=index2;i++){
                            a[i] = goal;
                        }
                    }
                }
                index1--;
                index2++;
            }
            if(!found){
                cout << "NO\n";
                return;
            }
        }
    }
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
