#pragma once


#include <iterator>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "../lib/debug.h"
#include "token.h"
#include <vector>
#include <fstream>
#include <optional>


class Lexer {
public:
    Lexer(std::string fname);

    void print_stream() const;
        
private:
    std::unordered_map<std::string, token_t>    _hm;
    std::vector<Token>                          _tokens;
    

};
