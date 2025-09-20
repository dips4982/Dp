#include<iostream>
#include<bits/stdc++.h>

using namespace std;
const int INF = 1e9;

long long int dp[1000001];

int solve(int n, int x, vector<int>& coins) {

    dp[0] = 0; // all coins have positive integer values.

    for(int i=1;i<=x;i++){
        dp[i] = INF;
        for(auto coin: coins){
            if(i-coin>=0){
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }

    if(dp[x]>=INF) {
        return -1;
    }

    return dp[x];
}


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << solve(n, x, coins) << endl;

    return 0;
}