#include <unity.h>
#include <unity_internals.h>
#include "header.h"
#include "Stochastic_header.h"

#define PROJECT_NAME "TradingStrategy"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void testSma(void);
void testBollingerBands(void);
void testStochastic(void);

//array to test sma and crossover functions
float *close; float *HIGH; float *LOW;
//array to test sma and crossover functions
const char *filePath = "LTTS.csv";
int main(){

    //array to test sma and crossover functions
    const char *filePath = "LTTS.csv";
    FILE *file = fopen(filePath,"r");
    close = readColumn(file,7);
    HIGH = readColumn(file,3); // Accessing HIGH column from .csv file
    LOW = readColumn(file,4); // Accessing LOW column from .csv file
    UNITY_BEGIN();

    RUN_TEST(testSma);
    RUN_TEST(testBollingerBands);
    RUN_TEST(testStochastic);

    return UNITY_END();
}

void testSma(void)
{
    TEST_ASSERT_EQUAL_FLOAT(2848.829,sma(12,10,close));
}
void testBollingerBands(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1774.471,upperBand(2,20,361,close));
    TEST_ASSERT_EQUAL_FLOAT(1469.00298,lowerBand(2,20,361,close));
    TEST_ASSERT_FLOAT_WITHIN(2.000,1774.471,upperBand(2,20,361,close));
    TEST_ASSERT_FLOAT_WITHIN(2.000,1469.00298,lowerBand(2,20,361,close));
    TEST_ASSERT_EQUAL(-3,upperBand(2,20,365,close));
    TEST_ASSERT_EQUAL(1,lowerBand(2,20,365,close));
    TEST_ASSERT_EQUAL(-1,movingMiddleBand(20,365,close));
    TEST_ASSERT_EQUAL(-1,stdDev(20,365,close));
}
void testStochastic(void)
{
    TEST_ASSERT_EQUAL(2147483648,funforK(14,370,close,HIGH,LOW));
    
}