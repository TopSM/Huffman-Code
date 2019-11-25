#include <string>
#include <iostream>
#include <vector>
#include "H_tree.h" 
#include "Alph.h"

using namespace std;
namespace H_Tree_OP
{
  //CONSTRUCTOR
  H_tree::H_tree(){
    text="";
    merge=NULL;
  }   

  //MODIFYING MEMBER FUNCTIONS 
  void H_tree::text_save(string& s){ text=s; }  

  int H_tree::original_bit_size(){
  
    int size= va.size();
    int Bits=0;
    int variable=ceil(log2(size));
    for(int i=0;i<va.size();i++){
      Bits+=va[i]->ammounts()*variable;
    }
    return Bits;
  }
  void H_tree::insert_list(vector<alph*> vec_al) { va=vec_al; }
  
  void H_tree::organize(alph* refa){
    alph* a;
    va.push_back(refa);
    for(int j=(va.size()-1);j>0;j--){
      if(va[j-1]->ammounts()<va[j]->ammounts()){
        a=va[j-1];
        va[j-1]=va[j];
        va[j]=a;
      }
      else{ break; }
    }
  }
  void H_tree::make_tree(){

    int size= va.size();
    alph* aL;
    alph* aR;
    for(int i=0; i<size&&va.size()!=1;i++){
      aL = va.back(); 
      va.pop_back();
      aR = va.back(); 
      va.pop_back();

      merge = new alph;
      merge->aleft(aL); 
      merge->aright(aR);
      merge->add(aL->ammounts(),aR->ammounts());
      organize(merge);
    }
  }

  void H_tree::final_ouput(){
    bool swap=false;
    string newstring="";
    //cout<<text<<": is the word\n"<<endl;

    for(int i=0;i<text.size();i++){
      newstring+=traverse(va[0],text[i],swap);
      swap=false;
    }
    cout<<"Newstring:\n"<<newstring<<endl<<endl;
    bit_size= newstring.length();
  }

  string H_tree::traverse( alph* ptra, char c, bool& switcher){ 
    //can uncomment if you want to see 
    //the steps that are taken
    string s="";
  //  cout<<*ptra<<" is the current node, looking for '"<<c<<"'"<<endl;
    if(ptra->letter()==c){
    //  cout<<" Found letter!\n\n ";
      switcher= true;
      return s;
    }

    if(ptra->return_left()==NULL && ptra->return_right()==NULL ){ 
      s.clear();
    //  cout<<" Nothing found, clearing\n";
      return s;
    }
    if(ptra->letter()!=c && ptra->return_left()!=NULL){
      s="0";
    //  cout<<"Going to left node "<<endl;
      s+=traverse(ptra->return_left(), c,switcher);          
    }

    if(switcher==true){return s;}
    if(switcher==false){ s.clear();}
    
   // cout<<*ptra<<" is the current node, ";
    if(ptra->letter()!=c && ptra->return_right()!=NULL){
      s="1";
    //  cout<<" Going to right"<<endl;
      s+=traverse(ptra->return_right(), c,switcher);
    }    
    if(switcher==false){ s.clear();}
   // ptra->enter_new_size(s.length());
   // bit_size += ptra->new_bits_length()*ptra->ammounts();
  return s;
  }
  // FRIEND FUNCTIONS  
  ostream& operator<<( ostream& o,const H_tree& ht){

    for (int i=0;i<ht.va.size();i++){
      o<<*ht.va[i]<<endl; 
    }
    return o;
  }
}