# XIOT Project
This repo contain project required for xiot filtration phase

This project works with interrupts like external, timer, serial and ADC interrupts for all to work in parallel without waiting for one another


## kit used and Implementation:

This project is done over atmega32 (Amit AVR kit)

Nearly all of the functions are implemented just the string functions are included from pre implemented header files


## Drivers used:
In this project there are many drivers needed in order to perform the functions :

### 1- GPIO (general purpose input output):

This driver is needed to perform the function of turning the LED on and off when the button is pressed and when it is released.

### 2- ADC (analogue to digital converter)

This driver is needed to perform the task of taking the results from the temperature sensor and change it to a digital representation

### 3- UART (universal asynchronous receiver transmitter):

This driver is needed to perform the function of serial communication between the micro controller and the screen monitor on the PC.

In this driver I have written just the functions that I will need to use.

### 4- Timer:

This driver is needed to perform the task of making an event every certain amount of time without waiting (pulling) just when the timer reach a certain adjusted value it will overflow and the ISA will do the event required. 

In this driver I have written just the functions that I will need to use.


### I have written the drivers myself and defined the registers needed than including the predefined header file containing them which save a lot of memory.


## Assumptions:

The initial state of the led is On, whenever the push button is pressed or released the state of the led changes


## Program flow:

The flow of this program is as follows:

It is all based on the concept of interrupts that whenever something is done it will notify the MCU and the MCU will respond.

Initially the LED is on so the initial message send to the serial monitor is a message indicating this on status of the LED. whenever the button is pressed the LED goes off and a new message is sent to the serial screen telling the new status. 

Alongside this the timer is working and every 3 seconds it start the conversion to read the new temp from the sensor an also send to the serial screen which is always listening for anything to display and this listening is also based on interrupts and not pulling in order not to waste the processor power or effect the performance of other things waiting for this event to occur

This is all shown in the code and I hope this gives a pref description of the work done and be helpful in understanding the code.