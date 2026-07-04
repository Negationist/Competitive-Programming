#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int binPow(int b, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) {
            if (res > LLONG_MAX / b) return LLONG_MAX;
            res *= b;
        }
        p >>= 1;
        if (b > LLONG_MAX / b) return LLONG_MAX;
        b *= b;
    }
    return res;
}


int take(int f, int base) {
    int l = 1, r = 63;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int res = binPow(f, mid);
        if (res == LLONG_MAX || res > base) {
            r = mid - 1;
        } else if (base % res == 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    map<int,int> z;
    int num = 0;
    int og = n;
    for(int i=2;i<=sqrtl(og);i++){
        while(n%i==0){
            int res = take(i,n);
            z[i]+=res;
            num+=res;
            n/=binPow(i,res);
        }
    }
    if(n>1){
        z[n]++;
        num++;
    }
    if(z.size()>2){
        cout << "tie\n";
    } else if(z.size()==2){
        int x,y;
        int inc = 0;
        for(auto num : z){
            if(!inc){
                x = num.ss;
            } else{
                y = num.ss;
            }
            inc++;
        }
        if(abs(x-y)>=2){
            cout << "tie\n";
        } else{
            if(num%2==0){
            if(s=="Alice"){
                cout << "Bob\n";
            } else{
                cout << "Alice\n";
            }
        } else{
            cout << s << "\n";
        }
        }
    } else{
        if(num%2==0){
            if(s=="Alice"){
                cout << "Bob\n";
            } else{
                cout << "Alice\n";
            }
        } else{
            cout << s << "\n";
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
