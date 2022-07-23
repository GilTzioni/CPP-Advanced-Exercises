#include <string>
#include <vector>
#include <stdexcept>
#include<limits.h>
#include<iostream>

using namespace std;

class SniperCommander: public Sniper{

public:

SniperCommander(){}

SniperCommander(int PID){
     this->Hp=120;
    this->Dp=100;
    this->cur_Hp=120;
    this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     Sniper::specialAttack(Board, location,2);
     for(auto i=0;i<Board.size();i++){
          for(auto j=0;j<Board.front().size();j++){
              if(i==location.first && j==location.second)
              j++;
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
                  if(Sniper* x=dynamic_cast<Sniper*>(Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     Sniper::specialAttack(Board,s);
                  }
              }
          }
     }
}
};