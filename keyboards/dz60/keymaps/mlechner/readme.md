# mlechner keymap for dz60

- hhkb style backspace
- macros for german umlaute

## Additional Notes

## Build

To build the default keymap, simply run `make dz60:mlechner`.

- `sudo dfu-programmer atmega32u4 erase`
- `sudo dfu-programmer atmega32u4 flash dz60_mlechner.hex`
- `sudo dfu-programmer atmega32u4 start`
