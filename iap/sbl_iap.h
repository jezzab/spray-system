/**
  ******************** (C) COPYRIGHT 2011 DJI **********************************
  *
  * @Project Name       : BL_WKM2_LED_IAP.uvproj
  * @File Name          : bsp.h
  * @Environment        : keil mdk4.12/LPC1765/100M cclock
  * @Author&Date        : 2011-07-28 
  * @Version            : 1.00
  ******************************************************************************
  * @Description
  *	    Begginning of application   
  */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef  __SBL_IAP_H__
#define  __SBL_IAP_H__

#include "stdbool.h"

extern const uint32_t sector_start_map[];
extern const uint32_t sector_end_map[];
extern const uint32_t crp;
/* add 2013-02-26 主设备ID和从设备ID */

uint32_t write_flash(uint32_t * dst, uint8_t * src, uint32_t no_of_bytes);
void execute_user_code(void);
uint32_t user_code_present(void);
void erase_user_flash(void);
void check_iap_entry_init(void);
void check_iap_entry_pin(void);
void erase_user_flash(void);

void place_aes_key(void);
void write_programming_done_flag(void);
void erase_programming_done_flag(void);
unsigned compare_data(unsigned flash_address,unsigned ram_address,unsigned length);
void erase_flag_aera(void);
uint8_t erase_user_area(void);

bool hardware_id_write_flash(uint8_t *buf, uint32_t len);
void hardware_id_read_flash(uint8_t *buf, uint32_t len);

void cali_flow_para1_read_flash(uint8_t *buf, uint32_t len);
void cali_flow_para2_read_flash(uint8_t *buf, uint32_t len);
bool cali_flow_para1_write_flash( uint8_t *buf , uint32_t len);
bool cali_flow_para2_write_flash( uint8_t *buf , uint32_t len);
bool residual_volume_para_write_flash( uint8_t *buf , uint32_t len );
bool flowmeter_para_write_flash( uint8_t *buf , uint32_t len );


void cali_pressure1_para_read_flash(uint8_t *buf, uint32_t len);
bool cali_pressure1_para_write_flash( uint8_t *buf , uint32_t len);
void cali_pressure2_para_read_flash(uint8_t *buf, uint32_t len);
bool cali_pressure2_para_write_flash( uint8_t *buf , uint32_t len);
void cali_volume_para_read_flash(uint8_t *buf, uint32_t len);
void flowmeter_para_read_flash(uint8_t *buf, uint32_t len);
uint32_t sbl_get_loader_version( void );

typedef enum
{
	PREPARE_SECTOR_FOR_WRITE	= 50,
	COPY_RAM_TO_FLASH					= 51,
	ERASE_SECTOR							= 52,
	BLANK_CHECK_SECTOR				= 53,
	READ_PART_ID							= 54,
	READ_BOOT_VER							= 55,
	COMPARE										= 56,
	REINVOKE_ISP							= 57
}IAP_Command_Code;

#define IAP_CCLK                    100000u       /* 100,000 KHz for lpc17xx */
#define CMD_SUCCESS                 0
#define IAP_ADDRESS                 0x1FFF1FF1

#define FLASH_DATA_SECTOR_START		  (7)
#define PROGRAM_FLAG_SECTOR         (8)
#define HARDWARE_ID_SECTOR          (9)


#define FLASH_DATA_ADDR_START       (SECTOR_7_START)
#define PROGRAM_FLAG_ADDR		        (SECTOR_8_START)
#define HARDWARE_ID_ADDR            (SECTOR_9_START)

#define HARDWARE_ID_OFFSET          (0)   // totla = 64*4 = 32 *8
#define CALI_PRESSURE1_PARA_OFFSET  (32*1)
#define CALI_FLOW1_PARA_OFFSET      (32*2)
#define CALI_PRESSURE2_PARA_OFFSET  (32*3)
#define CALI_FLOW2_PARA_OFFSET      (32*4)
#define RESIDUAL_VOLUME_PARA_OFFSET (32*5)
#define FLOWMETER_PARA_OFFSET       (32*6)

#define MAX_LENGTH				      (256u)
#define SECTOR_SIZE			        (4096u)

#define USER_DATA_MAX_SIZE		    (256u)

/* check entry pin define */
#define ISP_ENTRY_PIN_00            ((uint32_t)(1<<2))
#define ISP_ENTRY_PIN_01	        ((uint32_t)(1<<4))

#define ISP_ENTRY_PIN_00_IN 		(FIO2DIR &= ~ISP_ENTRY_PIN_00)
#define ISP_ENTRY_PIN_01_IN			(FIO2DIR &= ~ISP_ENTRY_PIN_01)

#define ISP_ENTRY_PIN_00_OUT		(FIO2DIR |=  ISP_ENTRY_PIN_00)
#define ISP_ENTRY_PIN_01_OUT		(FIO2DIR |=  ISP_ENTRY_PIN_01)

#define ISP_ENTRY_PIN_00_OUT_H	    (FIO2SET  =  ISP_ENTRY_PIN_00) 
#define ISP_ENTRY_PIN_01_OUT_H		(FIO2SET  =  ISP_ENTRY_PIN_01)

#define ISP_ENTRY_PIN_00_OUT_L		(FIO2CLR  =  ISP_ENTRY_PIN_00)
#define ISP_ENTRY_PIN_01_OUT_L		(FIO2CLR  =  ISP_ENTRY_PIN_01)

#define ISP_ENTRY_PIN_00_RD		    (FIO2PIN&ISP_ENTRY_PIN_00)
#define ISP_ENTRY_PIN_01_RD		    (FIO2PIN&ISP_ENTRY_PIN_01)

#endif /* __SBL_IAP_H__ */
/*******************  (C) COPYRIGHT 2012 DJI ************END OF FILE***********/

