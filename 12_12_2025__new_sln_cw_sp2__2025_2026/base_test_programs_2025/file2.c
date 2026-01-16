#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //";"

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //";"

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"Scan"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //";"

    //"If"

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Ge"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Ge"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF66147A828;

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF66147A828:

    //"Else" (part of "ElseIf")
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF66147BCF0;

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Ge"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Ge"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] >= opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //after cond expresion (after "ElseIf")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF66147E258;

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //"}" (after "then"-part of ElseIf-operator)
    opTemp = 1;
LABEL__AFTER_ELSE_00007FF66147BCF0:
LABEL__AFTER_THEN_00007FF66147E258:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF66147F720;

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF66147F720:

    //"If"

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"And"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] && opStack[opStackIndex]; --opStackIndex;

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF6614841F0;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF6614841F0:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF6614856B8;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF6614856B8:

    //"If"

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Le"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Le"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"Or"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Le"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"Or"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] || opStack[opStackIndex]; --opStackIndex;

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF66148A188;

    //"-1"
    opStack[++opStackIndex] = opTemp = 0xFFFFFFFF;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF66148A188:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF66148B650;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF66148B650:

    //"If"

    //"_Aa"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"_Bb"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"_Cc"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"++"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"Le"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] <= opStack[opStackIndex]; --opStackIndex;

    //"Not"
    opTemp = opStack[opStackIndex] = !opStack[opStackIndex];

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_00007FF66148EC58;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_00007FF66148EC58:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_00007FF661490120;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Print"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //";"

    //";" (after "Else")
LABEL__AFTER_ELSE_00007FF661490120:

    return 0;
}