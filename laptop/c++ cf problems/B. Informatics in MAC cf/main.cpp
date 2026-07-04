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
        int a[n];
        set<int> s;
        for(int i=0;i<n;i++){
            cin >> a[i];
            s.insert(a[i]);
        }
        int MEX=0;
        while(true){
            if(s.find(MEX) != s.end()){
                MEX++;
            }
            else{
                break;
            }
        }
        s.clear();
        for(int i=0;i<MEX;i++){
            s.insert(i);
        }
        int r=0;
        for(int i=0;i<n;i++){
            s.erase(a[i]);
            if(s.empty()){
                for(int i=0;i<MEX;i++){
                    s.insert(i);
                }
                break;
            } else{
                r++;
            }
        }
        for(int i=r+1;i<n;i++){
            s.erase(a[i]);
            if(s.empty()){
                cout << 2 << "\n1 " << r+1 << "\n" << r+2 << " " << n << "\n";
                return;
            }
        }
        cout << -1 << "\n";
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
