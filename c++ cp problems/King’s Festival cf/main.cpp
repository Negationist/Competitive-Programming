#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vi a(n,0);
    for(int i=0;i<n;i++){
        a[i]+=(s[i]=='#');
    }
    for(int i=0;i<n;i++){
        if(i&1) ++a[i]; //odds first
    }
    set<tuple<int,int,int>> st,gone;
    for(int i=0;i<n;i+=2){ //check for even arithmetic
        for(int j=i+2;j<n;j+=2){
            if(!a[i] && !a[j]){
                int m = (i+j)/2;
                if(!a[m]){
                    st.insert({i,m,j});
                }
            }
        }
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
