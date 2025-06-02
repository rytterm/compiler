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
    WHITESPACE
};



class Token {
public:
    Token(token_t type, token_t next, std::string raw, int line);

    token_t     type()      const;
    token_t     next()      const;
    std::string raw()       const;
    int         line()      const;
    void        print()     const;

private:
    token_t         _type;
    token_t         _next;
    std::string     _raw;
    int             _line;
};




