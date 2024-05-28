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

void test1 (){
  int a = 0;
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
Name: AFC, Number Register: 1, Adress Memory: 0, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: COP, Number Register: 1, Adress Memory: 0, Val: 0
Name: JMF, Number Register: 1, Adress Memory: 6, Val: 0
Name: AFC, Number Register: 1, Adress Memory: 6, Val: 0
Name: COP, Number Register: 0, Adress Memory: 1, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
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
-------------------


int f (int a) {
    return a + 2;
}
int main() {
    int a = f(2);
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
Name: AFC, Number Register: 5, Adress Memory: 2, Val: 0
Name: PUSH, Number Register: 3, Adress Memory: 0, Val: 0
Name: CALL, Number Register: 1, Adress Memory: 0, Val: 0
Name: POP, Number Register: 3, Adress Memory: 0, Val: 0
Name: COP, Number Register: 3, Adress Memory: 4, Val: 0
Name: COP, Number Register: 2, Adress Memory: 3, Val: 0
Name: RET, Number Register: 0, Adress Memory: 0, Val: 0
Name: NOP, Number Register: 0, Adress Memory: 0, Val: 0
-------------------




int fact(int a) {
    if (a) { 
        return fact(a - 1) * a;
        }
    return1;
}
int main() { 
    return fact(3); 
}


TEST - 5
-------------------