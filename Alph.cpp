#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include "Alph.h"

using namespace std;
namespace Alph_OP
{
  //Constructor  
    alph::alph(){
      ammount=0;
      c='\0';
      left=NULL;
      right=NULL;
      new_size=0;
    }

  //MODIFYING MEMBER FUNCTIONS 
    void alph::make_letter(int i){ c = i; }
    void alph::add(){ ammount++; }
    void alph::add(int f1, int f2){ ammount=f1+f2; }
    void alph::aleft(alph *a){ left = a; }
    void alph::aright(alph *a){ right = a; }
    void alph::enter_new_size(int x) {new_size= x;}
    

    void alph::operator=( const alph& a){
      ammount = a.ammount;
      c= a.c;
      left= a.left;
      right=a.right;
    }
    

    
    //FRIEND FUNCTION 
    ostream& operator<<( ostream& o,const alph& a){

      if(a.c=='\0') o<<"ptr";
      
      o<< a.c<<":"<<a.ammount;      
      return o;
    }
     bool operator<(const alph& a1,const alph& a2){
      return (a1.ammounts()<a2.ammounts());
    }
    
}
