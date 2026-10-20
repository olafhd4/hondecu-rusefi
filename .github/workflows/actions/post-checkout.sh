#!/bin/bash
set -e

echo "Checking SDIO command diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
echo "Applying SDIO command diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
echo "Checking SDC connect-stage diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
echo "Applying SDC connect-stage diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
echo "Checking RCA mask patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
echo "Applying RCA mask patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
echo "Checking SDIO clock diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
echo "Applying SDIO clock diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
echo "Checking SD info diagnostics patch"
git -C ext/rusefi apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"
echo "Applying SD info diagnostics patch"
git -C ext/rusefi apply \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"

echo "Verifying SDIO command diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
echo "Verifying SDC connect-stage diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
echo "Verifying RCA mask patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
echo "Verifying SDIO clock diagnostics patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
echo "Verifying SD info diagnostics patch"
git -C ext/rusefi apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"
