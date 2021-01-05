#ifndef GLOBAL_H
#define GLOBAL_H

#include<stdio.h>

enum TAG
{
  ERR, //error
  END, //the end of file
  ID, //identifier
  KW_INT, KW_CHAR, KW_VOID, //data type
  NUM, CH, STR, //constant
  NOT, LEA, //Monocular operation
  ADD, SUB, MUL, DIV, MOD,
  INC, DEC,
  GT, GE, LT, LE, EQU, NEQU,
  AND, OR, LOGIC_OR, BIT_OR,
  LPAREN, RPAREN, //()
  LBRACK, RBRACK, //[]
  LBRACE, RBRACE, //{}
  COMMA, COLON, SEMICON, //,:;
  ASSIGN,
  KW_IF, KW_ELSE,
  KW_SWITCH, KW_CASE, KW_DEFAULT,
  KW_WHILE, KW_DO, KW_FOR,
  KW_BREAK, KW_CONTINUE, KW_RETURN,
  KW_EXTERN
};

static const char* TagString[] = {
  "ERR", //error
  "END", //the end of file
  "ID", //identifier
  "KW_INT", "KW_CHAR", "KW_VOID", //data type
  "NUM", "CH", "STR", //constant
  "NOT", "LEA", //Monocular operation
  "ADD", "SUB", "MUL", "DIV", "MOD",
  "INC", "DEC",
  "GT", "GE", "LT", "LE", "EQU", "NEQU",
  "AND", "OR", "LOGIC_OR", "BIT_OR",
  "LPAREN", "RPAREN", //()
  "LBRACK", "RBRACK", //[]
  "LBRACE", "RBRACE", //{}
  "COMMA", "COLON", "SEMICON", //,:;
  "ASSIGN",
  "KW_IF", "KW_ELSE",
  "KW_SWITCH", "KW_CASE", "KW_DEFAULT",
  "KW_WHILE", "KW_DO", "KW_FOR",
  "KW_BREAK", "KW_CONTINUE", "KW_RETURN",
  "KW_EXTERN"
};

enum ERROR_CODE
{
  charwrong,strwrong,str2long,num2long,id2long,excpchar,
  semiconlost,commalost,typelost,identlost,semiconwrong,typewrong,
  paralost,rparenlost,lbraclost,rbraclost,
  statementexcp,localidentlost,lparenlost,lparenwrong,staterparenlost,rparenwrong,elselost,elsespelterr,elsewrong,
  idtaillost,returnwrong,arglost,argwrong,arglistwrong,na_input,input_err,output_err,
  opplost,oppwrong,exprlost,exprparenlost,exprwrong,
  var_redef,para_redef,localvar_redef,fun_redef,fun_def_err,fun_dec_err,
  str_nadd,void_ncal,
  void_nassi,assi_ncomtype,ret_type_err,fun_undec,var_undec,real_args_err,str_nb_cond
  ,void_nb_cond,break_nin_while,continue_nin_while,void_nin,
};


extern FILE* fin; //points to the source code

#endif
