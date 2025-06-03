#include "lexer/lexer.h"
#include "lib/debug.h"


int main(int argv, char** argc) {
    
    if (argc[1] == nullptr) PANIC("Argument for file is missing");

    Lexer l{argc[1]};
    //l.print_stream();

   return 0;
}
