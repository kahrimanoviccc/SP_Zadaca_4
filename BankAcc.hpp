#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <ctime>
#include <chrono>

class Transaction{
  public: 

  Transaction(char c, double am, std::string dt)
   : c_{c}, amount_{am}, dateTime_{dt}
   {};

   Transaction(){
   c_ = '+';
   amount_ = 0.0;
   dateTime_ = "n/a";
   };
  
  const char& get_char() const{
  return c_;
  };

  const double& get_am() const{
  return amount_;
  }

  const std::string& get_dt() const{
  return dateTime_;
  }

  friend std::ostream& operator<<(std::ostream& o, const Transaction& t){
  o<<t.get_char()<<t.get_am()<<"\n"<<t.get_dt() <<"\n";
  return o;
  }

  private:
    char c_;
    double amount_;
    std::string dateTime_;

};


class BankAcc{
  public:
    void new_transaction(){
      char c;
      double am;
      std::string dt;

      std::cout<<"\nYour choice is new transaction!\nIf you want add money to your account balance press +. If you want to get money from your account balance press -" << std::endl;
      std::cin>> c;
      if((c != '+') && (c != '-')) throw std::string{"Incorecct input!"};
      std::cout<<"Please enter amount" <<std::endl;
      std::cin>> am;

      //vrijeme transakcije i konverzija u string 
      auto now = std::chrono::system_clock::now();
      std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
      dt = std::ctime(&currentTime);
      // provjera datuma std::cout<< dt << std::endl;
      transactions_.push(Transaction(c,am,dt));
      // provjera push std::cout<< transactions_.size() << std::endl;
    };


    void apply_tr(){
    if(transactions_.size() == 0) return;
      Transaction tmp = transactions_.front();
      if(tmp.get_char() == '+'){
        balance_+= tmp.get_am();
      }else {
        balance_-= tmp.get_am();
      };
      transactions_.pop();
    };


    void pending_tr(){
      std::cout<<transactions_.front();
    };

    void discard_pending_tr(){
    transactions_.pop();
    }

    void print_balance() const{
      std::cout<< "Your account balance: " << balance_ << std::endl;
    }

  private:
    double balance_ = 0.00;
    std::queue<Transaction> transactions_;
};
