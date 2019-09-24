#pragma once

#include <stdbool.h>
#include "epoll_timerfd_utilities.h"
#include <applibs/gpio.h>

#define LSM6DSO_ID         0x6C   // register value
#define LSM6DSO_ADDRESS	   0x6A	  // I2C Address
struct i2c_telemetry {
	float acceleration_mg[3];
	float angular_rate_dps[3];
	float lsm6dsoTemperature_degC;
	float pressure_hPa;
	float lps22hhTemperature_degC;
};

struct lint_telemetry {
	GPIO_Value_Type input;
};

static int lintInfraredLedGpioFd = -1;
static int lintInfraredSensorGpioFd = -1;

typedef struct i2c_telemetry i2c_telemetry;
typedef struct lint_telemetry lint_telemetry;
void DeviceEventHandler(EventData* eventData);
void ReportTelemetry(i2c_telemetry receivedData, lint_telemetry lintData);
lint_telemetry sense_lint();
i2c_telemetry i2cPoll(void);
int initI2c(void);
int initLint(void);
int setupDeviceAndStartPolling(void);
void closeI2c(void);

