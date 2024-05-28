 void test1 (){
  int a = 8;
  if (a) { 
    a = 0;
    if (a) { 
      a = 9;
      } 
      a = 7;
}
}  
/*
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
*/