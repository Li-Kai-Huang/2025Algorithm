#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義活動結構
struct Activity {
    int start;
    int end;
};

// 排序用：按結束時間遞增排序
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i) {
        cin >> activities[i].start >> activities[i].end;
    }

    // 按結束時間排序
    sort(activities.begin(), activities.end(), compare);

    // 貪婪選擇活動
    vector<Activity> selected;
    selected.push_back(activities[0]);
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= lastEnd) {
            selected.push_back(activities[i]);
            lastEnd = activities[i].end;
        }
    }

    cout << selected.size() << endl;

    return 0;
}
