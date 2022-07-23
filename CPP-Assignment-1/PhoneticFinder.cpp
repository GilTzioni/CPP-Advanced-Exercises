#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
#include<bits/stdc++.h> 
#include <stdbool.h>

using namespace std;

 bool equal(char fir,char sec){

    if(fir==sec){
       return true;
  }
    else if (fir=='w' || fir=='v'){
    if(sec=='w' || sec=='v'){
       return true;
    }
}

    else if (fir=='b' || fir=='f' || fir=='p'){
    if(sec=='b' || sec=='f' || sec=='p'){
     return true;
    }
 }

    else if (fir=='g' || fir=='j'){
    if(sec=='g' || sec=='j'){
     return true;
   }
  }

   else if(fir=='c' || fir=='k' || fir=='q'){ 
    if(sec=='c' || sec=='k' || sec=='q'){
     return true;
    }
   }

    else if(fir=='s' || fir=='z'){ 
    if(sec=='s' || sec=='z'){
     return true;
    }
    }

    else if(fir=='d' || fir=='t'){ 
    if(sec=='d' || sec=='t'){
     return true;
    }
    }

    else if(fir=='o' || fir=='u'){ 
    if(sec=='o' || sec=='u'){
     return true;
    }
    }

    else if(fir=='i' || fir=='y'){ 
    if(sec=='i' || sec=='y'){
     return true;
    }
    }

    return false;
}

 bool isEquals(string textw,string word){
   int i=0;
   for(auto x : textw){
     if(!equal(x,word.at(i))){
       return false;
     }
     i++;
   }
   return true;
}



string phonetic::find(string text,string word){
  
  if(word.length()==0 || word==" "){
      throw logic_error{"Empty word"};
     }

  while(text.at(0)==' '){
    text=text.substr(1);
  }
  while(word.at(0)==' '){
    word=word.substr(1);
  }

  if(text.length()<word.length()){
      throw logic_error{"word length too long"};
     }

     string strt=text;
     string strw=word;
     string temp;
    
     transform(strt.begin(), strt.end(), strt.begin(), ::tolower);
     transform(strw.begin(), strw.end(), strw.begin(), ::tolower);

    int count=0,pos=0;
    int size=strw.length();

 if(text.length()==word.length()){
      if(isEquals(strt,strw))
      return text;
      throw logic_error{"Word isn't part of the text"};
    }

      for (auto x : strt) 
   { 
       if (x == ' ' || pos==strt.length()-1){
           if(isEquals(temp,strw)){
            if(pos==count){
              if(size==count){
              return text.substr(pos-size,size);
              }
             
           }

            else if(pos==strt.length()-1){
              if(size==count){
               return text.substr(pos+1-size,size);
              }
             }

            else if(size==count-1){
             return text.substr(pos-size,size);
            }
           }
          
           count=0; 
           temp = "";  
  }
       else
       temp = temp + x; 
       count++;
       pos++;
   
   }

throw logic_error{"Word isn't part of the text"};
}
