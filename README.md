# TERMAK
**Termak** (a made-up word that means **mini-terminal**) is a STUPID VTE-based terminal emulator.

*It has no superiority over other terminals and is developed for personal purposes only!*

*No support for tabs or other bells and whistles are implemnted.*

## Dependencies
- libglib-dev
- libgtk-dev
- libvte-dev

## Installing
`gcc termak.c $(pkg-config --cflags --libs vte-2.91) -o termak`

