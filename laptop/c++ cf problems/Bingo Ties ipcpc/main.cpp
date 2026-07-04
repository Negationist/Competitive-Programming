#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> a[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<25;j++){
            int z;
            cin >> z;
            a[i].insert(z);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int x : a[i]){
                if(a[j].find(x)!=a[j].end()){
                    cout << i+1 << " " << j+1 << "\n";
                    return;
                }
            }
        }
    }
    cout << "no ties\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
