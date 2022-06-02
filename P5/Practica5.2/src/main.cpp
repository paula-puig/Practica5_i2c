#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"
#include<SPI.h>

RTC_DS1307 rtc;

int segundo,minuto,hora,dia,mes;
long anio; //variable año
DateTime HoraFecha;

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  Serial.begin(115200);
  rtc.begin(); //Inicializamos el RTC
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  HoraFecha = rtc.now(); //obtenemos la hora y fecha actual
    
  segundo=HoraFecha.second();
  minuto=HoraFecha.minute();
  hora=HoraFecha.hour();
  dia=HoraFecha.day();
  mes=HoraFecha.month();
  anio=HoraFecha.year();

  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("hora = ");
  lcd.print(hora);
  lcd.print(":");
  lcd.print(minuto);
  lcd.print(":");
  lcd.print(segundo);
  lcd.print("  Fecha = ");
  lcd.print(dia);
  lcd.print("/");
  lcd.print(mes);
  lcd.print("/");
  lcd.print(anio);
  lcd.println();
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  //lcd.setCursor(0,1);
  //lcd.print("Hello, World!");
  //delay(1000);
  //lcd.clear(); 
}
