/**
 * @file boards/hondecu/board.c
 *
 * @date Sep 05, 2026
 * @author Hondecu Board Configuration
 */

#include "hal.h"
#if !defined(EFI_SIMULATOR)
#include "hal_community.h"
#endif
#include "unused.h"

#include "board.h"

/**
 * @brief Board-specific initialization.
 */
#if !defined(EFI_SIMULATOR)
void boardInit(void) {
	/* STM32F4xx HAL initialization */
	stm32_gpio_init();
	stm32_clock_init();
}
#else
void boardInit(void) {
	/* Simulator doesn't need hardware initialization */
}
#endif

#if !defined(EFI_SIMULATOR) && (HAL_USE_SDC || defined(__DOXYGEN__))
/**
 * @brief SDC card detection.
 */
bool sdc_lld_is_card_inserted(SDCDriver *sdcp)
{
	UNUSED(sdcp);
	/* SD card is always present on this board */
	return true;
}

/**
 * @brief SDC card write protection detection.
 */
bool sdc_lld_is_write_protected(SDCDriver *sdcp)
{
	UNUSED(sdcp);
	/* SD card is not write protected */
	return false;
}
#endif /* HAL_USE_SDC */

#if !defined(EFI_SIMULATOR) && (HAL_USE_MMC_SPI || defined(__DOXYGEN__))
/**
 * @brief MMC_SPI card detection.
 */
bool mmc_lld_is_card_inserted(MMCDriver *mmcp)
{
	UNUSED(mmcp);
	/* TODO: Fill the implementation.*/
	return true;
}

/**
 * @brief MMC_SPI card write protection detection.
 */
bool mmc_lld_is_write_protected(MMCDriver *mmcp)
{
	UNUSED(mmcp);
	/* TODO: Fill the implementation.*/
	return false;
}
#endif /* HAL_USE_MMC_SPI */
