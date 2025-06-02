#include "lexer.h"



Lexer::Lexer(std::string fname) 
    : _hm {
    { "return"  ,   RETURN      },
    { "if"      ,   IF          },
    { "while"   ,   WHILE       },
    { ";"       ,   SEMICOLON   }
    }
{
    std::ifstream ifs(fname);
}


