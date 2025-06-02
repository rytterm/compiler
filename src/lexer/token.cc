#include "token.h"
#include <iostream>
#include <iomanip>


Token::Token(token_t type, token_t next, std::string raw, int line)
    : _type{type}, _next{next}, _raw{raw}, _line{line}
{
    ASSERT(_type >= 0);
    ASSERT(_line >= 1);
}
 

token_t Token::type() const {
    return _type;
}

token_t Token::next() const {
    return _next;
}

std::string Token::raw() const {
    return _raw;
}

int Token::line() const {
    return _line;
}


void Token::print() const {
    std::cout << std::left << std::setw(15) << _type << std::setw(15) << _next << std::setw(15) << _raw << std::setw(15) << _line << '\n';
}
