#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,L=INT_MAX, R=0;
    vector<int> l;
    vector<int> r;
    cin >> n;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if (a<L){
            l.clear();
            l.push_back(i);
            L = a;
        } else if(a==L){
            l.push_back(i);
        }
        if (b>R){
            r.clear();
            r.push_back(i);
            R = b;
        } else if(b==R){
            r.push_back(i);
        }
    }

    FOR(i,l.size()){
    FOR(a,r.size()){
        if (l[i]==r[a]){
            cout << l[i]+1;
            return 0;
        }
    }
    }
    cout << -1;
    return 0;
}
