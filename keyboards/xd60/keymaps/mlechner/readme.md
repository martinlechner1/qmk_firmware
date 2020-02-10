# mlechner Keymap for XIUDI's 60% XD60 PCB

## Additional Notes

-   hhkb style backspace
-   macros for german umlaute

## Build

To build the default keymap, simply run `make xd60/rev2:mlechner`.

-   `sudo dfu-programmer atmega32u4 erase`
-   `sudo dfu-programmer atmega32u4 flash xd60_rev2_mlechner.hex`
-   `sudo dfu-programmer atmega32u4 start`
