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
/*
|----------------------------------------------|
|                  SYMBOL TABLE                |
|----------------------------------------------|
|   Name   |   Adresse  |  Function  |  Valor  |
|----------------------------------------------|
|         a|           0|         int|        0|
|----------------------------------------------|
|--------------------------------------------------------|
|                 ASSEMBLY INSTRUCTION TABLE             |
|--------------------------------------------------------|
|   Instruction   |   Operand 1  |  Operand 2  |  Other  |
|--------------------------------------------------------|
|              AFC|             1|            8|        0|
|              COP|             0|            1|        0|
|              COP|             1|            0|        0|
|              JMF|             1|           12|        0|
|              AFC|             1|            0|        0|
|              COP|             0|            1|        0|
|              COP|             1|            0|        0|
|              JMF|             2|           10|        0|
|              AFC|             1|            9|        0|
|              COP|             0|            1|        0|
|              AFC|             1|            7|        0|
|              COP|             0|            1|        0|
|              NOP|             0|            0|        0|
|--------------------------------------------------------|
| SIZE :                                               13|
|--------------------------------------------------------|
*/