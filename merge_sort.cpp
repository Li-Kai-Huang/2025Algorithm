#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void MERGE(vector<int>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j +1 ];
    }
    L[n1] = INT_MAX, R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void MERGE_SORT(vector<int>& A, int p, int r)
{
    if (p < r)
    {
        int q = p+(r-p) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}
int main()
{
    vector<int> array;
    int num;
    string input;
    getline(cin, input);  // 讀取整行輸入

    stringstream ss(input);
    while (ss >> num)
    {
        array.push_back(num);
    }
    int n = array.size();

    MERGE_SORT(array, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
