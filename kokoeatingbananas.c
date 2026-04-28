#include <stdio.h>


long long canEat(int piles[], int n, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
       
        hours += (piles[i] + k - 1) / k;
    }

    return hours <= h;
}


int minEatingSpeed(int piles[], int n, int h) {
    int max = piles[0];
    
   
    for (int i = 1; i < n; i++) {
        if (piles[i] > max) {
            max = piles[i];
        }
    }

    int low = 1, high = max;
    int ans = max;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canEat(piles, n, h, mid)) {
            ans = mid;        
            high = mid - 1;   
        } else {
            low = mid + 1;    
        }
    }

    return ans;
}
