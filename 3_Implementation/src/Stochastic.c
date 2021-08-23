#include <header.h>

float K,D;

float Stochastic(int days, int crtday, float *close,float *HIGH, float *LOW)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
    float sum1 = 0,sum2 = 0,sum3 = 0; // sum of all days price
    if(crtday<=(close[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum1 += close[i];
            sum2 += HIGH[i];
            sum3 += LOW[i];
        }
    }
    else{
        return -1;
    }
    K = (sum1-sum3)/(sum2-sum3);
    D = 3-K;

    return K;
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
