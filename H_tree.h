#ifndef H_TREE_H
#define H_TREE_H

#include <string>
#include <iostream>
#include <vector>
#include "Alph.h"
#include <queue>
#include <ostream>
#include <cmath>

using namespace Alph_OP;
using namespace std;

namespace H_Tree_OP
{
class H_tree{
  private:
    string text;  
    vector<alph*> va;
    alph* merge;
    int bit_size;

    
  public: 
    //CONSTRUCTOR
    H_tree();  
    //CONSTANT NON-MODIFYING MEMEBER FUNCTIONS
    int newstring_length()const{ return bit_size; }

    //MODIFYING MEMBER FUNCTIONS 
    void text_save(string& s);
    int original_bit_size();
    void insert_list(vector<alph*> Vec_al);
    void organize(alph* a);
    void make_tree();
    string traverse( alph* ptra, char c, bool& switcher);
    void final_ouput();

    friend ostream& operator<<( ostream& o,const H_tree& ht);
  }; 
}
#endif
