#pragma once

#ifndef configs_h

  #define configs_h

  #define POLISH_POTATO

  //// BOARD TARGETS
  #define MARAUDER_V4
  //// END BOARD TARGETS

  #define MARAUDER_VERSION "v1.4.3"

  #define GRAPH_REFRESH 100

  //// HARDWARE NAMES
  #define HARDWARE_NAME "Marauder vCYD"
  //// END HARDWARE NAMES

 //// BOARD FEATURES
  #define HAS_BATTERY
  #define HAS_BT
  #define HAS_NEOPIXEL_LED
  //#define HAS_PWR_MGMT
  #define HAS_SCREEN
  #define HAS_FULL_SCREEN
  #define HAS_SD
  #define USE_SD
  #define HAS_GPS
  #define CYD_28CAP

  //// END BOARD FEATURES

  //// BUTTON DEFINITIONS
  // No physical buttons on JC2432W328C (touch-only).
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  #ifdef HAS_SCREEN

    #ifdef MARAUDER_V4
      #ifdef CYD_28CAP
        #define SCREEN_CHAR_WIDTH 40
        #define HAS_ST7789
        #define BANNER_TEXT_SIZE 2

        #ifndef TFT_WIDTH
          #define TFT_WIDTH 240
        #endif

        #ifndef TFT_HEIGHT
          #define TFT_HEIGHT 320
        #endif

        #define THROW_AWAY_TOUCH_COUNT 31
        // Touchscreen pins (CST820)
        #define TOUCH_SDA  33
        #define TOUCH_SCL  32
        #define TOUCH_INT 21
        #define TOUCH_RST 25

        // Display pins (ST7789)
        #define TFT_MISO 12 // or SDO
        #define TFT_MOSI 13 // In some display driver board, it might be written as "SDA" or SDI
        #define TFT_SCLK 14
        #define TFT_CS   15  // Chip select control pin
        #define TFT_DC   2   // Data Command control pin (OR RS)
        #define TFT_RST  -1  // Reset pin (could connect to Arduino RESET pin)
        #define TFT_BL   27  // LED back-light
        #define TFT_BACKLIGHT_ON HIGH  // Level to turn ON back-light (HIGH or LOW)

        #define TOUCH_WIDTH  240
        #define TOUCH_HEIGHT 320

        #define SPI_FREQUENCY  65000000
        #define SPI_READ_FREQUENCY  20000000
        #define SPI_TOUCH_FREQUENCY  2500000

        // Generic commands used by TFT_eSPI.cpp
        #define TFT_NOP     0x00
        #define TFT_SWRST   0x01
        #define TFT_INVOFF  0x20
        #define TFT_INVON   0x21
        #define TFT_DISPOFF 0x28
        #define TFT_DISPON  0x29
        #define TFT_CASET   0x2A
        #define TFT_PASET   0x2B
        #define TFT_RAMWR   0x2C
        #define TFT_RAMRD   0x2E
        #define TFT_MADCTL  0x36
        #define TFT_MAD_MY  0x80
        #define TFT_MAD_MX  0x40
        #define TFT_MAD_MV  0x20
        #define TFT_MAD_ML  0x10
        #define TFT_MAD_BGR 0x08
        #define TFT_MAD_MH  0x10
        #define TFT_MAD_RGB 0x00

        #ifdef TFT_RGB_ORDER
          #if (TFT_RGB_ORDER == 1)
            #define TFT_MAD_COLOR_ORDER TFT_MAD_RGB
          #else
            #define TFT_MAD_COLOR_ORDER TFT_MAD_BGR
          #endif
        #else
          #define TFT_MAD_COLOR_ORDER TFT_MAD_BGR
        #endif

        #define ST7789_NOP     0x00
        #define ST7789_SWRESET 0x01
        #define ST7789_RDDID   0x04
        #define ST7789_RDDST   0x09
        #define ST7789_SLPIN   0x10
        #define ST7789_SLPOUT  0x11
        #define ST7789_PTLON   0x12
        #define ST7789_NORON   0x13
        #define ST7789_INVOFF  0x20
        #define ST7789_INVON   0x21
        #define ST7789_DISPOFF 0x28
        #define ST7789_DISPON  0x29
        #define ST7789_CASET   0x2A
        #define ST7789_PASET   0x2B
        #define ST7789_RAMWR   0x2C
        #define ST7789_RAMRD   0x2E
        #define ST7789_PTLAR   0x30
        #define ST7789_MADCTL  0x36
        #define ST7789_COLMOD  0x3A
        #define ST7789_FRMCTR1 0xB1
        #define ST7789_FRMCTR2 0xB2
        #define ST7789_FRMCTR3 0xB3
        #define ST7789_INVCTR  0xB4
        #define ST7789_DISSET5 0xB6
        #define ST7789_PWCTR1  0xC0
        #define ST7789_PWCTR2  0xC1
        #define ST7789_PWCTR3  0xC2
        #define ST7789_VMCTR1  0xC5
        #define ST7789_RDID1   0xDA
        #define ST7789_RDID2   0xDB
        #define ST7789_RDID3   0xDC
        #define ST7789_RDID4   0xDD
        #define ST7789_GMCTRP1 0xE0
        #define ST7789_GMCTRN1 0xE1
      #endif // CYD_28CAP


      #define SCREEN_BUFFER
      #define MAX_SCREEN_BUFFER 22

      #define GRAPH_VERT_LIM TFT_HEIGHT/2

      #define EXT_BUTTON_WIDTH 20

      #define TEXT_HEIGHT 16 // Height of text to be printed and scrolled
      #define CHAR_WIDTH 12
      #define SCREEN_WIDTH TFT_WIDTH
      #define SCREEN_HEIGHT TFT_HEIGHT
      #define HEIGHT_1 TFT_WIDTH
      #define WIDTH_1 TFT_HEIGHT
      #define STANDARD_FONT_CHAR_LIMIT (TFT_WIDTH / 6) // number of characters on a single line with normal font
      
      #define BOT_FIXED_AREA 0 // Number of lines in bottom fixed area (lines counted from bottom of screen)
      #define TOP_FIXED_AREA 48 // Number of lines in top fixed area (lines counted from top of screen)
      #define YMAX TFT_HEIGHT // Dynamically set based on the display height
      #define minimum(a,b)     (((a) < (b)) ? (a) : (b))
      //#define MENU_FONT NULL
      #define MENU_FONT &FreeMono9pt7b // Winner
      //#define MENU_FONT &FreeMonoBold9pt7b
      //#define MENU_FONT &FreeSans9pt7b
      //#define MENU_FONT &FreeSansBold9pt7b
      #define BUTTON_SCREEN_LIMIT 12
      #define BUTTON_ARRAY_LEN BUTTON_SCREEN_LIMIT
      #define STATUS_BAR_WIDTH 16
      #define LVGL_TICK_PERIOD 6

      #define FRAME_X 100
      #define FRAME_Y 64
      #define FRAME_W 120
      #define FRAME_H 50

      // Red zone size
      #define REDBUTTON_X FRAME_X
      #define REDBUTTON_Y FRAME_Y
      #define REDBUTTON_W (FRAME_W / 2)
      #define REDBUTTON_H FRAME_H

      // Green zone size
      #define GREENBUTTON_X (REDBUTTON_X + REDBUTTON_W)
      #define GREENBUTTON_Y FRAME_Y
      #define GREENBUTTON_W (FRAME_W / 2)
      #define GREENBUTTON_H FRAME_H

      #define STATUSBAR_COLOR 0x18ED

      #define KIT_LED_BUILTIN 4
    #endif
    




  #endif
  //// END DISPLAY DEFINITIONS

  //// MENU DEFINITIONS
  #if defined(MARAUDER_V4)
    #define BANNER_TIME 100
    
    #define COMMAND_PREFIX "!"
    
    // Keypad start position, key sizes and spacing
    #define KEY_X 120 // Centre of key
    #define KEY_Y 50
    #define KEY_W 240 // Width and height
    #define KEY_H 22
    #define KEY_SPACING_X 0 // X and Y gap
    #define KEY_SPACING_Y 1
    #define KEY_TEXTSIZE 1   // Font size multiplier
    #define ICON_W 22
    #define ICON_H 22
    #define BUTTON_PADDING 22
    //#define BUTTON_ARRAY_LEN 5
  #endif

  
  //// END MENU DEFINITIONS

  //// SD DEFINITIONS
  #if defined(USE_SD)

    #ifdef MARAUDER_V4
      #define SD_CS 5
    #endif

  #endif
  //// END SD DEFINITIONS

  //// SPACE SAVING COLORS
  #define TFTWHITE     1
  #define TFTCYAN      2
  #define TFTBLUE      3
  #define TFTRED       4
  #define TFTGREEN     5
  #define TFTGREY      6
  #define TFTGRAY      7
  #define TFTMAGENTA   8
  #define TFTVIOLET    9
  #define TFTORANGE    10
  #define TFTYELLOW    11
  #define TFTLIGHTGREY 12
  #define TFTPURPLE    13
  #define TFTNAVY      14
  #define TFTSILVER    15
  #define TFTDARKGREY  16
  #define TFTSKYBLUE   17
  #define TFTLIME      18
  //// END SPACE SAVING COLORS
  
  //// SCREEN STUFF
  #ifndef HAS_SCREEN

    #define BANNER_TIME GRAPH_REFRESH
    
    #define TFT_WHITE 0
    #define TFT_CYAN 0
    #define TFT_BLUE 0
    #define TFT_RED 0
    #define TFT_GREEN 0
    #define TFT_GREY 0
    #define TFT_GRAY 0
    #define TFT_MAGENTA 0
    #define TFT_VIOLET 0
    #define TFT_ORANGE 0
    #define TFT_YELLOW 0
    #define STANDARD_FONT_CHAR_LIMIT 40
    #define FLASH_BUTTON -1

    #include <FS.h>
    #include <functional>
    #include <LinkedList.h>
    #include "SPIFFS.h"
    #include "Assets.h"

  #endif
  //// END SCREEN STUFF

  //// MEMORY LOWER LIMIT STUFF
  // These values are in bytes
  #define MEM_LOWER_LIM 10000
  //// END MEMORY LOWER LIMIT STUFF

  //// NEOPIXEL STUFF  
  #ifdef HAS_NEOPIXEL_LED
    #define PIN 4
  
  #endif
  //// END NEOPIXEL STUFF

  //// EVIL PORTAL STUFF
  #define MAX_HTML_SIZE 11400
  //// END EVIL PORTAL STUFF

  //// GPS STUFF
  #ifdef HAS_GPS
    #define GPS_SERIAL_INDEX 2
    #define GPS_TX 1
    #define GPS_RX 3
    #define mac_history_len 100
  #else
    #define mac_history_len 100
  #endif
  //// END GPS STUFF

  //// BATTERY STUFF
  #ifdef HAS_BATTERY
    #define I2C_SDA 22
    #define I2C_SCL 27

  #endif

  //// MARAUDER TITLE STUFF
  #define MARAUDER_TITLE_BYTES 13578
  //// END MARAUDER TITLE STUFF

  //// PCAP BUFFER STUFF
  #define BUF_SIZE 3 * 1024 // Had to reduce buffer size to save RAM. GG @spacehuhn
  #define SNAP_LEN 2324 // max len of each recieved packet
  //// PCAP BUFFER STUFF
#endif
