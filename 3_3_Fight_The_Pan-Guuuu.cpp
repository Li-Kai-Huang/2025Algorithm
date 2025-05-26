#include <iostream>
#include <vector>
#include <algorithm> // for std::min

using namespace std ;
const long long INFINITY = 4e18;

int main() {
    cin.tie(NULL);

    int N, M; 
    long long K; 

    cin >> N >> M >> K;


    vector<vector<long long>> A(N, vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }


    vector<long long> prev_dp(N);
    vector<long long> current_dp(N);

    for (int i = 0; i < N; ++i) {
        prev_dp[i] = A[i][0];
    }

    for (int j = 1; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            int prev_row_up = (i - 1 + N) % N;
            long long cost_from_up = prev_dp[prev_row_up];
            long long cost_from_left = prev_dp[i];

            int prev_row_down = (i + 1) % N;
            long long cost_from_down = prev_dp[prev_row_down];
            current_dp[i] = A[i][j] + min({cost_from_up, cost_from_left, cost_from_down});
        }
        
        prev_dp = current_dp; 

    }

    long long min_total_cost = INFINITY; 

    for (int i = 0; i < N; ++i) {
        min_total_cost = std::min(min_total_cost, prev_dp[i]);
    }

    if (min_total_cost <= K) {
        cout << min_total_cost << endl;
    } else {
        cout << "RE: START :<" << endl;
    }

    return 0;
}