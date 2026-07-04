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

void begone(vector<int> &a){
    cout << "- " << a.size() << " ";
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n";
    cout.flush();
}

void guess(int x){
    cout << "! " << x << "\n";
    cout.flush();
}

int here;
void solve(){
    int n;
    cin >> n;
    vector<map<int,int>> cnt(10);
    int i = -1;
    while(true){
        i++;
        vector<int> cur;
        for(int j=0;j<n;j++){
            int z;
            cin >> z;
            cnt[i][z]++;
            cur.pb(z);
        }
        if(i==0){
            cout << "- 0\n";
            cout.flush();
            continue;
        }
        int found = -1;
        int index = -1;
        for(auto x : cnt[i]){
            int l = x.ff;
            if(cnt[i][l]>cnt[i-1][l]){
                found = x.ff;
                break;
            }
        }
        if(found==-1){
            cout << "- 0\n";
            cout.flush();
            continue;
        } else{
            vector<int> gone;
            for(int j=0;j<n;j++){
                if(cur[j]!=found){
                    gone.pb(j+1);
                    cnt[i][cur[j]]--;
                } else{
                    index = j;
                }
            }
            n-=gone.size();
            if(n==1){
                guess(index+1);
                return;
            }
            begone(gone);
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
