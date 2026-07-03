#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    int n;
    cin >> n;
    int x = 0;
    vii out;
    if(n&1){
        int a[3];
        bool flag = false;
        for(int i=0;i<3;i++){
            cin >> a[i];
            if(!a[i]) flag = true;
        }
        if(flag){
            out.pb({1,3});
            x+=1;
        } else{
            x+=3;
        }
        int last;
        for(int i=3;i<n;i++){
            int z;
            cin >> z;
            if(!(i&1)){
                if(last==0 || z==0){
                    out.pb({i,i+1});
                    x+=1;
                } else{
                    x+=2;
                }
            }
            last = z;
        }
    } else{
        int last;
        for(int i=0;i<n;i++){
            int z;
            cin >> z;
            if(i&1){
                if(last==0 || z==0){
                    out.pb({i,i+1});
                    x+=1;
                } else{
                    x+=2;
                }
            }
            last = z;
        }
    }
    reverse(out.begin(),out.end());
    out.pb({1,x});
    cout << out.size() << "\n";
    for(auto p : out){
        cout << p.ff << " " << p.ss << "\n";
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
