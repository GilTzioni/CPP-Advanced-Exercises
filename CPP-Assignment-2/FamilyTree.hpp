#include <string>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdbool.h>
#include<bits/stdc++.h> 
using namespace std;

#define COUNT 10 
#ifndef FamilyTree
#define FamilyTree

namespace family{

class node{

private:

  char G;
  int height;
  string name;
  node *left;
  node *right;

public:

   node(){
   name="me";
   left=nullptr;
   right=nullptr;
   height=0;
   G='m';
  }
  
  node(string n){
   name=n;
   left=nullptr;
   right=nullptr;
   height=0;
   G='m';
  }

  ~node(){
   if(this->getleft()){
   delete left;
    this->left=NULL;
   }
   if(this->getright()){
   delete right;
   this->right=NULL;
   }
  }

  void setname();
  void setname(string name);
  string getname();
  void setheight(int height);
  int getheight();
  void setleft(string name, int height);
  node *getleft();
  void setright(string name, int height);
  node *getright();
  node *search(node *leaf,string name);
  node *_search(node *leaf,string name);
  void setGender(char g);
  char getGender();
  void print2D(node *root);
  void print2DUtil(node *root, int space);
  node *findParentM(node *leaf,int h);
  node *findParentF(node *leaf,int h);
}; //node

class Tree{

private:

node *root;  

public:

  Tree(){}

  Tree(string n){
    this->root=new node(n);
  }

  ~Tree(){
    delete root;
    
  }

  Tree& addFather(string son, string father);
  Tree& addMother(string son, string mother);
  string find(string relation);
  string relation(string name);
  void remove(string name);
  void display();
  node *getroot();

  }; //Tree

}; // namespace family
#endif