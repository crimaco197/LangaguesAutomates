
void test3(){
int a = 7;
if (a) { 
  int b =8;
 if(b){ 
  int c = 9; 
 }
}
}



/*
Symbol Table:
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
*/