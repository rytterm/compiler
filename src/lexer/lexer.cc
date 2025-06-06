#include "lexer.h"
#include <iomanip>

Lexer::Lexer(std::string const& fname) 
    : hm_ {
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
    tokens_{}, pos_{}, line_{1}, column_{1}
{

    std::ifstream file(fname);

    if (!file) PANIC("File ", fname, " could not be opened");


    std::string stream_((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    

    ASSERT(stream_.size() > 0);





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


char Lexer::peek_() const {
    return pos_ < stream_.size() ? stream_[pos_] : '\0';
}


char Lexer::get_() {

    char c{peek_()};

    if (c == '\0') return c;

    pos_++;

    if (c == '\n') {
        line_++;
        column_ = 1;
    }
    else column_++;

    return c;
}


void Lexer::skip_() {
    while (true) {
        char c = peek_();

        switch(c) {
            case ' ':
            case '\t':
            case '\r':
                get_();
                break;
            case '\':
                get_();
                if (peek_() == '\')
                    while (peek_() != '\0' && peek_() != '\n')
                        get_();
            default:
                return;
        }
    }
}


Token Lexer::next_() {
    skip_();


}




void Lexer::print_stream() const {
    std::cout << "---------------------------------------------------\n";
    std::cout << std::left << std::setw(15) << "TOKEN:" << std::setw(15) << "RAW:" << "LINE:\n";
    std::for_each(tokens_.begin(), tokens_.end(), 
                  [](Token const& token){
                        token.print();
                  });
    std::cout << "---------------------------------------------------";
}
