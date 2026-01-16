/*
Перевірка РБНФ №1 за допомогою коду
(помістити у файл "EBNF_N1.h")
*/


#define NONTERMINALS labeled_point, \
goto_label, \
program_name, \
value_type, \
array_specify, \
declaration_element, \
\
other_declaration_ident, \
declaration, \
\
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
\
expression, \
\
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
\
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
\
\
statement,\
block_statements, \
input_rule, \
argument_for_input, \
output_rule, \
\
\
program_rule, \
\
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
\
sign, \
ident, \
letter_in_upper_case, \
letter_in_lower_case, \
sign_plus, \
sign_minus
#define TOKENS \
tokenCOLON, \
tokenGOTO, \
tokenINT4, \
tokenCOMMA, \
tokenNOT, \
tokenAND, \
tokenOR, \
tokenEQUAL, \
tokenNOTEQUAL, \
tokenLESSOREQUAL, \
tokenGREATEROREQUAL, \
tokenPLUS, \
tokenMINUS, \
tokenMUL, \
tokenDIV, \
tokenMOD, \
tokenGROUPEXPRESSIONBEGIN, \
tokenGROUPEXPRESSIONEND, \
tokenLRASSIGN, \
tokenELSE, \
tokenIF, \
tokenSCAN, \
tokenPRINT, \
tokenPROGRAM, \
tokenVAR, \
tokenSTART, \
tokenFINISH, \
tokenBEGINBLOCK, \
tokenENDBLOCK, \
tokenLEFTSQUAREBRACKETS, \
tokenRIGHTSQUAREBRACKETS, \
tokenSEMICOLON, \
digit_0, \
digit_1, \
digit_2, \
digit_3, \
digit_4, \
digit_5, \
digit_6, \
digit_7, \
digit_8, \
digit_9, \
tokenUNDERSCORE, \
A, \
B, \
C, \
D, \
E, \
F, \
G, \
H, \
I, \
J, \
K, \
L, \
M, \
N, \
O, \
P, \
Q, \
R, \
S, \
T, \
U, \
V, \
W, \
X, \
Y, \
Z, \
a, \
b, \
c, \
d, \
e, \
f, \
g, \
h, \
i, \
j, \
k, \
l, \
m, \
n, \
o, \
p, \
q, \
r, \
s, \
t, \
u, \
v, \
w, \
x, \
y, \
z
#define COMMENT_BEGIN_STR "%*"
#define COMMENT_END_STR   "*%"




tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
tokenBEGINBLOCK = "{" >> BOUNDARIES;
tokenENDBLOCK = "}" >> BOUNDARIES;
tokenSEMICOLON = ";" >> BOUNDARIES;
tokenCOLON = ":" >> BOUNDARIES;
tokenCOMMA = "," >> BOUNDARIES;

/* Keywords from Prototype */
tokenGOTO = "Goto" >> STRICT_BOUNDARIES;
tokenINT4 = "Int_4" >> STRICT_BOUNDARIES;
tokenNOT = "Not" >> STRICT_BOUNDARIES;
tokenAND = "And" >> STRICT_BOUNDARIES;
tokenOR = "Or" >> STRICT_BOUNDARIES;
tokenELSE = "Else" >> STRICT_BOUNDARIES;
tokenIF = "If" >> STRICT_BOUNDARIES;
tokenSCAN = "Scan" >> STRICT_BOUNDARIES;
tokenPRINT = "Print" >> STRICT_BOUNDARIES;
tokenPROGRAM = "Program" >> STRICT_BOUNDARIES;
tokenVAR = "Var" >> STRICT_BOUNDARIES;
tokenSTART = "Start" >> STRICT_BOUNDARIES;
tokenFINISH = "Finish" >> STRICT_BOUNDARIES;

/* Operators from Prototype */
tokenEQUAL = "Eg" >> STRICT_BOUNDARIES;
tokenNOTEQUAL = "Ne" >> STRICT_BOUNDARIES;
tokenLESSOREQUAL = "Le" >> STRICT_BOUNDARIES;
tokenGREATEROREQUAL = "Ge" >> STRICT_BOUNDARIES;
tokenPLUS = "++" >> BOUNDARIES;
tokenMINUS = "Sub" >> STRICT_BOUNDARIES;
tokenMUL = "**" >> BOUNDARIES;
tokenDIV = "Div" >> STRICT_BOUNDARIES;
tokenMOD = "Mod" >> STRICT_BOUNDARIES;
tokenLRASSIGN = "->" >> BOUNDARIES;


labeled_point = ident >> tokenCOLON;
goto_label = tokenGOTO >> ident;
program_name = SAME_RULE(ident);
value_type = SAME_RULE(tokenINT4);

/* Array Declaration: [ Size ] */
declaration_element = ident >> -(tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS);

other_declaration_ident = tokenCOMMA >> declaration_element;
declaration = value_type >> declaration_element >> *other_declaration_ident;

index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;
unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;

binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESSOREQUAL | tokenGREATEROREQUAL | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;

left_expression = group_expression | unary_operation | cond_block | value | ident >> -index_action;

expression = left_expression >> *binary_action;

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

