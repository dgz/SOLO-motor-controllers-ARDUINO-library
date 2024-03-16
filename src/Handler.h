/**
 *******************************************************************************
 * @file    Handler.h
 * @authors SOLO Motor Controllers
 * @brief   This file contains all the functions interrupt based for CANopen
 *          Availability: https://github.com/Solo-FL/SOLO-motor-controllers-ARDUINO-library
 *
 * @date    Date: 2024
 * @version 5.2.0
 * *******************************************************************************
 * @attention
 * Copyright: (c) 2021-present, SOLO motor controllers project
 * GNU General Public License v3.0+ (see COPYING or https://www.gnu.org/licenses/gpl-3.0.txt)
 *******************************************************************************
 */

#ifndef HANDLER_H
#define HANDLER_H

#include "MCP2515.hpp"
#include "SOLOMotorControllersCanopen.h"

#define CAN_BUFF_SIZE 15

typedef enum
{
    BUFFER_0,
    BUFFER_1
} MCP2515_RX_BUFFER;

void ISR_Handler();
void enableNodeFilter(uint8_t node_number, uint8_t filter_number);
void enableAddrFilter(uint16_t addr, uint8_t filter_number);
int enableRangeFilter(uint16_t start_addr, uint16_t end_addr, uint8_t filter_number);
void disableAllFilters();
void enableAllFilters();
void removeAllFilters();
void storeDataFromBuffers(bool checkInterruptPin = true);
void storeDataFromBuffer(MCP2515_RX_BUFFER _RXBn);
#endif // HANDLER_H