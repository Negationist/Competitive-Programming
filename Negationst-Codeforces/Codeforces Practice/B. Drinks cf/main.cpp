#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int q; double result;
    double sum = 0;
    cin >> q;
    vector <int> d(q);
    for (int i=0;i<q;i++){
        cin >> d[i];
    }
    for (int i=0; i<q; i++){
        sum +=d[i];
    }
    result = sum/q;

    cout << fixed << setprecision(12) << result;

    return 0;
}
