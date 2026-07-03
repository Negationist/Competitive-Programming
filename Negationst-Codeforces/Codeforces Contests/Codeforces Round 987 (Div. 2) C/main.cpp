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
    if(n%2==0){
        for(int i=0;i<n;i++){
            cout << 1+i/2 << " ";
        }
    }
    else{
        if(n<27){
            cout << -1;
        } else{
            int cur = 3;
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(i==1 || i==10 || i==26){
                    cout << 1 << " ";
                } else if(i==23 || i==27){
                    cout << 2 << " ";
                } else{
                    cout << cur << " ";
                    cnt++;
                    if(cnt==2){
                        cnt = 0;
                        cur++;
                    }
                }
            }
        }
    }
    cout << "\n";
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
