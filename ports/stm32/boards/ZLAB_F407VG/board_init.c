#include "py/mphal.h"
#include "storage.h"

void ZLAB_F407VG_board_early_init(void) {
    mp_hal_stdout_tx_str("Board early init...\n");
}
