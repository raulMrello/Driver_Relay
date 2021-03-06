/*
 * Relay.cpp
 *
 *  Created on: 20/04/2015
 *      Author: raulMrello
 */

#include "Relay.h"



//------------------------------------------------------------------------------------
//--- PRIVATE TYPES ------------------------------------------------------------------
//------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------
//-- PUBLIC METHODS IMPLEMENTATION ---------------------------------------------------
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
Relay::Relay(uint32_t id, PinName gpio_out, RelayLogicLevel level){
    // Crea objetos
    _id = id;

    _out = new DigitalOut(gpio_out);
    MBED_ASSERT(_out);
    _level = level;

    // Deja apagado por defecto
    turnOff();
}


//------------------------------------------------------------------------------------
void Relay::turnOn(){
    uint8_t value = (_level == OnIsHighLevel)? 1 : 0;
    _stat = RelayIsOn;          
    _out->write(value);
}


//------------------------------------------------------------------------------------
void Relay::turnOff(){
    uint8_t value = (_level == OnIsHighLevel)? 0 : 1;
    _stat = RelayIsOff;          
    _out->write(value);
}
 

 
//------------------------------------------------------------------------------------
//-- PRIVATE METHODS IMPLEMENTATION --------------------------------------------------
//------------------------------------------------------------------------------------


