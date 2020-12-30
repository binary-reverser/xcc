#ifndef GLOBAL_H
#define GLOBAL_H

enum symbol
{
  null,ident,excep,number,
  addi,subs,mult,divi,assign,
  gt,ge,lt,le,equ,nequ,
  input,output,
  comma,chara,strings,semicon,lparen,rparen,lbrac,rbrac,
  rsv_min,
  rsv_break,rsv_char,rsv_continue,rsv_else,rsv_extern,rsv_if,rsv_in,rsv_int,rsv_out,rsv_return,rsv_string,rsv_void,rsv_while
  ,rsv_max
};
enum errcode
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


FILE* fin; //points to the source code

#endif
