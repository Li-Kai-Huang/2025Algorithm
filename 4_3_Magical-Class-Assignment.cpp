//未過資測

#include <iostream> 
#include <vector>   
#include <algorithm> 

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K; 

    cin >> N >> K;

    vector<long long> P(N);

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

 
    auto check = [&](long long target_missing_value) {
        long long num_classes_formed = 0;
        long long current_idx = 0;       
        if (target_missing_value == 0) {
            while (current_idx < N) {
                num_classes_formed++; 

                if (num_classes_formed > K) {
                    return false;
                }

                long long temp_idx = current_idx;       
                bool found_zero_in_segment = false;     


                while (temp_idx < N) {
                    if (P[temp_idx] == 0) {
                        found_zero_in_segment = true;
                        break;
                    }
                    temp_idx++; 
                }

                if (found_zero_in_segment && temp_idx == current_idx) {
                    return false;
                }
                current_idx = temp_idx; 
                if (found_zero_in_segment) {
                    current_idx++;
                }
            }
        } else {
            while (current_idx < N) {
                num_classes_formed++; 

                if (num_classes_formed > K) {
                    return false;
                }
                vector<int> freq(target_missing_value, 0);

                long long elements_found = 0; 

                long long temp_idx = current_idx;
                bool found_valid_segment = false;


                while (temp_idx < N) {
                    if (P[temp_idx] < target_missing_value) {
                        if (freq[P[temp_idx]] == 0) {
                            elements_found++;
                        }
                        freq[P[temp_idx]]++; 
                    }

                    
                    if (elements_found == target_missing_value) {
                        found_valid_segment = true;
                        current_idx = temp_idx + 1;
                        break; 
                    }
                    temp_idx++;
                }

                if (!found_valid_segment) {
                    return false;
                }
            }
        }
        return num_classes_formed == K;
    };

    long long low = 0; 
    long long high = N;
    long long ans = 0;  

    while (low <= high) {
        long long mid = low + (high - low) / 2; 

        if (check(mid)) {
            ans = mid;      
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }
    
    
    cout << ans << endl;

    return 0; 
}
