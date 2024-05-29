int fact(int a) {
    if (a) { 
        return fact(a - 1) * a;
        }
    return 1;
}
int main() { 
return fact(3); 
}


/*
TEST - 5
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
SIZE : 27
-------------------
*/