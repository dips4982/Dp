#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
const int INF = 1e9;

long long int dp[1000001];


// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?

// note that even greedy works for this problem, but I can't prove it mathematically so using DP.

int solve(int n) {

    // dp[i] -> minimum number of steps needed to make i 0 by subtracting it's digits.
    // dp[i] = min(dp[i]-k) + 1 where k are digits in i

    // dp[0] = 0;
    
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        string num = to_string(i);
        dp[i] = INF;
        for(auto ch:num){
            int dig = ch - '0';
            dp[i] = min(dp[i], dp[i-dig]+1);
        }
    }
    return dp[n];
}


int main() {
    int n;
    cin>>n;
    cout<< solve(n) << endl;
    return 0;
}