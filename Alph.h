#ifndef ALPH_H
#define ALPH_H

#include <string>
#include <iostream>
#include <vector>
#include "Alph.h"
using namespace std;
namespace Alph_OP
{
class alph
  { // ALPH IS A NODE ITSELF
  private:
    char c;
    int ammount;
    alph* left;
    alph* right;
    int new_size;
  
  public: 

  //CONSTRUCTOR
    alph();

  //CONSTANT NON-MODIFYING MEMEBER FUNCTIONS
     
    char letter()const {  return c; }
    int ammounts() const{  return ammount;  }
    alph* return_left()const { return left; }
    alph* return_right()const { return right; }
    int new_bits_length() const{return new_size; }
    


  //MODIFYING MEMBER FUNCTIONS 
    void make_letter(int i);
    void add();
    void add(int f1, int f2);
    void aleft(alph *a);
    void aright(alph *a);
    void operator=( const alph& a);
    void enter_new_size(int x);

    
    //FRIEND FUNCTION 
    friend ostream& operator<<( ostream& o,const alph& a);
    friend bool operator<(const alph& a1,const alph& a2);

  };
}

#endif