#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include<iostream>

namespace WarGame {

Soldier*& Board::operator[](std::pair<int,int> location){
    return this->board[location.first][location.second];
     
}
Soldier* Board::operator[](std::pair<int,int> location) const{
    return this->board[location.first][location.second];
}
bool Board::isLocationEmpty(std::pair<int,int> source){
     if(source.first<0 || source.first>this->board.size()-1 || source.second<0 || source.second>this->board.front().size()-1)
        return false;
       
     if(this->board[source.first][source.second]!=nullptr){
       return false;
     }

     return true;

}

void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
 
std::pair<int,int> target;
target.first=source.first;
target.second=source.second;

if(this->board[source.first][source.second]==nullptr || this->board[source.first][source.second]->getPID()!=player_number ||  board.empty()){
     throw std::invalid_argument("invalid move!");
}

if(direction==MoveDIR::Up){
     target.first=source.first+1;
 }
if(direction==MoveDIR::Down){
     target.first=source.first-1;
 }
if(direction==MoveDIR::Left ){
     target.second=source.second-1;
 }
if(direction==MoveDIR::Right){
     target.second=source.second+1;
 }

if(isLocationEmpty(target)){
      this->board[target.first][target.second]=this->board[source.first][source.second];
      this->board[source.first][source.second]=nullptr;
      this->board[target.first][target.second]->specialAttack(this->board,target);
      
   }
   else{
      throw std::invalid_argument("invalid move!");
   }
   
 } 


bool Board::has_soldiers(uint player_number) const {
    if(this->board.empty()){
    return false;
    }
    for (size_t i = 0; i < this->board.size(); i++){
      for (size_t j = 0; j < this->board.front().size(); j++){
          if(this->board[i][j]!=nullptr && this->board[i][j]->getPID()==player_number){
            return true;
          }
      }
    }
    return false;
}
void Board::deleteall() {
			for (int i = 0; i < this->board.size(); i++) {
				for (int j = 0; j < this->board.front().size(); j++) {
					if (this->board[i][j] != nullptr)
						delete board[i][j];
				}
			}
		}
 }