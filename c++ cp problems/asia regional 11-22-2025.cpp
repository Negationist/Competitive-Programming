#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define all(x) (int)(x.begin(), x.end())
#define ff first
#define ss second
#define int long long

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    unordered_map<int,int> to;
    vector<string> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    vi occur(q+1,0), queries(q+1);
    unordered_set<int> exists;
    for(int i=1;i<=q;i++){
        cin >> queries[i];
        to[queries[i]] = i;
        exists.insert(queries[i]);
    }
    auto thing = [&](vector<char> &seq)->void {
        vector<array<int,4>> dp; //{value, products, last, flag}
        for(int i=0;i<(int)seq.size();i++){
            vector<array<int,4>> ndp;
            char x = seq[i];
            for(auto [value, products, last, flag] : dp){
                array<int,4> consider;
                if(x=='+'){
                    if(flag!=2) continue;
                    consider = {value+(products * last), -1, -1, 0};
                } else if(x=='*'){
                    if(flag!=2) continue;
                    consider = {value, products * last, -1, 1};
                } else{ //is a number
                    if(flag == 0){
                        consider = {value, 1, (int)(x - '0'), 2};
                    } else if(flag == 1){
                        consider = {value, products, (int)(x - '0'), 2};
                    } else{
                        consider = {value, products, last*10+(int)(x - '0'), 2};
                    }
                }
                ndp.pb(consider);
            }
            vector<array<int,4>> real;
            for(auto [value, products, last, flag] : ndp){
                if(flag == 0){
                    if(value <= 1000000){
                        real.pb({value, products, last, flag});
                    }
                } else if(flag == 1){
                    if(value <= 1000000 && products <= 1000000){
                        real.pb({value, products, last, flag});
                    }
                } else{
                    if(value <= 1000000 && products <= 1000000){
                        real.pb({value, products, last, flag});
                    }
                    int res = value + (products * last);
                    if(exists.find(res) != exists.end()){
                        occur[to[res]]++;
                    }
                }
            }
            if(x!='+' && x!='*'){
                real.pb({0,1,(int)(x - '0'), 2});
            }
            dp = move(real);
            //cout << "_______________________________\n";
        }
    };
    for(int i=0;i<n;i++){//horizontals
        vector<char> bruh;
        for(char x : b[i]){
            bruh.pb(x);
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=0;i<m;i++){ //verts
        vector<char> bruh;
        for(int j=0;j<n;j++){
            bruh.pb(b[j][i]);
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=0;i<m;i++){ //down and to the right from top
        int x = 0, y = i;
        vector<char> bruh;
        while(x>=0 && x<n && y>=0 && y<m){
            bruh.pb(b[x][y]);
            x++;
            y++;
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=1;i<n;i++){ //down and to the right from left
        int x = i, y = 0;
        vector<char> bruh;
        while(x>=0 && x<n && y>=0 && y<m){
            bruh.pb(b[x][y]);
            x++;
            y++;
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=0;i<m;i++){ //down and to the left from top
        int x = 0, y = i;
        vector<char> bruh;
        while(x>=0 && x<n && y>=0 && y<m){
            bruh.pb(b[x][y]);
            x++;
            y--;
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=1;i<n;i++){ //down and to the left from right side
        int x = i, y = m-1;
        vector<char> bruh;
        while(x>=0 && x<n && y>=0 && y<m){
            bruh.pb(b[x][y]);
            x++;
            y--;
        }
        thing(bruh);
        reverse(bruh.begin(),bruh.end());
        thing(bruh);
    }
    for(int i=0;i<n;i++){ //verts
        for(int j=0;j<m;j++){
            char x = b[i][j];
            if(x!='+' && x!='*'){
                int res = (int)(x-'0');
                if(exists.find(res) != exists.end()){
                    occur[to[res]]++;
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cout << occur[i] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}