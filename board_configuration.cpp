#include "pch.h"
#include "board_overrides.h"

void setupBoardHardwareTestOverrides();

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::D13; // MIL / warning LED on PD13
}

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

    // SD card on SPI3
    engineConfiguration->isSdCardEnabled = true;
    engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
    engineConfiguration->sdCardCsPin = Gpio::C9;
    engineConfiguration->is_enabled_spi_3 = true;
    engineConfiguration->spi3sckPin = Gpio::C10;
    engineConfiguration->spi3misoPin = Gpio::C11;
    engineConfiguration->spi3mosiPin = Gpio::C12;
}

void setup_custom_board_overrides() {
    setupBoardHardwareTestOverrides();
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
