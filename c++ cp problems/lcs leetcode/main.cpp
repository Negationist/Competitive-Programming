#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()>text2.size()){
            swap(text1,text2);
        }
        int n = text1.size(), m = text2.size();
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++){
            a[i] = (int)(text1[i]);
        }
        for(int i=0;i<m;i++){
            b[i] = (int)(text2[i]);
        }
        map<int,vector<int>> weight;
        int val = 1;
        for(int i=0;i<m;i++){
            weight[b[i]].push_back(val);
            ++val;
        }
        vector<int> temp;
        map<int,int> pointer;
        for(int i=0;i<n;i++){
            cout << text1[i] << " is " << a[i] << "! ";
            if(pointer[a[i]]==weight[a[i]].size()){
                cout << "\n";
                continue;
            } else{
                temp.push_back(weight[a[i]][pointer[a[i]]]);
                cout << weight[a[i]][pointer[a[i]]] << "\n";
                ++pointer[a[i]];
            }
        }
        for(int x : temp){
            cout << x << " ";
        }
        cout << "\n";
        auto lis = [&](vector<int> &a)->int{
            vector<int> dp;
            int len = a.size();
            for(int i=0;i<len;i++){
                int pos = upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
                if(pos==dp.size()){
                    dp.push_back(a[i]);
                } else{
                    dp[pos] = a[i];
                }
            }
            return dp.size();
        };
       return lis(temp);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t1,t2;
    cin >> t1 >> t2;
    cout << longestCommonSubsequence(t1,t2) << "\n";
    return 0;
}
