#include <bits/stdc++.h>
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

int MOD = 2;
struct mi {
    int v;
    explicit operator int() const { return v; }

    mi() : v(0) {}
    mi(long long _v) : v(int(_v % MOD)) { if (v < 0) v += MOD; }
};
mi &operator+=(mi &a, mi b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mi &operator-=(mi &a, mi b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(1LL * a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    mi res = 1;
    while (p) { if (p & 1) res *= a; a *= a; p >>= 1; }
    return res;
}
mi inv(mi a) { assert(a.v); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
mi &operator/=(mi &a, mi b) { return a = a / b; }
inline bool operator==(mi a, mi b) { return a.v == b.v; }
inline bool operator!=(mi a, mi b) { return a.v != b.v; }
inline bool operator<(mi a, mi b)  { return a.v <  b.v; }
inline bool operator>(mi a, mi b)  { return a.v >  b.v; }
inline bool operator<=(mi a, mi b) { return a.v <= b.v; }
inline bool operator>=(mi a, mi b) { return a.v >= b.v; }
inline mi abs(mi a) { return (a.v < 0 ? mi(-a.v) : a); }
inline std::ostream& operator<<(std::ostream& os, const mi& x) { return os << x.v; }

template<class T> struct Matrix{
    enum FieldType {
        DOUBLE = 0,
        MOD = 1
    };
    int n,m,type;
    static constexpr double eps = 1e-10;
    vector<vector<T>> data;
    Matrix(int n, int m) : n(n), m(m), data(n,vector<T>(m,T(0))){set_type();}
    vector<T>& operator[](int i) {return data[i];}
    Matrix<T> operator*(Matrix<T>& other) const{
        assert(m == other.n);
        Matrix<T> res(n,other.m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<other.m;k++){
                    res[i][k] += data[i][j] * other[j][k];
                }
            }
        }
        return res;
    }
    void eye(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                data[i][j] = (i==j);
            }
        }
    }
    Matrix<T> operator^(ll p) {
		assert(p >= 0 && n==m);
		Matrix<T> res(n,n);
        res.eye();
        Matrix base = *this;
        while(p){
            if(p&1){
                res = res*base;
            }
            base = base*base;
            p>>=1;
        }
        return res;
	}
    void set_type(){
        if constexpr (std::is_floating_point<T>::value){
            type = DOUBLE;
        } else{
            type = MOD;
        }
    }
    void rref(){
        int last_row = -1; //last row that had a pivot 
        for(int j=0;j<m;j++){ //pivot column
            int pivot_row = -1;
            if constexpr(std::is_floating_point_v<T>){
                T max_pivot = eps;
                for(int i=last_row+1;i<n;i++){
                    T num = abs(data[i][j]);
                    if(num>max_pivot){
                        pivot_row = i;
                        max_pivot = num;
                    }
                }
            } else{
                for(int i=last_row+1;i<n;i++){
                    T num = data[i][j];
                    if(num!=T(0)){
                        pivot_row = i;
                        break;
                    }
                }
            }
            if(pivot_row==-1) continue;
            last_row++;
            swap(data[last_row],data[pivot_row]);
            for(int i=0;i<n;i++){
                if(i!=last_row){
                    if(nonzero(data[i][j])){
                        T fact = (data[i][j]/data[last_row][j])*(T)(-1);
                        for(int k=j;k<m;k++){
                            data[i][k]+=(data[last_row][k]*fact);
                        }
                    }
                }
            }
            for(int k=j+1;k<m;k++){
                data[last_row][k]/=data[last_row][j];
            }
            data[last_row][j] = T(1);
        }
    }
    void transpose(){
        Matrix<T> res(m,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][i] = data[i][j];
            }
        }
        *this = res;
    }
    bool nonzero(T val){
        if(type==DOUBLE){
            return (abs(val)>eps);
        } else{
            return (val!=T(0));
        }
    }
    friend Matrix<T> rref(const Matrix<T> &A){
        Matrix<T> res = A;
        res.rref();
        return res;
    }
    friend Matrix<T> transpose(const Matrix<T> &A){
        Matrix<T> res = A;
        res.transpose();
        return res;
    }
    friend int rankof(const Matrix<T> &A){
        int res = 0;
        Matrix<T> temp = A;
        temp.rref();
        for(int i=0;i<temp.n;i++){
            bool found = 0;
            for(int j=0;j<temp.m;j++){
                if(temp.nonzero(temp[i][j])){
                    found = 1;
                }
            }
            res+=found;
        }
        return res;
    }
    friend int nullityof(const Matrix<T> &A){
        return A.m-rankof(A);
    }
    friend void debug(const Matrix<T> &A){
        cout << "\n";
        for(int i=0;i<A.n;i++){
            for(int j=0;j<A.m;j++){
                cout << A.data[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

const int maxN = 5001;
int num_primes;

int sieve[maxN] = {};
vi primes;
 
void compute(){
    for(int i=2;i<maxN;i++) sieve[i] = i;
    for(int i=2;i<maxN;i++){
        if(sieve[i]==i){
            for(int j=i;j<maxN;j+=i){
                sieve[j] = i;
            }
            primes.pb(i);
        }
    }
    num_primes = sz(primes);
}

void solve(){
   int n;
   cin >> n;
   Matrix<mi> A(num_primes,n);
   for(int i=0;i<n;i++){
        int z;
        cin >> z;
        for(int j=0;j<num_primes;j++){
            while(z%primes[j]==0){
                A[j][i]+=1;
                z/=primes[j];
            }
        }
   }
   int num = nullityof(A);
   MOD = 1e9+7;
   mi ans = pow(mi(2),num);
   cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    compute();
    solve();
    return 0;
}