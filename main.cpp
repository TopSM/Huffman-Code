#include <iostream>
#include <cstring>
#include <vector>
#include <ostream>
#include <cmath>
#include <queue>
#include "Alph.h"
#include "H_tree.h"

using namespace std;

void create(string s,vector<Alph_OP::alph*>& vec_a);
void num_clear(vector<Alph_OP::alph*>& vec_a);
void num_create(string text, vector<Alph_OP::alph*>& vec_a);
void organize(vector<Alph_OP::alph*>& vec_a);


int main() {

  string s;
  cout<< "Enter the poem" <<endl;
  string inp;
  vector<Alph_OP::alph*> va;
  H_Tree_OP::H_tree htr;
while(true)
{  
  getline(cin,inp);
  s+=inp;
  if(inp ==""){ break; }
}  
cout<<s<<endl;
  htr.text_save(s);
  create(s, va); 
  htr.insert_list(va);
  int text_save= htr.original_bit_size();
  cout<<"the original ammount of bits: ";
  cout<< text_save <<endl<<endl;
  
  htr.make_tree();
  htr.final_ouput();
  cout<<"The new ammount of bits are: "<<htr.newstring_length()<<endl;  
  cout<<"\nThe difference is "<<text_save-htr.newstring_length()<<endl;
  return 0;
}

void create(string s, vector<Alph_OP::alph*>& vec_a)
{
  Alph_OP::alph* a;
    for (int i=65;i<90;i++){
      a = new alph;
      a->make_letter(i);
      vec_a.push_back(a); 
    }
    for (int i=96;i<122;i++){
      a = new alph;
      a->make_letter(i);
      vec_a.push_back(a); 
    }
    for (int i=32;i<63;i++){ 
       a = new alph;
      a->make_letter(i);  
      vec_a.push_back(a); 
    }   
    num_create(s,vec_a);
    num_clear(vec_a);
    organize(vec_a);
}

  void num_create(string text, vector<Alph_OP::alph*>& vec_a){
    for(int i=0;i<vec_a.size();i++){
      for(int j=0;j<text.length();j++){
        if(vec_a[i]->letter()==text[j]){ vec_a[i]->add(); }
      }
      
    }
  }
  void num_clear(vector<Alph_OP::alph*>& vec_a) {
    for (int i=0; i<vec_a.size();i++){
      if(vec_a[i]->ammounts()==0){
        vec_a.erase(vec_a.begin()+i);
        i--;
      }
    }  
  }

  void organize(vector<Alph_OP::alph*>& vec_a){
    Alph_OP::alph* a;
    int biggest;
    int size= vec_a.size();
    for(int i =0;i<vec_a.size()-1;i++){
      biggest= i;
      for(int j=i+1;j<vec_a.size();j++){
        if(vec_a[biggest]->ammounts()<vec_a[j]->ammounts()){
          biggest=j; 
        }
      }
      a=vec_a[i];
      vec_a[i]=vec_a[biggest];
      vec_a[biggest]=a;
    }
  }