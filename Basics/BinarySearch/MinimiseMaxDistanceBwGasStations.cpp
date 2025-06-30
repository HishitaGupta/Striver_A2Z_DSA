#include <bits/stdc++.h>
using namespace std;

long double minMaxDistance_Simple(vector<int> gasStations , int gasStationsToPlace) {
    vector<int> howMany(gasStations.size() - 1, 0);

    for (int newGasStation = 1; newGasStation <= gasStationsToPlace; newGasStation++) {
        long double maxLength = -1;
        int maxIndex = -1;
        for (int i = 0; i < gasStations.size() - 1; i++) {
            long double distance = gasStations[i + 1] - gasStations[i];
            long double sectionLength = distance / (howMany[i] + 1.0);
            if (sectionLength > maxLength) {
                maxLength = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < gasStations.size() - 1; i++) {
        long double diff = gasStations[i + 1] - gasStations[i];
        long double sectionLength = diff / (howMany[i] + 1.0);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

long double minimiseMaxDistance_PQ(vector<int> gasStations , int gasStationsToPlace) {
    int n = gasStations.size();
    priority_queue<pair<long double,int>>pq;
    vector<int> howMany (n-1,0);

    for (int i=0;i<n-1;i++) {
        pq.push({gasStations[i+1]-gasStations[i],i});
    }

    for (int i=1;i<=gasStationsToPlace;i++) {
        auto top = pq.top();
        int topIndex = top.second;
        pq.pop();
        howMany[topIndex]++;

        long double originalDistance = gasStations[topIndex+1]-gasStations[topIndex];
        long double newSectionLength = originalDistance / (long double)(howMany[topIndex]+1);

        pq.push({newSectionLength,topIndex});

    }

    return pq.top().first;
}

int numberOfGasStationsPlaced(vector<int> gasStations , long double dist) {
    int count =0;

    for (int i=0;i<gasStations.size()-1;i++) {
        int numberOfDivisions = ((gasStations[i+1]-gasStations[i])/dist);
        if (((gasStations[i+1]-gasStations[i])/dist) == (numberOfDivisions*dist)) {
            numberOfDivisions--;
        }
        count+=numberOfDivisions;
    }

    return count;
}

long double minimiseMaxDistance_BS(vector<int> gasStations , int gasStationsToPlace) {
    long double low=0;
    long double high =0;

    for (int i=0;i<gasStations.size()-1;i++) {
        high = max(high,(long double)(gasStations[i+1]-gasStations[i]));
    }

    long double diff = 1e-6;

    while ((high-low)>diff) {
        long double mid = (low+high)/2.0;
        int gasStationsPlaced = numberOfGasStationsPlaced(gasStations,mid);

        if (gasStationsPlaced > gasStationsToPlace) {
            low = mid;
        }else {
            high = mid;
        }
    }

    return high;
}

int main() {
    vector<int> gasStations = {1, 13, 17, 23};
    int gasStationsToPlace = 5;

    // cout << fixed << setprecision(6) << minMaxDistance_Simple(gasStations, gasStationsToPlace) << endl;
    // cout <<minimiseMaxDistance_PQ(gasStations, gasStationsToPlace) << endl;
    cout <<minimiseMaxDistance_BS(gasStations, gasStationsToPlace) << endl;
}
