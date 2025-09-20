#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int mod = 1e9+7;

long long int dp[1000001];

int solve(int n, int x, vector<int> &coins) {

    // dp[i] -> number of distinct ways to make sum x. I am still confused about the base case intuition.
    // if we say dp[0] = 1, that means 1 way to make sum 0, but the problem asks from available denominations, then 0 won't be possible right?
    // for now, i am interpreting it this way -> when you have x=available denominations then there is one way to achieve that by picking the coin itself.
    // maybe wrong, revisit this.
    // dp[i] = sum(dp[i-coin]) where coin is available denomination.

    dp[0] = 1;

    for(int i=1;i<=x;i++){
        dp[i]=0;
        for(auto coin:coins){
            if(i-coin>=0){
                dp[i] = (dp[i] + dp[i-coin])%mod;
            }
        }
    }

    return dp[x];
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    cout << solve(n,x,coins) << endl;
    return 0;
}