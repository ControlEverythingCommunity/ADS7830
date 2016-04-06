# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# ADS7830
# This code is designed to work with the ADS7830_I2CADC_I2CS I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7830_I2CADC#tabs-0-product_tabset-2

import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# ADS7830 address, 0x48(72)
# Send command byte
#		0x04(04)	Differential inputs, Channel-0, Channel-1 selected
bus.write_byte(0x48, 0x04)

time.sleep(0.5)

# ADS7830 address, 0x48(72)
# Read data back, 1 byte
data = bus.read_byte(0x48)

# Output data to screen
print "Digital value of analog input : %d" %data
