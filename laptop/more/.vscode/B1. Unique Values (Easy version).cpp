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
    int n; cin >> n;
    set<int> ans;
    auto guess = [&](int x){
        int inc = 0, ptr = 1;
        cout << "? " << x + (int)ans.size() << " ";
        while(inc < x){
            if(ans.find(ptr) == ans.end()){
                cout << ptr << " ";
                ++inc;
            }
            ++ptr; 
        }
        for(int y : ans){
            cout << y << " ";
        }
        cout << "\n";
        cout.flush();
        int z; cin >> z;
        return z;
    };
    auto get_num = [&](int x){
        int inc = 0, ptr = 1;
        while(inc < x){
            if(ans.find(ptr) == ans.end()){
                ++inc;
            }
            ++ptr; 
        }
        return ptr-1;
    };
    while((int)ans.size() < 3){
        int lo = 3-(int)(ans.size()), hi = 2*n+1-(int)(ans.size());
        //cout << "lo is " << lo << ", high is " << hi << "\n";
        while(lo <= hi){ //find the earliest element such that there are 3 instances of a number
            int mid = (lo+hi)/2;
            int res = guess(mid);
            if((mid + (int)(ans.size()) - res)%2 == 1){
                hi = mid-1;
            } else{
                lo = mid+1;
            }
            //cout << "lo is " << lo << ", high is " << hi << "\n";
        }
        cout << get_num(lo) << "!!\n";
        int z = get_num(lo);
        ans.insert(z);
        for(int y : ans){
            cout << y << "!!\n";
        }
    }
    cout << "! ";
    for(int x : ans){
        cout << x << " ";
    }
    cout << "\n";
    cout.flush();
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