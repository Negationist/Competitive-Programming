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
    int t;
    cin >> t;
    while(t--){
        int n,mx=0;
        cin >> n;
        map<int,int> m1;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            m1[a]++;
            if(m1[a]>mx){
                mx = m1[a];
            }
        }

        cout << n-mx << "\n";
    }
    return 0;
}
