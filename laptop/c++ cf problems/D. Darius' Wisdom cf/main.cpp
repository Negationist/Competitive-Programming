#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;


void solve(){
    int n;
    cin >> n;
    vi a(n),b(n);
    vii ans;
    vector<set<int>> cnt(3);
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
        cnt[a[i]].insert(i);
    }
    sort(b.begin(),b.end());
    int j = 0;
    if(cnt[0].size()<=cnt[2].size()){ //0s are sorted baby
        while(b[j]==0){
            if(a[j]==0){
                cnt[0].erase(j);
            }
            else if(a[j]==1){
                int z = *cnt[0].begin();
                ans.pb({z+1,j+1});
                swap(a[z],a[j]);
                cnt[1].erase(j);
                cnt[1].insert(z);
                cnt[0].erase(z);
            } else{
                int one = *cnt[1].begin();
                int zero = *cnt[0].begin();
                ans.pb({j+1,one+1});
                ans.pb({j+1,zero+1});
                swap(a[j],a[one]);
                swap(a[j],a[zero]);
                cnt[1].erase(one);
                cnt[1].insert(zero);
                cnt[2].erase(j);
                cnt[2].insert(one);
                cnt[0].erase(zero);
            }
            j++;
        }
    } else{
        j = n-1;
        while(b[j]==2){
            if(a[j]==2){
                cnt[2].erase(j);
            }
            else if(a[j]==1){
                int two = *cnt[2].begin();
                ans.pb({two+1,j+1});
                swap(a[two],a[j]);
                cnt[1].erase(j);
                cnt[1].insert(two);
                cnt[2].erase(two);
            } else{
                int two = *cnt[2].begin();
                int one = *cnt[1].begin();
                ans.pb({j+1,one+1});
                ans.pb({j+1,two+1});
                swap(a[j],a[one]);
                swap(a[j],a[two]);
                cnt[0].erase(j);
                cnt[0].insert(one);
                cnt[1].erase(one);
                cnt[1].insert(two);
                cnt[2].erase(two);
            }
            j--;
        }
    }
    j=0; //should be one pointer
    int i = 0; //other pointer
    while(j<n && i<n){
        bool flag = false;
        while(!(a[j]!=1 && b[j]==1)){
            j++;
            if(j>=n){
                flag = true;
                break;
            }
        }
        while(!(a[i]==1 && b[i]!=1)){
            i++;
            if(i>=n){
                flag = true;
                break;
            }
        }
        if(flag) break;
        ans.pb({++i,++j});
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.ff << " " << x.ss << "\n";
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
