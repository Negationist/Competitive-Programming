#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; int Amz=0;
    int l,h;
    cin >> q;
    vector<int> s;
    for (int i=0;i<q;i++){
        int a;
        cin >> a;
        s.push_back(a);
    }
    l = s[0]; h = s[0];
    for (int i=1;i<q;i++){
        if (s[i]> h){
            Amz++;
            h = s[i];
        }
        else if (s[i]<l){
            Amz++;
            l = s[i];
        }
    }
    cout << Amz;

    return 0;
}
