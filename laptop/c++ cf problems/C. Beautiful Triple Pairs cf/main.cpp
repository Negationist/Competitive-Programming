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
    unordered_map<string,int> m1;
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(i>1){
                stringstream sso1;
                stringstream sso2;
                stringstream sso3;
                sso1 << 'G' << 'x' << a[i-1] << 'x' << a[i];
                sso2 << a[i-2] << 'x' << 'G' << 'x' << a[i];
                sso3 << a[i-2] << 'x' << a[i-1] << 'x' << 'G';
                m1[sso1.str()]++;
                m1[sso2.str()]++;
                m1[sso3.str()]++;
            }
        }
        for(auto it = m1.begin();it!=m1.end();it++){
            if((it->second)>1){
                int z = it->second;
                int inc = z*(z-1)/2;

                ans+=inc;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
