#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int MOD = 1e9+7;
vector<int> a(6);
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a[0] >> a[1];
    int n;
    cin >> n;
    n--;
    for(int i=2;i<6;i++){
        a[i] = a[i-1]-a[i-2];
    }
    cout << (a[n%6]+100*MOD)%MOD;
    return 0;
}
