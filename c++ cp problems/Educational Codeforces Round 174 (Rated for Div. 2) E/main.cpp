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
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int a,b,ab,ba;
    cin >> a >> b >> ab >> ba;
    vi d(n,-1);
    vi cnt(5,0);
    for(int i=0;i+1<n;i++){
        if(s[i]=='B' && s[i+1]=='A'){
            d[i] = 4;
            d[i+1] = 0;
            cnt[4]++;
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==-1){
            if(s[i]=='A'){
                d[i] = 1;
            } else{
                d[i] = 2;
            }
        }
    }
    for(int x : d){
        cout << x << " ";
    }
    cout << "\n";
    //fix ba
    for(int i=0;i+1<n && cnt[4]>ba && cnt[3]<ab;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            if(d[i-1]==4){
                d[i-1] = -1;
                d[i] = 3;
                d[i+1] = 0;
                cnt[3]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==-1 || d[i]==0){
            if(s[i]=='A'){
                d[i] = 1;
            } else{
                d[i] = 2;
            }
        }
    }
    for(int i=0;i<n && cnt[3]<ab;i++){
        if(s[i]=='A' && s[i+1]=='B'){
            if(d[i]==1 && d[i+1]==2){
                d[i] = 3;
                d[i+1] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==3 || d[i]==4){
            d[i+1] = 0;
            ++i;
        } else{
            if(s[i]=='A'){
                d[i] = 1;
            } else{
                d[i] = 2;
            }
        }
    }
    vi cnt2(5,0);
    for(int i=0;i<n;i++){
        cnt2[d[i]]++;
    }
    if(cnt2[0]<a && cnt2[1]<b && cnt2[2]<ab && cnt2[3]<ba){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
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
