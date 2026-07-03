#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        unordered_map<int,int> m1;
        long long ans = 0;
        long long n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            m1[a]++;
        }
        for(auto it = m1.begin();it!=m1.end();it++){
            bool found = true;
            int next = (it->first)+1;
            if(m1.find(next) == m1.end()) found = false;
            for(int i=1;i<=it->second;i++){
                long long sum = it->first*i;
                if(sum <= m) ans = max(ans,sum);
                if(found){
                    long long r = m-sum;
                    int amount  = min((r/next), (long long) m1[next]);
                    sum+=(amount*next);
                    ans = min(ans,sum);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
