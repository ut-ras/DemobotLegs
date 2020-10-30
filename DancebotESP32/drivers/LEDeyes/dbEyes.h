/**
 * Author: Alejandro Nunez
 * Last Modified: 10/23/2020
 * Project: Dancebot Swarm
 * File: dbEyes.h
 * Description: Defines implementation for actuating LED eyes on the dancebot swarm
 */
#pragma once
#include <Adafruit_NeoPixel.h>

class dbEyes {
    public:
        explicit dbEyes(int pin){
            leftEyePixels = Adafruit_NeoPixel(7, pin, NEO_RGBW+NEO_KHZ800);
            leftEyePixels.begin();
        }

        enum Expression{
            RESET,
            CLEAR,
            LOADING,
            HAPPY,
            SAD,
            LOWKEY,
            ANGRY,
            WINKY
        };



        void set_expression(Expression expression){
            pixels.clear();
            switch (expression){
                case Expression::LOADING:
                    leftEyePixels.clear();
                    int num = 0;
                    while(true){
                        leftEyePixels.setBrightness(10);
                        leftEyePixels.setPixelColor(num, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.show();
                        delay(1000);
                        leftEyePixels.clear();
                        num++;
                        if (num==7){
                        num=0;
                        }
                    }
                case Expression::CLEAR:
                    leftEyePixels.clear();
                case Expression::HAPPY:
                    leftEyePixels.clear();
                    int value=0;
                    while (true){
                        float num = (150/2)*cos(value)+(150/2);
                        leftEyePixels.setBrightness(num);
                        leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.show();
                        value=value+.001;
                    }
                case Expression::SAD:
                    leftEyePixels.clear();
                    int value=0;
                    while (true){
                        //LEFT EYE
                        float num = (150/2)*cos(value)+(150/2);
                        leftEyePixels.setBrightness(num);
                        leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.show();
                        value=value+.001;
                    }
                case Expression::LOWKEY:
                    int value=0;
                    while(true){
                        int num = (150/2)*cos(value)+(150/2);
                        leftEyePixels.setBrightness(num);
                        leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.show();
                        value=value+.001;
                        delay(1);
                    }
                case Expression::WINKY:
                    leftEyePixels.clear();
                    int value=0;
                        while (true){        
                        //LEFT EYE                    
                        float num = (150/2)*cos(value)+(150/2);
                        leftEyePixels.setBrightness(num);
                        leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                        leftEyePixels.show();
                        value=value+.001;
                    }
                default:
                    float num=155;
                    leftEyePixels.clear();
                    leftEyePixels.setBrightness(num);
                    leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    delay(5000);
                    blink(155); 
                    break;
            }
        }

        void blink(int brightness){
            leftEyePixels.clear();
            leftEyePixels.setBrightness(brightness);
            leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.show();
            delay(100);
            leftEyePixels.clear();
            leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.show();
            delay(300);
            leftEyePixels.clear();
            leftEyePixels.setBrightness(brightness);
            leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
            leftEyePixels.show();
            delay(100);
        }

    private:
        Adafruit_NeoPixel leftEyePixels;

};