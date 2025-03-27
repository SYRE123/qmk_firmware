#pragma once

#define MATRIX_ROWS (5 * 2)
#define MATRIX_COLS (4 * 2)
#define MATRIX_ROW_PINS {GP4, GP5, GP6, GP7, GP8}
#define MATRIX_COL_PINS {GP29, GP28, GP27, GP26}
#define MATRIX_MASKED

#define SERIAL_USART_TX_PIN GP1
#define SPLIT_HAND_MATRIX_GRID GP26, GP6
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_X

#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define PMW33XX_CS_PIN GP21

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
