#pragma once

#include <stdbool.h>
#include "epoll_timerfd_utilities.h"

#define LSM6DSO_ID         0x6C   // register value
#define LSM6DSO_ADDRESS	   0x6A	  // I2C Address
struct i2c_telemetry {
	float acceleration_mg[3];
	float angular_rate_dps[3];
	float lsm6dsoTemperature_degC;
	float pressure_hPa;
	float lps22hhTemperature_degC;
};

typedef struct i2c_telemetry i2c_telemetry;
void ReportTelemetry(i2c_telemetry receivedData);
i2c_telemetry i2cPoll(void);
int initI2c(void);
int setupDeviceAndStartPolling(void);
void closeI2c(void);

