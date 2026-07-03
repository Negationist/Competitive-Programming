#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    int x;
    while(cin >> x){
        s.insert(x);
    }
    cout << 4-s.size();
    return 0;
}
