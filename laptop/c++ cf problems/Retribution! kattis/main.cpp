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
    int n,m,p;
    cin >> n >> m >> p;
    vii j(n);
    vii r(m);
    vii s(p);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        j[i] = {a,b};
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        r[i] = {a,b};
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin >> a >> b;
        s[i] = {a,b};
    }
    vector<vector<long double>> rD(n, vector<long double>(m));
    vector<vector<long double>> sD(n, vector<long double>(p));
    multiset<tuple<long double, int,int >> arD;
    multiset<tuple<long double, int,int >> asD;
    for(int i=0;i<n;i++){
        for(int z=0;z<m;z++){
            int f = j[i].first-r[z].first;
            int l = j[i].second-r[z].second;
            rD[i][z] = sqrt(f*f+l*l);
            arD.insert({rD[i][z],i,z});
        }
    }

    for(int i=0;i<n;i++){
        for(int z=0;z<p;z++){
            int f = j[i].first-s[z].first;
            int l = j[i].second-s[z].second;
            sD[i][z] = sqrt(f*f+l*l);
            asD.insert({sD[i][z],i,z});
        }
    }
    long double ans =0;
    for(int i=0;i<n;i++){
        long double inc = get<0>(*(arD.begin()));
        int tag = get<1>(*(arD.begin()));
        for(int j=0;j<m;j++){
            auto it = arD.find({rD[tag][j],tag,j});
            arD.erase(it);
        }
        ans+=inc;
    }
    for(int i=0;i<n;i++){
        long double inc = get<0>(*(asD.begin()));
        int tag = get<1>(*(asD.begin()));
        for(int j=0;j<p;j++){
            auto it = asD.find({sD[tag][j],tag,j});
            asD.erase(it);
        }
        ans+=inc;
    }
    cout << fixed << setprecision(15) << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
