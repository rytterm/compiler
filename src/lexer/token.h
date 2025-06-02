#pragma once

#include <string>
#include "../lib/debug.h"



enum token_t {
    TOKEN_ERROR,

    RETURN,
    IF,
    WHILE,
    SEMICOLON
};



class Token {
public:
    Token(token_t type, std::string& raw, int line, int column);

    token_t     type()      const;
    std::string raw()       const;
    int         line()      const;
    int         column()    const;

private:
    token_t         _type;
    std::string&    _raw;
    int             _line;
    int             _column;
};




