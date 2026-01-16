/*
Перевірка РБНФ №2 за допомогою коду
(помістити у файл "EBNF_N2.h")
*/


#define NONTERMINALS labeled_point, \
goto_label, \
program_name, \
value_type, \
array_specify, \
declaration_element, \
array_specify__optional, \
other_declaration_ident, \
declaration, \
other_declaration_ident__iteration, \
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
index_action__optional, \
expression, \
binary_action__iteration, \
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
assign_to_right__optional, \
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
false_cond_block_without_else__iteration, \
body_for_false__optional, \
statement,\
block_statements, \
input_rule, \
argument_for_input, \
output_rule, \
statement__iteration, \
expression__optional, \
program_rule, \
declaration__optional, \
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
sign__optional, \
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


/* Токени згідно з KEYWORDS_RE та TOKENS_RE */
tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
tokenBEGINBLOCK = "{" >> BOUNDARIES;
tokenENDBLOCK = "}" >> BOUNDARIES;
tokenSEMICOLON = ";" >> BOUNDARIES;
tokenCOLON = ":" >> BOUNDARIES;
tokenCOMMA = "," >> BOUNDARIES;

/* Ключові слова */
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

/* Оператори */
tokenEQUAL = "Eg" >> STRICT_BOUNDARIES;
tokenNOTEQUAL = "Ne" >> STRICT_BOUNDARIES;
tokenLESSOREQUAL = "Le" >> STRICT_BOUNDARIES;
tokenGREATEROREQUAL = "Ge" >> STRICT_BOUNDARIES;

tokenPLUS = "++" >> BOUNDARIES;
tokenMINUS = "Sub" >> STRICT_BOUNDARIES; /* Sub - це ключове слово, тому STRICT */
tokenMUL = "**" >> BOUNDARIES;
tokenDIV = "Div" >> STRICT_BOUNDARIES;
tokenMOD = "Mod" >> STRICT_BOUNDARIES;
tokenLRASSIGN = "->" >> BOUNDARIES;


/* Правила граматики (LL2 структура адаптована під EBNF) */

labeled_point = ident >> tokenCOLON;
goto_label = tokenGOTO >> ident;
program_name = SAME_RULE(ident);
value_type = SAME_RULE(tokenINT4);

array_specify = tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS;
declaration_element = ident >> array_specify__optional;
array_specify__optional = array_specify | "";
other_declaration_ident = tokenCOMMA >> declaration_element;

declaration = value_type >> declaration_element >> other_declaration_ident__iteration;
other_declaration_ident__iteration = other_declaration_ident >> other_declaration_ident__iteration | "";

index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;

unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;

binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESSOREQUAL | tokenGREATEROREQUAL | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;

left_expression = group_expression | unary_operation | cond_block | value | ident >> index_action__optional;
index_action__optional = index_action | "";

expression = left_expression >> binary_action__iteration;
binary_action__iteration = binary_action >> binary_action__iteration | "";

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

expression_or_cond_block__with_optional_assign = expression >> assign_to_right__optional;
assign_to_right = tokenLRASSIGN >> ident >> index_action__optional;
assign_to_right__optional = assign_to_right | "";

if_expression = SAME_RULE(expression);
body_for_true = SAME_RULE(block_statements);

/* Структура If ... Else If ... Else */
false_cond_block_without_else = tokenELSE >> tokenIF >> if_expression >> body_for_true;
body_for_false = tokenELSE >> block_statements;

cond_block = tokenIF >> if_expression >> body_for_true >> false_cond_block_without_else__iteration >> body_for_false__optional;
false_cond_block_without_else__iteration = false_cond_block_without_else >> false_cond_block_without_else__iteration | "";
body_for_false__optional = body_for_false | "";

input_rule = tokenSCAN >> argument_for_input;
argument_for_input = ident >> index_action__optional | tokenGROUPEXPRESSIONBEGIN >> ident >> index_action__optional >> tokenGROUPEXPRESSIONEND;

output_rule = tokenPRINT >> expression;

statement = labeled_point /* мітка */ | expression_or_cond_block__with_optional_assign | goto_label | input_rule | output_rule | tokenSEMICOLON;
statement__iteration = statement >> statement__iteration | "";

block_statements = tokenBEGINBLOCK >> statement__iteration >> tokenENDBLOCK;
expression__optional = expression | "";

/* Головне правило програми: Program Name ; Start Var Decl ; Statements Finish */
program_rule = BOUNDARIES >> tokenPROGRAM >> program_name >> tokenSEMICOLON >> tokenSTART >> tokenVAR >> declaration__optional >> tokenSEMICOLON >> statement__iteration >> tokenFINISH;
declaration__optional = declaration | "";

value = sign__optional >> unsigned_value >> BOUNDARIES;
sign__optional = sign | "";
sign = sign_plus | sign_minus;
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);

unsigned_value = (non_zero_digit >> digit__iteration | digit_0) >> BOUNDARIES;
digit__iteration = digit >> digit__iteration | "";

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

/* Ідентифікатор: _[A-Z][a-z] */
ident = tokenUNDERSCORE >> letter_in_upper_case >> letter_in_lower_case >> STRICT_BOUNDARIES;

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