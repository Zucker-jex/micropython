MCU_SERIES = f4
CMSIS_MCU = STM32F407xx
AF_FILE = boards/stm32f405_af.csv
ifeq ($(USE_MBOOT),1)
# When using Mboot all the text goes together after the filesystem
LD_FILES = boards/stm32f405.ld boards/common_blifs.ld
TEXT0_ADDR = 0x08020000
else
# When not using Mboot the ISR text goes first, then the rest after the filesystem
LD_FILES = boards/stm32f405.ld boards/common_ifs.ld
TEXT0_ADDR = 0x08000000
TEXT1_ADDR = 0x08020000
endif

ifdef SPI_FLASH_SIZE_MB
BUILD := $(BUILD)_FLASH_$(SPI_FLASH_SIZE_MB)M
endif

# MicroPython settings
MICROPY_VFS_LFS2 = 1

# PYB-specific frozen modules
FROZEN_MANIFEST ?= $(BOARD_DIR)/manifest.py

SPI_FLASH_SIZE_MB ?= 32

# If SPI flash size is provided via make (SPI_FLASH_SIZE_MB), define the
# MICROPY_HW_SPIFLASH_SIZE_BYTES macro so the board header can enable
# external SPI flash support.
ifdef SPI_FLASH_SIZE_MB
CFLAGS += -DMICROPY_HW_SPIFLASH_SIZE_BYTES="($(SPI_FLASH_SIZE_MB) * 1024 * 1024)"
endif
