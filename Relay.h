/*
 * Relay.h
 *
 *  Created on: Sep 2017
 *      Author: raulMrello
 *
 *	Relay es el módulo encargado de gestionar la activación y apagado de un Relé. Es posible generar patrones de encendido
 *  en caso de que se pueda controlar con dos líneas distintas. De forma que active a máxima potencia durante un tiempo
 *  y posteriormente desactive una de las líneas para mantener una corriente de mantenimiento inferior.
 *  En el constructor, se puede configurar el funcionamiento del módulo para no tener que hacer nada más al encender o apagar
 *  el relé
 *
 */
 
#ifndef __Relay__H
#define __Relay__H

#include "mbed.h"

   
class Relay{
  public:
        
    /** Configuración del nivel lógico de activación del relé */
	enum RelayLogicLevel{
		OnIsLowLevel,       /// El relé se activa con una salida a nivel bajo
		OnIsHighLevel       /// El relé se activa con una salida a nivel alto
	};
    
    /** Tipo de estado en el que se puede encontrar un relé */
    enum RelayStat{
        RelayIsOff,         /// Desactivado 
        RelayIsOn,          /// Activado        
    };
        
	/** Constructor
     *  Durante la construcción del objeto, se asignan los pines de control (1 o 2), la lógica de activación, y
     *  el tiempo que debe proporcionarse la corriente de pico antes de bajar a la corriente de mantenimiento, en 
     *  el caso de utilizar una configuración de doble nivel.
     *  @param id Identificador del relé
     *  @param gpio_out GPIO conectado al canal de máxima corriente
     *  @param level Nivel de activación lógico 
     */
    Relay(uint32_t id, PinName gpio_out, RelayLogicLevel level = OnIsHighLevel);
    ~Relay(){}
  
  
	/** turnOn
     *  Inicia el encendido del relé
     */
    void turnOn();
  
    
	/** turnOff
     *  Apaga el relé
     */
    void turnOff();
  
  
	/** getState
     *  Obtiene el estado actual del relé
     *  @return RelayStat
     */
    RelayStat getState(){ return _stat; }   
  
  
	/** getId
     *  Obtiene el identificador del relé
     *  @return Identificador
     */
    uint32_t getId(){ return _id; }       
             
  private:

    uint32_t _id;               			/// Identificador del relé
    DigitalOut* _out;		      			/// Salida de relé
    RelayLogicLevel _level;     			/// Nivel de activación lógico
    RelayStat _stat;            			/// Estado de ejecución (Off, On)
};
     


#endif /*__Relay__H */

/**** END OF FILE ****/


