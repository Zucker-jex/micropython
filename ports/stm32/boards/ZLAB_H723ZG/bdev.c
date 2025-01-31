#include "py/obj.h"
#include "storage.h"
#include "spi.h"

#if MICROPY_HW_SPIFLASH_ENABLE_CACHE
// Shared cache for first and second SPI block devices
static mp_spiflash_cache_t spi_bdev_cache;
#endif

// First external SPI flash uses hardware SPI interface
const mp_spiflash_config_t spiflash_config = {
    .bus_kind = MP_SPIFLASH_BUS_SPI,
    .bus.u_spi.data = NULL,
    .bus.u_spi.proto = &spi_proto,
    #if MICROPY_HW_SPIFLASH_ENABLE_CACHE
    .cache = &spi_bdev_cache,
    #endif
};

spi_bdev_t spi_bdev;
