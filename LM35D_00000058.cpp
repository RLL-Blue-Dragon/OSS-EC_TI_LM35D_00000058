// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35D_00000058.cpp
// BSL              : 00000058
// Model number     : Texas Instruments LM35D
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "LM35D.h"

AnalogIn LM35D_adc( iLM35D_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t LM35D_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( LM35D_adc , tbl_LM35D );
        return( res );
}
