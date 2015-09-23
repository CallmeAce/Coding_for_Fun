#ifndef _CHECKERS_STRATEGY_HPP_
#define _CHECKERS_STRATEGY_HPP_
#include "constants.hpp"
#include "move.hpp"
#include <stdint.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
namespace checkers
{

class Strategy
{
  public:
	  uint8_t move_num;
	  vector<uint8_t> red_num;
      vector<uint8_t> white_num;
	  vector<uint8_t> empty_num;
	  vector<uint8_t> variance_red;
	  vector<uint8_t> variance_white;
      Strategy();
	  void clear_data();
	  void load(vector<GameState> &states);
	  uint8_t aggressive (); // an aggressive strategy charging to the bottom to become king, and make as many jumps as possible
	  uint8_t moderate ();   // moderate strategy  
      uint8_t concervative ();  // defence strategy always get together
  
  private:
      vector< vector<uint8_t*> > red_posi;
      vector< vector<uint8_t*> > white_posi;
	  vector< vector<uint8_t*> > empty_posi;
	  uint8_t compute_variance (vector<uint8_t*> posi_list); // euclidean distance is a crucial criteria in choosing movement
	  void get_posi(const GameState & pState);
};

}































#endif
