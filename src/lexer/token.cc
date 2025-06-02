#include "token.h"

Token::Token(token_t type, std::string& raw, int line, int column)
    : _type{type}, _raw{raw}, _line{line}, _column{column}
{
    ASSERT(_type    != TOKEN_ERROR);
    ASSERT(_line    > 0);
    ASSERT(_column  > 0);
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

int Token::column() const {
    return _column;
}
