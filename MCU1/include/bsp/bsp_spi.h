#ifndef __BSPSPI_H_
#define __BSPSPI_H_

#ifndef On_Chip_SPI
#define On_Chip_SPI

#ifndef __SOFTSPI_
#define __SOFTSPI_
#include <../../ti_msp_dl_config.h>
#define SOFT_SPI_PORT       GPIOA
#define SOFT_SPI_SCK_PORT   GPIOA
#define SOFT_SPI_MOSI_PORT  GPIOA
#define SOFT_SPI_MISO_PORT  GPIOA
#define SOFT_SPI_CS_PORT    GPIOA
#define SOFT_SPI_CS2_PORT   GPIOA
#define SOFT_SPI_CS3_PORT   GPIOA

#define SOFT_SPI_SCK_PIN   0
#define SOFT_SPI_MOSI_PIN  0
#define SOFT_SPI_MISO_PIN  0
#define SOFT_SPI_CS_PIN    0
#define SOFT_SPI_CS2_PIN   0
#define SOFT_SPI_CS3_PIN   0

#define CPOL 0 //时钟极性
#define CPHA 0 //时钟相位

#define MODE1 1//SPI工作模式1
#define MODE2 2//SPI工作模式2
#define MODE3 3//SPI工作模式3
#define MODE4 4//SPI工作模式4

#if (CPOL == 0 && CPHA == 0)
#define SPI_MODE MODE1 //CPOL=0,CPHA=0
#elif (CPOL == 0 && CPHA == 1)
#define SPI_MODE MODE2 //CPOL=0,CPHA=1
#elif (CPOL == 1 && CPHA == 0)
#define SPI_MODE MODE3 //CPOL=1,CPHA=0
#elif (CPOL == 1 && CPHA == 1)
#define SPI_MODE MODE4 //CPOL=1,CPHA=1
#endif


#endif

typedef struct Soft_SPI_APIs_Struct
{
    void (*Soft_SPI_GPIO_Port_Init)(void); //SPI GPIO端口初始化函数
    void (*delay_us)(uint32_t nus); //延时函数
    void (*dealy_ms)(uint32_t nms); //延时函数
    void (*Soft_SPI_SCK)(uint8_t state); //SCK线控制函数
    void (*Soft_SPI_MOSI)(uint8_t state); //MOSI线控制函数
    uint8_t (*Soft_SPI_MISO)(void); //读取MISO线状态
    void (*Soft_SPI_CS)(uint8_t state); //CS线控制函数
    void (*Soft_SPI_CS2)(uint8_t state); //CS2线控制函数
    void (*Soft_SPI_CS3)(uint8_t state); //CS3线控制函数
} SSAS;




#endif

#endif