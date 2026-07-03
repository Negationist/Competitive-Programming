#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

struct dsu_node{
    dsu_node* parent;
    int cnt = 1;
    dsu_node(){
        parent = this;
    };
    dsu_node* _find(){
        if(parent != this){
            parent = parent->_find();
        }
        return parent;
    }
    bool unite(dsu_node* a, dsu_node* b){
        dsu_node* x = a->_find();
        dsu_node* y = b->_find();
        if(x==y) return false;
        if(x->cnt < y->cnt){
            swap(x,y);
        }
        y->parent = x;
        (x->cnt)+=(y->cnt);
        return true;
    }
};

void solve(){
    map<dsu_node*, int> deleted; 
    int n,m; cin >> n >> m;
    vector<vi> b(n, vi(m));
    vector<vector<dsu_node*>> node(n, vector<dsu_node*>(m, nullptr));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }
    int ans = 0;
    auto val = [&](int i, int j){
        //cout << i << " " << j << "\n";
        if(i>=0 && i<n && j>=0 && j<m){
            return b[i][j];
        } else{
            return -1LL;
        }
    };
    auto join = [&](int x1, int y1, int x2, int y2){
        //cout << "started\n";
        dsu_node first = *node[x1][y1], second = *node[x2][y2];
        if(deleted[node[x1][y1]->_find()] || deleted[node[x2][y2]->_find()]){
            if(!deleted[node[x1][y1]->_find()]){
                deleted[node[x1][y1]->_find()] = 1;
                --ans;
            }
            if(!deleted[node[x2][y2]->_find()]){
                deleted[node[x2][y2]->_find()] = 1;
                --ans;
            }
        }
        //cout << "in\n";
        if(!deleted[node[x1][y1]->_find()] && !deleted[node[x2][y2]->_find()]){
            ans-=(first.unite(node[x1][y1], node[x2][y2]));
        } else{
            first.unite(node[x1][y1], node[x2][y2]);
        }
        //cout << "out\n";
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ++ans;
            node[i][j] = new dsu_node();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j] > val(i+1, j) && val(i+1,j)!=-1) continue;
            if(b[i][j] > val(i-1, j) && val(i-1,j)!=-1) continue;
            if(b[i][j] > val(i, j+1) && val(i,j+1)!=-1) continue;
            if(b[i][j] > val(i, j-1) && val(i,j-1)!=-1) continue;
            if(b[i][j] == val(i+1, j)){
                join(i,j,i+1,j);
            }
            if(b[i][j] == val(i-1, j)){
                join(i,j,i-1,j);
            }
            if(b[i][j] == val(i, j+1)){
                join(i,j,i,j+1);
            }
            if(b[i][j] == val(i, j-1)){
                join(i,j,i,j-1);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(node[i][j] == nullptr) continue;
            if(b[i][j] > val(i+1, j) && val(i+1,j)!=-1){
                ans-=(1-deleted[node[i][j]->_find()]);
                deleted[node[i][j]->_find()] = 1;
                continue;
            }
            if(b[i][j] > val(i-1, j) && val(i-1,j)!=-1){
                ans-=(1-deleted[node[i][j]->_find()]);
                deleted[node[i][j]->_find()] = 1;
                continue;
            }
            if(b[i][j] > val(i, j+1) && val(i,j+1)!=-1){
                ans-=(1-deleted[node[i][j]->_find()]);
                deleted[node[i][j]->_find()] = 1;
                continue;
            }
            if(b[i][j] > val(i, j-1) && val(i,j-1)!=-1){
                ans-=(1-deleted[node[i][j]->_find()]);
                deleted[node[i][j]->_find()] = 1;
                continue;
            }
        }
    }
    //cout << "!here\n";
    cout << ans << "\n";
    int q; cin >> q;
    while(q--){
        int i,j,x; cin >> i >> j >> x;
        --i; --j;
        b[i][j]-=x;
        if(!deleted[node[i][j]->_find()]){
            deleted[node[i][j]->_find()] = 1;
            --ans;
        }
        node[i][j] = new dsu_node();
        ++ans;
        //cout << ans << "!!!!\n";
        bool mn = true;
        if(b[i][j] == val(i+1, j)){
            join(i,j,i+1,j);
        } else if(b[i][j] < val(i+1, j)){
            if(!deleted[node[i+1][j]->_find()]){
                ans--;
                deleted[node[i+1][j]->_find()] = 1;
                //cout << "down was not deleted\n";
            }
        } else if(val(i+1,j)!=-1){
            mn = false;
        }

        if(b[i][j] == val(i-1, j)){
            join(i,j,i-1,j);
        } else if(b[i][j] < val(i-1, j)){
            if(!deleted[node[i-1][j]->_find()]){
                ans--;
                deleted[node[i-1][j]->_find()] = 1;
                //cout << "up was not deleted\n";
            }
        } else if(val(i-1,j)!=-1){
            mn = false;
        }

        if(b[i][j] == val(i, j+1)){
            join(i,j,i,j+1);
        } else if(b[i][j] < val(i, j+1)){
            if(!deleted[node[i][j+1]->_find()]){
                ans--;
                deleted[node[i][j+1]->_find()] = 1;
                //cout << "right was not deleted\n";
            }
        } else if(val(i,j+1)!=-1){
            mn = false;
        }

        if(b[i][j] == val(i, j-1)){
            join(i,j,i,j-1);
        } else if(b[i][j] < val(i, j-1)){
            if(!deleted[node[i][j-1]->_find()]){
                ans--;
                deleted[node[i][j-1]->_find()] = 1;
                //cout << "left was not deleted\n";
            }
        } else if(val(i,j-1)!=-1){
            mn = false;
        }

        if(!mn){
            if(!deleted[node[i][j]->_find()]){
                deleted[node[i][j]->_find()] = 1;
                --ans;
            }
        }
        cout << ans << "\n";
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