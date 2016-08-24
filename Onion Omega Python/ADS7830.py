# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# ADS7830
# This code is designed to work with the ADS7830_I2CADC_I2CS I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7830_I2CADC#tabs-0-product_tabset-2

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# ADS7830 address, 0x48(72)
# Send command byte
#		0x04(04)	Differential inputs, Channel-0, Channel-1 selected
data = [0x04]
i2c.write(0x48, data)

time.sleep(0.5)

# ADS7830 address, 0x48(72)
# Read data back, 1 byte
data = i2c.readBytes(0x48, 0x00, 1)

# Output data to screen
print "Digital value of analog input : %d" %data[0]