expression_or_cond_block__with_optional_assign = expression >> -(tokenLRASSIGN >> ident >> -index_action);


if_expression = SAME_RULE(expression);
body_for_true = SAME_RULE(block_statements);

/* If structure: If ... { ... } Else If ... { ... } Else { ... } */
false_cond_block_without_else = tokenELSE >> tokenIF >> if_expression >> body_for_true;
body_for_false = tokenELSE >> block_statements;
cond_block = tokenIF >> if_expression >> body_for_true >> *false_cond_block_without_else >> -body_for_false;


input_rule = tokenSCAN >> (ident >> -index_action | tokenGROUPEXPRESSIONBEGIN >> ident >> -index_action >> tokenGROUPEXPRESSIONEND);

output_rule = tokenPRINT >> expression;

statement = labeled_point /* labeled_point first*/ | expression_or_cond_block__with_optional_assign | goto_label | input_rule | output_rule | tokenSEMICOLON;

block_statements = tokenBEGINBLOCK >> *statement >> tokenENDBLOCK;

/* Program structure: Program Name ; Start Var Decl ; Statements Finish */
program_rule = BOUNDARIES >> tokenPROGRAM >> program_name >> tokenSEMICOLON >> tokenSTART >> tokenVAR >> (-declaration) >> tokenSEMICOLON >> *statement >> tokenFINISH;

value = -sign >> unsigned_value >> BOUNDARIES;

sign = sign_plus | sign_minus;
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);
unsigned_value = (non_zero_digit >> *digit | digit_0) >> BOUNDARIES;

digit_0 = '0';
digit = digit_0 | non_zero_digit;
digit_1 = '1';
digit_2 = '2';
digit_3 = '3';
digit_4 = '4';
digit_5 = '5';
digit_6 = '6';
digit_7 = '7';
digit_8 = '8';
digit_9 = '9';
non_zero_digit = digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
tokenUNDERSCORE = "_";

/* Identifier: _[A-Z][a-z] excluding keywords */
ident =
!(
	tokenCOLON |
	tokenGOTO |
	tokenINT4 |
	tokenCOMMA |
	tokenNOT |
	tokenAND |
	tokenOR |
	tokenEQUAL |
	tokenNOTEQUAL |
	tokenLESSOREQUAL |
	tokenGREATEROREQUAL |
	tokenPLUS |
	tokenMINUS |
	tokenMUL |
	tokenDIV |
	tokenMOD |
	tokenGROUPEXPRESSIONBEGIN |
	tokenGROUPEXPRESSIONEND |
	tokenLRASSIGN |
	tokenELSE |
	tokenIF |
	tokenSCAN |
	tokenPRINT |
	tokenPROGRAM |
	tokenVAR |
	tokenSTART |
	tokenFINISH |
	tokenBEGINBLOCK |
	tokenENDBLOCK |
	tokenLEFTSQUAREBRACKETS |
	tokenRIGHTSQUAREBRACKETS |
	tokenSEMICOLON
	) >>
	tokenUNDERSCORE >> letter_in_upper_case >> letter_in_lower_case >> STRICT_BOUNDARIES;
A = "A";
B = "B";
C = "C";
D = "D";
E = "E";
F = "F";
G = "G";
H = "H";
I = "I";
J = "J";
K = "K";
L = "L";
M = "M";
N = "N";
O = "O";
P = "P";
Q = "Q";
R = "R";
S = "S";
T = "T";
U = "U";
V = "V";
W = "W";
X = "X";
Y = "Y";
Z = "Z";
letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;
a = "a";
b = "b";
c = "c";
d = "d";
e = "e";
f = "f";
g = "g";
h = "h";
i = "i";
j = "j";
k = "k";
l = "l";
m = "m";
n = "n";
o = "o";
p = "p";
q = "q";
r = "r";
s = "s";
t = "t";
u = "u";
v = "v";
w = "w";
x = "x";
y = "y";
z = "z";
letter_in_upper_case = A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z;
STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
BOUNDARY = BOUNDARY__SPACE | BOUNDARY__TAB | BOUNDARY__VERTICAL_TAB | BOUNDARY__FORM_FEED | BOUNDARY__CARRIAGE_RETURN | BOUNDARY__LINE_FEED | BOUNDARY__NULL;
BOUNDARY__SPACE = " ";
BOUNDARY__TAB = "\t";
BOUNDARY__VERTICAL_TAB = "\v";
BOUNDARY__FORM_FEED = "\f";
BOUNDARY__CARRIAGE_RETURN = "\r";
BOUNDARY__LINE_FEED = "\n";
BOUNDARY__NULL = "\0";
NO_BOUNDARY = "";
#define WHITESPACES \
STRICT_BOUNDARIES, \
BOUNDARIES, \
BOUNDARY, \
BOUNDARY__SPACE, \
BOUNDARY__TAB, \
BOUNDARY__VERTICAL_TAB, \
BOUNDARY__FORM_FEED, \
BOUNDARY__CARRIAGE_RETURN, \
BOUNDARY__LINE_FEED, \
BOUNDARY__NULL, \
NO_BOUNDARY