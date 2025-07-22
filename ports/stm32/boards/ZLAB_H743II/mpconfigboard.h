#define MICROPY_HW_BOARD_NAME       "ZLAB_H743II"
#define MICROPY_HW_MCU_NAME         "STM32H743IIT6"

#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_SPI       (1)
#define MICROPY_HW_SPIFLASH_ENABLED (1)

#define MICROPY_BOARD_EARLY_INIT    ZLAB_H743II_board_early_init
void ZLAB_H743II_board_early_init(void);

// The board has a 25MHz HSE, the following gives 400MHz CPU speed
#define MICROPY_HW_CLK_USE_BYPASS   (0)

#define MICROPY_HW_CLK_PLLM         (5)   // 25MHz / 5 = 5MHz
#define MICROPY_HW_CLK_PLLN         (160) // 5MHz * 160 = 800MHz
#define MICROPY_HW_CLK_PLLP         (2)   // 800MHz / 2 = 400MHz
#define MICROPY_HW_CLK_PLLQ         (4)   // 800MHz / 4 = 200MHz
#define MICROPY_HW_CLK_PLLR         (2)   // 800MHz / 2 = 400MHz
#define MICROPY_HW_CLK_PLLVCI       (RCC_PLL1VCIRANGE_2) // VCI range for 4-8 MHz
#define MICROPY_HW_CLK_PLLVCO       (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC      (0)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M        (5)   // 25MHz / 5 = 5MHz
#define MICROPY_HW_CLK_PLL3N        (240) // 5MHz * 240 = 1200MHz
#define MICROPY_HW_CLK_PLL3P        (2)   // 1200MHz / 2 = 600MHz
#define MICROPY_HW_CLK_PLL3Q        (5)   // 1200MHz / 5 = 240MHz
#define MICROPY_HW_CLK_PLL3R        (2)   // 1200MHz / 2 = 600MHz
#define MICROPY_HW_CLK_PLL3VCI      (RCC_PLL3VCIRANGE_2) // VCI range for 4-8 MHz
#define MICROPY_HW_CLK_PLL3VCO      (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC     (0)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// The board has an external 32kHz crystal attached
#define MICROPY_HW_RTC_USE_LSE              (1)

// UART config
#define MICROPY_HW_UART1_TX         (pin_B6)
#define MICROPY_HW_UART1_RX         (pin_B7)
// #define MICROPY_HW_UART1_RTS        (pin_A12)
// #define MICROPY_HW_UART1_CTS        (pin_A11)
// #define MICROPY_HW_UART2_TX         (pin_D5)
// #define MICROPY_HW_UART2_RX         (pin_D6)
// #define MICROPY_HW_UART3_TX         (pin_D8)
// #define MICROPY_HW_UART3_RX         (pin_D9)
// #define MICROPY_HW_UART5_TX         (pin_B6)
// #define MICROPY_HW_UART5_RX         (pin_B12)
// #define MICROPY_HW_UART6_TX         (pin_C6)
// #define MICROPY_HW_UART6_RX         (pin_C7)
// #define MICROPY_HW_UART7_TX         (pin_F7)
// #define MICROPY_HW_UART7_RX         (pin_F6)
// #define MICROPY_HW_UART8_TX         (pin_E1)
// #define MICROPY_HW_UART8_RX         (pin_E0)

#define MICROPY_HW_UART_REPL        PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
#define MICROPY_HW_I2C1_SCL         (pin_B8)
#define MICROPY_HW_I2C1_SDA         (pin_B9)
// #define MICROPY_HW_I2C2_SCL         (pin_F1)
// #define MICROPY_HW_I2C2_SDA         (pin_F0)
// #define MICROPY_HW_I2C4_SCL         (pin_F14)
// #define MICROPY_HW_I2C4_SDA         (pin_F15)

// SPI buses
#define MICROPY_HW_SPI3_NSS         (pin_A4)
#define MICROPY_HW_SPI3_SCK         (pin_B3)
#define MICROPY_HW_SPI3_MISO        (pin_B4)
#define MICROPY_HW_SPI3_MOSI        (pin_B5)

// USRSW is pulled low. Pressing the button makes the input go high.
// #define MICROPY_HW_USRSW_PIN        (pin_C13)
// #define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
// #define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
// #define MICROPY_HW_USRSW_PRESSED    (1)

// LEDs
#define MICROPY_HW_LED1             (pin_H7)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USB config
#define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_HS_IN_FS        (1)
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)
#define MICROPY_HW_USB_FS_DP           (pin_A6)
#define MICROPY_HW_USB_FS_DM           (pin_A7)

// FDCAN bus
#define MICROPY_HW_CAN1_NAME  "FDCAN1"
#define MICROPY_HW_CAN1_TX    (pin_A12)
#define MICROPY_HW_CAN1_RX    (pin_A11)

// SD card detect switch
// #define MICROPY_HW_SDCARD_DETECT_PIN        (pin_G2)
// #define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
// #define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)

// Ethernet via RMII
// #define MICROPY_HW_ETH_MDC          (pin_C1)
// #define MICROPY_HW_ETH_MDIO         (pin_A2)
// #define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
// #define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
// #define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
// #define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)
// #define MICROPY_HW_ETH_RMII_TX_EN   (pin_G11)
// #define MICROPY_HW_ETH_RMII_TXD0    (pin_G13)
// #define MICROPY_HW_ETH_RMII_TXD1    (pin_B13)

// Use external SPI flash for storage
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE         (1)
#define MICROPY_HW_SPIFLASH_SOFT_RESET           (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)

