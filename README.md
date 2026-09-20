# oversteel-qmk
QMK firmware for Oversteel Titanium Red (105-keys).  
To make use of this, you need to follow the [SonixQMK Docs](https://sonixqmk.github.io//SonixDocs/install/). Linux user should use the [SonixFlasherC](https://github.com/SonixQMK/SonixFlasherC) to flash the firmware
Using stock QMK without following the documentation above will produce a firmware not compatible with the Sonix fork of QMK.

Firmware should be feature complete

## Side LED fix — core patch required

To build this firmware with the side LED fixes applied, you need to apply the patch in
[`patches/side-leds-gb-swap-core.patch`](patches/side-leds-gb-swap-core.patch) to your
**SonixQMK core checkout** (not to this repository) before compiling. This patch modifies
`drivers/led/sn32/rgb_matrix_sn32f24xb.c` to swap the G/B channels for LED indices 106-111
(the side LEDs), which are wired with inverted green/blue pins on the PCB.

Without applying this patch, the firmware will still compile and work normally, but the
6 side LEDs will show green and blue swapped.

To apply it:

```bash
cd /path/to/your/qmk_firmware
git apply /path/to/oversteel-titanium-qmk/patches/side-leds-gb-swap-core.patch
```
