#pragma once

#include <string>
#include "../lib/debug.h"



enum token_t {
    TOKEN_ERROR,

    RETURN,
    IF,
    WHILE,

    SEMICOLON,
    COMMA,
    LEFT_PAREN,
    RIGHT_PAREN,

    IDENTIFIER,

    NUM_TOKENS
};



class Token {
public:
    Token(token_t type, std::string raw, int line);

    token_t     type()      const;
    std::string raw()       const;
    int         line()      const;
    void        print()     const;

private:
    token_t         _type;
    std::string     _raw;
    int             _line;
};




