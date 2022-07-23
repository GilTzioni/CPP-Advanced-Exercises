#include "FamilyTree.hpp"

using namespace std;
namespace family{
 void family::node::print2DUtil(node *root, int space){
   //print2DUtil copied from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions//
    if (root == NULL)  
        return;  

    space += COUNT;  
    family::node::print2DUtil(root->right, space);   
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    family::node::print2DUtil(root->left, space);  
}  
    
void family::node::print2D(node *root){  
    print2DUtil(root, 0);  
}   
void family::node::setname(){
  this->name="";
}
void family::node::setname(string NewName){
   this->name=NewName;
}

void family::node::setheight(int h){
   this->height=h+1;;
}

string family::node::getname(){
   return this->name;
}

int family::node::getheight(){
  return this->height;
}
void family::node::setGender(char g){
   this->G=g;
}

void family::node::setright(string name, int height){
  this->right=new node(name);
  this->right->setheight(this->height);
  this->right->setGender('m');
}

void family::node::setleft(string name, int height){
  this->left=new node(name);
  this->left->setheight(this->height);
  this->left->setGender('f');
}

family::node* family::node::getleft(){
  return this->left;
}
family::node* family::node::getright(){
  return this->right;
}
char family::node::getGender(){
  return this->G;
}

  family::node* family::node::search(node *leaf,string name){

  if(leaf->getname().compare(name)==0 || !leaf){
    return leaf;
  }
  
  else

  if(leaf->getleft()){
  if(leaf->search(leaf->getleft(),name)){
    return leaf->search(leaf->getleft(),name);
  }
  }
  //getright()
  //getleft()
  if(leaf->getright()){
  if(leaf->search(leaf->getright(),name))
  return leaf->search(leaf->getleft(),name);
  }
    return NULL;
}

family::node* family::node::_search(node *leaf,string name){
    node *temp=NULL;
  if(leaf->getname().compare(name)==0 || leaf==NULL){
    return leaf;
  }
  
  else

  if(leaf->getleft()){
  temp=leaf->_search(leaf->getleft(),name);
  if(temp){
    return temp;
  }
  }
  //getright()
  //getleft()
  if(leaf->getright()){
  temp=leaf->_search(leaf->getright(),name);
  if(temp){
    return temp;
  }
  }
    return nullptr;
}
Tree& family::Tree::addFather(string son, string father){
  
  if(!(*root)._search(root,son))
   {
    throw logic_error{"Match not found"};
   }
 // cout<<(*root).search(root,son)->getname()<<endl;
   if((*root)._search(root,son)->getright() && (*root)._search(root,son)->getright()->getname()!=""){
     throw logic_error{"Double insert"};
   }
   else if(root->getname().compare(son)==0)
   {
    this->root->setright(father, this->root->getheight() + 1);
   }
  else
   {
    node *temp;
    temp=this->root->_search(root,son);
     temp->setright(father,temp->getheight() + 1);
    }

  return *this;
}

Tree& family::Tree::addMother(string son,string mother){

   if(!this->root->_search(root,son))
   {
    throw logic_error{"Match not found"};
   }

   if((*root)._search(root,son)->getleft()!=NULL){
     throw logic_error{"Double insert"};
   }

   if(root->getname().compare(son)==0)
   {
    this->root->setleft(mother, this->root->getheight() + 1);
   }

  else
   {
    node *temp;
    temp=this->root->_search(root,son);
     temp->setleft(mother, temp->getheight() + 1);
   }
  return *this;
}

string family::Tree::relation(string name){
  string ans;
  node *temp=this->root->_search(root,name);

  if(!temp)
  {
    return "unrelated";
  }

  else
  {
  int height=this->root->getheight();
  int r_height=temp->getheight()-height;

    if(r_height==0)
     return "me";

    if(r_height==1){
       if(this->root->getleft()->getname().compare(name)==0)
          return "mother";
          return "father";
     }
    else if(r_height==2){
        if(temp->getGender()=='m')
        return "grandfather";
        return "grandmother";
     }
    else{

       while(r_height>2)
       {
         ans=ans+"great-";
         r_height--;
       }

       if(temp->getGender()=='m')
        ans=ans+"grandfather";
       else
         ans=ans+"grandmother";
    }
  }
  return ans;
}

string family::Tree::find(string relation){
  int h=1;
  char gender='m';
  string ans;
  node *temp=nullptr;
  // while(relation.at(0)==char(' ')){
  //   relation=relation.substr(1);
  // }
  if(relation.length()<6){
    throw invalid_argument{"The tree cannot handle that relation"};
  }
  if(relation.substr(0,6)==string("great-"))
  {
  while(relation.substr(0,6)==string("great-")){
    relation=relation.substr(6);
   if(h==1)
     h=3;
   else
     h=h+1;
   }
  }

    if(relation.substr(0,11)==string("grandfather") || relation.substr(0,11)==string("grandmother"))
  {
    if(relation.substr(0,11)==string("grandfather"))
        gender='m';
    else
      gender='f';
    
    if(h<3)
    h++;
   }

  else if(relation.length()==6)
  {
    if(relation.at(0)=='m')
      gender='f';
  }

  else
  {
    throw invalid_argument{"The tree cannot handle the " +relation+ " relation"};
  }
 // cout<<h<<endl;;
   
   if(h==1){
    if(gender=='m'){
      if(root->getright()){
        ans=root->getright()->getname();
      }
    }

    if(gender=='f'){
     if(root->getleft())
      ans=root->getleft()->getname();
      }
      if(!ans.empty())
      return ans;
    }
   
   if(h>1){
    if(gender=='f' && root->findParentF(root,h))
    temp=root->findParentF(root,h);
    if(gender=='m' && root->findParentM(root,h))  
    temp=root->findParentM(root,h);
   }
   if(!temp)
  throw invalid_argument{"The tree cannot handle that relation"};

return temp->getname();
}

void family::Tree::remove(string name){

  if(this->root->_search(root,name) && root->getname()!=name && name!=string("   ")){
   // cout<<temp->getname()<<endl;
    delete this->root->search(root,name);
    //cout<<this->root->search(root,name)->getname()<<endl;
  }
  else 
  throw logic_error{"Nothing to remove!"};
}

 family::node* family::node::findParentM(node *leaf,int h){
  //cout<<leaf->getname()<<endl;
    node *temp;
  if(leaf->right && leaf->right->getheight()==h){
    return leaf->right;
  }
  
  else

  if(leaf->left){
  temp=leaf->findParentM(leaf->left,h);
  if(temp){
   // cout<<"here1"<<endl;
    return temp;
  }
  }

  if(leaf->right){
  temp=leaf->findParentM(leaf->right,h);
  if(temp){
   // cout<<"here2"<<endl;
    return temp;
  }
  }
  
    return NULL;
}

family::node* family::node::findParentF(node *leaf,int h){
    node *temp;
   // cout<<leaf->getheight()<<endl;
  if(leaf->getleft() && leaf->getleft()->getheight()==h){
    return leaf->getleft();
  }
  
  else

  if(leaf->getleft()){
  temp=leaf->findParentF(leaf->getleft(),h);
  if(temp!=NULL){
    return temp;
  }
  }

  if(leaf->getright()){
  temp=leaf->findParentF(leaf->getright(),h);
  if(temp!=NULL){
    return temp;
  }
  }
 // cout<<leaf->getname()<<endl;
    return NULL;
}

void family::Tree::display(){
  root->print2D(this->root);
}
node * family::Tree::getroot(){
    return root;
  }
}; // namespace MyTree