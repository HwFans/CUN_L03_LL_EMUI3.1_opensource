################################################################################

1. How to Build
	- get Toolchain
		From android git server , codesourcery and etc ..
		 - arm-eabi-4.8

	- edit Makefile
		edit "CROSS_COMPILE" to right toolchain path(You downloaded).
		                                                                
		  EX)   CROSS_COMPILE= $(android platform directory you download)/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
          Ex)   CROSS_COMPILE=/usr/local/toolchain/arm-eabi-4.8/bin/arm-eabi-          // check the location of toolchain
		  or
		  Ex)	export CROSS_COMPILE=arm-eabi-
		  Ex)	export PATH=$PATH:<toolchain_parent_dir>/arm-eabi-4.8/bin

		$ make ARCH=arm hq6735_35u_b1n_l1_defconfig
		$ make ARCH=arm zImage

2. Output files
	- Kernel : arch/arm/boot/zImage
	- module : drivers/*/*.ko

3. How to Clean
		$ make ARCH=arm distclean
################################################################################