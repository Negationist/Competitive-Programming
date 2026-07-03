using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> parent, rank_size;
void debug(vector<ll> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
ll find_set(ll v) {
    if(parent[v] != v)
    {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_size[a] > rank_size[b])
            swap(a, b);
        parent[a] = b;
        rank_size[b] += rank_size[a];
    }
}
int main()
{
    //freopen("mootube.in","r",stdin);
    //freopen("mootube.out", "w", stdout);
    ll n, q; cin >> n >> q;
    vector<pair<ll, pii>> edges;
    for(int i = 0; i < n - 1; i++){
        ll p, q, r; cin >> p >> q >> r;
        edges.push_back({r, {p, q}});
    }
    vector<pair<pii, ll>> queries;
    for(int i = 0; i < q; i++){
        ll k, v; cin >> k >> v;
        queries.push_back({{k, v}, i});
    }
    sort(queries.begin(), queries.end());
    sort(edges.begin(), edges.end());
    for(int i = 0; i <= n; i++){
        parent.push_back(i);
        rank_size.push_back(1);
    }
    vector<ll> res(q);
    ll j = n - 2;
    for(int i = q - 1; i >= 0; i--){
        while(j >= 0 && edges[j].ff >= queries[i].ff.ff){
            union_sets(edges[j].ss.ff, edges[j].ss.ss);
            j--;
        }
        int par = find_set(queries[i].ff.ss);
        res[queries[i].ss] = rank_size[parent[queries[i].ff.ss]] - 1;
    }
    for(int i = 0; i < q; i++){
        cout << res[i] << "\n";
    }


}
