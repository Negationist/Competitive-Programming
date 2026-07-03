#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
const int mod = 1e9+7;
struct Matrix{
    vector<vi> cell;
    int n,m;
    Matrix(int x, int y){
        n = x;
        m = y;
        cell.assign(n,vi(m,0));
    }
    Matrix operator*(const Matrix& other){
        int x = n;
        int y = other.m;
        Matrix res(x,y);
        if(m!=other.n){
            cout << "check indexing!\n";
        } else{
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    for(int k=0;k<m;k++){
                        //int inc = (cell[i][k]*other.cell[k][j]);
                        //res.cell[i][j]+=inc;
                        int inc = (cell[i][k]*other.cell[k][j])%mod;
                        res.cell[i][j]+=inc;
                        res.cell[i][j]%=mod;
                    }
                }
            }
        }
        return res;
    }
    void update(int i, int j, int num){
        if(i<n && j<m){
            cell[i][j] = num;
        } else{
            cout << "check indexing!\n";
        }
    }
    void identity(){
        if(n!=m){
            cout << "check indexing!\n";
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    cell[i][j] = 1;
                } else{
                    cell[i][j] = 0;
                }
            }
        }
    }
    void debug(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << cell[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void normalize(int mod){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cell[i][j]%=mod;
            }
        }
    }
    Matrix powMod(int p, int mod){
        Matrix res(n,m);
        Matrix temp = *this;
        temp.normalize(mod);
        res.identity();
        if(n!=m){
            cout << "check indexing!\n";
        }
        while(p>0){
            if(p&1){
                res = res*temp;
            }
            p/=2;
            temp = temp*temp;
        }
        return res;
    }
};

void solve(){
    int n,k;
    cin >> n >> k;
    vii r(n);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        r[i] = {b-a,c};
        if(i==n-1){
            r[i].ff = k-a;
        }
    }
    Matrix pos(1,16);
    pos.update(0,0,1);
    Matrix trans(16,16);
    for(int k=0;k<n;k++){
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                if(abs(i-j)<=1 && j<=r[k].ss && i<=r[k].ss){
                    trans.update(i,j,1);
                } else{
                    trans.update(i,j,0);
                }
            }
        }
        trans = trans.powMod(r[k].ff,mod);
        pos = pos*trans;
    }
    cout << pos.cell[0][0] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
