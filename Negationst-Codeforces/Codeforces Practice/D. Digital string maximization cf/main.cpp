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
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    stack<pii> stck;
    int cur = 1;
    for(int i=n-1;i>=0;i--){
        int z = s[i]-'0';
        stck.push({z,i});
    }
    while(cur<n){
        while(stck.top().ss<cur-9){
            ans.pb((char)(stck.top().ff+'0'));
            stck.pop();
        }
        int start;
        vector<int> consider;
        while(stck.size() && stck.top().ss!=cur){
            consider.pb(stck.top().ff);
            start = stck.top().ss;
            stck.pop();
        }
        start++;
        int q = consider.size();
        int num = stck.top().ff;
        stck.pop();
        int best = -1;
        int real;
        for(int i=0;i<q;i++){
            real = num-(q-i);
            if(real>consider[i]){
                best = i;
                break;
            }
        }
        vector<int> goback;
        if(best==-1){
            for(int x : consider){
                goback.pb(x);
            }
            goback.pb(num);
        } else{
            for(int i=0;i<q;i++){
                if(best==i){
                    goback.pb(real);
                }
                 goback.pb(consider[i]);
            }
        }
        q = goback.size();
        for(int i=q-1;i>=0;i--){
            stck.push({goback[i],start});
            start--;
        }
        cur++;
    }
    while(stck.size()){
        ans.pb((char)(stck.top().ff+'0'));
        stck.pop();
    }
    cout << ans << "\n";
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
