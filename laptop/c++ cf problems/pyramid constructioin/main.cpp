#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int h,n,m;
    cin >> h >> n >> m;
    int a=0,b=0;
    if(n==0){ //if we have no 2x2 add one
        a++;
        n++;
    }
    n--; //take away one 2x2
    m+=(n/2); //convert
    n-=(n/2)*2; //convert
    for(int i=2;i<=h;i++){
        int take = 2*(i-1);
        m-=take; //take away 4x2s
    }
    if(m>0){ //we have enough
        cout << a << " " << b;
    } else if(m<0 && n%2==1){
        a++; //make one more a
        m++; //basically an extra 4x2
        b+=(-1*m); //need -m more blocks
        cout << a << " " << b;
    } else{
        b+=(-1*m); //need -m more blocks
        cout << a << " " << b;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
