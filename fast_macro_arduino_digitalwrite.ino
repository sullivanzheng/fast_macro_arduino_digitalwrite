/*  fast_macro_digitalWrite is a MACRO that translates intuitive 
 *  but SLOW Arduino digitalWrite() to very fast AVR port
 *  manipulations.
 *  
 *  About 15~20x speedup is expected.
 *  
 * USAGE: 
 * #include "fast_macro_digitalWrite.h"
 * ....
 * //Replace digitalWrite(SOME_PIN,HIGH) with:
 * fast_digitalWrite(SOME_PIN,HIGH); 
 * 
 * This MACRO is very useful in accelerating many driver libraries which uses 
 * big-banged/software I2C/SPI protocol that used digitalWrite to generate clock and data
 * signals
 * 
 * REMINDER:
 * 
 * fast_digitalWrite doesn't support expressions as arguments.
 * The following statements are not valid:
 * 
 * for (int i=0;i<5;i++)
 *    fast_digitalWrite(i,HIGH); //i is an expression
 * 
 * for (int i=0;i<5;i++)
 *    fast_digitalWrite(2,(i%2==0)?HIGH:LOW); //(i%2==0)?HIGH:LOW is an expression
 * 
 */

#include "fast_macro_digitalWrite.h"
#define SQUARE_WAVE_GENERATION_PIN 2

void setup(void){}

void loop(void){
    while(1){
        fast_digitalWrite(SQUARE_WAVE_GENERATION_PIN,HIGH); 
        fast_digitalWrite(SQUARE_WAVE_GENERATION_PIN,LOW);
        fast_digitalToggle(SQUARE_WAVE_GENERATION_PIN); //Toggle the pin
        fast_digitalToggle(SQUARE_WAVE_GENERATION_PIN); //Toggle the pin
    }
}
