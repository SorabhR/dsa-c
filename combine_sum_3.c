/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int soln_count = 0;

int find_combo(int k, int n,int** ret,int curr_ele,int* curr_soln,int idx,int curr_sum){
    if(idx == k){
        //printf("Reached here %d\r\n",curr_sum);
        if(curr_sum == n){
            for(int i = 0;i<k;i++){
                ret[soln_count][i] = curr_soln[i]; 
            }
            soln_count++;
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int i=curr_ele+1;i<=9;i++){
        if((curr_sum + i) > n)
            return 0;
        curr_soln[idx] = i;
        //printf("%d %d\r\n",idx,i);
        if(find_combo(k,n,ret,i,curr_soln,idx+1,curr_sum+i) == 1 && (idx==k-1))
            return 1;
    }
    return 0;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    if((n < (k*(k+1)/2)) || (n > 9*k)){
        *returnSize = 0;
        *returnColumnSizes = malloc(sizeof(int) * 1);
        returnColumnSizes[0] = 0;
        return NULL;
    }

    int max_combos = 500;
    
    int** ret = (int**)malloc(max_combos*sizeof(int*));
    for(int i = 0;i<max_combos;i++)
        ret[i] = malloc(k*sizeof(int));
    soln_count = 0;
    int curr_soln[k];
    memset(curr_soln,0,k);

    for(int i = 1;i<=9-k+1;i++){
        curr_soln[0] = i;
        find_combo(k,n,ret,i,curr_soln,1,i);
    }
    printf("%d\r\n",soln_count);
    *returnSize = soln_count;
    *returnColumnSizes = malloc(sizeof(int) * soln_count);
    for(int i = 0;i<soln_count;i++){
        (*returnColumnSizes)[i] = k;
    }
    return ret;
}
