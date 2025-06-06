#include "token.h"
#include <iostream>
#include <iomanip>


Token::Token(token_t type, std::string raw, int line, int column)
    : type_{type}, raw_{std::move(raw)}, line_{line}, column_{column}
{
    ASSERT(type_ >= 0 && type_ < NUM_TOKENS);
    ASSERT(line_ >= 1);
}
 

token_t Token::type() const {
    return type_;
}


std::string Token::raw() const {
    return raw_;
}

int Token::line() const {
    return line_;
}


int Token::column() const {
    return column_;
}


void Token::print() const {
    std::cout << std::left << std::setw(15) << type_ << std::setw(15) << raw_ << std::setw(15) << line_ << '\n';
}
