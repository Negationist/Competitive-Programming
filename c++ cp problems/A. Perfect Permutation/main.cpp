#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n%2 != 0){
        cout << "-1";
        return 0;
    }
    vector<int> ans;
    for (int i=1; i<100;i++){
        ans.push_back(i+1);
        ans.push_back(i);
        i++;
    }
    for (int i=0; i <n; i++){
        cout << ans[i] << ' ';
    }




    return 0;
}
