#include "py/mphal.h"
#include "storage.h"

void ZLAB_H743II_board_early_init(void) {
    // 关闭USB开关
    // mp_hal_pin_output(pyb_pin_OTG_FS_POWER);
    // mp_hal_pin_low(pyb_pin_OTG_FS_POWER);
    mp_hal_stdout_tx_str("Board early init...\n");
}
