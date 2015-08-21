#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

class node{
           node * parent;
           node * children[];
           int level;
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
		for(int i = 0;i<word_length;i++)
		{	
			for( char j = 'a';j<='z';i++)
			{
				start_tmp[i] = j;
				if( start[i] !=j && dict.find(start_tmp) )
				{
					node* node_new = node_queue.pop();
					bool exist_
					if(node_new == NULL or )
				}
				
			}
		}
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
