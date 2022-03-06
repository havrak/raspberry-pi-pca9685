# PCA9685 library for Raspberry Pi3

This library is a fork of [PCA9685 library made by vanvught](https://github.com/vanvught/rpidmx512/tree/master/lib-pca9685).
I have just rewritten read/write functions to call those in WiringPi.
Since using WiringPi and bcm2835 at the same time has lead to collision in timeing.

This library has all the servo functionality the original had.
I didn't bother to deal with LED support.

Since second half of 2021 wiringPi is no longer in standart repositories.
If you wish to use this library please use the [unofficial fork](https://github.com/WiringPi/WiringPi).

