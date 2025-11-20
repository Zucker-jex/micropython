#include "py/mphal.h"
#include "storage.h"
// #include "stm32h7xx_hal.h"

// void MX_FMC_Init(void) {
//     SRAM_HandleTypeDef hsram = {0};
//     FMC_NORSRAM_TimingTypeDef Timing = {0};

//     hsram.Instance = FMC_NORSRAM_DEVICE;
//     hsram.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
//     hsram.Init.NSBank = FMC_NORSRAM_BANK1;        // 使用Bank1 (NE3对应地址0x60000000)
//     hsram.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
//     hsram.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16; // 16位数据宽度
//     hsram.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;

//     // 时序配置（假设FMC时钟100MHz，周期10ns）
//     Timing.AddressSetupTime = 5;      // 50ns (满足tSA=55ns)
//     Timing.DataSetupTime = 1;         // 10ns (总tRC=50+10=60ns > 55ns)
//     Timing.AccessMode = FMC_ACCESS_MODE_A;

//     HAL_SRAM_Init(&hsram, &Timing, NULL);
// }

void ZLAB_H723ZG_board_early_init(void) {
    // // 初始化GPIO和FMC
    // MX_GPIO_Init();
    // MX_FMC_Init();

    // // 简单测试SRAM访问
    // volatile uint16_t *sram = (volatile uint16_t*)0x60000000;
    // sram[0] = 0xA5A5;
    // if (sram[0] != 0xA5A5) {
    //     // 初始化失败处理
    //     while(1);
    // }
    // 关闭USB开关
    // mp_hal_pin_output(pyb_pin_OTG_FS_POWER);
    // mp_hal_pin_low(pyb_pin_OTG_FS_POWER);
    mp_hal_stdout_tx_str("Board early init...\n");
}

// static void MX_GPIO_Init(void) {
//     GPIO_InitTypeDef GPIO_InitStruct = {0};

//     /* 使能所有相关GPIO时钟 */
//     __HAL_RCC_GPIOA_CLK_ENABLE();
//     __HAL_RCC_GPIOB_CLK_ENABLE();
//     __HAL_RCC_GPIOC_CLK_ENABLE();
//     __HAL_RCC_GPIOD_CLK_ENABLE();
//     __HAL_RCC_GPIOE_CLK_ENABLE();
//     __HAL_RCC_GPIOF_CLK_ENABLE();
//     __HAL_RCC_GPIOG_CLK_ENABLE();

//     /* 公共配置：复用推挽，无上下拉，高速模式 */
//     GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//     GPIO_InitStruct.Pull = GPIO_NOPULL;
//     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//     GPIO_InitStruct.Alternate = GPIO_AF12_FMC;

//     /******************** 地址线配置 ********************/
//     // A0-A4 (PF0-PF4)
//     GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;
//     HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//     // A5 (PE5)
//     GPIO_InitStruct.Pin = GPIO_PIN_5;
//     HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

//     // A6-A9 (PF12-PF15)
//     GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//     HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

//     // A10-A15 (PG0-PG5)
//     GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5;
//     HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

//     // A16-A18 (PD11-PD13)
//     GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13;
//     HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

//     /******************** 数据线配置 ********************/
//     // D0-D15 配置（16位总线）
//     // D0 (PD14), D1 (PD15), D2 (PD0), D3 (PD1)
//     GPIO_InitStruct.Pin = GPIO_PIN_14 | GPIO_PIN_15 | GPIO_PIN_0 | GPIO_PIN_1;
//     HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

//     // D4-D7 (PE7-PE10)
//     GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
//     HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

//     // D8-D12 (PE11-PE15)
//     GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
//     HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

//     // D13-D15 (PD8-PD10)
//     GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
//     HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

//     /******************** 控制信号配置 ********************/
//     // NE3 (PG10)
//     GPIO_InitStruct.Pin = GPIO_PIN_10;
//     HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

//     // NOE (PD4)
//     GPIO_InitStruct.Pin = GPIO_PIN_4;
//     HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

//     // NWE (PD5)
//     GPIO_InitStruct.Pin = GPIO_PIN_5;
//     HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

//     // NBL0 (PE0), NBL1 (PE1)
//     GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1;
//     HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
// }
