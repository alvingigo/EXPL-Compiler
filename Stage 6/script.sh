#!/bin/bash

lex exprtree.l

yacc -d exprtree.y

gcc lex.yy.c y.tab.c

./a.out test2.txt

lex labeltrans.l

gcc lex.yy.c

./a.out

