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
    int n,f;
    cin >> n >> f;
    string s;
    cin >> s;
    if(f==1){
        set<string> m;
        for(int i=0;i<n-2;i++){
            string x = s.substr(i,3);
            for(int j=0;j<3;j++){
                char cur = x[j];
                for(int k=0;k<26;k++){
                    x[j] = (char)('a'+k);
                    if(x[0]!=x[1] && x[1]==x[2]){
                        m.insert(x);
                    }
                }
                x[j] = cur;
            }
        }
        cout << m.size() << "\n";
        for(string x : m){
            cout << x << "\n";
        }
    } else{
        map<string,int> cnt;
        set<string> ans;
        for(int i=0;i<n-2;i++){
            string x = s.substr(i,3);
            if(x[0]!=x[1] && x[1]==x[2]){
                cnt[x]++;
            }
        }
        for(int i=0;i<n;i++){
            char og = s[i];
            vector<string> moos;
            int l = max(0LL,i-2);
            int r = min(n-1,i+2);
            for(int j=l;j+2<=r;j++){
                if(s[j]!=s[j+1] && s[j+1]==s[j+2]){
                    moos.pb(s.substr(j,3));
                    cnt[s.substr(j,3)]--;
                }
            }
            for(int k=0;k<26;k++){
                vector<string> newmoos;
                s[i]=(char)('a'+k);
                for(int j=l;j+2<=r;j++){
                    if(s[j]!=s[j+1] && s[j+1]==s[j+2]){
                        newmoos.pb(s.substr(j,3));
                        cnt[s.substr(j,3)]++;
                    }
                }
                for(auto moo : newmoos){
                    if(cnt[moo]>=f){
                        ans.insert(moo);
                    }
                    cnt[moo]--;
                }
            }
            for(auto moo : moos){
                cnt[moo]++;
            }
            s[i] = og;
        }
        cout << ans.size() << "\n";
        for(auto moo : ans){
            cout << moo << "\n";
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
