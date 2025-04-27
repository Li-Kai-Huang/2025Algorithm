#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int idx, d, s;
};

bool cmp(const Job& a, const Job& b) {
    long long left = 1LL * a.s * b.d;
    long long right = 1LL * b.s * a.d;
    if (left != right) return left > right;
    return a.idx < b.idx;
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].d >> jobs[i].s;
        jobs[i].idx = i + 1; // 編號從1開始
    }
    sort(jobs.begin(), jobs.end(), cmp);
    for (const auto& job : jobs) {
        cout << job.idx << " ";
    }
    cout << endl;
    return 0;
}
