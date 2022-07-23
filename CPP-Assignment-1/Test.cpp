#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace phonetic;

#include <string>

using namespace std;

TEST_CASE("text length < word length"){
    string text = "aba ba";
    CHECK_THROWS_WITH(find(text,"aba baba"), "word length too long");
    CHECK_THROWS_WITH(find(text,"abababa"), "word length too long");
    CHECK_THROWS_WITH(find(text,"a ba   a"), "word length too long");
    CHECK_THROWS_WITH(find(text,"a bababa"), "word length too long");
    
}

TEST_CASE("Word isn't part of the text"){
     string text = "abbas sad aas";
    CHECK_THROWS_WITH(find(text,""), "Empty word");
    CHECK_THROWS_WITH(find(text,"ab1ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab%ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab_ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"aba^"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab-ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab!ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab(ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab&ba"), "Word isn't part of the text");
    CHECK_THROWS_WITH(find(text,"ab.ba"), "Word isn't part of the text");
     CHECK_THROWS_WITH(find(text,"ab=ba"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text,"ab_ba"), "Word isn't part of the text");
       CHECK_THROWS_WITH(find(text,"ab$ba"), "Word isn't part of the text");
        CHECK_THROWS_WITH(find(text,"ab@ba"), "Word isn't part of the text");
        CHECK_THROWS_WITH(find(text,"ab[ba"), "Word isn't part of the text");
         CHECK_THROWS_WITH(find(text,"ab*ba"), "Word isn't part of the text");
         CHECK_THROWS_WITH(find(text,"ab/ba"), "Word isn't part of the text");
          CHECK_THROWS_WITH(find(text,"ab~ba"), "Word isn't part of the text");
            CHECK_THROWS_WITH(find(text,"ab;ba"), "Word isn't part of the text");
}

TEST_CASE("word is almost a text substring but missing one letter or more"){
    string text="the times they are a changin";
     CHECK_THROWS_WITH(find(text,"tims"), "Word isn't part of the text");
     CHECK_THROWS_WITH(find(text,"hey"), "Word isn't part of the text");
     CHECK_THROWS_WITH(find(text,"chanin"), "Word isn't part of the text");
     CHECK_THROWS_WITH(find(text, "he"), "Word isn't part of the text");
}

TEST_CASE("word is a text substring but with one letter or more added"){
    string text="Dont think twice its alright";
      CHECK_THROWS_WITH(find(text,"itsalright"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text, "dontt"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text,"tthink"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text,"twwice"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text,"allright"), "Word isn't part of the text");
      CHECK_THROWS_WITH(find(text,"dontthink"), "Word isn't part of the text");
     
}
        
TEST_CASE("valid word with switched letters"){
     string text = "God is great and aba k";
     CHECK(find(text,"q")==string("k"));
     CHECK(find(text,"god")==string("God"));
     CHECK(find(text,"God")==string("God"));
     CHECK(find(text,"jud")==string("God"));
     CHECK(find(text,"jUD")==string("God"));
     CHECK(find(text,"Jud")==string("God"));
     CHECK(find(text,"GOD")==string("God"));
     CHECK(find(text,"GoD")==string("God"));
     CHECK(find(text,"gOD")==string("God"));
     CHECK(find(text,"JOD")==string("God"));
     CHECK(find(text,"jOd")==string("God"));
     CHECK(find(text,"gOt")==string("God"));
     CHECK(find(text,"JOt")==string("God"));
     CHECK(find(text,"jOt")==string("God"));
     CHECK(find(text,"jot")==string("God"));
     CHECK(find(text,"got")==string("God"));
     CHECK(find(text,"JOt")==string("God"));
     CHECK(find(text,"goT")==string("God"));
     CHECK(find(text,"gOT")==string("God"));
     CHECK(find(text,"GOT")==string("God"));
     CHECK(find(text,"JUT")==string("God"));
     CHECK(find(text,"GUT")==string("God"));
     CHECK(find(text,"gut")==string("God"));
     CHECK(find(text,"jut")==string("God"));
     CHECK(find(text,"guD")==string("God"));
     CHECK(find(text,"gUD")==string("God"));
     CHECK(find(text,"JUD")==string("God"));
     CHECK(find(text,"Jod")==string("God"));
     CHECK(find(text,"great")==string("great"));
     CHECK(find(text,"Great")==string("great"));
     CHECK(find(text,"GReat")==string("great"));
     CHECK(find(text,"GREat")==string("great"));
     CHECK(find(text,"GREAt")==string("great"));
     CHECK(find(text,"GREAT")==string("great"));
     CHECK(find(text,"greaT")==string("great"));
     CHECK(find(text,"greAT")==string("great"));
     CHECK(find(text,"grEAT")==string("great"));
     CHECK(find(text,"gREAT")==string("great"));
     CHECK(find(text,"grEAt")==string("great"));
     CHECK(find(text,"gREAT")==string("great"));
     CHECK(find(text,"Jreat")==string("great"));
     CHECK(find(text,"jreat")==string("great"));
     CHECK(find(text,"JReat")==string("great"));
     CHECK(find(text,"JREat")==string("great"));
     CHECK(find(text,"JREAt")==string("great"));
     CHECK(find(text,"JREAT")==string("great"));
     CHECK(find(text,"greaD")==string("great"));
     CHECK(find(text,"gread")==string("great"));
     CHECK(find(text,"jread")==string("great"));
     CHECK(find(text,"JreaD")==string("great"));
     CHECK(find(text,"JREAD")==string("great"));
     CHECK(find(text,"greAD")==string("great"));
     CHECK(find(text,"grEAD")==string("great"));
     CHECK(find(text,"gREAD")==string("great"));
     CHECK(find(text,"grEAd")==string("great"));
     CHECK(find(text,"grEad")==string("great"));
     CHECK(find(text,"jRead")==string("great"));
     CHECK(find(text,"GrEaT")==string("great"));
     CHECK(find(text,"JrEaT")==string("great"));
     CHECK(find(text,"GrEaD")==string("great"));
     CHECK(find(text,"JrEaD")==string("great"));
     CHECK(find(text,"gReAD")==string("great"));
     CHECK(find(text,"IS")==string("is"));
     CHECK(find(text,"is")==string("is"));
     CHECK(find(text,"Is")==string("is"));
     CHECK(find(text,"iS")==string("is"));
     CHECK(find(text,"yS")==string("is"));
     CHECK(find(text,"YS")==string("is"));
     CHECK(find(text,"ys")==string("is"));
     CHECK(find(text,"iz")==string("is"));
     CHECK(find(text,"Iz")==string("is"));
     CHECK(find(text,"iZ")==string("is"));
     CHECK(find(text,"YZ")==string("is"));
     CHECK(find(text,"yz")==string("is"));
     CHECK(find(text,"Yz")==string("is"));
     CHECK(find(text,"yZ")==string("is"));
     CHECK(find(text,"IZ")==string("is"));
}
TEST_CASE("valid word with switched letters"){
  string text=" hello";
  CHECK(find(text,"HELLO")==string("hello"));
}
