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
    Lexer(std::string const& fname);

    void print_stream() const;
        
private:
    char peek_() const;
    char get_();

    void skip_();

    Token next_();


    std::unordered_map<std::string, token_t>    hm_;
    std::vector<Token>                          tokens_;
    std::string                                 stream_;
    long unsigned int                           pos_;
    int                                         line_;
    int                                         column_;
};
