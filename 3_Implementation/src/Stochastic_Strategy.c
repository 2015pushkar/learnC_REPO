#include "header.h"
#include <unistd.h>


void Stochastic_Strategy(char * filePath)
{
    int SS_Choice; // for your choice
    int days=14;
  
    printf("/n Stochastic Strategy necessitates use of 2 different days for its calculations:");
    scanf("%d",&SS_Choice);// Asking the user whether to go with default values or will user input the values(eg: Enter '14' -> for 14 day moving average)
    while (SS_Choice!=1 && SS_Choice!=2) // checks is the user has inputted any values other than the given menu
    {
        printf("\nEnter a valid choice from the list given:");
        scanf("%d",&SS_Choice);
    }
    if(SS_Choice==2)
    {
        printf("\nEnter the number of days for middle band average and factor for bands calculation(positive whole number): "); 
        scanf("%d",&days);// you can input different values in here according to your strategy
    }
    
    FILE *file_ptr = fopen(filePath,"r"); // This is to open the .csv file path and assign it to pointer for the further processing by choosing specific Column.
    float *close = readColumn(file_ptr,7); // Accessing close column from .csv file
    float *HIGH = readColumn(file_ptr,3); // Accessing HIGH column from .csv file
    float *LOW = readColumn(file_ptr,4); // Accessing LOW column from .csv file

    //SS is prefix for the common variables to differentiate it is for bollinger band strategy.
    int SSTradeNo = 1;// This indicates the total number of trades that can happen. 
    float SSBuyp = 0; // This is the price at which the trade can be bought. 
    float SSSellp = 0; //This is the price at which the trade can be sold.
    float SSProfitLoss = 0; //This is the profit or loss for a single trade.
    float SSTotalpl = 0;//This the total profit or loss for all trades in a given time period
    float SSTotalProfit = 0;//This the total profit from the all trades in a given time period.
    float SSTotalLoss = 0;//This is the total loss from  the all trades in a given time period.
    float SSProfitFactor = 0;//This is the profit factor using bollinger bands strategy.
    float SSProfitableTrades = 0; //This is the total number of trades which gave profit in a given time period. 
    float SSProfitablePercent = 0;// This is the percent of trades which gave profit in a given time period.

    _Bool SSIntrade = false; //False means the Trade is in and allowed to buy the stock

    printf("Trade\tStatus\t\tDate\t\t\tPrice\t\tP/L\n\n");
    for (int i=(close[0]-days); i>0; i--)
    {
        float presentDayClosePrice=close[i];

        if (Stochastic_crossover(days,i, close, HIGH,LOW) && !SSIntrade ){
            char *date = readDate(filePath,i+1);
            SSBuyp=close[i];

            printf("%d\tBUY\t\t%s\t\t%d\n", SSTradeNo, date, SSBuyp);
            SSTradeNo++;
            SSIntrade = true;// True means the trade is open and allowed to sell the stock 
        }
        else if (!Stochastic_crossover(days,i, close,HIGH,LOW) && SSIntrade){
            char *date = readDate(filePath,i+1);
            SSSellp=close[i];

            SSProfitLoss= SSSellp-SSBuyp;
            SSTotalpl += SSProfitLoss;

            SSTotalProfit += ((SSProfitLoss>0)?SSProfitLoss:0);
            SSTotalLoss += abs((SSProfitLoss<0)?SSProfitLoss:0);
            SSProfitableTrades += ((SSProfitLoss>0)?1:0);
            
            printf("\tSELL\t\t%s\t\t%d\t\t%d\n\n", date, SSSellp, SSProfitLoss);
            
            SSIntrade = false;
        }
    }

    SSTotalLoss = (SSTotalLoss==0)?1:SSTotalLoss;
    SSProfitFactor = SSTotalProfit/SSTotalLoss;
    SSProfitablePercent = (SSProfitableTrades/(SSTradeNo-2))*100;
    printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f %% ||\t|| Total P/L: %d ||\t|| Profit Factor: %0.3f ||\n\n", (SSTradeNo-2), SSProfitablePercent,SSTotalpl, SSProfitFactor);

    free(filePath);
    return;

}
