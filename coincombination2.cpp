#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
const int INF = 1e9;

int dp[101][1000001];

int solve(int n, int x, vector<int> &coins) {

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(j==0) dp[i][j] = 1;
            else
            {
                int opt1 = j<coins[i] ? 0 : dp[i][j-coins[i]];   // pick the coin, you can pick it again so i stays same.
                int opt2 = i==1 ? 0 : dp[i-1][j]; // don't pick the coin.
                dp[i][j] = (opt1+opt2)%mod;
            }
        }
    }

    return dp[n][x];
    return 0;
}

int main() {

    int n, x;
    cin>>n>>x;
    vector<int> coins(n+1);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    cout<<solve(n,x,coins)<<endl;
    return 0;
}