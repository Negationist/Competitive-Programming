#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

class Point{
public:
    Point(int a, int b) : x(a),y(b){}
    int x;
    int y;
    bool upper = false;
    bool lower = false;
    bool left = false;
    bool right = false;

};

int main()
{
    vector<Point*> points;
    int t, countt = 0;
    cin >> t;
    FOR(i,t){
        int a,b;
        cin >> a >> b;
        Point *obj = new Point(a,b);
        points.push_back(obj);

    }
    for (auto it = points.begin(); it != points.end(); ++it){
        for (auto a = it+1; a!=points.end(); ++a){
            if ((*it)->x == (*a)->x){
                if ((*it)->y > (*a)->y){
                    (*it)->lower = true;
                    (*a)->upper = true;
                } else if ((*it)->y < (*a)->y){
                    (*it)->upper = true;
                    (*a)->lower = true;
                }
            } else if ((*it)->y == (*a)->y){
                if ((*it)->x > (*a)->x){
                    (*it)->left = true;
                    (*a)->right = true;
                } else if ((*it)->x < (*a)->x){
                    (*it)->right = true;
                    (*a)->left = true;
                }
        }
    }
}
for(auto it = points.begin();it!=points.end();it++){
        if ((*it)->upper && (*it)->lower && (*it)->left && (*it)->right){
            countt++;
        }
    }
    cout << countt;
    return 0;
}
