#!/usr/bin/env bash

GEN_FILE=../src/lex.yy.cc

sed -i "/int yyFlexLexer::yywrap()/,+5d" ${GEN_FILE}
