Time --> O(sqrt(N))
Space --> O(1)

int reachNumber(int target) {
    int step=1;
    int tar=abs(target);
    int val=0;
    while(val<tar){
        val+=step;
        step++;
    }
    step--;

    if((val-tar)%2==0) return step;

    if((val-tar+step)%2!=0) return step+1;
            
    return step+2;
}