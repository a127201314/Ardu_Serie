/*
   Project name: JayThree Time_Lapse CAM Project #arduSerie 36
     A very cool project that captures images for a predetermined time. 
     Serves as a time lapse camera. It is widely used in biology, 
     for the study of human or animal behavior. Have a good time!!!
     
     Flavour I - SDCard Writting and Reading procedures 
     INO File: _36_SDCard_Write_Read_File_01.ino
   
   Revision History:
     Oct, 2017
       - v 1.0 - Medium webpage:
   Description:
          This code initializes SDCARD, writes to the card and then reads it. 
          The written LOG.CSV file will contain 'Test SDCard OK' lines. 
          Leave the file on the card because the next code will read it.
          This example shows how to log data from analog sensors
          to an SD card using the SD library.
   MCU:                  Arduino Pro Micro - Atmega328 16MHz 5V @16MHz - https://www.sparkfun.com/products/12640
   IDE:                  Arduino 1.8.3 - http://www.arduino.cc/
   SDCard:               SD Card Module Slot Socket Reader LC Studio 3.3V/5V - https://goo.gl/gCUnEU
   DS1307 RTC:           DS1307 Real Time Clock breakout board - https://www.adafruit.com/product/264
   Serial Camera:        Grove - Serial Camera Kit - https://www.seeedstudio.com/Grove-Serial-Camera-Kit-p-1608.html?cPath=25_33                            
   Connections:          See Official youtube channel vids: https://goo.gl/unfHZA
   Based on:             http://jungletronics.blogspot.com.br/2014/06/blog-post.html
   Credit:               JR TimeLapse Cam Project!                  
   Cam Datasheet (pdf):  https://goo.gl/oGBQbx  (CJ-OV528 Protocol（通信协议） (2))
   Terms of use:  
     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
     IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
     AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
     THE SOFTWARE.  
  
  //original notes:
  created  24 Nov 2010
  modified 9 Apr 2012
  by Tom Igoe
  This example code is in the public domain.
*/

#include <SPI.h>
#include <SD.h>

//Set by default for the SD card library for SparkFun Pro Micro 5v
//MOSI = Pin 11
//MISO = Pin 16
//SCLK = PIN 15
//Set for Arduino UNO
//MOSI = Pin 11
//MISO = Pin 12
//SCLK = PIN 13
//We always need to set the CS Pin
const int CS_PIN = 10;
const int SD_POW_PIN  = 8;

void setup()
{
                                     // Open serial communications and wait for port to open:
                                     // Serial Output:
                                                                                                                                                                                                                                                                                                                                  // [ SDCard test!                              ]
                                     // [ Initializing SD card...card initialized.  ]
                                     // [ It works!!congrats                        ]

  Serial.begin(9600);
  //Serial1.begin(9600);             // For SparkFun Arduino Pro Micro - put 1 on end of Serial[1]
  Serial.println("SDCard test!");
  while (!Serial) {
    ;                                // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.print("Initializing SD card...");

  pinMode(CS_PIN,   OUTPUT);         // CS pin is an output
  pinMode(SD_POW_PIN, OUTPUT);       // Supply 5v to SDCard
  digitalWrite(SD_POW_PIN, HIGH);    // Card will draw power from pin 8, so set it high
  

                                     // see if the card is present and can be initialized:
  if (!SD.begin(CS_PIN)) {
    Serial.println("Card failed, or not present");
                                     // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{

                                     // open the file. note that only one file can be open at a time,
                                     // so you have to close this one before opening another.
  File dataFile = SD.open("LOG.CSV", FILE_WRITE);

                                     // if the file is available, write to it; debug info into serial
  if (dataFile) {
    dataFile.println("Test SDCard OK");
    Serial.println("It works!!congrats");
    dataFile.close();
  }
                                     // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening LOG.CSV");
  }
  delay(1000);
}


