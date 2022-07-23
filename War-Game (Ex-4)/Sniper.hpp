#include <string>
#include <vector>
#include <stdexcept>
#include<limits.h>
 
class Sniper: public Soldier{

public:

Sniper(){}

Sniper(int PID){
    this->Hp=100;
    this->Dp=50;
    this->cur_Hp=100;
    this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location,int dummy) override{
     int myID=Board[location.first][location.second]->getPID();
     int max_power=0;
     pair<int, int> s_enemy;
      s_enemy.first=100000;
     s_enemy.second=100000;
  
     for(auto i=0;i<Board.size();i++){
          for(auto j=0;j<Board.front().size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
                 if(Board[i][j]->cur_Hp>max_power){
                  max_power=Board[i][j]->cur_Hp;
                  s_enemy.first=i;
                  s_enemy.second=j;
                 }
              }
          }
     }
 if(s_enemy.first!=10000){
      int a=Board[s_enemy.first][s_enemy.second]->cur_Hp-100;
      Board[s_enemy.first][s_enemy.second]->cur_Hp=a;
      if(a<=0){
          Board[s_enemy.first][s_enemy.second]=nullptr;
      }
 }

} 

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();

     int max_power=0;
     pair<int, int> s_enemy;
     s_enemy.first=100000;
     s_enemy.second=100000;
     for(auto i=0;i<Board.size();i++){
          for(auto j=0;j<Board[i].size();j++){
              if(Board[i][j]!=nullptr && Board[i][j]->getPID()!=myID){
                 if(Board[i][j]->cur_Hp>max_power){
                  max_power=Board[i][j]->cur_Hp;
                  s_enemy.first=i;
                  s_enemy.second=j;
                 }
              }
          }
     }
    
     if(s_enemy.first!=100000 && Board[s_enemy.first][s_enemy.second]!=nullptr){
      int a=Board[s_enemy.first][s_enemy.second]->cur_Hp-50;
      Board[s_enemy.first][s_enemy.second]->cur_Hp=a;
      if(a<=0){
          Board[s_enemy.first][s_enemy.second]=nullptr;
      }
     
     }
        //  cout<<"e"<<endl;
}
};