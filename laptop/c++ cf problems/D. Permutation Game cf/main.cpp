#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;


bool visited1[200002] = {};
bool visited2[200002] = {};
vector<int> cycleB;
vector<int> cycleS;
vector<int> p;
vi a;
int bmax;
int smax;

void cyclefindB(int x){
    if(visited1[x]==true) return;
    else{
        cycleB.pb(x);
        visited1[x] = true;
        cyclefindB(p[x]);
        bmax = max(bmax,a[x]);
    }
}
void cyclefindS(int x){
    if(visited2[x]==true) return;
    else{
        cycleS.pb(x);
        visited2[x] = true;
        cyclefindS(p[x]);
        smax = max(smax,a[x]);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        bmax = smax = 0;
        int bAns = 0;
        int sAns = 0;
        cycleB.resize(0);
        cycleS.resize(0);
        int n,k,pB,pS;
        cin >> n >> k >> pB >> pS;
        p.resize(n+1);
        a.resize(n+1);
        for(int i=1;i<n+1;i++){
            cin >> p[i];
        }
        for(int i=1;i<n+1;i++){
            cin >> a[i];
        }
        //identify the respective cycles
        cyclefindB(pB);
        cyclefindS(pS);
        //not so brute force
        vi prefCycleB(cycleB.size());
        vi prefCycleS(cycleS.size());
        prefCycleB[0] = a[cycleB[0]];
        prefCycleS[0] = a[cycleS[0]];


        for(int i=1;i<cycleB.size();i++){
            prefCycleB[i]=a[cycleB[i]]+prefCycleB[i-1];
        }
        for(int i=1;i<cycleS.size();i++){
            prefCycleS[i]=a[cycleS[i]]+prefCycleS[i-1];
        }
        bAns = a[pB]*k;
        sAns = a[pS]*k;
        for(int i=1;i<cycleB.size();i++){
            int result = prefCycleB[i-1] + a[cycleB[i]]*(k-i);
            bAns = max(bAns,result);
            if(a[cycleB[i]]==bmax) break;
        }
        for(int i=1;i<cycleS.size();i++){
            int result = prefCycleS[i-1] + a[cycleS[i]]*(k-i);
            sAns = max(sAns,result);
            if(a[cycleS[i]]==smax) break;
        }
        if(bAns > sAns){
            cout << "Bodya\n";
        } else if(sAns > bAns){
            cout << "Sasha\n";
        } else{
            cout << "Draw\n";
        }

        for(int i=0;i<n+1;i++){
            visited1[i] = false;
            visited2[i] = false;
        }

    }
    return 0;
}
