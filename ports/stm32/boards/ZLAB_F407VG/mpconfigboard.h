#define MICROPY_HW_BOARD_NAME       "ZLAB_F407VG"
#define MICROPY_HW_MCU_NAME         "STM32F407VG"

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)

#define MICROPY_BOARD_EARLY_INIT    ZLAB_F407VG_board_early_init
void ZLAB_F407VG_board_early_init(void);

// HSE为25MHz
#define MICROPY_HW_CLK_USE_HSI (1)
#define MICROPY_HW_CLK_PLLM (16)
#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ (7)

// 32.768kHz LSE用于RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (0)

// UART配置
#define MICROPY_HW_UART1_NAME   "CH340N"
#define MICROPY_HW_UART1_TX     (pin_A9)    // CH340N RX
#define MICROPY_HW_UART1_RX     (pin_A10)   // CH340N TX
#define MICROPY_HW_UART2_NAME   "ESP32"
#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)

#define MICROPY_HW_UART_REPL                1
#define MICROPY_HW_UART_REPL_BAUD           115200

// I2C
#define MICROPY_HW_I2C1_NAME "I2C1"
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)
#define MICROPY_HW_I2C2_NAME "EEPROM"
#define MICROPY_HW_I2C2_SCL (pin_B10)
#define MICROPY_HW_I2C2_SDA (pin_B11)

// SPI
#define MICROPY_HW_SPI1_NAME "SPI1"
#define MICROPY_HW_SPI1_NSS  (pin_A4)
#define MICROPY_HW_SPI1_SCK  (pin_A5)
#define MICROPY_HW_SPI1_MISO (pin_A6)
#define MICROPY_HW_SPI1_MOSI (pin_A7)
#define MICROPY_HW_SPI2_NAME "FLASH"
#define MICROPY_HW_SPI2_NSS  (pin_B12)
#define MICROPY_HW_SPI2_SCK  (pin_B13)
#define MICROPY_HW_SPI2_MISO (pin_B14)
#define MICROPY_HW_SPI2_MOSI (pin_B15)

// SD卡（SDIO）
#define MICROPY_HW_SDCARD_SDIO        (1)
#define MICROPY_HW_SDCARD_CK          (pin_C12)
#define MICROPY_HW_SDCARD_CMD         (pin_D2)
#define MICROPY_HW_SDCARD_D0          (pin_C8)
#define MICROPY_HW_SDCARD_D1          (pin_C9)
#define MICROPY_HW_SDCARD_D2          (pin_C10)
#define MICROPY_HW_SDCARD_D3          (pin_C11)

// 用户按键
#define MICROPY_HW_USRSW_PIN        (pin_E8)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLDOWN)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (1) // 按下为高电平

// LED（低电平点亮）
#define MICROPY_HW_LED1             (pin_A0)
#define MICROPY_HW_LED2             (pin_A1)
#define MICROPY_HW_LED3             (pin_E13)
#define MICROPY_HW_LED4             (pin_E14)
#define MICROPY_HW_LED5             (pin_E15)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// 蜂鸣器（高电平响）
#define MICROPY_HW_BUZZER_PIN       (pin_A8)
#define MICROPY_HW_BUZZER_ON(pin)   (mp_hal_pin_high(pin))
#define MICROPY_HW_BUZZER_OFF(pin)  (mp_hal_pin_low(pin))

// USB
#define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_FS_VBUS_DETECT_PIN (0)
#define MICROPY_HW_USB_FS_ID_DETECT_PIN   (0)

// 片外Flash参数
#if !MICROPY_HW_SPIFLASH_SIZE_BYTES
// Use internal filesystem if spiflash not enabled.
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)

#else
// Reserve SPI flash bus (use SPI2 for external SPI flash).
#define MICROPY_HW_SPI_IS_RESERVED(id)  (id == 2)

// Disable internal filesystem to use spiflash.
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (0)

// Ensure SPI2 pins are defined for the spiflash driver.
#define SPI2_NSS  (pin_B12)
#define SPI2_SCK  (pin_B13)
#define SPI2_MISO (pin_B14)
#define SPI2_MOSI (pin_B15)

// SPI flash pins
#define MICROPY_HW_SPIFLASH_CS          (SPI2_NSS)
#define MICROPY_HW_SPIFLASH_SCK         (SPI2_SCK)
#define MICROPY_HW_SPIFLASH_MOSI        (SPI2_MOSI)
#define MICROPY_HW_SPIFLASH_MISO        (SPI2_MISO)

extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)
#define MICROPY_HW_BDEV_SPIFLASH    (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol
#define MICROPY_HW_SPIFLASH_SIZE_BITS (MICROPY_HW_SPIFLASH_SIZE_BYTES * 8)
#endif

// VCAP电容
#define MICROPY_HW_VCAP_1             (pin_C3)
#define MICROPY_HW_VCAP_2             (pin_C2)

// VBAT
#define MICROPY_HW_VBAT               (pin_C5)
