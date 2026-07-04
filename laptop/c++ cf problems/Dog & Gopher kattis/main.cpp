#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<long double, long double> goph;
    pair<long double, long double> dog;
    long double a,b,c,d;
    cin >> a >> b >> c >> d;
    goph.first = a;
    goph.second = b;
    dog.first = c;
    dog.second = d;
    long double x,y;
    bool win = false;
    long double wx,wy;
    while(cin >> x >> y){
        long double disGoph = sqrtl((goph.first-x)*(goph.first-x) + (goph.second-y)*(goph.second-y));
        long double disDog =  sqrtl((dog.first-x)*(dog.first-x) + (dog.second-y)*(dog.second-y));
        disDog/=2;
        if(disDog >= disGoph) {
                win = true;
                wx = x;
                wy = y;
        }
    }
    if(win){
        cout << "The gopher can escape through the hole at (" << fixed << setprecision(3) << wx << "," << wy << ").";
    } else {
        cout << "The gopher cannot escape.";
    }
    return 0;
}
