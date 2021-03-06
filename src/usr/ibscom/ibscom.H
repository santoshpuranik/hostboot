/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/ibscom.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __IBSCOM_H
#define __IBSCOM_H

/** @file ibscom.H
 *  @brief Provides the interfaces to perform IBSCOM
 */

#include <stdint.h>

/**
 *  @brief  Type definition for IBSCOM address
 */
typedef uint64_t IBScomBase_t;

namespace IBSCOM
{

const size_t  IBSCOM_BUFFER_SIZE = 8;   // 8 bytes

/**
 * @brief Performs an inband scom access operation
 * This function performs an inband scom access operation. It follows a 
 * pre-defined prototype functions in order to be registered with the 
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        inband scom target
 * @param[in] io_buffer      Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in] i_args            This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the MMIO inband scom address
 * @return  errlHndl_t
 */
errlHndl_t ibscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args);

/**
 * Bit definition for MBSIBERR0
 */
struct MBSIBERRO_Reg_t
{
    union
    {
        uint64_t data;
        struct
        {
            uint64_t addr:32;    //MBSIBERR0Q_IB_HOST_ADDRESS
            uint64_t errvalid:1; //MBSIBERR0Q_IB_HOST_ERROR_VALID
            uint64_t piberr:3;   //MBSIBERR0Q_IB_HOST_ERROR_STATUS
            uint64_t iswrite:1;  //MBSIBERR0Q_IB_HOST_WRITE_NOT_READ
            uint64_t reserved:27;
        };
    };
};


};


#endif
