/**
 * @file nmea.h
 * @author Paul Götzinger
 * @brief NMEA protocol interface
 * @version 1.0
 * @date 2019-02-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef NMEA_H
#define NMEA_H

#include "position.h"

#define NMEA_DATA_LENGTH 72 //length of nmea paylaod buffer

/**
 * @brief Nmea message state
 * 
 */
typedef enum {
    NMEA_State_IDLE = 0,
    NMEA_State_TYPE,
    NMEA_State_DATA,
    NMEA_State_CS0,
    NMEA_State_CS1,
    NMEA_State_CR,
    NMEA_State_LF
} NMEA_State;

/**
 * @brief Nmea message type
 * 
 */
typedef enum {
    NMEA_Type_NONE = 0,
    NMEA_Type_GPGLL,
    NMEA_Type_GNGLL,
    NMEA_Type_GLGSB,
    NMEA_Type_GPGSV,
    NMEA_Type_GNGSA,
    NMEA_Type_GNGGA,
    NMEA_Type_GNVTG,
    NMEA_Type_GNRMC
} NMEA_Type;

/**
 * @brief Nmea position callback
 * 
 * @param pos gps position
 * 
 */
typedef void (*NMEA_Callback_Position)(POS_Position *pos);

/**
 * @brief Nmea unknown callback
 * 
 * @param pos gps position
 * 
 */
typedef void (*NMEA_Callback_Unknown)(NMEA_Type type, uint8_t* data, uint16_t len);

/**
 * @brief Nmea instance structure
 * 
 */
typedef struct {
    NMEA_State state;
    NMEA_Type type;
    NMEA_Callback_Position cb_pos;
    NMEA_Callback_Unknown  cb_unk;
    uint8_t cs;
    uint8_t data[NMEA_DATA_LENGTH+1];
    uint8_t idx;
} NMEA_Instance;

/**
 * @brief Nmea initialization
 * 
 * @param nmea nmea instance structure
 */
void NMEA_Init(NMEA_Instance* nmea);

/**
 * @brief Set callback for new position
 * 
 * @param nmea nmea instance structure
 * @param cb callback function
 */
void NMEA_SetPositionCallback(NMEA_Instance* nmea, NMEA_Callback_Position cb);

/**
 * @brief Set callback for unknown types
 * 
 * @param nmea nmea instance structure
 * @param cb callback function
 */
void NMEA_SetUnknownCallback(NMEA_Instance* nmea, NMEA_Callback_Unknown cb);

/**
 * @brief Process received byte
 * 
 * @param nmea nmea instance structure
 * @param byte byte to parse
 */
void NMEA_Process(NMEA_Instance* nmea, uint8_t byte);

#endif //NMEA_H