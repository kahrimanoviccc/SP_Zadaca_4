#include <iostream>
#include <stack>


bool check(const std::string& s){
  std::stack<char> brackets;
  bool valid = true;

  for(const char& c : s){
  
    if(c != '{' && c != '}' && c!= '[' && c!=']' && c!= '(' && c!= ')' && c!= '<' && c!= '>'){
  valid = false;
  return valid;
  };

  switch(c){
    case '{':
      if(!brackets.empty()){
        if(brackets.top() == '[' || brackets.top() == '(' || brackets.top() == '<'){
      valid = false;
      return valid;
      };
      };

      brackets.push(c);
      break;
    case '[':
      if(!brackets.empty()){
        if(brackets.top() == '(' || brackets.top() == '<'){
      valid = false;
      return valid;
      };
      };

      brackets.push(c);
      break;
    case '(':
      if(!brackets.empty()){
        if(brackets.top() == '<'){
      valid = false;
      return valid;
      };
      };

      brackets.push(c);
      break;
    case '<': 
      brackets.push(c);
      break;
    case '}':
    if(!brackets.empty() && brackets.top() == '{') brackets.pop();
    else valid = false;
    break;
    case ']':
      if(!brackets.empty() && brackets.top() == '[') brackets.pop();
      else valid = false;
    break;
    case ')' :
    if(!brackets.empty() && brackets.top() == '(') brackets.pop();
    else valid = false;
    break;
     case '>' :
    
       if(!brackets.empty() && brackets.top() == '<') brackets.pop();
    else valid = false;
    break;

  }
}
if(brackets.size() == 1) valid = false;

return valid;
}


int main(){

std::string input;

while(std::getline(std::cin, input)){
   if(check(input)){
     std::cout<<"Dobar"<<std::endl;
   }else{
      std::cout<<"Pogresan!" << std::endl;
    };
};

  
}
