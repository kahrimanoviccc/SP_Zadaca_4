#include <iostream>
#include <stack>
#include "PostfixCalc.hpp"



int main()
{
PostfixCalc myCal;
std::string s;
  std::cout<<"Unesite izraz: " <<std::endl; 
  while( std::getline(std::cin,s) ){
  myCal.calculate(s);
  }
  
}
