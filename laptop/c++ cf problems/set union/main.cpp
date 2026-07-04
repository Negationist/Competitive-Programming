#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void unite(int a, int b, vi &link, vi &cnt){
    while(a!=link[a]) a=link[a];
    while(b!=link[b]) b=link[b];
    if(link[a]==link[b]) return;
    if(cnt[a]<cnt[b]) swap(a,b);
    cnt[a]+=cnt[b];
    link[b] = a;
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    cin >> n;
    vi cnt(n);
    vi link(n);
    for(int i=0;i<n;i++){
        cnt[i] = 1;
        link[i] = i;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        unite(a,b,link,cnt);
    }
    set<int> s;
    for(int i=0;i<n;i++){
        int z = i;
        while(z!=link[z]) z = link[z];
        s.insert(z);
    }
    cout << s.size() << "\n";
    return 0;
}
