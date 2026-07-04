#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<int> possible;
        for(int i=0;i<m;i++){
            int a;
            cin >> a;
            possible.insert(a);
        }
        string c;
        cin >> c;
        sort(c.begin(),c.end());
        int z=0;
        for(int x :possible){
            s[x-1] = c[z];
            z++;
        }
        cout << s << endl;
    }
    return 0;
}

