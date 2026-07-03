#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
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

//#include <bits/stdc++.h>
//using namespace std;

const int mod = 1e9+7;

struct Matrix{
    vector<vi> cell;
    int n,m;
    Matrix(int x, int y){
        n = x;
        m = y;l
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
    int n,k, ans = 1;
    cin >> n >> k;
    auto contribute = [&](int x){
        Matrix dp(2,2);
        dp.update(0,1,x); //is to not
        dp.update(1,0,1); //not to is
        dp.update(1,1,1); //is to is
        dp = dp.powMod(n-1,mod);
        Matrix res(2,1);
        res.cell[0][0] = x;
        res.cell[1][0] = 1;
        res = dp*res;
        int total = (res.cell[0][0]+res.cell[1][0])%mod;
        ans = (ans*total)%mod;
    };
    map<int,int> primes;
    while(k!=1){
        bool found = false;
        for(int i=2;i<=sqrt(k);i++){
            if(k%i==0){
                found = true;
                while(k%i==0){
                    k/=i;
                    primes[i]++;
                }
                break;
            }
        }
        if(!found){
            primes[k]++;
            break;
        }
    }
    for(auto [x,num] : primes){
        contribute(num);
    }
    cout << ans << "\n";
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