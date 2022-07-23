#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include<limits.h>

using namespace std;

class Paramedic: public Soldier{

public:

Paramedic(){}

Paramedic(int PID){
     this->Hp=100;
     this->cur_Hp=100;
     this->PlayerID=PID;
}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location,int dummy) override{}

void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location) override{
     int myID=Board[location.first][location.second]->getPID();
     int u=location.first,d=location.first,l=location.second,r=location.second;

     if(location.first>0)
     d=location.first-1;

     if(location.first<Board.size()-1)
     u=location.first+1;

     if(location.second>0)
     l=location.second-1;

     if(location.second<Board.front().size()-1)
     r=location.second+1;
    // cout<<d<<" "<<u<<" "<<l<<" "<<r<<endl;
     for(auto i=d;i<=u;i++){
          for(auto j=l;j<=r;j++){
           if(Board[i][j]!=nullptr && Board[i][j]->getPID()==myID){
             Board[i][j]->cur_Hp= Board[i][j]->Hp; 
            // cout<<i<<","<<j<<" "<<Board[i][j]->cur_Hp<<endl;
           }
          }
     }
    //  cout<<location.first<<endl;
}
}; 
