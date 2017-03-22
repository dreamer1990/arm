#ifndef __CRC_H__
#define __CRC_H__



typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long size_t;


u16 crc16(u16 crc, u8 const *buffer, size_t len);


#endif /*__CRC_H__*/
