#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;
    bool solved = false;
    while (!solved){
        year++;
        string year_s = to_string(year);
        bool allDistinct = true;
        for (int i=0; i<year_s.size()-1; i++){
            for (int j=i+1; j<year_s.size(); j++){
                if (year_s[i]== year_s[j]){
                    allDistinct = false;
                    break;
                }
            }
            if (!allDistinct){
                break;
            }
        }
        if (allDistinct){
            solved = true;
        }
    }
    cout << year;
    return 0;
}
