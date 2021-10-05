#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int dp[1001][1001];

// rows represent weights and cols represent sum (0-cap)
int knapsackUtil(int cap, int wts[], int vals[], int i, int **dp) // here n is that particular wt value's index
{
    if(i<0)
        return 0;

    if(dp[i][cap] != -1)
        return dp[i][cap];

    if(wts[i]>cap) // if the wt is more than capacity we are not considering this item. so capacity will be same but we have to find with 1 less items. so total items now will be it-1.
    {
        dp[i][cap] = knapsackUtil(cap, wts, vals, i-1, dp); // go to previous row same col and return that value.\\
        because using wt 2, u cant make sum 1 or 0 so use previous value only.

        return dp[i][cap];
    }
    else // here we are considering ith item so add this items value. the capacity will be the cap-wt[i] (cap-wt of ith item) 
    // and this remainder capacity shud be fullfilled with i-1 items so recursively call this function.
    {
        dp[i][cap] = max((vals[i]+knapsackUtil(cap-wts[i], wts, vals, i-1, dp)), knapsackUtil(cap, wts, vals, i-1, dp) );
        // take the maximum of both cases: considering this item + not considering this item.

        // if u want to make sum for wt 2 using wt 2 then consider val[]

        return dp[i][cap];
    }
}

void knapsack(int vals[], int wts[], int n, int cap)
{
    int** dp;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[cap + 1]; // initialize it like this because we want to pass 2d array by reference.
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<cap+1;j++)
        {
            dp[i][j]=-1;
        }
    }

    cout<<"knapsack max value is = "<<knapsackUtil(cap, wts, vals, n-1, dp);
}

void knapsack_optimised(int vals[], int wts[], int n, int cap)
{
    int dp[cap+1];
    for(int i=0;i<cap+1;i++)
        dp[i]=0; // initialize with 0.
    // we can do the same with 1D array also. dp-state: value for that weight.
    for(int i=0;i<n;i++)
    {
        for(int j=cap;j>=0;j--)
        {
            if(wts[i]<=j)
                dp[j]=max(dp[j], vals[i]+dp[j-wts[i]]); // max of (not considering item, considering item)
                // not considering item means j wt with earlier items only and this earlier items is value is already stored in dp[j] so use it
                // considering this item: dp[j-wts[i]] ==> wt j - this wt i. now find this remainder wt's value with dp[j-wts[i]].
                // add value of this item also. so it will be vals[i]+dp[j-wts[i]].
        }
    }

    cout<<"\n"<<dp[cap]<<"\n";
}

int minimumCost(int costs[], int n, int W) // https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#
{

/*
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, 
the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output 
will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.


n => costs of oranges of weight with index (1..n) but our array indexing will be from 0 so check that.
W => wt of oranges we need.

*/

    vector<int>wt;
    vector<int>cost;

    for (int i = 0; i < n; i++) 
    {
        if (costs[i] != -1) 
        {
            cost.push_back(costs[i]); // if some cost value is -1 then u cant consider it you should ignore it. so for this only 
            // we are taking a new cost vector and storing non -ve values in this.
            wt.push_back(i + 1); // here indices of cost vector are also important. so we are storing corresponding indices into wt vector.
        }
    }
    int N = cost.size();
    int dp[N + 1][W + 1]; // dp with size N+1 x W+1 ==> cost of oranges x total_weight.
    for (int i = 1; i <= N; i++)
        dp[i][0] = 0; // if total weight is 0 then #oranges doesnt matter. so fill with 0s.

    for (int j = 0; j <= W; j++)
        dp[0][j] = INF; // if u dont have costs of any oranges then u cant find cost for any weight so initialize with INF.
    
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= W; j++) 
        {
            if (wt[i - 1] <= j ) // if weight (for cost) is less than current weight.
                dp[i][j] = min(dp[i - 1][j], cost[i - 1] + dp[i][j - wt[i - 1]]); // then min cost for that weight = \\
                min(considering this wt(j), not considering this wt j)\\
                if u consider this wt then remaining wt = j-wt[i-1]. so find the min cost for this remaining wt by checking its dp table value,
                // not considering this wt: same weight + not this cost (all previous costs.)
                // dp[i][w] state - how much cost to obtain weight w using first i oranges.
            else if (wt[i - 1] > j) // if wt is more than current weight then directly take previous value.
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[N][W] == INF)
        return -1;
    return dp[N][W];
}


int knapsackUnboundedUtil(int i, int j, int val[], int wts[])
{
    if(i<=-1) // if no more elements then return 0.
        return 0;
    if(dp[i][j]!=-1) // if dp[i][j] is not -1 means if j weight can be obtained by i items then return dp[i][j].
        return dp[i][j];
    if(wts[i]>j) // if wt of ith item is more than available wt then check with previous i-1 items for available wt.
        return dp[i][j]=knapsackUnboundedUtil(i-1, j, val, wts);
    
    // else :
    // each item can be either picked for evaluation or left from evaluation.
    // when picked for evaluation then it can be reused as it is unbounded knapsack. but the wt decreases. so i value is not decreased.
    return dp[i][j]=max(knapsackUnboundedUtil(i, j-wts[i], val, wts)+val[i], knapsackUnboundedUtil(i-1, j, val, wts));
}


int knapsackUnbounded(int n, int w, int val[], int wts[])
{
    dp[n][w]; // create dp of size nxw. dp[i][j] = with i items and for wt of j what is the max profit u can get.
    memset(dp, -1, sizeof(dp)); // initialize all cells with -1.
    return knapsackUnboundedUtil(n-1, w, val, wts); 
}

int main()
{

    int vals[3]={60, 100, 120};
    int wts[3]={10,20,30};
    int cap=50;

    knapsack(vals, wts, 3, cap);

    knapsack_optimised(vals, wts, 3, cap);

    int vals1[2] = {1, 1};
    int wts1[2] = {2, 1};
    cout<<"unbounded = "<<knapsackUnbounded(2, 3, vals1, wts1)<<"\n";
}