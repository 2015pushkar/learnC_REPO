#include <header.h>


_Bool Stochastic_crossover( int K, int D, int crtday, float *coloumnArray){
    if ((Stochastic(K,(crtday), coloumnArray) > 80 && Stochastic(D,(crtday), coloumnArray) > 80 && Stochastic(K,(crtday), coloumnArray) > Stochastic(D,(crtday), coloumnArray))){        
        return true;// Indicates SELL
    }
    else if ((Stochastic(K,(crtday), coloumnArray) < 20 && Stochastic(D,(crtday), coloumnArray) < 20 && Stochastic(K,(crtday), coloumnArray) < Stochastic(D,(crtday), coloumnArray))){
        return false; // Indicates BUY
    }
}

