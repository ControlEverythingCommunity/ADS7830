// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// ADS7830
// This code is designed to work with the ADS7830_I2CADC I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Analog-Digital-Converters?sku=ADS7830_I2CADC#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if ((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, ADS7830 I2C address is 0x48(72)
	ioctl(file, I2C_SLAVE, 0x48);

	// Differential inputs, Channel-0, Channel-1 selected
	char config[1] = {0x04};
	write(file, config, 1);
	sleep(1);

	// Read 1 byte of data
	char data[1]={0};
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
	}
	else 
	{
		// Convert the data
		int raw_adc = data[0];

		// Output data to screen
		printf("Digital value of analog input: %d \n", raw_adc);
	}
}