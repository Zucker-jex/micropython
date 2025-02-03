#define MICROPY_HW_BOARD_NAME               "ZLAB_H723ZG"
#define MICROPY_HW_MCU_NAME                 "STM32H723ZGT6"

#define MICROPY_HW_ENABLE_RTC               (1)
#define MICROPY_HW_ENABLE_RNG               (0) // RNG needs proper configuration
#define MICROPY_HW_ENABLE_ADC               (1)
#define MICROPY_HW_ENABLE_DAC               (1)
#define MICROPY_HW_ENABLE_USB               (1)
#define MICROPY_HW_ENABLE_SDCARD            (1)
#define MICROPY_HW_HAS_SWITCH               (1)
#define MICROPY_HW_HAS_FLASH                (1)

#define MICROPY_BOARD_EARLY_INIT            ZLAB_H723ZG_board_early_init
void ZLAB_H723ZG_board_early_init(void);

// There is no external HS crystal, instead it comes from ST-LINK MCO output which is 8MHz.
// The following gives a 550MHz CPU speed.
// #define MICROPY_HW_CLK_USE_BYPASS           (1)
// #define MICROPY_HW_CLK_PLLM                 (4)
// #define MICROPY_HW_CLK_PLLN                 (275)
// #define MICROPY_HW_CLK_PLLP                 (1)
// #define MICROPY_HW_CLK_PLLQ                 (4)
// #define MICROPY_HW_CLK_PLLR                 (2)
// #define MICROPY_HW_CLK_PLLVCI               (RCC_PLL1VCIRANGE_1)
// #define MICROPY_HW_CLK_PLLVCO               (RCC_PLL1VCOWIDE)
// #define MICROPY_HW_CLK_PLLFRAC              (0)

// The USB clock is set using PLL3
// #define MICROPY_HW_CLK_PLL3M                (4)
// #define MICROPY_HW_CLK_PLL3N                (120)
// #define MICROPY_HW_CLK_PLL3P                (2)
// #define MICROPY_HW_CLK_PLL3Q                (5)
// #define MICROPY_HW_CLK_PLL3R                (2)
// #define MICROPY_HW_CLK_PLL3VCI              (RCC_PLL3VCIRANGE_1)
// #define MICROPY_HW_CLK_PLL3VCO              (RCC_PLL3VCOWIDE)
// #define MICROPY_HW_CLK_PLL3FRAC             (0)

// 使用外部 25MHz HSE
#define MICROPY_HW_CLK_USE_BYPASS           (0)  // 使用晶振而非直接外部时钟输入

// 主 PLL 配置
#define MICROPY_HW_CLK_PLLM                 (5)   // HSE 25MHz / 5 = 5MHz
#define MICROPY_HW_CLK_PLLN                 (220) // 5MHz * 220 = 1100MHz
#define MICROPY_HW_CLK_PLLP                 (2)   // 1100MHz / 2 = 550MHz
#define MICROPY_HW_CLK_PLLQ                 (4)   // 1100MHz / 4 = 275MHz
#define MICROPY_HW_CLK_PLLR                 (2)   // 1100MHz / 2 = 550MHz
#define MICROPY_HW_CLK_PLLVCI               (RCC_PLL1VCIRANGE_2) // 输入频率范围为 4-8MHz
#define MICROPY_HW_CLK_PLLVCO               (RCC_PLL1VCOWIDE)    // 宽 VCO 范围
#define MICROPY_HW_CLK_PLLFRAC              (0)   // 无小数分频

// USB 时钟配置 (PLL3，用于生成 48MHz)
#define MICROPY_HW_CLK_PLL3M                (5)   // HSE 25MHz / 5 = 5MHz
#define MICROPY_HW_CLK_PLL3N                (240) // 5MHz * 240 = 1200MHz
#define MICROPY_HW_CLK_PLL3P                (2)   // 无需配置
#define MICROPY_HW_CLK_PLL3Q                (25)  // 1200MHz / 25 = 48MHz
#define MICROPY_HW_CLK_PLL3R                (2)   // 无需配置
#define MICROPY_HW_CLK_PLL3VCI              (RCC_PLL3VCIRANGE_2) // 输入频率范围为 4-8MHz
#define MICROPY_HW_CLK_PLL3VCO              (RCC_PLL3VCOWIDE)    // 宽 VCO 范围
#define MICROPY_HW_CLK_PLL3FRAC             (0)   // 无小数分频

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY            FLASH_LATENCY_4

// The board has an external 32kHz crystal attached
#define MICROPY_HW_RTC_USE_LSE              (1)

