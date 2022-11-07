// License       : License.txt
// Specifications: Spec-LM35D.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : LM35D.cpp
// Reason for change: 01.00.00 : 03/11/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "LM35D.h"

#if     iLM35D_ma == iSMA                               // Simple moving average filter
static float32 LM35D_sma_buf[iLM35D_SMA_num];
static sma_f32_t LM35D_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iLM35D_SMA_num ,                                // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &LM35D_sma_buf[0]                               // buffer
};

#elif   iLM35D_ma == iEMA                               // Exponential moving average filter
static ema_f32_t LM35D_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iLM35D_EMA_K                                    // Exponential smoothing factor
};

#elif   iLM35D_ma == iWMA                               // Weighted moving average filter
static float32 LM35D_wma_buf[iLM35D_WMA_num];
static wma_f32_t LM35D_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iLM35D_WMA_num ,                                // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iLM35D_WMA_num * (iLM35D_WMA_num + 1)/2 ,       // kn sum
        &LM35D_wma_buf[0]                               // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_LM35D =
{
        iLM35D                  ,
        iLM35D_pin              ,
        iLM35D_xoff             ,
        iLM35D_yoff             ,
        iLM35D_gain             ,
        iLM35D_max              ,
        iLM35D_min              ,
        iLM35D_ma               ,
        
#if     iLM35D_ma == iSMA                               // Simple moving average filter
        &LM35D_Phy_SMA          ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35D_ma == iEMA                               // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &LM35D_Phy_EMA          ,
        (wma_f32_t*)iDummy_adr
#elif   iLM35D_ma == iWMA                               // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &LM35D_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
