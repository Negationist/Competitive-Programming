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
    int cnt[2*n+5][2];
    cnt[n][0] = cnt[n][1] = n+1;
    for(int i=n-1;i>=1;i--){
        int inc  = n-i;
        cnt[i][0] = (n+1-inc);
        cnt[i][1] = (n+1+inc);
    }
    vector<vi> a(n,vi(n));
    auto ans1 = a;
    auto ans2 = a;
    int fcnt[2*n+5] = {};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            fcnt[a[i][j]]++;
        }
    }
    if(n==1){
        cout << a[0][0] << "\n";
        return;
    }
    vi goal;
    for(int i=1;i<=n;i++){
        goal.pb(i);
    }
    int index;
    for(int i=0;i<n;i++){
        vi nums;
        for(int j=0;j<n;j++){
            nums.pb(fcnt[a[i][j]]);
        }
        sort(nums.begin(),nums.end());
        if(nums==goal){
           index = i;
           break;
        }
    }
    map<int,int> asgn;
    for(int i=0;i<n;i++){
        int num = fcnt[a[index][i]];
        int cur = cnt[num][0];
        asgn[a[index][i]] = cur;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(asgn[a[i][j]]){
                ans1[i][j] = asgn[a[i][j]];
            } else{
                int num = fcnt[a[i][j]];
                ans1[i][j] = cnt[num][1];
            }
        }
    }
    asgn.clear();
    for(int i=0;i<n;i++){
        int num = fcnt[a[index][i]];
        int cur = cnt[num][1];
        asgn[a[index][i]] = cur;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(asgn[a[i][j]]){
                ans2[i][j] = asgn[a[i][j]];
            } else{
                int num = fcnt[a[i][j]];
                ans2[i][j] = cnt[num][0];
            }
        }
    }
    vi goalmns;
    for(int i=2;i<=n+1;i++){
        goalmns.pb(i);
    }
    auto check = [&](vector<vi> cur)->bool{
        bool win = true;
        vi mns;
        for(int i=0;i<n;i++){
            auto temp = cur[i];
            sort(temp.begin(),temp.end());
            for(int i=1;i<n;i++){
                if(temp[i]!=temp[i-1]+1){
                    return false;
                }
            }
            mns.pb(temp[0]);
        }
        if(mns!=goalmns){
            win = false;
        }
        mns.resize(0);
        for(int i=0;i<n;i++){
            vi temp;
            for(int j=0;j<n;j++){
                temp.pb(cur[j][i]);
            }
            sort(temp.begin(),temp.end());
            for(int i=1;i<n;i++){
                if(temp[i]!=temp[i-1]+1){
                    return false;
                }
            }
            mns.pb(temp[0]);
        }
        if(mns!=goalmns){
            win = false;
        }
        return win;
    };
    bool pos1 = check(ans1);
    bool pos2 = check(ans2);
    if(pos1 && pos2){
        bool one;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans1[i][j]!=ans2[i][j]){
                    one = (ans1[i][j]>ans2[i][j]);
                    break;
                }
            }
        }
        if(one){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << ans1[i][j];
                    if(j!=n-1){
                        cout << " ";
                    } else if(i!=n-1){
                        cout << "\n";
                    }
                }
            }
        } else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << ans2[i][j];
                    if(j!=n-1){
                    cout << " ";
                } else if(i!=n-1){
                    cout << "\n";
                }
                }
            }
        }
    } else if(pos1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans1[i][j];
                if(j!=n-1){
                    cout << " ";
                } else if(i!=n-1){
                    cout << "\n";
                }
            }
        }
    } else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans2[i][j];
                 if(j!=n-1){
                    cout << " ";
                } else if(i!=n-1){
                    cout << "\n";
                }
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
