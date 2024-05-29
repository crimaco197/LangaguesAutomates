int fact(int a) {
    if (a) { 
        return fact(a - 1) * a;
        }
    return 1;
}
int main() { 
return fact(3); 
}
