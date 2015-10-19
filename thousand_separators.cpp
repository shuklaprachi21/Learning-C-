/*
 * thousand_separators.cpp
 * 
 * insert comma(,) in an entered number after every 3 digits
 */

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  string num_str;
  int num_int;
  bool neg = false;
  cout<<"Enter the number: "<<endl;
  cin >>num_str;
  if (num_str[0]=='-'){
    neg=true;
    num_str.erase(0,1);
  }
  if((all_of(num_str.begin(),num_str.end(),::isdigit))==true){
    num_int=stoi(num_str); 
    if (num_int<1000){
      if(neg==true) 
        cout<<"-";
      cout<<num_int<<endl;
      return 0;
    }
  }
  else {
    cout<<"InvalidInput\n";
    return -1;
  }
  if(num_int<0) neg = true;
  num_int=abs(num_int);
  int dig = 0;
  string res_str="";
  int count;
  for(;;){
    if(num_int%1000>=0){
      if(num_int/1000>0){
        count = 3;
        while(count>0){
          res_str.insert(0,to_string(num_int%10));
          num_int=num_int/10;
          count--;
        }
        res_str.insert(0,",");      
      }
      else{
        res_str.insert(0,to_string(num_int%1000)); 
        break;
      }        
    }
    else
      break;
  }
  if(neg==true)
    res_str.insert(0,"-");
  cout<<res_str<<endl; 
  return 0;
}