// QSPI Flash 64MBits
// QSPI Flash 64MBits
#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
#define MICROPY_HW_QSPI_PRESCALER           (2) // 100MHz
#define MICROPY_HW_SPIFLASH_SIZE_BITS   (64 * 1024 * 1024)
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_QSPIFLASH_CS         (pin_B6)
#define MICROPY_HW_QSPIFLASH_SCK        (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0        (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1        (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2        (pin_E2)
#define MICROPY_HW_QSPIFLASH_IO3        (pin_D13)

// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_SPIFLASH    (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev)
#endif

// // Use external SDRAM
// #define MICROPY_HW_SDRAM_SIZE               (32 * 1024 * 1024)
// #define MICROPY_HW_SDRAM_STARTUP_TEST       (1)
// #define MICROPY_HEAP_START  ((sdram_valid) ? sdram_start() : &_heap_start)
// #define MICROPY_HEAP_END    ((sdram_valid) ? sdram_end() : &_heap_end)
// // Timing configuration for 240MHz/2=120MHz (8.3ns)
// #define MICROPY_HW_SDRAM_CLOCK_PERIOD       2
// #define MICROPY_HW_SDRAM_CAS_LATENCY        2
// #define MICROPY_HW_SDRAM_FREQUENCY          (120000) // 120 MHz
// #define MICROPY_HW_SDRAM_FREQUENCY_KHZ      (120000)
// #define MICROPY_HW_SDRAM_TIMING_TMRD        (2)
// #define MICROPY_HW_SDRAM_TIMING_TXSR        (8)
// #define MICROPY_HW_SDRAM_TIMING_TRAS        (6)
// #define MICROPY_HW_SDRAM_TIMING_TRC         (6)
// #define MICROPY_HW_SDRAM_TIMING_TWR         (2)
// #define MICROPY_HW_SDRAM_TIMING_TRP         (2)
// #define MICROPY_HW_SDRAM_TIMING_TRCD        (2)

// // 16-bit SDRAM
// #define MICROPY_HW_SDRAM_ROW_BITS_NUM       13
// #define MICROPY_HW_SDRAM_MEM_BUS_WIDTH      16
// #define MICROPY_HW_SDRAM_REFRESH_CYCLES     8192
// #define MICROPY_HW_SDRAM_COLUMN_BITS_NUM    9
// #define MICROPY_HW_SDRAM_INTERN_BANKS_NUM   4
// #define MICROPY_HW_SDRAM_RPIPE_DELAY        1
// #define MICROPY_HW_SDRAM_RBURST             (1)
// #define MICROPY_HW_SDRAM_WRITE_PROTECTION   (0)
// #define MICROPY_HW_SDRAM_AUTOREFRESH_NUM    (8)
// #define MICROPY_HW_SDRAM_BURST_LENGTH       1
// #define MICROPY_HW_SDRAM_REFRESH_RATE       (64) // ms

// #define MICROPY_HW_FMC_SDCKE0   (pin_H2)
// #define MICROPY_HW_FMC_SDNE0    (pin_H3)
// #define MICROPY_HW_FMC_SDCLK    (pin_G8)
// #define MICROPY_HW_FMC_SDNCAS   (pin_G15)
// #define MICROPY_HW_FMC_SDNRAS   (pin_F11)
// #define MICROPY_HW_FMC_SDNWE    (pin_H5)
// #define MICROPY_HW_FMC_BA0      (pin_G4)
// #define MICROPY_HW_FMC_BA1      (pin_G5)
// #define MICROPY_HW_FMC_NBL0     (pin_E0)
// #define MICROPY_HW_FMC_NBL1     (pin_E1)
// // #define MICROPY_HW_FMC_NBL2     (pin_I4)
// // #define MICROPY_HW_FMC_NBL3     (pin_I5)
// #define MICROPY_HW_FMC_A0       (pin_F0)
// #define MICROPY_HW_FMC_A1       (pin_F1)
// #define MICROPY_HW_FMC_A2       (pin_F2)
// #define MICROPY_HW_FMC_A3       (pin_F3)
// #define MICROPY_HW_FMC_A4       (pin_F4)
// #define MICROPY_HW_FMC_A5       (pin_F5)
// #define MICROPY_HW_FMC_A6       (pin_F12)
// #define MICROPY_HW_FMC_A7       (pin_F13)
// #define MICROPY_HW_FMC_A8       (pin_F14)
// #define MICROPY_HW_FMC_A9       (pin_F15)
// #define MICROPY_HW_FMC_A10      (pin_G0)
// #define MICROPY_HW_FMC_A11      (pin_G1)
// #define MICROPY_HW_FMC_A12      (pin_G2)
// #define MICROPY_HW_FMC_D0       (pin_D14)
// #define MICROPY_HW_FMC_D1       (pin_D15)
// #define MICROPY_HW_FMC_D2       (pin_D0)
// #define MICROPY_HW_FMC_D3       (pin_D1)
// #define MICROPY_HW_FMC_D4       (pin_E7)
// #define MICROPY_HW_FMC_D5       (pin_E8)
// #define MICROPY_HW_FMC_D6       (pin_E9)
// #define MICROPY_HW_FMC_D7       (pin_E10)
// #define MICROPY_HW_FMC_D8       (pin_E11)
// #define MICROPY_HW_FMC_D9       (pin_E12)
// #define MICROPY_HW_FMC_D10      (pin_E13)
// #define MICROPY_HW_FMC_D11      (pin_E14)
// #define MICROPY_HW_FMC_D12      (pin_E15)
// #define MICROPY_HW_FMC_D13      (pin_D8)
// #define MICROPY_HW_FMC_D14      (pin_D9)
// #define MICROPY_HW_FMC_D15      (pin_D10)
