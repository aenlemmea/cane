#ifndef CANE_PARSER_HH
#define CANE_PARSER_HH

#include "lexertil.hh"

static dtok yylex(Lexer& lx) {
    lx.get_next_token();
}

#endif
