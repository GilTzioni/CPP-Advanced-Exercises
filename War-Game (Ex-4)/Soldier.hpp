#include <iostream>
#include <vector>
using namespace std;

class Soldier {

protected:

int PlayerID;

public:

int Hp; 
int Dp;
int cur_Hp;

Soldier(){}
    
virtual void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location)=0;
virtual void specialAttack(std::vector<std::vector<Soldier*>> &Board, std::pair<int, int> location,int dummy)=0;
int getPID(){
    return this->PlayerID;
}

virtual ~Soldier(){}

};