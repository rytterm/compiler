#pragma once

#include <unordered_map>
#include <algorithm>
#include <string>
#include "../lib/debug.h"
#include "token.h"
#include <vector>
#include <fstream>


class Lexer {
public:
    Lexer(std::string fname);
        
private:
    std::unordered_map<std::string, token_t>    _hm;
    std::vector<Token>                          _tokens;
    

};
