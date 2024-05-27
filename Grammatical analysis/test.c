/* void main(void) {
  int a;
  int a;
  a = 123 + 321 * 4 / 2 - 1;
  if (a == 1) {
    print(a);
  } else {
    print(a / 1);
  }
} */
void test(){
int a; 
int b , c;
b = 6;
c = 8;
a = b + c * 2;
}

/*
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

*/
/*
int compute(int a, int d) {
    int b, c = a + d * 5;
    b = a;
    while (c > 0) {
      b = b + a * 4;
    }
    return b;
}
*/
/*
int hola ()
{
    return 1; 
}

void main(void) {
  int a;
  if (a == 3) {
    int b = compute(a, 2 * a);
    print(a);
  } else { 
    compute(a, 2 * a);
    print(a);
  }
}

int main (int argc,int argv)
{
   print(argc);
   return 0;
}

*/