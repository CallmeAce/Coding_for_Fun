#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class node{
           node * parent;
           int level;
		   string str_val;
};

class Solution {
public:
    vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
    {
		string start_tmp = start;
		string end_tmp   = end;
		vector< vector<string> > output_list;
		vector<string> output;
		deque<node*> node_queue;
		word_length = start_tmp.length();
		node* root = new node();
		root->str_val = start;
		root->level   = 0;
		node_queue->push_back( root);
		bool exist_in_parents = false;
		bool found_one_path	=	false;
		int target_level;
		if(!dict.find(end))
		{
			return output_list;
		}
		 
		while( !node_queue->isempty() )
		{
			node * node_2_process = node_queue->pop_front();  // pop a node to build the tree
			if(found_one_path)
			{
				if(node_2_process->level > target_level)
					break;
			}
			string str_tmp = node_2_process->str_val;     // adding the children
		
			for(int i = 0;i<word_length;i++)
			{	
				for( char j = 'a';j<='z';i++)
				{
					str_tmp[i] = j;
					if( str_tmp[i] !=j && dict.find(start_tmp) )
					{	
						node* node_tmp = node_2_process;
						int level = 0;
						while(node_tmp)
						{
							if(str_tmp == node_tmp->str_val)
							{
								exist_in_parents = true;
								break;
							}
							node_tmp = node_tmp->parent;
							level++;
						}
						if(!exist_in_parents)
						{
							node * new_node = new node();
							new_node->str_val = str_tmp;
							new_node->parent = node_2_process;
							new_node->level  = level;
							if(new_node->str_val == end)
							{
								while(new_node)
								{
									output.push_back(new_node);
									new_node = new_node->parent;
								}
								output_list.push_back(output);
								found_one_path = true;
								target_level = new_node->level;
								
							}
							node_queue.push_back(new_node);
						}
					
					}
				
				}
			}
		}
		return output_list;
	}
};


int main()
{
  string start;
  string end;
  start = "hit";
  end   = "cog";
  unordered_set<string> myset = {"hot","dot","dog","lot","log"};
  myset.find(input);
  Solution sol = new Solution();
  sol.findLadders(start,end, myset);
  
}
