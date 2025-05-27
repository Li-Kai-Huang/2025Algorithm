#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std ;

bool check(long long max_balls_per_bag, int N, long long K, const std::vector<long long>& arr) {
    long long total_operations_needed = 0;
    for (long long current_balls : arr) {

        if (current_balls <= max_balls_per_bag) {
            continue;
        }

        long long num_resulting_bags = (current_balls + max_balls_per_bag - 1) / max_balls_per_bag;
        total_operations_needed += (num_resulting_bags - 1);

        if (total_operations_needed > K) {
            return false;
        }
    }
   
    return true;
}

int main() {
    
    int N; 
    long long K; 
    cin >> N >> K;

    vector<long long> arr(N);
    long long max_initial_balls = 0; 

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i] > max_initial_balls) {
            max_initial_balls = arr[i];
        }
    }

    long long low = 1;                  
    long long high = max_initial_balls; 
    long long result = max_initial_balls; 

    while (low <= high) {
        long long mid = low + (high - low) / 2; 

        if (check(mid, N, K, arr)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}