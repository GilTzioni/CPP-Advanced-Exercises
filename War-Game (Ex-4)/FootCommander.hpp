#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include<limits.h>

using namespace std;

class FootCommander: public FootSoldier{

public:

FootCommander(){}

FootCommander(int PID){
    this->Hp=150;
    this->Dp=50;
    this->cur_Hp=150;
    this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     FootSoldier::specialAttack(Board,location,2);
     for(auto i=0;i<Board.size();i++){
          for(auto j=0;j<Board.front().size();j++){
              if(i==location.first && j==location.second){
                 j++;
              }
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
                  if(FootSoldier* x=dynamic_cast<FootSoldier*>(Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                     FootSoldier::specialAttack(Board,s);
                  }
              }
              
          }
     }
}
          };