include $(BOARD_DIR)/firmware/firmware.mk


BOARDINC += $(BOARD_DIR)/generated/controllers/generated

# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

# this would save some flash while being unable to update WBO controller firmware
DDEFS += -DEFI_WIDEBAND_FIRMWARE_UPDATE=FALSE

# assign critical LED to a non-existent pin if you do not have it on your board
# good old PD14 is still the default value
# DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::I15

# EGT chip
#un-comment to enable
#DDEFS += -DEFI_MAX_31855=TRUE

#see main repo for details on this any many other optional subsystems. We have too many, one has to choose what fits into his choice of stm32
#DDEFS += -DEFI_ONBOARD_MEMS=TRUE

DDEFS += -DEFI_BLUETOOTH_SETUP=TRUE

# Primary UART: USART1 zamiast USART3 na PC10/PC11
DDEFS += -DTS_PRIMARY_PORT=UARTD1
DDEFS += -DSTM32_UART_USE_USART1=TRUE
DDEFS += -DEFI_CONSOLE_TX_BRAIN_PIN=Gpio::A9
DDEFS += -DEFI_CONSOLE_RX_BRAIN_PIN=Gpio::A10
DDEFS += -DEFI_CONSOLE_AF=7
