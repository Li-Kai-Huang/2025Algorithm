#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 物品結構
struct Item {
    double value;
    double weight;
    // 單位價值
    double ratio() const {
        return value / weight;
    }
};

// 排序用：單位價值由大到小
bool cmp(Item a, Item b) {
    return a.ratio() > b.ratio();
}

// 分數背包主函式
double fractionalKnapsack(vector<Item>& items, double capacity) {
    // 依單位價值排序
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;
    double currentWeight = 0.0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // 全部拿
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // 只能拿部分
            double remain = capacity - currentWeight;
            totalValue += item.value * (remain / item.weight);
            break; // 背包已滿
        }
    }
    return totalValue;
}

int main() {
    int n;
    double capacity;
    cin >> n >> capacity;
    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    double maxValue = fractionalKnapsack(items, capacity);
    cout << fixed << setprecision(6) << maxValue << endl;
    return 0;
}
