
#ifndef PCA9685_H_
#define PCA9685_H_

#include <cstdint>
#include <cstdio>
#include <thread>
#include <chrono>

#include <wiringPiI2C.h>
#include <unistd.h>        //Needed for I2C port
#include <fcntl.h>          //Needed for I2C port
#include <sys/ioctl.h>      //Needed for I2C port
#include <linux/i2c-dev.h>  //Needed for I2C port
#include <linux/i2c.h>      //Needed for I2C port

#define PCA9685_I2C_ADDRESS_DEFAULT	0x40
#define PCA9685_I2C_ADDRESS_FIXED	0x70
#define PCA9685_I2C_ADDRESSES_MAX	62

#define CHANNEL(x)	(static_cast<uint8_t>(x))
#define VALUE(x)	(static_cast<uint16_t>(x))

#define PCA9685_VALUE_MIN	VALUE(0)
#define PCA9685_VALUE_MAX	VALUE(4096)

#define PCA9685_PWM_CHANNELS	16

struct TPCA9685FrequencyRange {
	static constexpr uint32_t MIN = 24;
	static constexpr uint32_t MAX = 1526;
};

enum TPCA9685Och {
	PCA9685_OCH_STOP = 0,
	PCA9685_OCH_ACK = 1 << 3
};

class PCA9685 {
public:
	PCA9685(uint8_t nAddress = PCA9685_I2C_ADDRESS_DEFAULT);
	~PCA9685() {};

	void SetPreScaller(uint8_t);
	uint8_t GetPreScaller();

	void SetFrequency(uint16_t);
	uint16_t GetFrequency();

	void SetOCH(TPCA9685Och);
	TPCA9685Och GetOCH();

	void SetInvert(bool);
	bool GetInvert();

	void SetOutDriver(bool);
	bool GetOutDriver();

	void Write(uint8_t, uint16_t, uint16_t);
	void Read(uint8_t, uint16_t *, uint16_t *);

	void Write(uint16_t, uint16_t);
	void Read(uint16_t *, uint16_t *);

	void Write(uint8_t, uint16_t);
	void Write(uint16_t);

	void SetFullOn(uint8_t, bool);
	void SetFullOff(uint8_t, bool);

	void Dump();

private:
	uint8_t CalcPresScale(uint16_t);
	uint16_t CalcFrequency(uint8_t);
	int fd;

private:
	void Sleep(bool);
	void AutoIncrement(bool);

private:
	bool I2cSetup();

	void I2cWriteReg(uint8_t, uint8_t);
	uint8_t I2cReadReg(uint8_t);

	void I2cWriteReg(uint8_t, uint16_t);
	uint16_t I2cReadReg16(uint8_t);

	void I2cWriteReg(uint8_t, uint16_t, uint16_t);

private:
	uint8_t m_nAddress;
};

#endif /* PCA9685_H_ */
