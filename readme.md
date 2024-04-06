# fp-qmk-firmware

- this is the fp fork of the QMK firmware
- this fork is for the purposes of editing keymaps and reflashing the firmware for the following keyboards:
    - Redox Wireless
    - XD75
    - others to come

## General Instructions for flashing

- Requirements
    - `QMK_MSYS.exe`
    - `qmk_toolbox.exe`
    - a local clone of the `qmk_firmware` repo

## Other notes (fp-)

- [Keycode docss](docs\keycodes.md)

### Wireless Redox

- [Link to Wireless Redox keymap](keyboards\redox\keymaps\fp-redox\keymap.c)

1. update [keymapping](keyboards\redox\keymaps\fp-redox\keymap.c) linked above with changes
2. compile and build the firmware using `QMK_MSYS.exe`
    1. command: `qmk compile -kb redox/wireless -km fp-redox`
3. flash the firmware to the controller using `qmk_toolbox.exe`

### XD75

- [Link to XD75 keymap](keyboards\xiudi\xd75\keymaps\fp-xd75\keymap.c)

1. update [keymapping](keyboards\redox\keymaps\fp-redox\keymap.c) linked above with changes
2. compile and build the firmware using `QMK_MSYS.exe`
    1. command: `qmk compile -kb xiudi/xd75 -km fp-xd75`
3. flash the firmware to the controller using `qmk_toolbox.exe`

## Quantum Mechanical Keyboard Firmware

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the Clueboard product line.

## Documentation

* [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

* [Planck](/keyboards/planck/)
* [Preonic](/keyboards/preonic/)
* [ErgoDox EZ](/keyboards/ergodox_ez/)
* [Clueboard](/keyboards/clueboard/)
* [Cluepad](/keyboards/clueboard/17/)
* [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
