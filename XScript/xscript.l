%{
#undef YY_INPUT
#define YY_INPUT(buf, result, max_size) (result = my_yyinput(buf, max_size))
#include "stdafx.h"

static int
file_input(char *buf, int max_size)
{   
    if (feof(yyin))
    {  
		return 0;
	}
    for(int len = 0; len < max_size; len++) 
	{
		int ch;
        ch = getc(yyin);
        if (ch == EOF)
		{
            return len;
		}
        buf[len] = ch;
    }    
}

static char **st_source_string;
static int st_current_source_line;
static int st_current_char_index;
 
void
xs_set_source_string(char **source)
{
    st_source_string = source;
    st_current_source_line = 0;
    st_current_char_index = 0;
}

static int
string_input(char *buf, int max_size)
{
    int len;
    if (st_source_string[st_current_source_line] == NULL)
    {    
		return 0;
	}
    if (st_source_string[st_current_source_line][st_current_char_index] == '\0') 
	{
        st_current_source_line++;
        st_current_char_index = 0;
    }
    if (st_source_string[st_current_source_line] == NULL)
    {
		return 0;
	}
    len = smaller(strlen(st_source_string[st_current_source_line])- st_current_char_index, max_size);
    strncpy(buf,&st_source_string[st_current_source_line][st_current_char_index],len);
    st_current_char_index += len;
    return len;
}

static int
my_yyinput(char *buf, int max_size)
{
	int	result = file_input(buf, max_size);

    return result;
}


int
yywrap(void)
{
    return 1;
}

static void
increment_line_number()
{
    xs_get_current_compiler()->current_line_number++;
}
%}
%start C_COMMENT CC_COMMENT STRING_LITERAL_STATE
%%
<INITIAL>"struct"       return _Struct_;
<INITIAL>"class"        return _Class_;
<INITIAL>"if"           return _If_;
<INITIAL>"else"         return _Else_;
<INITIAL>"elsif"        return _Elseif_;
<INITIAL>"while"        return _While_;
<INITIAL>"for"          return _For_;
<INITIAL>"foreach"      return _Foreach_;
<INITIAL>"return"       return _Return_;
<INITIAL>"break"        return _Break_;
<INITIAL>"continue"     return _Continue_;
<INITIAL>"true"         return _True_;
<INITIAL>"false"        return _False_;
<INITIAL>"try"          return _Try_;
<INITIAL>"catch"        return _Catch_;
<INITIAL>"finally"      return _Finally_;
<INITIAL>"throw"        return _Throw_;
<INITIAL>"bool"			return _Boolean_;
<INITIAL>"int"          return _Int_;
<INITIAL>"double"       return _Double_;
<INITIAL>"string"       return _String_;
<INITIAL>"("            return _Lp_;
<INITIAL>")"            return _Rp_;
<INITIAL>"{"            return _Lc_;
<INITIAL>"}"            return _Rc_;
<INITIAL>";"            return _Semicolon_;
<INITIAL>":"            return _Colon_;
<INITIAL>","            return _Comma_;
<INITIAL>"&&"           return _LogicalAnd_;
<INITIAL>"||"           return _LogicalOr_;
<INITIAL>"="            return _Assign_;
<INITIAL>"=="           return _Eq_;
<INITIAL>"!="           return _Ne_;
<INITIAL>">"            return _Gt_;
<INITIAL>">="           return _Ge_;
<INITIAL>"<"            return _Lt_;
<INITIAL>"<="           return _Le_;
<INITIAL>"+"            return _Add_;
<INITIAL>"-"            return _Sub_;
<INITIAL>"*"            return _Mul_;
<INITIAL>"/"            return _Div_;
<INITIAL>"%"            return _Mod_;
<INITIAL>"+="           return _AddAssign_;
<INITIAL>"-="           return _SubAssign_;
<INITIAL>"*="           return _MulAssign_;
<INITIAL>"/="           return _DivAssign_;
<INITIAL>"%="           return _ModAssign_;
<INITIAL>"++"           return _Increment_;
<INITIAL>"--"           return _Decrement_;
<INITIAL>"!"            return _Exclamation_;
<INITIAL>"."            return _Dot_;

<INITIAL>[A-Za-z_][A-Za-z_0-9]* {
    yylval.identifier  = xs_create_identifier(yytext);
    return _Identifier_;
}
<INITIAL>[1-9][0-9]* {
	Int32 v;
    sscanf(yytext, "%d", &(v));
    yylval.expression  = xs_create_int32_expression(v);
    return _IntLiteral_;
}
<INITIAL>"0" {
	Int32 v;
    sscanf(yytext, "%d", &(v));
    yylval.expression  = xs_create_int32_expression(v);
    return _IntLiteral_;
}
<INITIAL>[0-9]+\.[0-9]+ {	
	Double v;
    sscanf(yytext, "%lf", &(v));
    yylval.expression  = xs_create_double_expression(v);
    return _DoubleLiteral_;
}
<INITIAL>\" {
    BEGIN STRING_LITERAL_STATE;
}
<INITIAL>[ \t] ;
<INITIAL>[ \t\r\n] {increment_line_number();}
<INITIAL>"/*"     BEGIN C_COMMENT;
<INITIAL>"//"     BEGIN CC_COMMENT;
<INITIAL>.      {
		char buf[128];
		if (isprint(yytext[0]))
		{
			buf[0] = yytext[0];
			buf[1] = '\0';
		}
		else
		{
			sprintf(buf, "0x%02x", (unsigned char)yytext[0]);
		}
		std::wstring err;
		mcstr_to_wstring(buf, err);
		xs_compile_bad_char_error(xs_get_current_compiler()->current_line_number, &err);
}
<C_COMMENT>\n     increment_line_number();
<C_COMMENT>"*/"     {
    BEGIN INITIAL;
}
<C_COMMENT>.      ;
<CC_COMMENT>\n  {
    increment_line_number();
    BEGIN INITIAL;
}
<CC_COMMENT>.   ;
<STRING_LITERAL_STATE>\"        {
    yylval.expression = xs_create_string_expression(xs_flush_string_buffer());
    BEGIN INITIAL;
    return _StringLiteral_;
}
<STRING_LITERAL_STATE>\n        {
    xs_push_string_buffer('\n');
    increment_line_number();	
}
<STRING_LITERAL_STATE>\\\"      xs_add_string_literal('"');
<STRING_LITERAL_STATE>\\n       xs_add_string_literal('\n');
<STRING_LITERAL_STATE>\\t       xs_add_string_literal('\t');
<STRING_LITERAL_STATE>\\\\      xs_add_string_literal('\\');
<STRING_LITERAL_STATE>.         {
    xs_push_string_buffer(yytext[0]);
}
%%