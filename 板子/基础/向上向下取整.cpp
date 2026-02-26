
int Ceil(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and !((n1 < 0)^(n2 < 0))) x++;
    return x;
}

int Floor(int n1,int n2) {
    if (n2 == 0) return 0;
    int x=n1/n2;
    int r=n1%n2;
    if (r != 0 and ((n1 < 0)^(n2 < 0))) x--;
    return x;
}
