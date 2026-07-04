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

int ask(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int z;
    cin >> z;
    return z;
}
void guess(int i, int j){
    cout << "! " << i << " " << j << "\n";
    cout.flush();
    int trash;
    cin >> trash;
    assert(trash==1);
}

void solve(){
    int n;
    cin >> n;
    if(n==2){
        guess(1,2);
        return;
    }
    vi done(n+1,0);
    done[1] = done[2] = done[3] = 1;
    int i = 1,j = 2, k = 3;
    int inc = 0;
    while(inc<n-3){
        int x = ask(i,j);
        int y = ask(i,k);
        if(x==y){
            while(done[i]){
                ++i;
            }
            done[i] = 1;
        } else if(x<y){
            while(done[j]){
                ++j;
            }
            done[j] = 1;
        } else{
            while(done[k]){
                ++k;
            }
            done[k] = 1;
        }
        ++inc;
    }
    int x = ask(i,j);
    int y = ask(i,k);
    if(x==y){
        guess(j,k);
    } else if(x<y){
        guess(i,k);
    } else{
        guess(i,j);
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
