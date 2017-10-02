// "Copyright 2017 Maruth Goyal"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "parser.hpp"
#include "../stdlib/stdlib.hpp"

parser::thing* parse_(std::string s, int& i, std::vector<char>& stack) {
 
  while (std::isspace(s[i]) && i < s.length()) i++;

  if (s[i] == '(') {

    parser::expression* e = new parser::expression;

    stack.push_back('(');
    i++;

    while (!stack.empty()) {
      if(!(e->insert_thing(parse_(s, i, stack))))
        break;
    }  // stack empty checking WHILE ENDs

    return e;
 
  }

  else if (s[i] == ')') {
   
    if (stack.empty())
      stdlib::exit("UNMATCHED BRACES");
  
    stack.pop_back();
    i++;
  
  }

  else {
   
    std::string buff;

    while (!isspace(s[i]) && s[i] != ')') {
      
      buff.push_back(s[i]);
      i++;
    
    }

    parser::token *t = new parser::token(buff);
    return t;

  }

  return NULL;

}

parser::thing* parser::parse(std::string s) {

  int i = 0;
  std::vector<char> stack;
  return parse_(s, i, stack);

}
