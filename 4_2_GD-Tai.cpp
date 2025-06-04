#include <iostream> 
#include <vector>   
#include <algorithm>
#include <climits>  

using namespace std;

// 主函數
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K; 
    cin >> N >> K;

    vector<long long> P(N); 
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    auto check = [&](long long D) {
        long long base_stations_needed = 0; 
        long long i = 0; 

        while (i < N) {
            base_stations_needed++; 
            if (base_stations_needed > K) {
                return false;
            }
            long long coverage_limit = P[i] + D;
            long long j = i + 1;
            while (j < N && P[j] <= coverage_limit) {
                j++;
            }
            i = j;
        }
        return true;
    };

    long long low = 0; 
    long long high = P[N - 1] - P[0]; 
    long long ans = high; 

    // 二分搜尋循環
    while (low <= high) {
        long long mid = low + (high - low) / 2; 
        if (check(mid)) {
            ans = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    cout << ans << endl;
    return 0;
}
