#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <iostream>

class PostfixCalc {
  public:
//   void load(std::istream& i);
   void calculate(const std::string&);
   bool is_num(const std::string&) const;
   bool is_op(const std::string&) const;
   int as_num(const std::string&) const;
   char as_op(const std::string&) const;

  private:

    std::stack<int> numbers;
};

bool PostfixCalc::is_num(const std::string& s) const{
return isdigit(s[0]);
};

bool PostfixCalc::is_op(const std::string& s) const {
return s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/';
}

int PostfixCalc::as_num(const std::string& s) const {
return std::stoi(s);
}

char PostfixCalc::as_op(const std::string& s) const{
return s[0];
}

// void PostfixCalc::load(std::istream& i){
// while( i >> inp ){
// transform(inp);
// };
// }

void PostfixCalc::calculate(const std::string& s){
  std::istringstream is(s);
  std::string part;
  while(is >> part){
  if(is_num(part)){
  numbers.push(std::stoi(part));
  }else if(is_op(part)){
    int r = numbers.top();
    numbers.pop();
    int l = numbers.top();
    numbers.pop();
  
    switch(as_op(part)){
    case '+':
      l = l+r;
      numbers.push(l);
      continue;
    case '-':
      l = l-r;
      numbers.push(l);
      continue;
    case '*':
      l = l*r;
      numbers.push(l);
      continue;
    case '/':
      l = l/r;
      numbers.push(l);
      continue;
    };
  }else{
    std::cout <<"Nedefiniran izraz" <<std::endl;
  continue;};
  
  };
  std::cout<<numbers.top()<<std::endl;
}
