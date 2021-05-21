 ## fast_digitalWrite() is a 15x-20x faster drop-in replacement of Arduino digitalWrite() ##
 fast_digitalWrite() is a MACRO that translates intuitive 
 but SLOW Arduino digitalWrite() to very fast AVR port
 manipulations.
 
 About 15~20x speedup is expected.
 
### USAGE ###
```c++
#include "fast_macro_digitalWrite.h"
#define SOME_PIN 2
//Replace digitalWrite(SOME_PIN,HIGH) with:
fast_digitalWrite(SOME_PIN,HIGH); 
```
You can use this macro to accelerate bit-banged protocol that uses slow digitalWrite() to generate clock and data signals

### REMINDER ###
For maximum speed, fast_digitalWrite doesn't support expressions as arguments.

The following examples are **not valid**
```c++
for (int i=0;i<5;i++)
   fast_digitalWrite(i,HIGH);              //i is an expression

for (int i=0;i<5;i++)
   fast_digitalWrite(2,(i%2==0)?HIGH:LOW); //(i%2==0)?HIGH:LOW is an expression
   
void set_pin(char pin_num){
   fast_digitalWrite(pin_num, HIGH);       //pin_num is an expression
}
```
The following examples are **valid**

```c++
#define MOSI 4
#define SCK  5
#define CS   6
char data = 0xa3;
void transmit_data(char data){ //SPI(0,0) MSB
    fast_digitalWrite(SCK, LOW);
    fast_digitalWrite(CS, LOW);
    for (char i=0;i<8;i++){
        if (data & 0b10000000 == 0b10000000) 
            fast_digitalWrite(MOSI, HIGH);
        else
            fast_digitalWrite(MOSI, LOW);
        fast_digitalWrite(CS, HIGH);
        data <<=1;
        fast_digitalWrite(CS, LOW);
    }
    fast_digitalWrite(CS, HIGH);
}
```
