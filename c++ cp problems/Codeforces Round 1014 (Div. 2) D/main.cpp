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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int T = 0, I = 0, L = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='T') ++T;
        else if(s[i]=='I') ++I;
        else ++L;
    }
    auto missing = [&](char a, char b){
        if(a!='T' && b!='T'){
            return 'T';
        } else if(a!='I' && b!='I'){
            return 'I';
        }
        return 'L';
    };
    vi out;
    if(T){
        for(int i=0;i<n-1;i++){
            if(s[i]=='T' && s[i+1]!='T'){
                string temp;
                for(int k=0;k<T;k++){
                    out.pb(i+1);
                    out.pb(i+1);
                    temp.pb(s[i+1]);
                    temp.pb(missing(s[i],s[i+1]));
                }
                T = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            } else if(s[i]!='T' && s[i+1]=='T'){
                string temp;
                int pos = i+1;
                for(int k=0;k<T;k++){
                    out.pb(pos);
                    ++pos;
                    out.pb(pos);
                    ++pos;
                    temp.pb(missing(s[i],s[i+1]));
                    temp.pb(s[i]);
                }
                T = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            }
        }
    }
    if(L){
        for(int i=0;i<n-1;i++){
            if(s[i]=='L' && s[i+1]!='L'){
                string temp;
                for(int k=0;k<L;k++){
                    out.pb(i+1);
                    out.pb(i+1);
                    temp.pb(s[i+1]);
                    temp.pb(missing(s[i],s[i+1]));
                }
                L = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            } else if(s[i]!='L' && s[i+1]=='L'){
                string temp;
                int pos = i+1;
                for(int k=0;k<L;k++){
                    out.pb(pos);
                    ++pos;
                    out.pb(pos);
                    ++pos;
                    temp.pb(missing(s[i],s[i+1]));
                    temp.pb(s[i]);
                }
                L = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            }
        }
    }
    if(I){
        for(int i=0;i<n-1;i++){
            if(s[i]=='I' && s[i+1]!='I'){
                string temp;
                for(int k=0;k<I;k++){
                    out.pb(i+1);
                    out.pb(i+1);
                    temp.pb(s[i+1]);
                    temp.pb(missing(s[i],s[i+1]));
                }
                I = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            } else if(s[i]!='I' && s[i+1]=='I'){
                string temp;
                int pos = i+1;
                for(int k=0;k<I;k++){
                    out.pb(pos);
                    ++pos;
                    out.pb(pos);
                    ++pos;
                    temp.pb(missing(s[i],s[i+1]));
                    temp.pb(s[i]);
                }
                I = 0;
                s.insert(i+1,temp);
                n = s.size();
                break;
            }
        }
    }
    if(max(T,max(I,L))==0){
        cout << out.size() << "\n";
        for(int x : out){
            cout << x << "\n";
        }
    } else{
        cout << -1 << "\n";
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
