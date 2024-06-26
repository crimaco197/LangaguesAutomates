void test(){
int a; 
int b , c;
b = 6;
c = 8;
a = b + c * 2;
}

TEST - 0
-------------------
Name: a, Type: int, Adress: 0
Name: b, Type: int, Adress: 1
Name: c, Type: int, Adress: 2
-------------------
Instruction Table:
-------------------
Name: AFC, Number Register: 3, Adress Memory: 6, Val: 0
Name: COP, Number Register: 1, Adress Memory: 3, Val: 0
Name: AFC, Number Register: 3, Adress Memory: 8, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0
Name: COP, Number Register: 3, Adress Memory: 1, Val: 0
Name: COP, Number Register: 4, Adress Memory: 2, Val: 0
Name: AFC, Number Register: 5, Adress Memory: 2, Val: 0
Name: MUL, Number Register: 4, Adress Memory: 4, Val: 5
Name: ADD, Number Register: 3, Adress Memory: 3, Val: 4
Name: COP, Number Register: 0, Adress Memory: 3, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 11  OK
-------------------

void test1 (){
  int a = 8;
   if (a) { a = 6; }
} 

TEST - 1
-------------------
Symbol Table:
-------------------
Name: a, Type: int, Adress: 0
-------------------
Instruction Table:
-------------------
Name: AFC, Number Register: 1, Adress Memory: 8, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 0, Val: 0
Name: JMF, Number Register: 1, Adress Memory: 6, Val: 0
Name: AFC, Number Register: 1, Adress Memory: 6, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 7  OK
-------------------

 void test2 (){
  int a = 8;
  if (a) { 
    a = 0;
    if (a) { 
      a = 9;
      } 
      a = 7;
}
}  

TEST - 2
-------------------
Name: a, Type: int, Adress: 0
-------------------
Instruction Table:
-------------------
Name: AFC, Number Register: 1, Adress Memory: 8, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 0, Val: 0
Name: JMF, Number Register: 1, Adress Memory: 12, Val: 0
Name: AFC, Number Register: 1, Adress Memory: 0, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 0, Val: 0
Name: JMF, Number Register: 1, Adress Memory: 10, Val: 0
Name: AFC, Number Register: 1, Adress Memory: 9, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: AFC, Number Register: 1, Adress Memory: 7, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 13  OK
-------------------


void test3(){
int a = 7;
if (a) { 
  int b =8;
 if(b){ 
  int c = 9; 
 }
}
}

TEST - 3
-------------------
Name: a, Type: int, Adress: 0
-------------------
Instruction Table:
-------------------
Name: AFC, Number Register: 1, Adress Memory: 7, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 0, Val: 0
Name: JMF, Number Register: 2, Adress Memory: 10, Val: 0
Name: AFC, Number Register: 2, Adress Memory: 8, Val: 0
Name: COP, Number Register: 1, Adress Memory: 2, Val: 0
Name: COP, Number Register: 2, Adress Memory: 1, Val: 0
Name: JMF, Number Register: 2, Adress Memory: 10, Val: 0
Name: AFC, Number Register: 3, Adress Memory: 9, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0 
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 11
-------------------


int f (int a) {
    return a + 222;
}
int main() {
    int a = f(333);
}

TEST - 4
-------------------
Symbol Table:
-------------------
-------------------
Instruction Table:
-------------------
Name: JMP, Number Register: 7, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 2, Val: 0
Name: AFC, Number Register: 4, Adress Memory: 2, Val: 0
Name: ADD, Number Register: 3, Adress Memory: 3, Val: 4
Name: COP, Number Register: 1, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: AFC, Number Register: 5, Adress Memory: 2, Val: 0 **
Name: PUSH, Number Register: 3, Adress Memory: 0, Val: 0
Name: CALL, Number Register: 1, Adress Memory: 0, Val: 0
Name: POP, Number Register: 3, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 4, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 15 OK -
-------------------




int fact(int a) {
    if (a) { 
        return fact(a - 111) * a;
        }
    return 222;
}
int main() { 
    return fact(333); 
}


TEST - 5
-------------------
Symbol Table:
-------------------
-------------------
Instruction Table:
-------------------
Name: JMP, Number Register: 18, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 2, Val: 0
Name: JMF, Number Register: 3, Adress Memory: 14, Val: 0
Name: COP, Number Register: 5, Adress Memory: 2, Val: 0
Name: AFC, Number Register: 6, Adress Memory: 1, Val: 0
Name: SUB, Number Register: 5, Adress Memory: 5, Val: 6
Name: PUSH, Number Register: 3, Adress Memory: 0, Val: 0
Name: CALL, Number Register: 1, Adress Memory: 0, Val: 0
Name: POP, Number Register: 3, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 4, Val: 0
Name: COP, Number Register: 4, Adress Memory: 2, Val: 0
Name: MUL, Number Register: 3, Adress Memory: 3, Val: 4
Name: COP, Number Register: 1, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: AFC, Number Register: 3, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: AFC, Number Register: 4, Adress Memory: 3, Val: 0
Name: PUSH, Number Register: 2, Adress Memory: 0, Val: 0
Name: CALL, Number Register: 1, Adress Memory: 0, Val: 0
Name: POP, Number Register: 2, Adress Memory: 0, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0
Name: COP, Number Register: 1, Adress Memory: 2, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 27  OK !
-------------------


|--------------------------------------------------------|
|                 ASSEMBLY INSTRUCTION TABLE             |
|--------------------------------------------------------|
|   Instruction   |   Operand 1  |  Operand 2  |  Other  |
|--------------------------------------------------------|
|              JMP|            19|            0|        0|
|              COP|             3|            2|        0|
|              JMF|             3|           14|        0|
|              COP|             5|            2|        0|
|              AFC|             6|            1|        0|
|              SUB|             5|            5|        6|
|             PUSH|             3|            0|        0|
|             CALL|             1|            0|        0|
|              POP|             3|            0|        0|
|              COP|             3|            4|        0|
|              COP|             4|            2|        0|
|              MUL|             3|            3|        4|
|              COP|             1|            3|        0|
|              RET|             0|            0|        0|
|              AFC|             3|            1|        0|
|              COP|             1|            3|        0|
|              RET|             0|            0|        0|
|              RET|             0|            0|        0|
|              AFC|             4|            3|        0|
|             PUSH|             2|            0|        0|
|             CALL|             1|            0|        0|
|              POP|             2|            0|        0|
|              COP|             2|            3|        0|
|              COP|             1|            2|        0|
|              RET|             0|            0|        0|
|              RET|             0|            0|        0|
|              NOP|             0|            0|        0|
|--------------------------------------------------------|


int main() { 
    int a = 0;
    while (a)
    {
        return fact(3); 
    }
}

TEST 6
-------------------
Symbol Table:
-------------------
-------------------
Instruction Table:
-------------------
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: AFC, Number Register: 3, Adress Memory: 0, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0
Name: COP, Number Register: 3, Adress Memory: 2, Val: 0
Name: JMF, Number Register: 3, Adress Memory: -999, Val: 0
Name: AFC, Number Register: 5, Adress Memory: 3, Val: 0
Name: PUSH, Number Register: 3, Adress Memory: 0, Val: 0
Name: CALL, Number Register: 0, Adress Memory: 0, Val: 0
Name: POP, Number Register: 3, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 3, Val: 0
Name: COP, Number Register: 1, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
SIZE : 14
-------------------



solo un test : ./analizador < test1.c 
Todos los test : make tests
Make clean
clear
ver shift/reduce : bison -t -v -d analizador.y    
yacc -d -v analizador.y