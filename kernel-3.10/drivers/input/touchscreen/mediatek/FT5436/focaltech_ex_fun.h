#ifndef __FOCALTECH_EX_FUN_H__
#define __FOCALTECH_EX_FUN_H__

#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/semaphore.h>
#include <linux/mutex.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>

#include <linux/syscalls.h>
#include <asm/unistd.h>
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/string.h>

#define FT_UPGRADE_AA					0xAA
#define FT_UPGRADE_55 					0x55

/***********************0705 mshl*/
#define    BL_VERSION_LZ4        0
#define    BL_VERSION_Z7        1
#define    BL_VERSION_GZF        2

/*****************************************************************************/
#define PAGE_SIZE                                       1016
#define FTS_PACKET_LENGTH        		       128
#define FTS_SETTING_BUF_LEN      		128
#define FTS_DMA_BUF_SIZE 			4096

#define FTS_UPGRADE_LOOP				30

#define FTS_FACTORYMODE_VALUE			0x40
#define FTS_WORKMODE_VALUE			0x00

/*create sysfs for debug*/
int fts_create_sysfs(struct i2c_client * client);

void fts_release_sysfs(struct i2c_client * client);
#ifdef  FTS_GESTURE_PROC_MODE
int fts_create_apk_debug_channel(struct i2c_client *client);
void fts_release_apk_debug_channel(void);
#endif
#ifdef FTS_GESTURE_SYSFS_MODE
int fts_gesture_sysfs(struct i2c_client * client);
#endif
int fts_ctpm_auto_upgrade(struct i2c_client *client);

/*
*fts_write_reg- write register
*@client: handle of i2c
*@regaddr: register address
*@regvalue: register value
*
*/
int fts_i2c_Read(struct i2c_client *client, char *writebuf,int writelen, char *readbuf, int readlen);

int fts_i2c_Write(struct i2c_client *client, char *writebuf, int writelen);

int fts_write_reg(struct i2c_client * client,u8 regaddr, u8 regvalue);

int fts_read_reg(struct i2c_client * client,u8 regaddr, u8 *regvalue);

#endif