# zephyr_thread

Example Zephyr application that creates two execution threads to toggle two LEDs on the nRF54L15 DK kit.

## Description

The application uses:

- `thread_led0`: toggles `led0` every 500 ms
- `thread_led1`: toggles `led1` every 1000 ms

The LEDs are configured as GPIO outputs in `main.c` and are controlled by independent threads.

## Structure

- `src/main.c`: main application logic and thread creation
- `CMakeLists.txt`: Zephyr project configuration
- `prj.conf`: project configuration
- `build_54dk/`: build directory generated for the `nrf54l15dk` board

## Requirements

- Zephyr RTOS / nRF Connect SDK installed
- nRF build toolchain
- Board compatible with `nrf54l15dk`

## Build

From the project root:

```bash
west build -b nrf54l15dk -d build_54dk .
```

## Flash

```bash
west flash -d build_54dk
```

## Expected result

After loading the application onto the device, the `led0` and `led1` LEDs should blink at different frequencies:

- `led0`: every 500 ms
- `led1`: every 1000 ms

## Key files

- [src/main.c](src/main.c)
- [CMakeLists.txt](CMakeLists.txt)
- [prj.conf](prj.conf)
