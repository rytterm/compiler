#include "lexer/lexer.h"


int main() {
    Lexer l{"/home/max/compiler/file.txt"};
    l.print_stream();

   return 0;
}
