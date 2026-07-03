#include <iostream>
#include <cmath>

using namespace std;

const double dt = 0.01;         // Time step
const int max_steps = 100000;   // Maximum number of iterations
const double eps = 1e-6;        // Threshold for stability detection
const double INF_THRESHOLD = 1e6; // If x or y exceed this, assume divergence

double dx_dt(double x, double y) {
    return x * (1 - x / 3.0 - y);
}

double dy_dt(double x, double y) {
    return y * (1 - y / 4.0 - x);
}

int main() {
    double x, y;
    cout << "Enter initial x (>= 0): ";
    cin >> x;
    cout << "Enter initial y (>= 0): ";
    cin >> y;

    for (int step = 0; step < max_steps; ++step) {
        double dx = dx_dt(x, y);
        double dy = dy_dt(x, y);

        double x_new = x + dt * dx;
        double y_new = y + dt * dy;

        // Check if diverging
        if (x_new > INF_THRESHOLD || y_new > INF_THRESHOLD || std::isnan(x_new) || std::isnan(y_new)) {
            cout << "System diverged to infinity at step " << step << endl;
            return 1;
        }

        // Check if stable
        if (fabs(x_new - x) < eps && fabs(y_new - y) < eps) {
            cout << "System stabilized at (x, y) = (" << x_new << ", " << y_new << ")" << endl;
            return 0;
        }

        x = x_new;
        y = y_new;
    }

    cout << "Max steps reached. Final (x, y) = (" << x << ", " << y << ")" << endl;
    return 0;
}
