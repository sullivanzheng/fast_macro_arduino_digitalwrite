#ifndef __FAST_DIGITAL_WRITE__
#define __FAST_DIGITAL_WRITE__
#define MACRO_ARDUINO_PIN_0   D,0 
#define MACRO_ARDUINO_PIN_1   D,1 
#define MACRO_ARDUINO_PIN_2   D,2 
#define MACRO_ARDUINO_PIN_3   D,3 
#define MACRO_ARDUINO_PIN_4   D,4 
#define MACRO_ARDUINO_PIN_5   D,5 
#define MACRO_ARDUINO_PIN_6   D,6 
#define MACRO_ARDUINO_PIN_7   D,7 
#define MACRO_ARDUINO_PIN_8   B,0 
#define MACRO_ARDUINO_PIN_9   B,1 
#define MACRO_ARDUINO_PIN_10  B,2 
#define MACRO_ARDUINO_PIN_11  B,3 
#define MACRO_ARDUINO_PIN_12  B,4 
#define MACRO_ARDUINO_PIN_13  B,5 
#define MACRO_ARDUINO_PIN_14  C,0  // A0
#define MACRO_ARDUINO_PIN_15  C,1  // A1
#define MACRO_ARDUINO_PIN_16  C,2  // A2
#define MACRO_ARDUINO_PIN_17  C,3  // A3
#define MACRO_ARDUINO_PIN_18  C,4  // A4
#define MACRO_ARDUINO_PIN_19  C,5  // A5
#define MACRO_ARDUINO_PIN_20  B,6  // XTAL1
#define MACRO_ARDUINO_PIN_21  B,7  // XTAL2
#define MACRO_ARDUINO_PIN_22  C,6  // RESET

#define concat(x, y) concat_i(x, y) //lower the precedence of ## concatenation operator
#define concat_i(x, y) x##y

#define fast_digitalWrite(pin,hl) concat(PORT_CHANGE_,hl)(concat(MACRO_ARDUINO_PIN_,pin))

#define PORT_CHANGE_HIGH(param) PORT_CHANGE_HIGH_2para(param)
#define PORT_CHANGE_1(param) PORT_CHANGE_HIGH_2para(param)
#define PORT_CHANGE_0x1(param) PORT_CHANGE_HIGH_2para(param)
#define PORT_CHANGE_HIGH_2para(port,shift) PORT##port|= (1<<(shift))

#define PORT_CHANGE_LOW(param) PORT_CHANGE_LOW_2para(param)
#define PORT_CHANGE_0(param) PORT_CHANGE_LOW_2para(param)
#define PORT_CHANGE_0x0(param) PORT_CHANGE_LOW_2para(param)
#define PORT_CHANGE_LOW_2para(port,shift)  PORT##port&= ~(1<<(shift))

#define fast_digitalToggle(pin) PORT_TOGGLE(concat(MACRO_ARDUINO_PIN_,pin))
#define PORT_TOGGLE(param) PORT_TOGGLE_2para(param)
#define PORT_TOGGLE_2para(port,shift) PIN##port|= (1<<(shift))

#endif