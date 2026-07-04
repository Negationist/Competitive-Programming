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
    int n,k;
    cin >> n >> k;
    map<string,tuple<int,int,bool>> m;
    for(int i=0;i<n;i++){
        string s;
        int num;
        cin >> s >> num;
        m[s] = {num,0,true};
    }
    int l;
    cin >> l;
    int mx = -1;
    string one;
    while(l--){
        string s;
        int num;
        cin >> s >> num;
        get<1>(m[s])++;
        if(get<0>(m[s]) < num){
            k-=(num-get<0>(m[s]));
            get<0>(m[s]) = num;
        }
        if(get<1>(m[s])>mx){
            mx = get<1>(m[s]);
            one = s;
        }
    }
    if(k<0){
        cout << 0 << "\n";
        return;
    }
    vii products;
    for(auto it=m.begin();it!=m.end();it++){
        int prod = (get<0>(it->second)+1)*(get<0>(it->second));
        //products.pb({prod,it->first});
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
