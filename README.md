# p123_best_buy_sell_3
My solution to Leetcode problem "123. Best Time to Buy and Sell Stock III"

1. Description
See https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/ or below for description of the problem. The problem is hard in that at most two transactions are allowed, unlike previous "buy and sell stock" problems.

You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4

2. My solution
The first step is to find the (globally) largest increment among the entire array and the beginning and end location of the increment (returned by function "profit_2" as vector {p_max,c_max, d_max}). The array is split into 3 segments, namely the one before "c_max", the one between "c_max" and "d_max" (both includingly) and the one after "d_max". The required (at most) largest 2 increment should appear near the two locations ("c_max" the beginning location, "d_max" the end location), so the second and third steps are to find the largest increment among the segments before "c_max" and after "d_max" respectively. So far, the function "profit_2" is invoked 3 times. Pick up the 2 largest increments found.
Then comes the 4th step that searches the largest increment among location "c_max" and "d_max - 1" (both includingly). Likewise the 5th and 6th steps searching among the segments before and after ther segment produced in 4th step.
Finally the 7th step searching the largest increment among location "c_max + 1" and "d_max" (both includingly). Likewise the 8th and 9th steps searching among the segments before and after ther segment prodeced in 7th step.

3. Complexity
Almost all time is spent on the function "profit_2", which has time complexity O(n) (n being the length of array "prices") and is invoked 9 times totally. Thus, time complexity of the solution is still O(n).

4. Results
Submitted to Leetcode and passed all tests with 100ms (beats 80.92% of users in c++) runtime and 77.98MB memory (beats 75.63% of users in c++). Considering that the problem is marked as "hard" and that I'm not a professional c++ programmer, the result is quite pleasant.

5. Troubleshooting
I share this for fun with no warranty absolutely. Should anyone find any bugs, please email me.

6. Author
Yiyi HUANG (yhuangcm@connect.ust.hk)

7. License
GPL3.0
