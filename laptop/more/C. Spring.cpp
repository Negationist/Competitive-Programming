#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endl
#define each(a, x) for(auto &&a : x)

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;

void solve(){
    int A,B,C,m;
    cin >> A >> B >> C >> m;
    int a, b, c, a_b, a_c, b_c, a_b_c;
    a = m/A;
    b = m/B;
    c = m/C;
    int temp = A*B/(__gcd(A,B));
    a_b = m/temp;
    temp = A*C/(__gcd(A,C));
    a_c = m/temp;
    temp = C*B/(__gcd(C,B));
    b_c = m/temp;
    temp = lcm(lcm(A, B), C);
    a_b_c = m/temp;
    //cout << a_b_c << "chicken\n";
    //cout << a << " " << b << " " << c << " " << a_b << " " << a_c << " " << b_c << " " << a_b_c << "\n";
    int a_r = (a - a_b - a_c + a_b_c) * 6;
    int b_r = (b - a_b - b_c + a_b_c) * 6;
    int c_r = (c - a_c - b_c + a_b_c) * 6;
    a_r+=((a_b + a_c - 2 * a_b_c) * 3);
    b_r+=((a_b + b_c - 2 * a_b_c) * 3);
    c_r+=((a_c + b_c - 2 * a_b_c) * 3);
    a_r+=(2 * a_b_c);
    b_r+=(2 * a_b_c);
    c_r+=(2 * a_b_c);
    cout << a_r << " " << b_r << " " << c_r << "\n";
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