// UART config
#define MICROPY_HW_UART1_TX                 (pin_B6)
#define MICROPY_HW_UART1_RX                 (pin_B7)
// #define MICROPY_HW_UART1_RTS                (pin_A12)
// #define MICROPY_HW_UART1_CTS                (pin_A11)
// #define MICROPY_HW_UART2_TX                 (pin_D5)
// #define MICROPY_HW_UART2_RX                 (pin_D6)
// #define MICROPY_HW_UART2_RTS                (pin_D4)
// #define MICROPY_HW_UART2_CTS                (pin_D3)
// #define MICROPY_HW_UART3_TX                 (pin_D8)
// #define MICROPY_HW_UART3_RX                 (pin_D9)
// #define MICROPY_HW_UART5_TX                 (pin_B6)
// #define MICROPY_HW_UART5_RX                 (pin_B12)
// #define MICROPY_HW_UART6_TX                 (pin_C6)
// #define MICROPY_HW_UART6_RX                 (pin_C7)
// #define MICROPY_HW_UART7_TX                 (pin_F7)
// #define MICROPY_HW_UART7_RX                 (pin_F6)
// #define MICROPY_HW_UART8_TX                 (pin_E1)
// #define MICROPY_HW_UART8_RX                 (pin_E0)

#define MICROPY_HW_UART_REPL                PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD           115200

// I2C buses
#define MICROPY_HW_I2C4_SCL                 (pin_B8)
#define MICROPY_HW_I2C4_SDA                 (pin_B9)
// #define MICROPY_HW_I2C1_SCL                 (pin_B8)
// #define MICROPY_HW_I2C1_SDA                 (pin_B9)
// #define MICROPY_HW_I2C2_SCL                 (pin_F1)
// #define MICROPY_HW_I2C2_SDA                 (pin_F0)
// #define MICROPY_HW_I2C4_SCL                 (pin_F14)
// #define MICROPY_HW_I2C4_SDA                 (pin_F15)

// SPI buses
// #define MICROPY_HW_SPI3_NSS                 (pin_A4)
// #define MICROPY_HW_SPI3_SCK                 (pin_B3)
// #define MICROPY_HW_SPI3_MISO                (pin_B4)
// #define MICROPY_HW_SPI3_MOSI                (pin_B5)

// USRSW is pulled high. Pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN                (pin_G15)
#define MICROPY_HW_USRSW_PULL               (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE          (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED            (0)

// LEDs
#define MICROPY_HW_LED1                     (pin_G8)
#define MICROPY_HW_LED2                     (pin_G7)
// #define MICROPY_HW_LED3                     (pin_B14)
#define MICROPY_HW_LED_ON(pin)              (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)             (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_HS                   (1)
#define MICROPY_HW_USB_HS_IN_FS             (1)
// #define MICROPY_HW_USB_MAIN_DEV             (USB_PHY_FS_ID)
#define MICROPY_HW_USB_VBUS_DETECT_PIN      (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN           (pin_A10)

// FDCAN bus
// #define MICROPY_HW_CAN1_NAME                "FDCAN1"
// #define MICROPY_HW_CAN1_TX                  (pin_D1)
// #define MICROPY_HW_CAN1_RX                  (pin_D0)

// SD card detect switch
// #define MICROPY_HW_SDCARD_DETECT_PIN        (0)
// #define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
// #define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)

// Ethernet via RMII
// #define MICROPY_HW_ETH_MDC                  (pin_C1)
// #define MICROPY_HW_ETH_MDIO                 (pin_A2)
// #define MICROPY_HW_ETH_RMII_REF_CLK         (pin_A1)
// #define MICROPY_HW_ETH_RMII_CRS_DV          (pin_A7)
// #define MICROPY_HW_ETH_RMII_RXD0            (pin_C4)
// #define MICROPY_HW_ETH_RMII_RXD1            (pin_C5)
// #define MICROPY_HW_ETH_RMII_TX_EN           (pin_G11)
// #define MICROPY_HW_ETH_RMII_TXD0            (pin_G13)
// #define MICROPY_HW_ETH_RMII_TXD1            (pin_B13)

// Use external SPI flash for storage
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE         (1)
#define MICROPY_HW_SPIFLASH_SOFT_RESET           (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)

// SPI Flash 64MBits
#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
#define MICROPY_HW_SPI_PRESCALER           (2) // 100MHz
#define MICROPY_HW_SPIFLASH_SIZE_BITS_LOG2 (27)
#define MICROPY_HW_SPIFLASH_SIZE_BITS   (120 * 1024 * 1024)
#define MICROPY_HW_SPIFLASH_CS         (pin_G6)
#define MICROPY_HW_SPIFLASH_SCK        (pin_F10)
#define MICROPY_HW_SPIFLASH_IO0        (pin_F8)
#define MICROPY_HW_SPIFLASH_IO1        (pin_F9)
#define MICROPY_HW_SPIFLASH_IO2        (pin_F7)
#define MICROPY_HW_SPIFLASH_IO3        (pin_F6)

// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_SPIFLASH    (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev)
#endif

// #define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)
// #define MICROPY_HW_ENABLE_EXTERNAL_SRAM_STORAGE  (1)
// #define MICROPY_HW_EXTERNAL_SRAM_SIZE            (1 * 1024 * 1024) // 1MB
