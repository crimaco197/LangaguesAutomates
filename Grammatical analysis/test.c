int compute(int a, int d) {
    int b, c = a + d * 5;
    b = a;
    while (c > 0) {
      b = b + a * 4;
    }
    returnO b;
}

int hola ()
{
    returnO 1; 
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