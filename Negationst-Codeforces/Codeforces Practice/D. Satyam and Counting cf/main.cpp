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
    int t;
    cin >> t;
    while(t--){
        int n,ans=0;
        cin >> n;
        vector<set<int>> points(2);
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            if(y==0){
                points[0].insert(x);
            } else{
                points[1].insert(x);
            }
        }
        for(int i=0;i<=n;i++){
            if(points[0].find(i) != points[0].end() && points[1].find(i) != points[1].end()){
                ans+=(points[0].size()+points[1].size()-2);
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<=n-2;j++){
                if(points[i].find(j) != points[i].end() && points[i].find(j+2) != points[i].end()){
                    if(points[1-i].find(j+1) != points[1-i].end()){
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
