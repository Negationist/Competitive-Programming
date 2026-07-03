#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vll vector<pair<long long,long long>>
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using i128 = __int128;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

struct change{
    int device, time, load;
};

void solve(){
    int d,u;
    cin >> d >> u;
    map<string, int> id;
    map<int, string> id_reverse;
    int inc = -1;
    for(int i=0;i<d;i++){
        string s;
        cin >> s;
        id[s] = ++inc;
        id_reverse[inc] = s;
    }
    vector<vector<change>> changes(u);
    for(int i=0;i<u;i++){
        string device; cin >> device;
        int s,f,w;
        cin >> s >> f >> w;
        changes[i].pb({id[device],s,w});
        changes[i].pb({-1,f,0});
    }
    auto combine = [&](vector<change> &l, vector<change> &r)->vector<change>{
        // cout << "l is\n";
        // for(auto x : l){
        //     cout << (x.device!=-1?id_reverse[x.device]:"-1") << " " << x.time << " " << x.load << "\n";
        // }
        // cout << "r is\n";
        // for(auto x : r){
        //     cout << (x.device!=-1?id_reverse[x.device]:"-1") << " " << x.time << " " << x.load << "\n";
        // }
        vector<change> res;
        int i = -1, j = -1, val_l = 0, val_r = 0, d_l = -1, d_r = -1, cur_time, mx = 0, last_d=-100, last_val=-100;
        while((i+1)!=sz(l) || (j+1)!=sz(r)){
            if((i+1)==sz(l)){
                j++;
                cur_time = r[j].time;
                val_r = r[j].load;
                d_r = r[j].device;
            } else if((j+1)==sz(r)){
                i++;
                cur_time = l[i].time;
                val_l = l[i].load;
                d_l = l[i].device;
            } else{
                //cout << "should i take " << r[j+1].time << " or " << l[i+1].time << "\n";
                if(r[j+1].time<l[i+1].time){
                    j++;
                    cur_time = r[j].time;
                    val_r = r[j].load;
                    d_r = r[j].device;
                } else if(r[j+1].time>l[i+1].time){
                    i++;
                    cur_time = l[i].time;
                    val_l = l[i].load;
                    d_l = l[i].device;
                } else{
                    j++;
                    cur_time = r[j].time;
                    val_r = r[j].load;
                    d_r = r[j].device;
                    i++;
                    cur_time = l[i].time;
                    val_l = l[i].load;
                    d_l = l[i].device;
                }
            }
            //cout << "cur time is " << cur_time << "\n";
            mx = max(val_l, val_r);
            if(val_l>val_r){
                if(last_d!=d_l || last_val !=mx){
                    res.pb({d_l, cur_time, mx});
                    last_d = d_l;
                    last_val = mx;
                }
             } else{
                if(last_d!=d_r || last_val !=mx){
                    res.pb({d_r, cur_time, mx});
                    last_d = d_r;
                    last_val = mx;
                }
            }
        }
        // cout << "final is\n";
        // for(auto x : res){
        //     cout << (x.device!=-1?id_reverse[x.device]:"-1") << " " << x.time << " " << x.load << "\n";
        // }
        return res;
    };
    auto conq = [&](auto self, vector<vector<change>> &changes, int l, int r)->vector<change>{
        if(l==r){
            return changes[l];
        } else{
            int m = (l+r)/2;
            vector<change> r_l = self(self, changes, l, m), r_r = self(self, changes, m+1, r);
            return combine(r_l, r_r);
        }
    };
    vector<change> final = conq(conq, changes, 0, u-1);
    for(auto x : final){
        cout << "(" << x.time << "," << x.load << ") ";
    }
    cout << "\n";
    //now lets get the rest from the sil
    int last = 0, n = sz(final);
    vi time(d,0), last_time(d,0);
    for(int i=0;i+1<n;i++){
        if(final[i].load){
            time[final[i].device]+=(final[i+1].time-final[i].time);
            last_time[final[i].device] = final[i+1].time;
        }
    }
    int mn = INT_MAX, mx = INT_MIN, id_mn, id_mx;
    for(int i=0;i<d;i++){
        if(time[i]<mn){
            mn = time[i];
            id_mn = i;
        } else if(time[i]==mn && last_time[i]<last_time[id_mn]){
            mn = time[i];
            id_mn = i;
        }
        if(time[i]>mx){
            mx = time[i];
            id_mx = i;
        } else if(time[i]==mx && last_time[i]<last_time[id_mx]){
            mx = time[i];
            id_mx = i;
        }
    }
    cout << id_reverse[id_mx] << " " << time[id_mx] << "\n";
    cout << id_reverse[id_mn] << " " << time[id_mn] << "\n";
}

signed main()
{
    //ios::sync_with_stdio(0);
   //cin.tie(0);
    solve();
    return 0;
}