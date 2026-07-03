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
    vi a(n);
    bool zero = false;
    bool other = false;
    bool sandwich = false;
    bool maybe = false;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        if(!z){
            zero = true;
            if(other){
                maybe = true;
            }
        } else{
            other = true;
            if(maybe){
                sandwich = true;
            }
        }
    }
    if(sandwich){
        cout << 2;
    } else if(!other){
        cout << 0;
    } else{
        cout << 1;
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
