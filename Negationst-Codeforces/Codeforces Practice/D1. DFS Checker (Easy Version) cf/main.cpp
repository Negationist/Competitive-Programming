#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
int depth;
int n,q;
void check(int i, int j, set<pii> &baddiff, set<int> &badpar, set<int> &parents,vi &pos, vi&a){
    if(i!=1){
        int bro = (i%2==0 ? i+1 : i-1);
        pii fam = {i,bro};
        if(fam.ff > fam.ss) swap(fam.ff,fam.ss);
        int diff = abs(pos[i]-pos[bro]);
        int z = log2(i);
        int sub = depth-z;
        int num = (1LL<<sub)-1;
        if(diff==num){
            baddiff.erase(fam);
        } else{
            baddiff.insert(fam);
        }
    }
    if(j!=1){
        int bro = (j%2==0 ? j+1 : j-1);
        pii fam = {j,bro};
        if(fam.ff > fam.ss) swap(fam.ff,fam.ss);
        int diff = abs(pos[j]-pos[bro]);
        int z = log2(j);
        int sub = depth-z;
        int num = (1LL<<sub)-1;
        if(diff==num){
            baddiff.erase(fam);
        } else{
            baddiff.insert(fam);
        }
    }
    int x = pos[i];
    if(x!=0){
        int last = a[x-1];
        if(i/2 == last){
            badpar.erase(last);
        } else if(parents.find(last)!=parents.end()){
            badpar.insert(last);
        }
    }
    if(x!=n-1){
        int next = a[x+1];
        if(next/2 == i){
            badpar.erase(i);
        } else if(parents.find(i)!=parents.end()){
            badpar.insert(i);
        }
    }
    int y = pos[j];
    if(y>0){
        int last = a[y-1];
        if(j/2 == last){
            badpar.erase(last);
        } else if(parents.find(last)!=parents.end()){
            badpar.insert(last);
        }
    }
    if(y<n-1){
        int next = a[y+1];
        if(next/2 == j){
            badpar.erase(j);
        } else if(parents.find(j)!=parents.end()){
            badpar.insert(j);
        }
    }
}

void solve(){
    cin >> n >> q;
    depth = log2(n+1);
    set<int> parents;
    for(int i=0;i<n-1;i++){
        int z;
        cin >> z;
        parents.insert(z);
    }
    vi pos(n+1);
    vi a(n);
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        a[i] = z;
        pos[z] = i;
    }
    set<pii> baddiff;
    set<int> badpar;
    for(int i=1;i<=n;i++){
        check(i,i,baddiff,badpar,parents,pos,a);
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        swap(a[x],a[y]);
        swap(pos[a[x]],pos[a[y]]);
        check(a[x],a[y],baddiff,badpar,parents,pos,a);
        int num = baddiff.size()+ badpar.size();
        if(!num && a[0]==1LL){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
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
