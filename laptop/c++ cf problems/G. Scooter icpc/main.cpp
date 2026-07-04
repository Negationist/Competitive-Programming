#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

string dict[3] = {"DRIVE", "PICKUP", "DROPOFF"};
vector<string> ans;
int ans_size = 0;
void out(int x, int n){
    ans.pb(dict[x]);
    ans.pb(" ");
    if(x==0){
        ans.pb(to_string(n));
    }
    ans.pb("\n");
    ++ans_size;
}

void solve(){
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    vector<stack<int>> b(6);
    int num = 0;
    for(int i=0;i<n;i++){
        if(s[0][i]=='-' && s[1][i]=='M'){
            b[0].push(i+1);
        }
        if(s[0][i]=='-' && s[1][i]=='C'){
            b[1].push(i+1);
        }
        if(s[0][i]=='C' && s[1][i]=='M'){
            b[2].push(i+1);
            ++num;
        }
        if(s[0][i]=='M' && s[1][i]=='C'){
            b[3].push(i+1);
            ++num;
        }
        if(s[0][i]=='M' && s[1][i]=='-'){
            b[4].push(i+1);
            ++num;
        }
        if(s[0][i]=='C' && s[1][i]=='-'){
            b[5].push(i+1);
            ++num;
        }
    }
    int last = -1;
    auto handle = [&](int x)->void{
        assert(b[x].size()>0);
        if(x!=0 && x!=1){
            --num;
        }
        last = x;
        if(x==0 || x==1){
            out(0,b[x].top());
            out(1,b[x].top());
            b[x].pop();
        } else if(x==2){
            out(0,b[x].top());
            out(2,b[x].top());
            if(b[3].size() || b[4].size()){
                out(1,b[x].top());
            } else{
                last = -1;
            }
            b[x].pop();
        } else if(x==3){
            out(0,b[x].top());
            out(2,b[x].top());
            if(b[2].size() || b[5].size()){
                out(1,b[x].top());
            } else{
                last = -1;
            }
            b[x].pop();
        }
        else{
            out(0,b[x].top());
            out(2,b[x].top());
            b[x].pop();
        }
    };
    while(num){
        if(last==0 || last==2){
            if(b[3].size()){
                handle(3);
            } else{
                handle(4);
            }
        } else if(last==1 || last==3){
            if(b[2].size()){
                handle(2);
            } else{
                handle(5);
            }
        } else{
            if(b[3].size() && b[0].size()){
                handle(0);
            } else if(b[2].size() && b[1].size()){
                handle(1);
            } else if(b[4].size() && b[0].size()){
                handle(0);
            } else{
                handle(1);
            }
        }
    }
    cout << ans_size << "\n";
    for(auto x : ans){
        cout << x;
    }
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solve();
    return 0;
}
