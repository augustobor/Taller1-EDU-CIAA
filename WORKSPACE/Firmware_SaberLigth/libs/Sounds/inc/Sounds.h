#ifndef _SOUNDS_H_
#define _SOUNDS_H_

#include "Neopixel_Efects.h"
#include "sapi.h" // Ensure the correct path to sapi.h
#include "board.h"
#define TRUNC(n) ((uint16_t)(n))

#define GYRO_MAX_VALUE 5	//rad/s

//Devuelven el valor absoluto de la entrada
#define GYRO_X_COMPONENT ((mpu60X0GetGyroX_rads() < 0) ? -mpu60X0GetGyroX_rads() : mpu60X0GetGyroX_rads())
#define GYRO_Y_COMPONENT ((mpu60X0GetGyroY_rads() < 0) ? -mpu60X0GetGyroY_rads() : mpu60X0GetGyroY_rads())
#define GYRO_Z_COMPONENT ((mpu60X0GetGyroZ_rads() < 0) ? -mpu60X0GetGyroZ_rads() : mpu60X0GetGyroZ_rads())

float get_gyro_abs_val();// retorna valor absoluto de movimiento entre [0..1]

void Sounds_Init();   // Inicializa configuraciones del Timer 1 , DAC y variables
void Sound_Service_DAC();	// servicio de ejecucion continua para enviar muestras al DAC
void setGanance(float g);
uint16_t amplificarS(float);
float interpol(uint16_t y1 ,uint16_t y2, float dx );
void moduleSound(float velocidad_transduccion);
void set_enable_colision_sound(bool_t enable);

