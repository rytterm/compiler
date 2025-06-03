#include "lexer.h"
#include <iomanip>

Lexer::Lexer(std::string fname) 
    : _hm {
    { "return"  ,   RETURN      },
    { "if"      ,   IF          },
    { "while"   ,   WHILE       },
    { ";"       ,   SEMICOLON   },
    { "("       ,   LEFT_PAREN  },
    { ")"       ,   RIGHT_PAREN },
    { "int"     ,   IDENTIFIER  },
    { "char"    ,   IDENTIFIER  },
    { "string"  ,   IDENTIFIER  },
    { "float"   ,   IDENTIFIER  }
    }, 
    _tokens{}, _file(fname)
{

    ASSERT(_file, fname, " could not be opened");

/*    std::istringstream iss(_file);
    std::string word;
    char cur;
    int curline;


    while (iss.get(cur)) {
        if (cur == '\n')
            curline++;
        
        if (_hm.count(cur)) {
            _tokens.push_back(Token{_hm[cur], cur, curline});
        }
        else if (std::isalpha(cur)) {
            word += cur;
            
        }
    }


        /*std::transform(
            std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter(_tokens),
            [this,&curline](std::string const& word) {

                auto it = _hm.find(word.substr(0, word.size()-1));
                if (word.back() == ';' && it != _hm.end())
                    return Token{it->second, SEMICOLON, word, curline};

                it = _hm.find(word);
                if (it != _hm.end() && it->second != TOKEN_ERROR)
                    return Token{it->second, WHITESPACE, word, curline};

                return Token{TOKEN_ERROR, TOKEN_ERROR, word, curline};
            }
        );*/

}


void Lexer::_getw(int curline) const {

}


void Lexer::print_stream() const {
    std::cout << "---------------------------------------------------\n";
    std::cout << std::left << std::setw(15) << "TOKEN:" << std::setw(15) << "RAW:" << "LINE:\n";
    std::for_each(_tokens.begin(), _tokens.end(), 
                  [](Token const& token){
                        token.print();
                  });
    std::cout << "---------------------------------------------------";
}
