/*
 * Relay.h
 *
 *  Created on: Sep 2017
 *      Author: raulMrello
 *
 *	Relay es el m�dulo encargado de gestionar la activaci�n y apagado de un Rel�. Es posible generar patrones de encendido
 *  en caso de que se pueda controlar con dos l�neas distintas. De forma que active a m�xima potencia durante un tiempo
 *  y posteriormente desactive una de las l�neas para mantener una corriente de mantenimiento inferior.
 *  En el constructor, se puede configurar el funcionamiento del m�dulo para no tener que hacer nada m�s al encender o apagar
 *  el rel�
 *
 */
 
#ifndef __Relay__H
#define __Relay__H

#include "mbed.h"

   
class Relay{
  public:
        
    /** Configuraci�n del nivel l�gico de activaci�n del rel� */
	enum RelayLogicLevel{
		OnIsLowLevel,       /// El rel� se activa con una salida a nivel bajo
		OnIsHighLevel       /// El rel� se activa con una salida a nivel alto
	};
    
    /** Tipo de estado en el que se puede encontrar un rel� */
    enum RelayStat{
        RelayIsOff,         /// Desactivado 
        RelayIsOn,          /// Activado        
    };
        
	/** Constructor
     *  Durante la construcci�n del objeto, se asignan los pines de control (1 o 2), la l�gica de activaci�n, y
     *  el tiempo que debe proporcionarse la corriente de pico antes de bajar a la corriente de mantenimiento, en 
     *  el caso de utilizar una configuraci�n de doble nivel.
     *  @param id Identificador del rel�
     *  @param gpio_out GPIO conectado al canal de m�xima corriente
     *  @param level Nivel de activaci�n l�gico 
     */
    Relay(uint32_t id, PinName gpio_out, RelayLogicLevel level = OnIsHighLevel);
    ~Relay(){}
  
  
	/** turnOn
     *  Inicia el encendido del rel�
     */
    void turnOn();
  
    
	/** turnOff
     *  Apaga el rel�
     */
    void turnOff();
  
  
	/** getState
     *  Obtiene el estado actual del rel�
     *  @return RelayStat
     */
    RelayStat getState(){ return _stat; }   
  
  
	/** getId
     *  Obtiene el identificador del rel�
     *  @return Identificador
     */
    uint32_t getId(){ return _id; }       
             
  private:

    uint32_t _id;               			/// Identificador del rel�
    DigitalOut* _out;		      			/// Salida de rel�
    RelayLogicLevel _level;     			/// Nivel de activaci�n l�gico
    RelayStat _stat;            			/// Estado de ejecuci�n (Off, On)
};
     


#endif /*__Relay__H */

/**** END OF FILE ****/


