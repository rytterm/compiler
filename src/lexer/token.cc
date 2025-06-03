#include "token.h"
#include <iostream>
#include <iomanip>


Token::Token(token_t type, std::string raw, int line)
    : _type{type}, _raw{std::move(raw)}, _line{line}
{
    ASSERT(_type >= 0 && _type < NUM_TOKENS);
    ASSERT(_line >= 1);
}
 

token_t Token::type() const {
    return _type;
}


std::string Token::raw() const {
    return _raw;
}

int Token::line() const {
    return _line;
}


void Token::print() const {
    std::cout << std::left << std::setw(15) << _type << std::setw(15) << _raw << std::setw(15) << _line << '\n';
}
