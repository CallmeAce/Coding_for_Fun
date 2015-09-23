#include "strategy.hpp"
#include <cstdlib>
#include <inttypes.h>
using namespace std;
namespace checkers
{
	Strategy::Strategy()
	{
		
	}
	Strategy::load(vector<GameState> &states)
	{
		clear.data();
		get_posi(states);
		int variance_tmp=0;
		move_num = states.size();
		for(int i =0;i<move_num;i++)
		{
		     variance_tmp = compute_variance(red_posi[i]);
			 variance_red.push_back(variance_tmp);
			 variance_tmp = compute_variance(white_posi[i]);
			 variance_white.push_back(variance_tmp);
		}
	
	}
	void Strategy::clear_data()
	{
		red_num.clear();
		white_num.clear();
		empty_num.clear();
		variance_red.clear();
		variance_white.clear();
		red_posi.clear();
		white_posi.clear();
		empty_posi.clear();
	}
	void Strategy::get_posi(vector<GameState> & States)
	{
		vector<uint8_t*> * red_posi_tmp = new vector<uint8_t>;
		vector<uint8_t*> * white_posi_tmp = new vector<uint8_t>;
		vector<uint8_t*> * empty_posi_tmp = new vector<uint8_t>;
		for(int k =0;k<States.size();k++)
		{
			GameState & pState = States[k];

			for (int i =0; i<32;i++)
			{
				uint8_t * posi = new uint8_t[2]; 
				if(pState.at(i)==CELL_EMPTY)
				{
					posi[0] = pState.cellToRow(i);
					posi[1] = pState.cellToCol(i);
					empty_posi_tmp.push_back(posi);
				}
				else if(pState.at(i)==CELL_RED)
				{	
					posi[0] = pState.cellToRow(i);
					posi[1] = pState.cellToCol(i);
					red_posi_tmp.push_back(posi);
				}
				else
				{
					posi[0] = pState.cellToRow(i);
					posi[1] = pState.cellToCol(i);
					white_posi_tmp.push_back(posi);
				}
			}
			red_num.push_back(red_posi_tmp->size());
			white_num.push_back(white_posi_tmp->size());
			empty_num.push_back(empty_posi_tmp->size());
			red_posi.push_back(red_posi_tmp);
			white_posi.push_back(white_posi_tmp);
			empty_posi.push_back(empty_posi_tmp);
		}
	}

	uint8_t Strategy::compute_variance (vector<uint8_t*> posi_list)
	{
		uint8_t row_mean = 0;
		uint8_t col_mean = 0;
		uint8_t row_sum = 0;
		uint8_t col_sum = 0;
		uint8_t elem_num = 0;
		uint8_t variance = 0;
		list_num = posi_list.size();

		for(int i =0;i<elem_num;i++ )
		{
			row_sum += posi_list[i][0];
			col_sum += posi_list[i][1];
		}

		row_mean = row_sum / elem_num;
		col_mean = col_sum / elem_num;

		for(int i=0;i<elem_num;i++)
		{
			variance = (posi_list[i][0] - row_mean)^2 + (posi_list[i][1] - col_mean)^2;
		}
		return variance;
	}

	uint8_t Strategy::aggressive ()
	{
		uint8_t s_num = red_num[0];
		for(int i =1;i<move_num;i++)
		{
			if(s_num>red_num[i])

		}			
	}

}


	Strategy::moderate (GameState & pState)
	{

	}

	Strategy:: concervative (GameState &pState)
	{
	
	}

}
