deps_config := \
	/home/esp32/esp32-loka-idf/esp-idf/components/app_trace/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/aws_iot/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/bt/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/esp32/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/ethernet/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/fatfs/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/freertos/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/heap/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/libsodium/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/log/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/lwip/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/mbedtls/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/openssl/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/pthread/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/spi_flash/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/spiffs/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/tcpip_adapter/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/wear_levelling/Kconfig \
	/home/esp32/esp32-loka-idf/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/esp32/esp32-loka-idf/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/esp32/esp32-loka-idf/esp-idf/examples/system/ota/main/Kconfig.projbuild \
	/home/esp32/esp32-loka-idf/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/esp32/esp32-loka-idf/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
