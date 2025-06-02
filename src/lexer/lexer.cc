#include "lexer.h"
#include <iomanip>

Lexer::Lexer(std::string fname) 
    : _hm {
    { "return"  ,   RETURN      },
    { "if"      ,   IF          },
    { "while"   ,   WHILE       },
    { ";"       ,   SEMICOLON   }
    }, 
    _tokens{}
{

    std::ifstream ifs(fname);
    std::string line;
    int curline{0};

    while (std::getline(ifs, line)) {
        curline++;
        
        std::istringstream iss(line);


        std::transform(
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
        );
    }

}


void Lexer::print_stream() const {
    std::cout << "---------------------------------------------------\n";
    std::cout << std::left << std::setw(15) << "TOKEN:" << std::setw(15) << "EOW:" << std::setw(15) << "RAW:" << "LINE:\n";
    std::for_each(_tokens.begin(), _tokens.end(), 
                  [](Token const& token){
                        token.print();
                  });
    std::cout << "---------------------------------------------------";
}
