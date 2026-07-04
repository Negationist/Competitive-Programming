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
    int a = 0;
    for(int i=0;i<40;i++){
        a+=1000;
        a*=(1.065);
    }
    cout << a;
    return 0;
}
