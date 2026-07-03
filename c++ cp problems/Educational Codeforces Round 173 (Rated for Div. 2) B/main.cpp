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
    int n,d;
    cin >> n >> d;
    cout << 1 << " ";
    if(d%3==0 || n>=3){
        cout << 3 << " ";
    }
    if(d==5){
        cout << 5 << " ";
    }
    if(d==7){
        cout << 7 << " ";
    } else if(n>=3){
        cout << 7 << " ";
    }
    if(d==9){
        cout << 9 << " ";
    } else if(d%3==0 && n>=3){
        cout << 9 << " ";
    } else if(n>=6){
        cout << 9 << " ";
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