#define raw_samples_length 5324
#define static uint16_t raw_samples[] = {
		0x7F, 0x8B, 0x9B, 0xA7, 0xB6, 0xC3, 0xCE, 0xD9, 0xE1, 0xE6, 0xE8, 0xE8, 0xE6, 0xE3, 0xE0, 0xDC, 0xD7, 0xD1, 0xC9, 0xC0, 0xB7, 0xAE, 0xA6, 0x9D, 0x94, 0x8C, 0x85, 0x7E, 0x77, 0x72, 0x6D, 0x69, 0x65, 0x63, 0x62, 0x62, 0x63, 0x66, 0x69, 0x6E, 0x73, 0x79, 0x80, 0x87, 0x8E, 0x94, 0x9B, 0xA2, 0xA8, 0xAF, 0xB5, 0xBA, 0xBF, 0xC3, 0xC7, 0xCB, 0xCE, 0xD1, 0xD3, 0xD5, 0xD6, 0xD7, 0xD6, 0xD5, 0xD4, 0xD2, 0xCF, 0xCC, 0xC9, 0xC5, 0xC0, 0xBB, 0xB7, 0xB2, 0xAE, 0xA9, 0xA5, 0xA0, 0x9B, 0x96, 0x92, 0x8E, 0x89, 0x85, 0x81, 0x7D, 0x7A, 0x76, 0x73, 0x70, 0x6D, 0x6B, 0x68, 0x66, 0x63, 0x60, 0x5D, 0x5B, 0x58, 0x55, 0x53, 0x50, 0x4D, 0x4B, 0x48, 0x46, 0x44, 0x42, 0x41, 0x3F, 0x3E, 0x3C, 0x3B, 0x3A, 0x39, 0x39, 0x38, 0x38, 0x38, 0x38, 0x39, 0x39, 0x39, 0x3A, 0x3A, 0x3B, 0x3D, 0x3E, 0x40, 0x41, 0x43, 0x45, 0x47, 0x4A, 0x4D, 0x4F, 0x51, 0x53, 0x55, 0x56, 0x58, 0x5A, 0x5C, 0x5E, 0x61, 0x64, 0x67, 0x6A, 0x6D, 0x6F, 0x72, 0x75, 0x77, 0x7A, 0x7D, 0x7F, 0x82, 0x84, 0x86, 0x88, 0x8B, 0x8D, 0x8F, 0x91, 0x93, 0x95, 0x97, 0x98, 0x9A, 0x9C, 0x9D, 0x9F, 0xA0, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA8, 0xA9, 0xA9, 0xA8, 0xA8, 0xA8, 0xA7, 0xA6, 0xA5, 0xA4, 0xA2, 0xA1, 0x9F, 0x9C, 0x99, 0x96, 0x93, 0x8F, 0x8C, 0x89, 0x86, 0x82, 0x7E, 0x7B, 0x78, 0x74, 0x71, 0x6D, 0x69, 0x65, 0x62, 0x5F, 0x5C, 0x5A, 0x58, 0x56, 0x54, 0x52, 0x52, 0x51, 0x50, 0x50, 0x50, 0x51, 0x52, 0x53, 0x55, 0x57, 0x5A, 0x5D, 0x60, 0x63, 0x67, 0x6B, 0x6F, 0x72, 0x76, 0x7B, 0x7F, 0x84, 0x88, 0x8C, 0x90, 0x94, 0x98, 0x9C, 0x9F, 0xA2, 0xA6, 0xA9, 0xAC, 0xAE, 0xB0, 0xB2, 0xB4, 0xB4, 0xB5, 0xB5, 0xB5, 0xB4, 0xB3, 0xB2, 0xB1, 0xAF, 0xAE, 0xAC, 0xAA, 0xA8, 0xA6, 0xA4, 0xA2, 0xA0, 0x9E, 0x9D, 0x9B, 0x99, 0x97, 0x96, 0x95, 0x93, 0x93, 0x92, 0x92, 0x92, 0x92, 0x92, 0x93, 0x94, 0x95, 0x97, 0x98, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA0, 0xA1, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA1, 0xA0, 0xA0, 0x9E, 0x9D, 0x9B, 0x99, 0x97, 0x95, 0x93, 0x91, 0x8E, 0x8B, 0x88, 0x86, 0x83, 0x81, 0x7E, 0x7C, 0x79, 0x77, 0x75, 0x73, 0x71, 0x70, 0x6D, 0x6B, 0x69, 0x67, 0x65, 0x63, 0x61, 0x5E, 0x5C, 0x5A, 0x58, 0x56, 0x54, 0x52, 0x51, 0x4F, 0x4E, 0x4C, 0x4B, 0x4A, 0x4A, 0x49, 0x48, 0x48, 0x47, 0x47, 0x47, 0x47, 0x48, 0x48, 0x49, 0x49, 0x4A, 0x4A, 0x4B, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x51, 0x53, 0x55, 0x57, 0x59, 0x5C, 0x5E, 0x60, 0x62, 0x63, 0x65, 0x66, 0x68, 0x6A, 0x6D, 0x6F, 0x72, 0x74, 0x77, 0x78, 0x7A, 0x7B, 0x7D, 0x7F, 0x80, 0x82, 0x83, 0x84, 0x85, 0x85, 0x86, 0x87, 0x88, 0x88, 0x89, 0x8A, 0x8A, 0x8B, 0x8C, 0x8E, 0x8F, 0x90, 0x91, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x97, 0x98, 0x98, 0x98, 0x98, 0x98, 0x98, 0x97, 0x97, 0x96, 0x95, 0x94, 0x93, 0x91, 0x8F, 0x8D, 0x8B, 0x89, 0x86, 0x84, 0x81, 0x7E, 0x7B, 0x78, 0x75, 0x73, 0x70, 0x6C, 0x69, 0x66, 0x63, 0x5F, 0x5D, 0x5A, 0x58, 0x56, 0x54, 0x52, 0x51, 0x50, 0x50, 0x50, 0x50, 0x51, 0x52, 0x53, 0x55, 0x57, 0x59, 0x5C, 0x5F, 0x63, 0x67, 0x6B, 0x70, 0x75, 0x7A, 0x7E, 0x84, 0x88, 0x8D, 0x92, 0x97, 0x9B, 0x9F, 0xA3, 0xA6, 0xA9, 0xAC, 0xAF, 0xB2, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB8, 0xB8, 0xB7, 0xB6, 0xB4, 0xB3, 0xB1, 0xB0, 0xAF, 0xAD, 0xAB, 0xAA, 0xA7, 0xA5, 0xA4, 0xA2, 0xA0, 0x9E, 0x9D, 0x9B, 0x99, 0x98, 0x96, 0x95, 0x94, 0x93, 0x92, 0x93, 0x92, 0x92, 0x92, 0x92, 0x92, 0x94, 0x95, 0x97, 0x98, 0x9A, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA2, 0xA3, 0xA5, 0xA6, 0xA7, 0xA7, 0xA8, 0xA8, 0xA7, 0xA7, 0xA6, 0xA4, 0xA3, 0xA1, 0x9F, 0x9C, 0x9A, 0x97, 0x95, 0x92, 0x8E, 0x8B, 0x88, 0x84, 0x81, 0x7E, 0x7A, 0x76, 0x72, 0x6F, 0x6B, 0x68, 0x64, 0x61, 0x5E, 0x5C, 0x59, 0x57, 0x55, 0x53, 0x51, 0x4F, 0x4D, 0x4B, 0x49, 0x47, 0x44, 0x40, 0x3A, 0x36, 0x36, 0x3A, 0x43, 0x4A, 0x53, 0x5D, 0x65, 0x6E, 0x77, 0x7C, 0x80, 0x81, 0x80, 0x7D, 0x7A, 0x76, 0x71, 0x6C, 0x67, 0x60, 0x5A, 0x53, 0x4C, 0x45, 0x3F, 0x39, 0x34, 0x2F, 0x2C, 0x29, 0x27, 0x24, 0x22, 0x21, 0x20, 0x22, 0x25, 0x29, 0x2E, 0x35, 0x3C, 0x43, 0x4B, 0x54, 0x5D, 0x65, 0x6E, 0x77, 0x7F, 0x86, 0x8D, 0x93, 0x99, 0x9F, 0xA5, 0xAA, 0xAE, 0xB2, 0xB6, 0xB8, 0xBA, 0xBC, 0xBC, 0xBD, 0xBD, 0xBC, 0xBB, 0xB9, 0xB7, 0xB5, 0xB3, 0xB0, 0xAE, 0xAC, 0xA9, 0xA7, 0xA4, 0xA2, 0x9F, 0x9C, 0x9A, 0x97, 0x95, 0x92, 0x90, 0x8D, 0x8A, 0x87, 0x84, 0x81, 0x7E, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x69, 0x65, 0x61, 0x5D, 0x58, 0x54, 0x50, 0x4B, 0x47, 0x43, 0x40, 0x3D, 0x3A, 0x37, 0x35, 0x33, 0x31, 0x30, 0x30, 0x2F, 0x2F, 0x30, 0x31, 0x32, 0x35, 0x37, 0x3A, 0x3D, 0x41, 0x45, 0x4A, 0x4F, 0x54, 0x58, 0x5E, 0x63, 0x69, 0x6F, 0x75, 0x7B, 0x80, 0x86, 0x8B, 0x90, 0x95, 0x9A, 0x9E, 0xA3, 0xA6, 0xAA, 0xAC, 0xAF, 0xB2, 0xB4, 0xB6, 0xB7, 0xB8, 0xB9, 0xB9, 0xB9, 0xB9, 0xB8, 0xB8, 0xB7, 0xB6, 0xB4, 0xB3, 0xB2, 0xB1, 0xAF, 0xAE, 0xAD, 0xAC, 0xAB, 0xAB, 0xAA, 0xAA, 0xAA, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB2, 0xB3, 0xB5, 0xB7, 0xB8, 0xBA, 0xBB, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC2, 0xC3, 0xC3, 0xC3, 0xC2, 0xC2, 0xC1, 0xBF, 0xBE, 0xBD, 0xBB, 0xB8, 0xB6, 0xB3, 0xB0, 0xAD, 0xAA, 0xA7, 0xA4, 0xA0, 0x9D, 0x99, 0x96, 0x92, 0x8F, 0x8B, 0x88, 0x85, 0x81, 0x7D, 0x7A, 0x77, 0x74, 0x71, 0x6E, 0x6B, 0x68, 0x65, 0x62, 0x5F, 0x5C, 0x59, 0x57, 0x54, 0x52, 0x50, 0x4E, 0x4C, 0x4A, 0x48, 0x46, 0x45, 0x43, 0x42, 0x41, 0x40, 0x3F, 0x3F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x40, 0x40, 0x41, 0x42, 0x44, 0x46, 0x47, 0x49, 0x4B, 0x4D, 0x4F, 0x51, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5B, 0x5D, 0x5F, 0x62, 0x64, 0x66, 0x68, 0x6A, 0x6C, 0x6E, 0x71, 0x73, 0x75, 0x77, 0x78, 0x79, 0x7A, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x84, 0x85, 0x86, 0x88, 0x89, 0x8A, 0x8B, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x8F, 0x90, 0x91, 0x90, 0x90, 0x90, 0x90, 0x8F, 0x8F, 0x8F, 0x8E, 0x8E, 0x8D, 0x8C, 0x8B, 0x8A, 0x88, 0x86, 0x84, 0x82, 0x7F, 0x7C, 0x79, 0x76, 0x72, 0x6F, 0x6C, 0x68, 0x65, 0x61, 0x5D, 0x5A, 0x57, 0x53, 0x51, 0x4F, 0x4C, 0x4A, 0x48, 0x47, 0x46, 0x45, 0x44, 0x44, 0x45, 0x46, 0x47, 0x49, 0x4B, 0x4D, 0x51, 0x54, 0x58, 0x5C, 0x61, 0x65, 0x6A, 0x6F, 0x75, 0x7A, 0x80, 0x85, 0x8B, 0x91, 0x96, 0x9B, 0xA0, 0xA4, 0xA8, 0xAC, 0xB0, 0xB3, 0xB6, 0xB8, 0xBB, 0xBC, 0xBD, 0xBE, 0xBE, 0xBE, 0xBD, 0xBB, 0xBA, 0xB8, 0xB6, 0xB4, 0xB2, 0xAF, 0xAC, 0xAA, 0xA8, 0xA5, 0xA2, 0xA0, 0x9E, 0x9D, 0x9B, 0x9B, 0x9A, 0x99, 0x99, 0x98, 0x99, 0x9A, 0x9A, 0x9B, 0x9C, 0x9D, 0x9F, 0xA0, 0xA2, 0xA4, 0xA6, 0xA9, 0xAB, 0xAD, 0xAF, 0xB0, 0xB2, 0xB3, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBA, 0xBA, 0xBA, 0xBA, 0xB8, 0xB7, 0xB6, 0xB4, 0xB2, 0xB0, 0xAD, 0xAA, 0xA8, 0xA4, 0xA1, 0x9E, 0x9A, 0x97, 0x93, 0x90, 0x8D, 0x8A, 0x87, 0x84, 0x81, 0x7E, 0x7B, 0x78, 0x76, 0x74, 0x71, 0x6F, 0x6D, 0x6B, 0x68, 0x66, 0x64, 0x63, 0x61, 0x5F, 0x5E, 0x5D, 0x5B, 0x59, 0x58, 0x56, 0x55, 0x53, 0x52, 0x51, 0x50, 0x4F, 0x4F, 0x4E, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x51, 0x53, 0x54, 0x56, 0x58, 0x5A, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x64, 0x66, 0x68, 0x6B, 0x6C, 0x6E, 0x70, 0x71, 0x73, 0x76, 0x78, 0x7A, 0x7C, 0x7E, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8B, 0x8D, 0x8F, 0x91, 0x92, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x99, 0x99, 0x99, 0x9A, 0x9A, 0x9A, 0x99, 0x99, 0x98, 0x97, 0x96, 0x95, 0x94, 0x92, 0x90, 0x8E, 0x8C, 0x8A, 0x87, 0x84, 0x81, 0x7E, 0x7A, 0x76, 0x73, 0x6F, 0x6C, 0x68, 0x64, 0x61, 0x5E, 0x5A, 0x56, 0x53, 0x4E, 0x4A, 0x46, 0x41, 0x3B, 0x34, 0x30, 0x2F, 0x33, 0x3B, 0x42, 0x4A, 0x54, 0x5C, 0x66, 0x6F, 0x76, 0x7A, 0x7D, 0x7E, 0x7E, 0x7D, 0x7C, 0x7C, 0x7A, 0x78, 0x76, 0x73, 0x70, 0x6D, 0x6A, 0x67, 0x65, 0x64, 0x63, 0x62, 0x61, 0x62, 0x62, 0x63, 0x65, 0x67, 0x6B, 0x6F, 0x74, 0x79, 0x7F, 0x85, 0x8C, 0x93, 0x9A, 0xA0, 0xA7, 0xAD, 0xB3, 0xB8, 0xBD, 0xC0, 0xC4, 0xC6, 0xC9, 0xCB, 0xCC, 0xCD, 0xCE, 0xCE, 0xCE, 0xCD, 0xCD, 0xCB, 0xCA, 0xC8, 0xC6, 0xC4, 0xC2, 0xC0, 0xBE, 0xBC, 0xBA, 0xB9, 0xB8, 0xB7, 0xB6, 0xB5, 0xB5, 0xB4, 0xB3, 0xB3, 0xB2, 0xB2, 0xB2, 0xB1, 0xB1, 0xB1, 0xB1, 0xB0, 0xB0, 0xAF, 0xAE, 0xAD, 0xAC, 0xAA, 0xA8, 0xA5, 0xA2, 0x9E, 0x9B, 0x98, 0x94, 0x90, 0x8B, 0x87, 0x83, 0x7E, 0x7A, 0x76, 0x72, 0x6D, 0x69, 0x65, 0x62, 0x5E, 0x5B, 0x58, 0x55, 0x53, 0x50, 0x4E, 0x4C, 0x49, 0x47, 0x45, 0x44, 0x43, 0x42, 0x41, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x3F, 0x3F, 0x3F, 0x3F, 0x40, 0x40, 0x40, 0x41, 0x41, 0x41, 0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x45, 0x47, 0x49, 0x4B, 0x4D, 0x4F, 0x51, 0x54, 0x57, 0x5A, 0x5D, 0x5F, 0x61, 0x63, 0x65, 0x68, 0x6B, 0x6E, 0x72, 0x75, 0x79, 0x7C, 0x7F, 0x82, 0x85, 0x88, 0x8B, 0x8E, 0x91, 0x94, 0x96, 0x98, 0x99, 0x9B, 0x9D, 0x9F, 0xA0, 0xA1, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2, 0xA3, 0xA3, 0xA2, 0xA2, 0xA2, 0xA2, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA0, 0xA0, 0x9F, 0x9E, 0x9D, 0x9C, 0x9A, 0x99, 0x97, 0x96, 0x94, 0x92, 0x90, 0x8D, 0x8A, 0x87, 0x84, 0x80, 0x7D, 0x7A, 0x76, 0x72, 0x6F, 0x6B, 0x68, 0x64, 0x61, 0x5C, 0x59, 0x55, 0x52, 0x4F, 0x4C, 0x4A, 0x47, 0x46, 0x44, 0x43, 0x42, 0x41, 0x41, 0x41, 0x42, 0x43, 0x44, 0x46, 0x48, 0x4A, 0x4D, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x65, 0x6A, 0x6F, 0x74, 0x79, 0x7E, 0x83, 0x89, 0x8D, 0x91, 0x95, 0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA7, 0xA9, 0xAB, 0xAC, 0xAD, 0xAE, 0xAE, 0xAD, 0xAD, 0xAC, 0xAA, 0xAA, 0xA8, 0xA7, 0xA5, 0xA3, 0xA2, 0xA0, 0x9D, 0x9B, 0x99, 0x97, 0x96, 0x94, 0x93, 0x92, 0x92, 0x91, 0x91, 0x90, 0x90, 0x91, 0x92, 0x93, 0x93, 0x94, 0x95, 0x97, 0x98, 0x9A, 0x9B, 0x9D, 0x9E, 0x9F, 0xA0, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA7, 0xA6, 0xA5, 0xA3, 0xA0, 0x9D, 0x9A, 0x97, 0x95, 0x91, 0x8E, 0x8B, 0x87, 0x84, 0x81, 0x7E, 0x7A, 0x77, 0x73, 0x70, 0x6D, 0x6A, 0x67, 0x64, 0x61, 0x5F, 0x5C, 0x5A, 0x58, 0x56, 0x54, 0x53, 0x51, 0x50, 0x4F, 0x4F, 0x4E, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x4E, 0x4E, 0x4F, 0x4F, 0x50, 0x51, 0x51, 0x52, 0x53, 0x54, 0x54, 0x54, 0x54, 0x55, 0x56, 0x56, 0x57, 0x58, 0x58, 0x5A, 0x5B, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x65, 0x66, 0x69, 0x6D, 0x6F, 0x72, 0x75, 0x77, 0x7A, 0x7C, 0x7F, 0x82, 0x84, 0x87, 0x8A, 0x8C, 0x8F, 0x91, 0x93, 0x96, 0x98, 0x9A, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA2, 0xA1, 0xA1, 0xA0, 0xA0, 0x9F, 0x9E, 0x9D, 0x9C, 0x9A, 0x99, 0x97, 0x95, 0x94, 0x92, 0x90, 0x8D, 0x8B, 0x88, 0x86, 0x83, 0x80, 0x7D, 0x7A, 0x77, 0x73, 0x6F, 0x6C, 0x68, 0x65, 0x63, 0x5F, 0x5C, 0x59, 0x56, 0x53, 0x50, 0x4E, 0x4B, 0x49, 0x48, 0x46, 0x44, 0x44, 0x43, 0x43, 0x44, 0x44, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4E, 0x51, 0x55, 0x59, 0x5D, 0x61, 0x66, 0x6A, 0x6F, 0x74, 0x79, 0x7E, 0x83, 0x88, 0x8C, 0x91, 0x96, 0x9A, 0x9E, 0xA2, 0xA5, 0xA8, 0xAA, 0xAC, 0xAE, 0xB0, 0xB2, 0xB2, 0xB3, 0xB3, 0xB3, 0xB3, 0xB2, 0xB2, 0xB2, 0xB1, 0xB0, 0xAF, 0xAD, 0xAC, 0xAB, 0xAA, 0xA9, 0xA8, 0xA7, 0xA6, 0xA5, 0xA4, 0xA4, 0xA4, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA4, 0xA5, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xA9, 0xAA, 0xAB, 0xAC, 0xAC, 0xAD, 0xAD, 0xAE, 0xAE, 0xAE, 0xAD, 0xAD, 0xAC, 0xAC, 0xAA, 0xA9, 0xA7, 0xA5, 0xA3, 0xA1, 0x9F, 0x9C, 0x9A, 0x97, 0x94, 0x91, 0x8D, 0x89, 0x85, 0x7F, 0x77, 0x71, 0x6C, 0x6A, 0x6F, 0x73, 0x77, 0x7E, 0x82, 0x87, 0x8C, 0x8F, 0x91, 0x91, 0x8E, 0x8A, 0x84, 0x7F, 0x78, 0x71, 0x6A, 0x62, 0x59, 0x4F, 0x46, 0x3D, 0x34, 0x2C, 0x24, 0x1D, 0x17, 0x12, 0x0D, 0x0A, 0x07, 0x04, 0x03, 0x03, 0x04, 0x07, 0x0A, 0x0E, 0x14, 0x1A, 0x21, 0x28, 0x30, 0x39, 0x41, 0x49, 0x51, 0x59, 0x61, 0x68, 0x6F, 0x76, 0x7B, 0x80, 0x84, 0x88, 0x8C, 0x90, 0x94, 0x97, 0x99, 0x9B, 0x9C, 0x9C, 0x9C, 0x9C, 0x9D, 0x9D, 0x9C, 0x9C, 0x9B, 0x9A, 0x9A, 0x99, 0x99, 0x99, 0x98, 0x99, 0x98, 0x97, 0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x98, 0x99, 0x98, 0x99, 0x9A, 0x9A, 0x9A, 0x9A, 0x99, 0x98, 0x97, 0x96, 0x94, 0x92, 0x91, 0x8F, 0x8D, 0x8B, 0x88, 0x85, 0x82, 0x80, 0x7D, 0x79, 0x76, 0x72, 0x6F, 0x6B, 0x67, 0x63, 0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4E, 0x4B, 0x49, 0x47, 0x46, 0x44, 0x43, 0x42, 0x41, 0x40, 0x3F, 0x3F, 0x40, 0x40, 0x41, 0x43, 0x45, 0x46, 0x49, 0x4B, 0x4E, 0x51, 0x55, 0x59, 0x5E, 0x62, 0x67, 0x6C, 0x71, 0x76, 0x7C, 0x81, 0x87, 0x8C, 0x92, 0x97, 0x9C, 0xA1, 0xA5, 0xA9, 0xAD, 0xB1, 0xB4, 0xB6, 0xB9, 0xBB, 0xBC, 0xBE, 0xC0, 0xC1, 0xC1, 0xC1, 0xC1, 0xC0, 0xC0, 0xBF, 0xBE, 0xBD, 0xBB, 0xB9, 0xB7, 0xB6, 0xB3, 0xB2, 0xB0, 0xAF, 0xAD, 0xAC, 0xAB, 0xAA, 0xA9, 0xA8, 0xA9, 0xA8, 0xA8, 0xA9, 0xA9, 0xAA, 0xAA, 0xAC, 0xAD, 0xAF, 0xB0, 0xB1, 0xB3, 0xB4, 0xB5, 0xB5, 0xB6, 0xB7, 0xB8, 0xB8, 0xB8, 0xB9, 0xB8, 0xB8, 0xB7, 0xB6, 0xB5, 0xB3, 0xB1, 0xAF, 0xAD, 0xAA, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C, 0x98, 0x95, 0x91, 0x8D, 0x8A, 0x86, 0x83, 0x7F, 0x7C, 0x78, 0x75, 0x72, 0x6F, 0x6C, 0x69, 0x66, 0x64, 0x62, 0x5F, 0x5D, 0x5B, 0x59, 0x56, 0x54, 0x53, 0x51, 0x50, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49, 0x49, 0x48, 0x47, 0x47, 0x47, 0x46, 0x46, 0x45, 0x45, 0x44, 0x44, 0x43, 0x43, 0x43, 0x42, 0x43, 0x43, 0x44, 0x44, 0x45, 0x46, 0x47, 0x49, 0x4A, 0x4C, 0x4E, 0x50, 0x52, 0x53, 0x55, 0x56, 0x57, 0x58, 0x5A, 0x5C, 0x5F, 0x61, 0x63, 0x66, 0x68, 0x6A, 0x6D, 0x6F, 0x72, 0x74, 0x77, 0x7A, 0x7B, 0x7D, 0x7F, 0x81, 0x83, 0x84, 0x86, 0x87, 0x88, 0x8A, 0x8B, 0x8C, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x92, 0x92, 0x93, 0x93, 0x93, 0x94, 0x94, 0x94, 0x93, 0x92, 0x91, 0x90, 0x8F, 0x8E, 0x8D, 0x8C, 0x8A, 0x88, 0x86, 0x84, 0x82, 0x7F, 0x7C, 0x79, 0x76, 0x73, 0x70, 0x6D, 0x69, 0x66, 0x63, 0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4F, 0x4D, 0x4B, 0x49, 0x48, 0x47, 0x46, 0x46, 0x46, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4E, 0x51, 0x54, 0x57, 0x5A, 0x5E, 0x61, 0x65, 0x6A, 0x6E, 0x73, 0x77, 0x7C, 0x80, 0x85, 0x8A, 0x8E, 0x93, 0x97, 0x9B, 0x9F, 0xA3, 0xA6, 0xAA, 0xAD, 0xB0, 0xB3, 0xB4, 0xB6, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBC, 0xBC, 0xBB, 0xBA, 0xBA, 0xB9, 0xB8, 0xB7, 0xB5, 0xB3, 0xB2, 0xB0, 0xAE, 0xAC, 0xAB, 0xA9, 0xA8, 0xA7, 0xA6, 0xA5, 0xA5, 0xA4, 0xA4, 0xA4, 0xA5, 0xA5, 0xA5, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAB, 0xAC, 0xAD, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB1, 0xB1, 0xB2, 0xB2, 0xB2, 0xB1, 0xB0, 0xAF, 0xAE, 0xAD, 0xAC, 0xAA, 0xA8, 0xA6, 0xA3, 0xA1, 0x9E, 0x9B, 0x98, 0x96, 0x92, 0x8F, 0x8C, 0x89, 0x86, 0x83, 0x81, 0x7D, 0x7B, 0x77, 0x75, 0x72, 0x6F, 0x6D, 0x6A, 0x68, 0x66, 0x63, 0x61, 0x5F, 0x5C, 0x5A, 0x58, 0x56, 0x54, 0x53, 0x52, 0x50, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49, 0x48, 0x47, 0x47, 0x46, 0x46, 0x46, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x45, 0x46, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4E, 0x50, 0x52, 0x55, 0x58, 0x5A, 0x5D, 0x5F, 0x61, 0x63, 0x66, 0x68, 0x6A, 0x6D, 0x70, 0x73, 0x76, 0x78, 0x7B, 0x7D, 0x7E, 0x80, 0x82, 0x84, 0x86, 0x87, 0x88, 0x88, 0x89, 0x8A, 0x8A, 0x8B, 0x8C, 0x8D, 0x8D, 0x8D, 0x8E, 0x8E, 0x8E, 0x8F, 0x8F, 0x90, 0x90, 0x90, 0x8F, 0x8F, 0x8F, 0x90, 0x90, 0x90, 0x90, 0x90, 0x8F, 0x8E, 0x8E, 0x8D, 0x8C, 0x8A, 0x88, 0x86, 0x84, 0x81, 0x7B, 0x75, 0x70, 0x6D, 0x6E, 0x74, 0x78, 0x7D, 0x82, 0x85, 0x89, 0x8E, 0x90, 0x8F, 0x8E, 0x8A, 0x83, 0x7C, 0x75, 0x6E, 0x66, 0x5E, 0x56, 0x4D, 0x44, 0x3C, 0x33, 0x2C, 0x25, 0x1F, 0x1A, 0x16, 0x13, 0x11, 0x10, 0x10, 0x11, 0x13, 0x17, 0x1D, 0x23, 0x2B, 0x34, 0x3D, 0x47, 0x52, 0x5D, 0x69, 0x74, 0x80, 0x8B, 0x96, 0xA0, 0xAA, 0xB3, 0xBC, 0xC4, 0xCB, 0xD1, 0xD6, 0xDB, 0xDE, 0xE1, 0xE3, 0xE4, 0xE4, 0xE3, 0xE1, 0xDF, 0xDC, 0xD9, 0xD6, 0xD2, 0xCF, 0xCB, 0xC7, 0xC3, 0xBF, 0xBC, 0xB8, 0xB4, 0xB2, 0xAF, 0xAC, 0xAA, 0xA8, 0xA6, 0xA5, 0xA3, 0xA3, 0xA2, 0xA2, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA5, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA5, 0xA5, 0xA4, 0xA2, 0xA1, 0x9F, 0x9E, 0x9B, 0x9A, 0x98, 0x95, 0x92, 0x8F, 0x8D, 0x8A, 0x87, 0x85, 0x82, 0x7F, 0x7C, 0x79, 0x76, 0x73, 0x70, 0x6D, 0x6A, 0x67, 0x65, 0x63, 0x60, 0x5E, 0x5C, 0x5A, 0x59, 0x57, 0x56, 0x54, 0x53, 0x51, 0x50, 0x4E, 0x4D, 0x4D, 0x4C, 0x4B, 0x4B, 0x4B, 0x4A, 0x4A, 0x4A, 0x49, 0x4A, 0x4A, 0x4A, 0x4B, 0x4B, 0x4B, 0x4C, 0x4C, 0x4C, 0x4D, 0x4D, 0x4D, 0x4D, 0x4E, 0x4F, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5A, 0x5C, 0x5F, 0x61, 0x64, 0x66, 0x68, 0x6A, 0x6B, 0x6D, 0x70, 0x73, 0x76, 0x79, 0x7C, 0x7F, 0x82, 0x84, 0x86, 0x89, 0x8B, 0x8E, 0x90, 0x93, 0x95, 0x96, 0x97, 0x99, 0x9A, 0x9C, 0x9D, 0x9E, 0x9F, 0x9F, 0xA0, 0xA0, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA1, 0xA0, 0x9F, 0x9F, 0x9E, 0x9E, 0x9E, 0x9D, 0x9D, 0x9C, 0x9C, 0x9A, 0x99, 0x98, 0x97, 0x96, 0x94, 0x92, 0x90, 0x8D, 0x8A, 0x88, 0x84, 0x81, 0x7D, 0x79, 0x76, 0x72, 0x6E, 0x6A, 0x66, 0x63, 0x60, 0x5C, 0x59, 0x56, 0x53, 0x4F, 0x4D, 0x4A, 0x48, 0x46, 0x44, 0x43, 0x41, 0x40, 0x40, 0x3F, 0x40, 0x41, 0x42, 0x44, 0x44, 0x46, 0x47, 0x49, 0x4B, 0x4E, 0x51, 0x53, 0x57, 0x5B, 0x5F, 0x63, 0x67, 0x6C, 0x70, 0x75, 0x7A, 0x7E, 0x83, 0x87, 0x8C, 0x90, 0x94, 0x98, 0x9C, 0x9F, 0xA2, 0xA5, 0xA7, 0xAA, 0xAC, 0xAE, 0xAF, 0xB0, 0xB1, 0xB1, 0xB2, 0xB2, 0xB2, 0xB1, 0xB1, 0xB0, 0xAE, 0xAD, 0xAB, 0xA9, 0xA8, 0xA6, 0xA5, 0xA3, 0xA2, 0xA1, 0x9F, 0x9F, 0x9E, 0x9D, 0x9D, 0x9D, 0x9D, 0x9E, 0x9E, 0x9E, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA6, 0xA7, 0xA7, 0xA8, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA9, 0xA8, 0xA7, 0xA6, 0xA4, 0xA2, 0xA0, 0x9E, 0x9D, 0x9B, 0x98, 0x96, 0x94, 0x92, 0x8F, 0x8C, 0x8A, 0x87, 0x85, 0x83, 0x80, 0x7E, 0x7C, 0x7A, 0x77, 0x75, 0x73, 0x71, 0x6E, 0x6C, 0x69, 0x67, 0x65, 0x62, 0x60, 0x5E, 0x5C, 0x5B, 0x59, 0x57, 0x56, 0x54, 0x53, 0x51, 0x50, 0x4E, 0x4C, 0x4A, 0x49, 0x48, 0x47, 0x47, 0x46, 0x46, 0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4F, 0x50, 0x52, 0x54, 0x57, 0x59, 0x5C, 0x5E, 0x60, 0x62, 0x63, 0x65, 0x67, 0x69, 0x6B, 0x6E, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7E, 0x80, 0x83, 0x85, 0x87, 0x88, 0x89, 0x8B, 0x8C, 0x8E, 0x8F, 0x90, 0x90, 0x92, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x99, 0x99, 0x9A, 0x9A, 0x9A, 0x9B, 0x9B, 0x9B, 0x9C, 0x9C, 0x9B, 0x9B, 0x9A, 0x9A, 0x99, 0x98, 0x97, 0x95, 0x93, 0x91, 0x8F, 0x8D, 0x8A, 0x87, 0x85, 0x82, 0x7F, 0x7B, 0x78, 0x75, 0x72, 0x6E, 0x6C, 0x69, 0x66, 0x62, 0x5F, 0x5C, 0x59, 0x57, 0x55, 0x52, 0x51, 0x4F, 0x4D, 0x4C, 0x4B, 0x4B, 0x4B, 0x4B, 0x4B, 0x4C, 0x4D, 0x4F, 0x50, 0x52, 0x54, 0x57, 0x5A, 0x5E, 0x62, 0x66, 0x6A, 0x6F, 0x73, 0x78, 0x7D, 0x82, 0x87, 0x8C, 0x91, 0x96, 0x9A, 0x9E, 0xA3, 0xA7, 0xAB, 0xAE, 0xB1, 0xB3, 0xB5, 0xB6, 0xB8, 0xB8, 0xB9, 0xB9, 0xB8, 0xB7, 0xB6, 0xB4, 0xB3, 0xB1, 0xAF, 0xAD, 0xAA, 0xA8, 0xA6, 0xA3, 0xA2, 0xA0, 0x9F, 0x9D, 0x9C, 0x9B, 0x9A, 0x99, 0x98, 0x97, 0x97, 0x96, 0x96, 0x96, 0x96, 0x96, 0x97, 0x97, 0x98, 0x99, 0x9B, 0x9C, 0x9D, 0x9D, 0x9E, 0x9E, 0x9E, 0x9E, 0x9D, 0x99, 0x95, 0x93, 0x94, 0x9A, 0xA1, 0xA9, 0xB0, 0xB8, 0xC0, 0xC5, 0xCB, 0xCD, 0xCE, 0xCD, 0xC8, 0xC2, 0xBC, 0xB5, 0xAE, 0xA5, 0x9C, 0x92, 0x87, 0x7C, 0x72, 0x66, 0x5C, 0x52, 0x48, 0x40, 0x38, 0x31, 0x2A, 0x25, 0x21, 0x1D, 0x1A, 0x19, 0x19, 0x1A, 0x1D, 0x20, 0x24, 0x29, 0x2E, 0x34, 0x3A, 0x40, 0x46, 0x4C, 0x51, 0x56, 0x5B, 0x5F, 0x63, 0x67, 0x6A, 0x6E, 0x70, 0x72, 0x74, 0x75, 0x76, 0x76, 0x75, 0x74, 0x73, 0x73, 0x72, 0x72, 0x71, 0x70, 0x70, 0x6F, 0x70, 0x70, 0x71, 0x71, 0x71, 0x70, 0x70, 0x6F, 0x70, 0x71, 0x73, 0x75, 0x77, 0x78, 0x7A, 0x7C, 0x7D, 0x80, 0x81, 0x84, 0x86, 0x87, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8C, 0x8B, 0x8A, 0x89, 0x89, 0x88, 0x87, 0x86, 0x84, 0x83, 0x82, 0x80, 0x7F, 0x7F, 0x7E, 0x7E, 0x7D, 0x7C, 0x7C, 0x7A, 0x7A, 0x79, 0x78, 0x77, 0x76, 0x75, 0x74, 0x73, 0x71, 0x6F, 0x6D, 0x6B, 0x69, 0x66, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x53, 0x50, 0x4E, 0x4C, 0x49, 0x47, 0x46, 0x44, 0x42, 0x41, 0x41, 0x3F, 0x3F, 0x40, 0x40, 0x41, 0x42, 0x44, 0x45, 0x48, 0x4A, 0x4C, 0x4F, 0x53, 0x56, 0x5B, 0x5F, 0x64, 0x69, 0x6F, 0x74, 0x7A, 0x80, 0x86, 0x8B, 0x91, 0x97, 0x9D, 0xA2, 0xA8, 0xAC, 0xB1, 0xB6, 0xBA, 0xBE, 0xC1, 0xC4, 0xC7, 0xC9, 0xCB, 0xCD, 0xCD, 0xCE, 0xCE, 0xCD, 0xCD, 0xCC, 0xCB, 0xCA, 0xC9, 0xC7, 0xC5, 0xC3, 0xC1, 0xBF, 0xBD, 0xBB, 0xB9, 0xB7, 0xB5, 0xB3, 0xB1, 0xB0, 0xAE, 0xAD, 0xAC, 0xAC, 0xAB, 0xAA, 0xAA, 0xA9, 0xA9, 0xAA, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xAF, 0xB0, 0xB0, 0xB1, 0xB1, 0xB1, 0xB1, 0xB2, 0xB2, 0xB2, 0xB1, 0xB0, 0xB0, 0xAE, 0xAC, 0xAB, 0xA9, 0xA6, 0xA4, 0xA1, 0x9F, 0x9C, 0x99, 0x96, 0x93, 0x90, 0x8C, 0x88, 0x85, 0x81, 0x7D, 0x7A, 0x76, 0x74, 0x70, 0x6D, 0x6B, 0x68, 0x65, 0x62, 0x60, 0x5D, 0x5A, 0x56, 0x53, 0x50, 0x4E, 0x4C, 0x4A, 0x48, 0x46, 0x44, 0x43, 0x41, 0x40, 0x3E, 0x3D, 0x3C, 0x3C, 0x3B, 0x3A, 0x3A, 0x3A, 0x3A, 0x39, 0x39, 0x39, 0x39, 0x39, 0x3A, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x40, 0x41, 0x43, 0x46, 0x48, 0x4B, 0x4D, 0x50, 0x53, 0x56, 0x59, 0x5A, 0x5C, 0x5E, 0x60, 0x62, 0x65, 0x68, 0x6B, 0x6E, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7C, 0x7E, 0x80, 0x82, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x92, 0x93, 0x94, 0x94, 0x95, 0x95, 0x96, 0x96, 0x97, 0x97, 0x97, 0x97, 0x96, 0x96, 0x96, 0x95, 0x95, 0x94, 0x93, 0x92, 0x91, 0x8F, 0x8D, 0x8A, 0x87, 0x84, 0x81, 0x7E, 0x7B, 0x77, 0x73, 0x6F, 0x6C, 0x68, 0x65, 0x61, 0x5E, 0x5A, 0x57, 0x53, 0x50, 0x4E, 0x4B, 0x49, 0x47, 0x45, 0x44, 0x43, 0x42, 0x42, 0x42, 0x43, 0x43, 0x44, 0x46, 0x48, 0x4B, 0x4D, 0x50, 0x54, 0x58, 0x5C, 0x61, 0x66, 0x6B, 0x70, 0x75, 0x7B, 0x81, 0x86, 0x8C, 0x91, 0x96, 0x9B, 0xA0, 0xA5, 0xA9, 0xAD, 0xB0, 0xB3, 0xB6, 0xB9, 0xBB, 0xBD, 0xBF, 0xC0, 0xC1, 0xC1, 0xC0, 0xBF, 0xBF, 0xBE, 0xBD, 0xBC, 0xBA, 0xB8, 0xB6, 0xB3, 0xB1, 0xAF, 0xAD, 0xAA, 0xA9, 0xA7, 0xA6, 0xA5, 0xA4, 0xA3, 0xA2, 0xA2, 0xA2, 0xA3, 0xA2, 0xA3, 0xA3, 0xA4, 0xA5, 0xA5, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAD, 0xAD, 0xAE, 0xAE, 0xAF, 0xAF, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xAF, 0xAE, 0xAD, 0xAC, 0xAB, 0xA9, 0xA7, 0xA5, 0xA2, 0xA0, 0x9D, 0x9A, 0x98, 0x95, 0x92, 0x8F, 0x8C, 0x89, 0x86, 0x83, 0x80, 0x7D, 0x79, 0x76, 0x73, 0x71, 0x6D, 0x6A, 0x68, 0x65, 0x62, 0x60, 0x5D, 0x5A, 0x57, 0x55, 0x53, 0x51, 0x4F, 0x4D, 0x4C, 0x4B, 0x4A, 0x49, 0x48, 0x48, 0x47, 0x47, 0x47, 0x47, 0x47, 0x48, 0x48, 0x49, 0x49, 0x4A, 0x4A, 0x4B, 0x4B, 0x4B, 0x4C, 0x4C, 0x4D, 0x4E, 0x4F, 0x4F, 0x51, 0x52, 0x53, 0x54, 0x55, 0x57, 0x59, 0x5A, 0x5C, 0x5C, 0x5D, 0x5E, 0x5F, 0x61, 0x63, 0x65, 0x68, 0x6A, 0x6C, 0x6E, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7A, 0x7B, 0x7D, 0x7D, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x7E, 0x7A, 0x77, 0x77, 0x7A, 0x84, 0x8E, 0x96, 0xA1, 0xA9, 0xB1, 0xB9, 0xBF, 0xC3, 0xC5, 0xC5, 0xC3, 0xBF, 0xBB, 0xB7, 0xB2, 0xAB, 0xA5, 0x9D, 0x94, 0x8B, 0x82, 0x79, 0x70, 0x67, 0x5F, 0x57, 0x50, 0x49, 0x43, 0x3D, 0x38, 0x34, 0x30, 0x2E, 0x2D, 0x2D, 0x2D, 0x2F, 0x31, 0x34, 0x37, 0x3B, 0x3F, 0x44, 0x48, 0x4C, 0x51, 0x55, 0x59, 0x5D, 0x61, 0x65, 0x69, 0x6C, 0x70, 0x73, 0x76, 0x7A, 0x7D, 0x80, 0x82, 0x85, 0x87, 0x8A, 0x8D, 0x8F, 0x92, 0x94, 0x96, 0x99, 0x9C, 0x9F, 0xA2, 0xA4, 0xA7, 0xAA, 0xAD, 0xB0, 0xB2, 0xB5, 0xB7, 0xB9, 0xBB, 0xBC, 0xBE, 0xBF, 0xC0, 0xC0, 0xC0, 0xC0, 0xBF, 0xBE, 0xBD, 0xBB, 0xB9, 0xB7, 0xB4, 0xB2, 0xAF, 0xAB, 0xA8, 0xA4, 0xA1, 0x9D, 0x9A, 0x97, 0x94, 0x92, 0x8F, 0x8D, 0x8B, 0x8A, 0x88, 0x87, 0x86, 0x86, 0x85, 0x85, 0x86, 0x86, 0x88, 0x89, 0x8B, 0x8D, 0x8E, 0x90, 0x91, 0x93, 0x95, 0x96, 0x98, 0x99, 0x9A, 0x9C, 0x9D, 0x9E, 0x9E, 0x9E, 0x9E, 0x9E, 0x9D, 0x9C, 0x9A, 0x99, 0x97, 0x96, 0x94, 0x91, 0x90, 0x8D, 0x8A, 0x88, 0x85, 0x82, 0x80, 0x7E, 0x7B, 0x79, 0x76, 0x74, 0x72, 0x6F, 0x6E, 0x6C, 0x6A, 0x67, 0x66, 0x64, 0x62, 0x61, 0x60, 0x5F, 0x5E, 0x5E, 0x5D, 0x5D, 0x5D, 0x5D, 0x5D, 0x5D, 0x5D, 0x5C, 0x5C, 0x5C, 0x5C, 0x5C, 0x5C, 0x5C, 0x5D, 0x5C, 0x5C, 0x5C, 0x5D, 0x5D, 0x5D, 0x5D, 0x5E, 0x5E, 0x5E, 0x5E, 0x5F, 0x61, 0x62, 0x63, 0x64, 0x65, 0x67, 0x68, 0x6A, 0x6C, 0x6E, 0x6E, 0x6F, 0x6F, 0x70, 0x72, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7C, 0x7E, 0x7F, 0x81, 0x82, 0x84, 0x86, 0x87, 0x88, 0x89, 0x89, 0x8A, 0x8B, 0x8B, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8B, 0x8B, 0x8A, 0x89, 0x88, 0x87, 0x86, 0x85, 0x84, 0x82, 0x81, 0x7F, 0x7E, 0x7B, 0x79, 0x77, 0x74, 0x72, 0x6E, 0x6B, 0x68, 0x64, 0x61, 0x5E, 0x5A, 0x57, 0x54, 0x51, 0x4E, 0x4B, 0x48, 0x46, 0x44, 0x42, 0x41, 0x3F, 0x3D, 0x3C, 0x3C, 0x3C, 0x3C, 0x3D, 0x3E, 0x40, 0x42, 0x44, 0x47, 0x4A, 0x4E, 0x52, 0x57, 0x5C, 0x61, 0x66, 0x6C, 0x71, 0x77, 0x7D, 0x83, 0x88, 0x8D, 0x93, 0x98, 0x9D, 0xA2, 0xA6, 0xAA, 0xAD, 0xB1, 0xB4, 0xB6, 0xB7, 0xB9, 0xBA, 0xBB, 0xBC, 0xBB, 0xBB, 0xBA, 0xB9, 0xB8, 0xB6, 0xB5, 0xB3, 0xB1, 0xAF, 0xAC, 0xAA, 0xA8, 0xA5, 0xA3, 0xA2, 0xA0, 0x9F, 0x9E, 0x9D, 0x9D, 0x9C, 0x9B, 0x9C, 0x9B, 0x9C, 0x9D, 0x9D, 0x9D, 0x9E, 0x9E, 0x9F, 0xA0, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6, 0xA6, 0xA7, 0xA9, 0xA9, 0xAA, 0xAB, 0xAB, 0xAC, 0xAC, 0xAB, 0xAB, 0xAA, 0xA9, 0xA8, 0xA7, 0xA5, 0xA3, 0xA1, 0x9F, 0x9C, 0x9A, 0x97, 0x94, 0x91, 0x8E, 0x8B, 0x88, 0x85, 0x81, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A, 0x68, 0x65, 0x63, 0x61, 0x5F, 0x5D, 0x5B, 0x5A, 0x59, 0x57, 0x57, 0x56, 0x55, 0x55, 0x55, 0x54, 0x54, 0x54, 0x54, 0x53, 0x53, 0x53, 0x53, 0x54, 0x54, 0x55, 0x55, 0x56, 0x57, 0x57, 0x58, 0x58, 0x59, 0x59, 0x5A, 0x5A, 0x5B, 0x5C, 0x5E, 0x5F, 0x60, 0x60, 0x61, 0x63, 0x64, 0x66, 0x68, 0x69, 0x6A, 0x6A, 0x6B, 0x6C, 0x6D, 0x70, 0x72, 0x74, 0x76, 0x79, 0x7B, 0x7C, 0x7E, 0x80, 0x82, 0x85, 0x87, 0x89, 0x8B, 0x8C, 0x8E, 0x8F, 0x90, 0x91, 0x93, 0x94, 0x95, 0x96, 0x96, 0x97, 0x97, 0x98, 0x98, 0x98, 0x98, 0x97, 0x97, 0x97, 0x97, 0x96, 0x95, 0x95, 0x94, 0x93, 0x92, 0x91, 0x8F, 0x8E, 0x8D, 0x8B, 0x8A, 0x88, 0x86, 0x84, 0x82, 0x80, 0x7D, 0x7A, 0x77, 0x74, 0x71, 0x6E, 0x6A, 0x66, 0x63, 0x5F, 0x5B, 0x57, 0x54, 0x50, 0x4D, 0x4A, 0x47, 0x44, 0x42, 0x40, 0x3E, 0x3D, 0x3C, 0x3B, 0x3B, 0x3B, 0x3C, 0x3D, 0x3E, 0x40, 0x42, 0x43, 0x46, 0x48, 0x4B, 0x4E, 0x52, 0x55, 0x5A, 0x5D, 0x62, 0x67, 0x6B, 0x70, 0x74, 0x79, 0x7E, 0x82, 0x87, 0x8C, 0x8F, 0x93, 0x97, 0x9B, 0x9F, 0xA2, 0xA6, 0xA9, 0xAB, 0xAD, 0xAF, 0xB0, 0xB2, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB3, 0xB2, 0xB1, 0xB0, 0xAE, 0xAC, 0xA9, 0xA6, 0xA3, 0x9D, 0x97, 0x94, 0x91, 0x95, 0x9D, 0xA3, 0xAC, 0xB4, 0xBB, 0xC4, 0xCA, 0xD0, 0xD3, 0xD4, 0xD4, 0xD1, 0xCE, 0xCB, 0xC8, 0xC4, 0xBF, 0xBA, 0xB3, 0xAC, 0xA6, 0x9F, 0x98, 0x92, 0x8B, 0x86, 0x81, 0x7D, 0x79, 0x75, 0x72, 0x6F, 0x6D, 0x6C, 0x6C, 0x6D, 0x6E, 0x70, 0x73, 0x76, 0x7A, 0x7D, 0x81, 0x85, 0x88, 0x8B, 0x8D, 0x8F, 0x91, 0x92, 0x93, 0x94, 0x94, 0x94, 0x94, 0x93, 0x92, 0x91, 0x8F, 0x8E, 0x8B, 0x88, 0x85, 0x81, 0x7E, 0x7A, 0x76, 0x72, 0x6E, 0x6B, 0x67, 0x63, 0x60, 0x5D, 0x5A, 0x56, 0x54, 0x51, 0x50, 0x4E, 0x4C, 0x4B, 0x4A, 0x49, 0x49, 0x48, 0x48, 0x48, 0x49, 0x49, 0x49, 0x4A, 0x4A, 0x4B, 0x4C, 0x4D, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x51, 0x52, 0x53, 0x53, 0x53, 0x53, 0x54, 0x54, 0x55, 0x57, 0x58, 0x5A, 0x5C, 0x5E, 0x60, 0x61, 0x63, 0x65, 0x67, 0x69, 0x6B, 0x6D, 0x6F, 0x71, 0x73, 0x75, 0x78, 0x7A, 0x7C, 0x7D, 0x7F, 0x81, 0x83, 0x85, 0x87, 0x88, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x8F, 0x90, 0x91, 0x90, 0x91, 0x91, 0x91, 0x90, 0x8F, 0x8F, 0x8E, 0x8E, 0x8D, 0x8C, 0x8B, 0x8A, 0x89, 0x88, 0x86, 0x84, 0x83, 0x81, 0x7F, 0x7D, 0x7B, 0x79, 0x76, 0x74, 0x72, 0x6F, 0x6D, 0x6B, 0x69, 0x67, 0x64, 0x62, 0x60, 0x5E, 0x5D, 0x5C, 0x5A, 0x5A, 0x59, 0x58, 0x58, 0x58, 0x58, 0x59, 0x5A, 0x5C, 0x5D, 0x5F, 0x61, 0x64, 0x68, 0x6B, 0x6F, 0x74, 0x78, 0x7D, 0x82, 0x87, 0x8C, 0x91, 0x96, 0x9B, 0xA0, 0xA4, 0xA8, 0xAC, 0xAF, 0xB3, 0xB5, 0xB8, 0xBA, 0xBB, 0xBC, 0xBD, 0xBD, 0xBE, 0xBD, 0xBD, 0xBC, 0xBA, 0xB8, 0xB7, 0xB5, 0xB3, 0xB1, 0xAE, 0xAC, 0xAA, 0xA8, 0xA5, 0xA3, 0xA1, 0x9F, 0x9D, 0x9C, 0x9B, 0x9A, 0x99, 0x98, 0x97, 0x97, 0x96, 0x97, 0x97, 0x97, 0x98, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x9F, 0xA1, 0xA2, 0xA3, 0xA3, 0xA4, 0xA5, 0xA6, 0xA6, 0xA6, 0xA5, 0xA5, 0xA3, 0xA1, 0xA0, 0x9E, 0x9C, 0x9A, 0x98, 0x95, 0x92, 0x90, 0x8D, 0x8B, 0x88, 0x85, 0x83, 0x80, 0x7D, 0x7A, 0x76, 0x74, 0x70, 0x6D, 0x6A, 0x67, 0x64, 0x61, 0x5F, 0x5D, 0x5B, 0x59, 0x57, 0x55, 0x54, 0x52, 0x51, 0x4F, 0x4E, 0x4E, 0x4D, 0x4C, 0x4C, 0x4B, 0x4B, 0x4B, 0x4A, 0x4A, 0x4A, 0x4A, 0x4B, 0x4B, 0x4C, 0x4C, 0x4D, 0x4E, 0x4E, 0x4F, 0x50, 0x51, 0x51, 0x51, 0x51, 0x52, 0x53, 0x53, 0x54, 0x55, 0x55, 0x56, 0x57, 0x58, 0x5A, 0x5C, 0x5D, 0x5E, 0x60, 0x61, 0x62, 0x64, 0x66, 0x68, 0x6B, 0x6D, 0x6F, 0x72, 0x74, 0x76, 0x78, 0x7A, 0x7C, 0x7E, 0x81, 0x83, 0x84, 0x86, 0x87, 0x89, 0x8B, 0x8C, 0x8D, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x95, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x95, 0x95, 0x94, 0x93, 0x92, 0x91, 0x90, 0x8E, 0x8C, 0x8A, 0x88, 0x86, 0x83, 0x81, 0x7E, 0x7B, 0x78, 0x76, 0x73, 0x6F, 0x6D, 0x6A, 0x67, 0x65, 0x62, 0x5F, 0x5C, 0x59, 0x57, 0x55, 0x53, 0x51, 0x50, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x53, 0x55, 0x57, 0x5A, 0x5D, 0x60, 0x63, 0x67, 0x6B, 0x70, 0x74, 0x79, 0x7D, 0x82, 0x87, 0x8B, 0x90, 0x94, 0x99, 0x9D, 0xA1, 0xA5, 0xA8, 0xAC, 0xAF, 0xB2, 0xB5, 0xB7, 0xB9, 0xBB, 0xBD, 0xBE, 0xBF, 0xC0, 0xC0, 0xC0, 0xC0, 0xBF, 0xBE, 0xBD, 0xBC, 0xBA, 0xB9, 0xB7, 0xB5, 0xB4, 0xB1, 0xAF, 0xAD, 0xAB, 0xA9, 0xA7, 0xA6, 0xA4, 0xA3, 0xA1, 0xA0, 0x9F, 0x9F, 0x9E, 0x9E, 0x9D, 0x9D, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA2, 0xA4, 0xA4, 0xA6, 0xA7, 0xA7, 0xA8, 0xA8, 0xA8, 0xA9, 0xA9, 0xA9, 0xA8, 0xA7, 0xA7, 0xA6, 0xA4, 0xA2, 0xA0, 0x9E, 0x9B, 0x98, 0x95, 0x93, 0x90, 0x8D, 0x89, 0x86, 0x83, 0x80, 0x7D, 0x7A, 0x78, 0x75, 0x73, 0x70, 0x6E, 0x6C, 0x6A, 0x68, 0x66, 0x64, 0x62, 0x61, 0x5F, 0x5D, 0x5B, 0x5A, 0x58, 0x56, 0x54, 0x53, 0x51, 0x4F, 0x4E, 0x4C, 0x4B, 0x49, 0x48, 0x47, 0x46, 0x45, 0x44, 0x44, 0x44, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x49, 0x4A, 0x4B, 0x49, 0x48, 0x48, 0x49, 0x50, 0x58, 0x62, 0x6D, 0x76, 0x82, 0x8D, 0x97, 0xA0, 0xA5, 0xA8, 0xA9, 0xA8, 0xA5, 0xA3, 0xA0, 0x9E, 0x99, 0x94, 0x8D, 0x86, 0x7F, 0x78, 0x72, 0x6C, 0x66, 0x61, 0x5C, 0x58, 0x55, 0x52, 0x51, 0x4F, 0x4F, 0x51, 0x52, 0x55, 0x59, 0x5E, 0x63, 0x69, 0x70, 0x76, 0x7D, 0x83, 0x89, 0x8F, 0x94, 0x99, 0x9D, 0xA1, 0xA4, 0xA7, 0xA9, 0xAA, 0xAB, 0xAC, 0xAC, 0xAB, 0xA9, 0xA7, 0xA5, 0xA1, 0x9D, 0x99, 0x94, 0x8E, 0x89, 0x84, 0x7E, 0x79, 0x73, 0x6D, 0x68, 0x63, 0x5E, 0x5A, 0x57, 0x54, 0x51, 0x4F, 0x4D, 0x4C, 0x4B, 0x4B, 0x4B, 0x4C, 0x4D, 0x4E, 0x50, 0x53, 0x56, 0x59, 0x5D, 0x61, 0x65, 0x69, 0x6D, 0x71, 0x75, 0x79, 0x7D, 0x81, 0x85, 0x89, 0x8C, 0x90, 0x93, 0x95, 0x99, 0x9B, 0x9D, 0xA0, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA7, 0xA6, 0xA6, 0xA5, 0xA5, 0xA4, 0xA3, 0xA2, 0xA1, 0xA0, 0x9F, 0x9E, 0x9D, 0x9B, 0x9A, 0x99, 0x98, 0x97, 0x96, 0x96, 0x95, 0x94, 0x94, 0x93, 0x93, 0x93, 0x94, 0x94, 0x94, 0x95, 0x95, 0x97, 0x99, 0x9B, 0x9D, 0x9E, 0xA0, 0xA1, 0xA3, 0xA4, 0xA6, 0xA8, 0xA9, 0xAA, 0xAC, 0xAD, 0xAD, 0xAE, 0xAF, 0xAF, 0xAF, 0xAF, 0xAF, 0xAE, 0xAE, 0xAD, 0xAB, 0xAA, 0xA8, 0xA6, 0xA4, 0xA2, 0xA0, 0x9D, 0x9A, 0x97, 0x94, 0x91, 0x8E, 0x8A, 0x88, 0x84, 0x81, 0x7E, 0x7B, 0x79, 0x76, 0x74, 0x71, 0x6F, 0x6D, 0x6A, 0x69, 0x67, 0x65, 0x64, 0x63, 0x61, 0x60, 0x5F, 0x5D, 0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x57, 0x56, 0x55, 0x54, 0x54, 0x53, 0x52, 0x52, 0x51, 0x51, 0x51, 0x50, 0x50, 0x50, 0x51, 0x51, 0x52, 0x52, 0x53, 0x54, 0x55, 0x57, 0x58, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x62, 0x64, 0x66, 0x69, 0x6C, 0x6E, 0x71, 0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x7F, 0x80, 0x81, 0x82, 0x84, 0x85, 0x86, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8C, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8D, 0x8C, 0x8B, 0x8B, 0x8B, 0x8B, 0x8A, 0x8A, 0x89, 0x88, 0x88, 0x87, 0x86, 0x85, 0x84, 0x82, 0x80, 0x7E, 0x7C, 0x7A, 0x77, 0x74, 0x72, 0x6F, 0x6C, 0x69, 0x67, 0x64, 0x61, 0x5F, 0x5C, 0x5A, 0x58, 0x56, 0x53, 0x51, 0x4E, 0x4C, 0x4A, 0x48, 0x47, 0x45, 0x44, 0x43, 0x42, 0x42, 0x42, 0x43, 0x44, 0x46, 0x47, 0x49, 0x4B, 0x4D, 0x50, 0x53, 0x56, 0x59, 0x5D, 0x62, 0x65, 0x6A, 0x6E, 0x72, 0x77, 0x7C, 0x80, 0x85, 0x8A, 0x8E, 0x92, 0x96, 0x9A, 0x9E, 0xA2, 0xA5, 0xA9, 0xAC, 0xAE, 0xB1, 0xB3, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xB9, 0xB9, 0xB8, 0xB8, 0xB8, 0xB7, 0xB6, 0xB4, 0xB3, 0xB1, 0xB0, 0xAE, 0xAD, 0xAB, 0xAA, 0xA9, 0xA7, 0xA6, 0xA5, 0xA4, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAD, 0xAE, 0xAF, 0xAF, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xAF, 0xAE, 0xAD, 0xAC, 0xAB, 0xA9, 0xA8, 0xA5, 0xA3, 0xA1, 0x9E, 0x9C, 0x99, 0x96, 0x93, 0x91, 0x8E, 0x8B, 0x88, 0x86, 0x83, 0x80, 0x7E, 0x7B, 0x79, 0x77, 0x74, 0x72, 0x70, 0x6E, 0x6B, 0x6A, 0x68, 0x65, 0x64, 0x62, 0x60, 0x5E, 0x5D, 0x5C, 0x5A, 0x59, 0x58, 0x56, 0x55, 0x53, 0x52, 0x51, 0x50, 0x4F, 0x4F, 0x4E, 0x4E, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D, 0x4E, 0x4E, 0x4E, 0x4E, 0x4F, 0x4F, 0x50, 0x52, 0x53, 0x55, 0x57, 0x58, 0x5A, 0x5C, 0x5E, 0x60, 0x62, 0x63, 0x64, 0x64, 0x65, 0x67, 0x68, 0x6A, 0x6C, 0x6F, 0x71, 0x72, 0x74, 0x75, 0x77, 0x79, 0x7B, 0x7E, 0x7F, 0x81, 0x82, 0x83, 0x84, 0x86, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8C, 0x8D, 0x8D, 0x8E, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8F, 0x8E, 0x8F, 0x8F, 0x8F, 0x8F, 0x8E, 0x8E, 0x8E, 0x8D, 0x8D, 0x8D, 0x8C, 0x8B, 0x8A, 0x89, 0x87, 0x85, 0x83, 0x81, 0x7F, 0x7D, 0x7B, 0x78, 0x76, 0x73, 0x70, 0x6D, 0x6B, 0x68, 0x65, 0x61, 0x5F, 0x5B, 0x58, 0x55, 0x53, 0x51, 0x4F, 0x4D, 0x4C, 0x4A, 0x49, 0x48, 0x48, 0x48, 0x49, 0x49, 0x4A, 0x4B, 0x4D, 0x4F, 0x52, 0x55, 0x58, 0x5C, 0x60, 0x64, 0x69, 0x6E, 0x72, 0x77, 0x7B, 0x7F,
};

#endif /* #ifndef _NEOPIXEL_EFECTS_H_ */

