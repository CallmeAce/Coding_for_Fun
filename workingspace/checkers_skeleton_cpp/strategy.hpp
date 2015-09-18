#ifndef _CHECKERS_STRATEGY_HPP_
#define _CHECKERS_STRATEGY_HPP_
#include "player.hpp"
#include <pair>
namespace checkers
{
class Strategy
{
  public:
      
      int compute_euclidean_distance(vector<int*> posi_list); // euclidean distance is a crucial criteria in choosing movement
      GameState aggressive (const GameState &pState); // an aggressive strategy charging to the bottom to become king, and make as many jumps as possible
      GameState moderate (const GameState &pState);   // moderate strategy  
      GameState concervative (const GameState &pState);  // defence strategy always get together
  
  private:
      int posi[2];
      vector<int*> red_posi;
      vector<int*> white_posi;
}


}


































#endif
