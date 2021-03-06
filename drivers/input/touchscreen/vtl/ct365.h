#ifndef CT365_H
#define CT365_H

#if 0
#define CT363M 		0x06

#define CT36X_TS_CHIP_DEBUG			1

/* max touch points supported */
#define CT36X_TS_POINT_NUM			10

#define CT36X_TS_ABS_X_MAX			1024
#define CT36X_TS_ABS_Y_MAX			768

#define CT36X_CHIP_FLASH_SECTOR_NUM	256
#define CT36X_CHIP_FLASH_SECTOR_SIZE	128
#define CT36X_CHIP_FLASH_SOURCE_SIZE	8

/* data structure of point event */
/* Old Touch Points Protocol
---------+-+-+-+-+-+-+-+-+
Byte0|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Finger ID|Statu|
---------+-+-+-+-+-+-+-+-+
Byte1|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |X High         |
---------+-+-+-+-+-+-+-+-+
Byte2|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Y High         |
---------+-+-+-+-+-+-+-+-+
Byte3|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |X Low  |X High |
---------+-+-+-+-+-+-+-+-+
Byte4|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Area           |
---------+-+-+-+-+-+-+-+-+
Byte5|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Pressure       |
---------+-+-+-+-+-+-+-+-+
*/
/* New Touch Points Protocol
---------+-+-+-+-+-+-+-+-+
Byte0|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |X High         |
---------+-+-+-+-+-+-+-+-+
Byte1|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Y High         |
---------+-+-+-+-+-+-+-+-+
Byte2|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |X Low  |X High |
---------+-+-+-+-+-+-+-+-+
Byte3|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Finger ID|Statu|
---------+-+-+-+-+-+-+-+-+
Byte4|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Area           |
---------+-+-+-+-+-+-+-+-+
Byte5|Bit|7|6|5|4|3|2|1|0|
---------+-+-+-+-+-+-+-+-+
         |Pressure       |
---------+-+-+-+-+-+-+-+-+
*/

struct ct36x_finger_info {
#ifndef CONFIG_TOUCHSCREEN_CT36X_MISC_NEW_TPS
	unsigned char	status : 3;		// Action information, 1: Down; 2: Move; 3: Up
	unsigned char	id : 5;			// ID information, from 1 to CFG_MAX_POINT_NUM
#endif
	unsigned char	xhi;			// X coordinate Hi
	unsigned char	yhi;			// Y coordinate Hi
	unsigned char	ylo : 4;		// Y coordinate Lo
	unsigned char	xlo : 4;		// X coordinate Lo
#ifdef CONFIG_TOUCHSCREEN_CT36X_MISC_NEW_TPS
	unsigned char	status : 3;		// Action information, 1: Down; 2: Move; 3: Up
	unsigned char	id : 5;			// ID information, from 1 to CFG_MAX_POINT_NUM
#endif
	unsigned char	area;			// Touch area
	unsigned char	pressure;		// Touch Pressure
};

extern unsigned char binary_data[];

int ct36x_chip_get_binchksum(unsigned char *buf);
int ct36x_chip_get_fwchksum(struct i2c_client *client, unsigned char *buf);

int ct36x_chip_get_ver(struct i2c_client *client, unsigned char *buf);

void ct36x_chip_go_sleep(struct i2c_client *client, unsigned char *buf);
int ct36x_chip_go_bootloader(struct i2c_client *client, unsigned char *buf);


void ct36x_chip_set_adapter_on(struct i2c_client *client);
void ct36x_chip_set_adapter_off(struct i2c_client *client);


unsigned char ct365_get_vendor(struct i2c_client *client);


#endif


extern unsigned char ct36x_update(struct i2c_client *client);
extern void ct36x_chip_go_sleep(struct i2c_client *client);

#endif
