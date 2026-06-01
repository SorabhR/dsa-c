int tribonacci(int n) {
    int Tri[n+1];
    if(n == 0)
        return 0;
    else if(n==1 || n==2){
        return 1;
    }
    Tri[0] = 0;
    Tri[1] = 1;
    Tri[2] = 1;

    for(int i=3;i<=n;i++){
        Tri[i] = Tri[i-1] + Tri[i-2] + Tri[i-3];
    }
    return Tri[n];
}