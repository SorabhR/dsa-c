int minFlips(int a, int b, int c){
    if((a | b) == c)
        return 0;
    
    int flips = 0;
    int current_c = 0;
    int current_b = 0;
    int current_a = 0;
    
    while(c > 0){
        current_c = c & 1;
        if(a != 0){
            current_a = a & 1;
            a = a >> 1;
        }else{
            current_a = 0;
        }
        if(b != 0){
            current_b = b & 1;
            b = b >> 1;
        }else{
            current_b = 0;
        }

        if(current_c == 0){
            if(current_a == 1)
                flips++;
            if(current_b == 1)
                flips++;
        }else{
            if(current_a == 0 && current_b == 0)
                flips++;
        }
        c = c >> 1;
    }

    while(a > 0){
        current_a = a & 1;
        if(current_a == 1)
            flips++;
        a = a >> 1;
    }
    while(b > 0){
        current_b = b & 1;
        if(current_b == 1)
            flips++;
        b = b >> 1;
    }

    return flips;
}