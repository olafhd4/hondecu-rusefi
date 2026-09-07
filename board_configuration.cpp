#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::D13; // MIL / warning LED on PD13
}

// ============================================================ // SDIO DEBUG // ============================================================ static void debugSdioRegisters(const char* where) { efiPrintf("========== SDIO DEBUG: %s ==========", where); efiPrintf("GPIOC MODER = 0x%08X", GPIOC->MODER); efiPrintf("GPIOC AFR0 = 0x%08X", GPIOC->AFR[0]); efiPrintf("GPIOC AFR1 = 0x%08X", GPIOC->AFR[1]); efiPrintf("GPIOD MODER = 0x%08X", GPIOD->MODER); efiPrintf("GPIOD AFR0 = 0x%08X", GPIOD->AFR[0]); efiPrintf("GPIOD AFR1 = 0x%08X", GPIOD->AFR[1]); efiPrintf("SDIO POWER = 0x%08X", SDIO->POWER); efiPrintf("SDIO CLKCR = 0x%08X", SDIO->CLKCR); efiPrintf("SDIO STA = 0x%08X", SDIO->STA); efiPrintf("======================================"); }

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
    // Wtryski
    engineConfiguration->injectionPins[0] = Gpio::B8;   // INJ14 - PB8
    engineConfiguration->injectionPins[1] = Gpio::B9;   // INJ23 - PB9
    engineConfiguration->injectionPins[2] = Gpio::E13;   // INJ3 - PE13
    engineConfiguration->injectionPins[3] = Gpio::E14;   // INJ4 - PE14

    // Zapłon
    engineConfiguration->ignitionPins[0] = Gpio::A8;    // IGPLS - PA8

    // Trigger (TDC)
    engineConfiguration->triggerInputPins[0] = Gpio::A5;  // TDC - PA5 (TIM2_CH1_ETR)

    engineConfiguration->map.sensor.hwChannel = EFI_ADC_10;  // MAP   - PC0
    engineConfiguration->tps1_1AdcChannel    = EFI_ADC_11;   // TPS   - PC1
    engineConfiguration->iat.adcChannel      = EFI_ADC_2;    // IAT - PA2
    engineConfiguration->clt.adcChannel      = EFI_ADC_3;    // ECT   - PA3
    engineConfiguration->vbattAdcChannel     = EFI_ADC_12;   // VBatt - PC2

    // CAN
    engineConfiguration->canRxPin = Gpio::D0;
    engineConfiguration->canTxPin = Gpio::D1;

    // Podstawowe dzielniki
	engineConfiguration->analogInputDividerCoefficient = 1.5f;   // dla MAP/TPS/oil/fuel press na tych dzielnikach
	engineConfiguration->vbattDividerCoeff = 5.68f;                // dla VBAT 220k/47k
    engineConfiguration->adcVcc = 3.3f;

    engineConfiguration->clt.config.bias_resistor = 2490;
    engineConfiguration->iat.config.bias_resistor = 2490;

    // Aktywacja logowania na kartę SD (Hardware SDIO)
    engineConfiguration->isSdCardEnabled = true;
    engineConfiguration->sdCardSpiDevice = SPI_NONE; // Wyłączamy zapis po SPI
    engineConfiguration->sdCardCsPin = Gpio::Unassigned;    // Nie potrzebujemy pinu CS, bo SDIO ogarnia to sprzętowo
}

static void customBoardInitHardware() {
    // STM32F407 SDIO:
    // PC8  = SDIO_D0
    // PC9  = SDIO_D1
    // PC10 = SDIO_D2
    // PC11 = SDIO_D3
    // PC12 = SDIO_CK
    // PD2  = SDIO_CMD

    const uint32_t sdioMode =
        PAL_MODE_ALTERNATE(12) |
        PAL_STM32_OTYPE_PUSHPULL |
        PAL_STM32_OSPEED_HIGHEST;

    palSetPadMode(GPIOC, 8,  sdioMode); // D0
    palSetPadMode(GPIOC, 9,  sdioMode); // D1
    palSetPadMode(GPIOC, 10, sdioMode); // D2
    palSetPadMode(GPIOC, 11, sdioMode); // D3
    palSetPadMode(GPIOC, 12, sdioMode); // CK
    palSetPadMode(GPIOD, 2,  sdioMode); // CMD

    debugSdioRegisters("AFTER GPIO CONFIG");
}

void setup_custom_board_overrides() {
    custom_board_preHalInit = customBoardInitHardware;
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
