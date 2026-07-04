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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            cout << -1 << "\n";
            continue;
        }
        cout << 1 << " ";
        n--;
        for(int i=0;i<n/2;i++){
            cout << 3+2*i << " " << 3+2*i-1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
