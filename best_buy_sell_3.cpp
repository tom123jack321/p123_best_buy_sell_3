// My solution to Leetcode problem "123. Best Time to Buy and Sell Stock III
// See https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/ for description of the problem
// The problem is hard in that at most two transactions are allowed, unlike previous "buy and sell stock" problems.

#include <iostream>
#include <string>
#include <vector>
// #mark a#

using namespace std;

// Best time to buy and sell stock 3
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int s=prices.size();
    if(s<=2){ return max(0, prices[s-1]-prices[0]); }
    vector <int> r_1, r_2, r_3;
    r_1 = profit_2(prices, 0, s-1);
    r_2 = profit_2(prices, 0, max(0, r_1[1]-1) );
    r_3 = profit_2(prices, min(r_1[2]+1, s-1), s-1);
    int p = max(r_1[0]+r_2[0], r_1[0]+r_3[0]);
    vector <int> r_21, r_22, r_23;
    r_21 = profit_2(prices, 0, r_1[2]-1);
    r_22 = profit_2(prices, 0, max(0, r_21[1]-1) );
    r_23 = profit_2(prices, min(r_21[2]+1, s-1), s-1);
    p = max(p, max(r_21[0]+r_22[0], r_21[0]+r_23[0]) );
    vector <int> r_31, r_32, r_33;
    r_31 = profit_2(prices, min(r_1[1]+1, s-1), s-1);
    r_32 = profit_2(prices, 0, max(0, r_31[1]-1) );
    r_33 = profit_2(prices, min(r_31[2]+1, s-1), s-1);
    p = max(p, max(r_31[0]+r_32[0], r_31[0]+r_33[0]) );
    return p;
  }
  // #mark f#
  vector<int> profit_2(const vector<int>& prices, const int a, const int b){
    vector <int> res;
    if(a+1 >= b){ 
      res={max(0, prices[b]-prices[a]), a, b};
      return res; 
    }
    int c=a, d=b;
    int pc=0, f;
    int c_max=a, d_max=b, p_max=0;
    for(int i=a+1;i<=b;i++){
      f=prices[i]-prices[c];
      // cout << "f " << f << " ";
      // cout << "pc " << pc << " ";
      // cout << endl;
      if(f>pc){
        pc=f;
        d=i;
      } else if(f<0){
        c=i;
        pc=0;
      }
      if(pc>p_max){
        p_max=pc;
        c_max=c; d_max=d;
      }
    }
    res={p_max, c_max, d_max};
    return res;
  }
};

// #mark z#

int main(){
  Solution sol;
  // vector <int> prices={3,3,5,0,0,3,1,4};    // 6
  // vector <int> prices={7,6,4,3,1};    // 0
  // vector <int> prices={1};    // 0
  // vector <int> prices={6,1,3,2,4,7};    // 7
  vector <int> prices={1,2,3,4,5};       // 4
  // vector <int> prices={14,9,10,12,4,8,1,16};       // 19
  // vector <int> prices={8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};       // 15
  // vector <int> prices={1,2,4,2,5,7,2,4,9,0};       // 13
  // int p=sol.profit_1(prices, 5, prices.size()-1);
  cout << "prices ";
  for (int i=0;i<prices.size();i++){ cout << prices[i] << " " ;}
  cout << endl;
  // vector <int> res=sol.profit_2(prices, 0, prices.size()-1 );              
  // cout << "res ";
  // for (int i=0;i<res.size();i++){ cout << res[i] << " " ;}
  // cout << endl;
  int p=sol.maxProfit(prices);              
  cout << "p " << p << "\n";
}
