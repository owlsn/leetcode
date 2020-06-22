#include "numPairsDivisibleBy60.h"

int Solution::numPairsDivisibleBy60(std::vector<int>& time){
  std::vector<int> times(60, 0);
  for (int i = 0; i < time.size(); i ++) {
    times[time[i] % 60] ++ ;
  }
  int count = 0;
  for (int i = 0; i <= 30; i ++) {
    if(i == 0 || i == 30){
      count += times[i] * (times[i] - 1) / 2;
    }
    else{
      count += times[i] * times[60 - i];
    }
  }
  return count;
}