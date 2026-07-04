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
        int n,ans=0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        set<int> s;
        vector<vector<int>> b(n);
        for(int j=0;j<n;j++){
            for(int i=0;i<21;i++){
                if(1<<i & a[j]){
                    b[j].pb(i);
                    s.insert(i);
                }
            }
        }
        if(s.empty()){
            cout << 1 << endl;
            continue;
        }
        int l=0, r=-1;
        int freq[21] = {};
        while(true){
            if(s.empty()){
                ans = max(ans,r-l+1);
                for(int x : b[l]){
                    freq[x]--;
                    if(freq[x]==0){
                        s.insert(x);
                    }
                }
                l++;
            } else{
               r++;
               if(r>=n) break;
               for(int x : b[r]){
                    s.erase(x);
                    freq[x]++;
               }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
