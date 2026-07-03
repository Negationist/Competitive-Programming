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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> c_a, c_b, b_c, b_a;
    for(int i=0;i<q;i++){
        char x,y;
        cin >> x >> y;
        if(x=='c' && y=='a'){
            c_a.insert(i);
        } else if(x=='c' && y=='b'){
            c_b.insert(i);
        } else if(x=='b' && y=='c'){
            b_c.insert(i);
        } else if(x=='b' && y=='a'){
            b_a.insert(i);
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='b'){
            if(b_a.size()){
                s[i] = 'a';
                int pos = *b_a.begin();
                b_a.erase(pos);
            } else if(b_c.size() && c_a.size()){
                int l = *b_c.begin();
                auto it = c_a.lower_bound(l);
                if(it!=c_a.end()){
                    int r = *it;
                    s[i] = 'a';
                    b_c.erase(l);
                    c_a.erase(r);
                }
            }
        }
        if(s[i]=='c'){
            bool done = false;
            if(c_a.size()){
                done = true;
                s[i] = 'a';
                int pos = *c_a.begin();
                c_a.erase(pos);
            } else if(c_b.size() && b_a.size()){
                int l = *c_b.begin();
                auto it = b_a.lower_bound(l);
                if(it!=b_a.end()){
                    done = true;
                    int r = *it;
                    s[i] = 'a';
                    c_b.erase(l);
                    b_a.erase(r);
                }
            }
            if(c_b.size() && !done){
                s[i] = 'b';
                int pos = *c_b.begin();
                c_b.erase(pos);
            }
        }
    }
    cout << s << "\n";
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
