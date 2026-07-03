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
    string s;
    cin >> s;
    int n = s.size();
    if(n%2==1){
        for(int i=0;i<n-1;i++){
            cout << "9";
        }
    } else{
        if(1==0){
            //china
        } else{
            vi cnt(10,0);
            int best = -1;
            int to;
            int bad = 1;
            cnt[s[0]-'0'] = 1;
            for(int i=1;i<n;i++){
                int cur = s[i]-'0';
                int num = (n-1-(i+1)+1);
                for(int j=cur-1;j>=0;j--){
                    //test this character being i
                    cnt[j] = 1-cnt[j];
                    if(cnt[j]) bad++;
                    else bad--;
                    if(num>=bad){
                        best = i;
                        to = j;
                        cnt[j] = 1-cnt[j];
                        if(cnt[j]) bad++;
                        else bad--;
                        break;
                    }
                    cnt[j] = 1-cnt[j];
                    if(cnt[j]) bad++;
                    else bad--;

                }
                cnt[cur] = (cnt[cur]+1)%2;
                if(cnt[cur]) bad++;
                else bad--;
            }
            if(best==-1){
                --s[0];
                if(s[0]!='0'){
                    cout << s[0] << s[0];
                }
                for(int i=0;i<n-2;i++){
                    cout << "9";
                }
            } else{
                cnt.assign(10,0);
                for(int i=0;i<best;i++){
                    int cur = (int)(s[i]-'0');
                    cnt[cur] = (cnt[cur]+1)%2;
                    cout << s[i];
                }
                cout << (char)(to+'0');
                cnt[to] = (cnt[to]+1)%2;
                vector<int> fixing;
                for(int i=9;i>=0;i--){
                    if(cnt[i]){
                        fixing.pb(i);
                    }
                }
                int num = n-(best+1)-fixing.size();
                for(int i=0;i<num;i++){
                    cout << "9";
                }
                for(int x : fixing){
                    cout << (char)(x+'0');
                }
            }
        }
    }
    cout << "\n";
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
