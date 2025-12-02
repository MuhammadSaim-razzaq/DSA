#include <iostream>
#include <vector>
using namespace std;

int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> minT(d), maxT(d);
    int minSum = 0, maxSum = 0;

    for (int i = 0; i < d; ++i) {
        cin >> minT[i] >> maxT[i];
        minSum += minT[i];
        maxSum += maxT[i];
    }

    if (sumTime < minSum || sumTime > maxSum) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    vector<int> result = minT;
    int remaining = sumTime - minSum;

    for (int i = 0; i < d && remaining > 0; ++i) {
        int add = min(remaining, maxT[i] - minT[i]);
        result[i] += add;
        remaining -= add;
    }

    for (int i = 0; i < d; ++i) cout << result[i] << " ";
}
