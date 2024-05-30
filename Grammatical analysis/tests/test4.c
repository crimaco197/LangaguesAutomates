int test4 (int a) {
    return a + 2;
}
int main() {
    int a = f(2);
}

/*
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
*/