#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &wallUnits, int maxUnitsAllowed, int painters) {
    int total = 0;
    int painterCount = 1;

    for (int units : wallUnits) {
        if (units > maxUnitsAllowed) return false; // single wall too large

        if (total + units <= maxUnitsAllowed) {
            total += units;
        } else {
            painterCount++;
            total = units;
            if (painterCount > painters) return false;
        }
    }
    return true;
}

int minMaxUnitsAllocated(vector<int> &wallUnits, int painters) {
    int low = *max_element(wallUnits.begin(), wallUnits.end());
    int high = accumulate(wallUnits.begin(), wallUnits.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(wallUnits, mid, painters)) {
            result = mid;
            high = mid - 1;  // try to minimize
        } else {
            low = mid + 1;
        }
    }

    return result;
}


int main() {
    vector<int> wallUnits = {10, 20, 30, 40, 50};
    int painters = 2;

    cout << minMaxUnitsAllocated(wallUnits, painters) << endl;  // Output: 90

    return 0;
}
