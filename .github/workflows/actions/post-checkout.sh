#!/bin/bash
set -e

git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
git -C ext/rusefi/firmware/ChibiOS apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
git -C ext/rusefi apply --check \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"
git -C ext/rusefi apply \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"

git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdio-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-connect-diagnostics.patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-rca-mask.patch"
git -C ext/rusefi/firmware/ChibiOS apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdc-clock-diagnostics.patch"
git -C ext/rusefi apply --reverse --check \
  "$GITHUB_WORKSPACE/.github/patches/sdinfo-diagnostics.patch"
