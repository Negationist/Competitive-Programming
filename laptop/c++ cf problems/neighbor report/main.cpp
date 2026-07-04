#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        while(true){
            int x;
            cin >> x;
            if(x==i+1){
                break;
            } else{
                a[i].pb(x);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int x : a[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
