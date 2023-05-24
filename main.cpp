#include "BankAcc.hpp"

void actions(){
  std::cout<<"\n1. New transaction\n2. Apply transaction\n3. Pending transaction\n4. Discard pending transaction\n5. Balance\n6. Exit" << std::endl;
  std::cout<<"Your choice? \t";
};

int main(){
  
  BankAcc user1;
  char act;
  
  actions();
  
  while(std::cin>>act){
      switch(act){
        case '1':
          user1.new_transaction();
          break;
        case '2':
          user1.apply_tr();
          break;
        case '3':
          user1.pending_tr();
          break;
        case '4':
          user1.discard_pending_tr();
          break;
        case '5':
          user1.print_balance();
          break;
        case '6':
          return 0;
        default:
          std::cout<<"Incorrect input, please try again!"<<std::endl;
          break;
      };
    actions();
  };
}
