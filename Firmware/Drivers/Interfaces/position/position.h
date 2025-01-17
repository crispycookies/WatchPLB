/**
 * @file position.h
 * @author Paul Götzinger
 * @brief Position interface
 * @version 1.0
 * @date 2019-02-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef POSITION_H
#define POSITION_H

/**
 * @brief Position latitude flag
 * 
 */
typedef enum {
	POS_Latitude_Flag_N = 0,
	POS_Latitude_Flag_S = 1
} POS_Latitude_Flag;

/**
 * @brief Position longitude flag
 * 
 */
typedef enum {
	POS_Longitude_Flag_E = 0,
	POS_Longitude_Flag_W = 1
} POS_Longitude_Flag;

/**
 * @brief Position valid flag
 * 
 */
typedef enum {
	POS_Valid_Flag_Invalid = 0,
	POS_Valid_Flag_Valid
} POS_Valid_Flag;

/**
 * @brief Position timestamp
 * 
 */
typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t split;
} POS_Time;

/**
 * @brief Position latitude structure
 * 
 */
typedef struct{
	POS_Latitude_Flag direction;
	uint16_t degree;
	float minute;
} POS_Latitude;

/**
 * @brief Position longitude structure
 * 
 */
typedef struct{
	POS_Longitude_Flag direction;
	uint16_t degree;
	float minute;
} POS_Longitude;

/**
 * @brief position structure
 * 
 */
typedef struct {
    POS_Time time;
	POS_Latitude latitude;
	POS_Longitude longitude;
	POS_Valid_Flag valid;
} POS_Position;

int16_t POS_CmpTime(POS_Time *left, POS_Time *right);

uint16_t POS_ToString(POS_Position *pos, uint8_t* str, uint16_t len);

#endif //!POSITION_H