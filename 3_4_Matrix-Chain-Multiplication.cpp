#include <bits/stdc++.h>

using namespace std ;

long long INF = 4e18;

int main(){
    int n ;
    cin>>n;
    vector <long long> p(n+1);
    cin >> p[0] >> p[1]; 
    for (int i = 2; i <=n; ++i)
    {
        long long dummy_r; 
        std::cin >> dummy_r >> p[i]; 
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    for(int len=2;len<=n;++len){
        for(int i =1;i<=n-len+1;++i){
            int j = i+len -1;
            dp[i][j] = INF ;
            for (int k = i; k < j; ++k)
            {
                long long cost = dp[i][k] +dp[k+1][j]+p[i-1]*p[k]*p[j];
                if (cost<dp[i][j]) dp [i][j] = cost ;
            }
            
        }
    }
    cout << dp[1][n]<<endl;
    return 0 ;

}
