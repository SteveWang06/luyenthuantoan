#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long target;
vector<long long> weights;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 輸入
    cin >> target;
    cin >> n;
    weights.resize(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];

    vector<long long> results;
    for (long long mask = 0; mask < (1LL << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) sum += weights[i];
        }
        if (sum == target) results.push_back(mask);
    }

    sort(results.begin(), results.end());
    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) cout << " ";
        cout << results[i];
    }
    cout << "\n";

    return 0;
}
