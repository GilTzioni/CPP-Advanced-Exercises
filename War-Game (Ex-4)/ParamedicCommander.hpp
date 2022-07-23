#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include<limits.h>

using namespace std;

class ParamedicCommander: public Paramedic{

public:
ParamedicCommander(){}

ParamedicCommander(int PID){
      this->Hp=200;
      this->cur_Hp=100;
      this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{

     int myID=Board[location.first][location.second]->getPID();
     Paramedic::specialAttack(Board,location);
     for(auto i=0;i<Board.size();i++){
          for(auto j=0;j<Board.front().size();j++){
              if(i==location.first && j==location.second){
                 j++;
              }
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
                  if(Paramedic* x=dynamic_cast<Paramedic*>(Board[i][j])){
                      pair<int,int> s;
                      s.first=i;
                      s.second=j;
                    //  cout<<i<<" "<<j<<endl;
                     Paramedic::specialAttack(Board,s);
                    // cout<<i<<" "<<j<<endl;
                  }
              }
          }
     }
}
};