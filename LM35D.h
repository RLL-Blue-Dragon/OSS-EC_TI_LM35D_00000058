// License       : License.txt
// Specifications: Spec-LM35D.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35D.h
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __LM35D_H__
#define __LM35D_H__

#include "user_define.h"

// Components number
#define iLM35D                  128U                    // Texas Instruments LM35D

// LM35D System Parts definitions
#define iLM35D_xoff             0.0F                    // X offset [V]
#define iLM35D_yoff             0.0F                    // Y offset [degree celsius]
#define iLM35D_gain             0.01F                   // Gain [V/degree celsius]
#define iLM35D_max              100.0F                  // Temperature Max [degree celsius]
#define iLM35D_min              2.0F                    // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_LM35D;

#endif /*__LM35D_H__*/
