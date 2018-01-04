openocd -f /usr/share/openocd/scripts/board/stm32f3discovery.cfg -f openocd/stm32f3-openocd.cfg -c "stm_flash `pwd`/main.bin" -c shutdown
