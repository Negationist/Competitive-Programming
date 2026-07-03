#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int binPowMod(int b, int p, int mod){
    int res = 1;
    b%=mod;
    while(p>0){
        if(p&1){
            res*=b;
            res%=mod;
        }
        p>>=1;
        b = (b*b)%mod;
    }
    return res;
}

int modInv(int x, int mod){
    return binPowMod(x,mod-2,mod);
}

struct Fraction {
    pair<int, int> fraction;

    void simplify() {
        int g = __gcd(fraction.first, fraction.second);
        fraction.first /= g;
        fraction.second /= g;
        if (fraction.second < 0) {
            fraction.first = -fraction.first;
            fraction.second = -fraction.second;
        }
    }

    Fraction(int num, int denom) : fraction(num, denom) {
        if (denom == 0){
            fraction.ff = 0;
            fraction.ss = 1;
        }
        simplify();
    }

    Fraction operator+(const Fraction &other) const {
        int num = fraction.first * other.fraction.second + other.fraction.first * fraction.second;
        int denom = fraction.second * other.fraction.second;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction &other) const {
        int num = fraction.first * other.fraction.second - other.fraction.first * fraction.second;
        int denom = fraction.second * other.fraction.second;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction &other) const {
        return Fraction(fraction.first * other.fraction.first, fraction.second * other.fraction.second);
    }

    Fraction operator/(const Fraction &other) const {
        if (other.fraction.first == 0) throw invalid_argument("Cannot divide by zero");
        return Fraction(fraction.first * other.fraction.second, fraction.second * other.fraction.first);
    }

    void print() const {
        cout << fraction.first << "/" << fraction.second << "\n";
    }
    void modDebug(){
        int res = (fraction.first*modInv(fraction.ss,mod))%mod;
        cout << res << "\n";
    }
    void modulo(){
        fraction.ff%=mod;
        fraction.ss%=mod;
    }
};

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++){
        if(i<k){
            sum1+=a[i];
        } else{
            sum2+=a[i];
        }
    }
    sum1%=mod;
    sum2%=mod;
    Fraction avg1(sum1,k);
    Fraction t1((n-k+2)/2*k,n-k+1);
    t1.modulo();
    t1 = t1*avg1;
    t1.modulo();
    Fraction t2((n-k+1)/2*sum2,n-k);
    t2.modulo();
    Fraction ev1 = t1+t2;
    ev1.modulo();
    ev1.modDebug();
    Fraction t3((k*(n-k+1))-((n-k+2)/2*k),n-k+1);
    t3.modulo();
    t3 = t3*Fraction(sum1,k);
    t3.modulo();
    Fraction t4((n-k-((n-k+1)/2))*sum2,n-k);
    t4.modulo();
    Fraction ev2 = t3+t4;
    ev2.modulo();
    ev2.modDebug();
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
