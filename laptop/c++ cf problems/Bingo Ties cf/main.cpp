#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define print(x) cout << (x) << endl
#define each(a, x) for (auto &&a : x)

using namespace std;
using tii = array<int,5>;

struct array_hash {
    size_t operator()(const array<int, 5> &arr) const {
        size_t hash_val = 0;
        for (int i = 0; i < 5; i++) {
            hash_val ^= hash<int>{}(arr[i]) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
        }
        return hash_val;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<tii>> a(n, vector<tii>(5));
    for (int i=0;i<n;i++){
        for (int j=0;j<5;j++){
            for (int k=0;k<5;k++){
                cin >> a[i][j][k];
            }
            sort(a[i][j].begin(),a[i][j].end());
        }
    }
    unordered_map<tii,int,array_hash> cnt;
    for (int i=0;i<n;i++){
        for (int j=0;j<5;j++){
            ++cnt[a[i][j]];
        }
    }
    auto check = [&](vi &temp)->bool{
        int z = temp.size();
        int good = true;
        for(int i=0;i<z;i++){
            for(int j=i+1;j<z;j++){
                for(int k=j+1;k<z;k++){
                    for(int l=k+1;l<z;l++){
                        for(int m=l+1;m<z;m++){
                            tii temp2 = {temp[i],temp[j],temp[k],temp[l],temp[m]};
                            if(cnt[temp2]){
                                good = false;
                            }
                        }
                    }
                }
            }
        }
        return good;
    };
    for(int i=0;i<n;i++){ //first
        for(int j=i+1;j<n;j++){ //second
            for(int k=0;k<5;k++){ //first row
                for(int l=0;l<5;l++){ //2nd row
                    for(int m=0;m<5;m++){ //entry taken from first row
                        int tie_val = a[i][k][m];
                        set<int> vals;
                        int num = 0;
                        for(int x : a[i][k]){
                            if(x!=tie_val){
                                vals.insert(x);
                            } else{
                                ++num;
                            }
                        }
                        for(int x : a[j][l]){
                            if(x!=tie_val){
                                vals.insert(x);
                            } else{
                                ++num;
                            }
                        }
                        if(num==2){
                            vi temp;
                            for(int x : vals){
                                temp.pb(x);
                            }
                            if(check(temp)){
                                cout << i+1 << " " << j+1 << "\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "no ties\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
