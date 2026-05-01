/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
 int guess(int num);

int guessNumber(int n){
	int l = 1;
    int h = n;
    int mid = 0;
    int ret = 0;

    while(l <= h){
        mid = l + (h-l)/2;
        ret = guess(mid);
        if(ret == 0){
            return mid;
        }else if(ret == 1){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return 0;
}