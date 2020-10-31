/**
 * Author: Alejandro Nunez
 * Last Modified: 10/23/2020
 * Project: Dancebot Swarm
 * File: dbEyes.h
 * Description: Defines implementation for actuating LED eyes on the dancebot swarm
 */
#pragma once
#include <Adafruit_NeoPixel.h>
#include <math.h>

#define PI 3.142

class dbEyes {
    public:
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

    private:
        Adafruit_NeoPixel leftEyePixels;
        Expression expression = Expression::RESET;
        static const int NUM_PIXELS = 7;

    private:
        void fade() {
            static int ledValue = 0;
            static float brightnessLevel = 0;

            leftEyePixels.setBrightness((150/2)*cos(ledValue/1000)+(150/2));
            ledValue = (ledValue + 1) % ((int) PI*1000*2);
        }

        void blink(float brightness) {
            static int iteration = 0;

            leftEyePixels.setBrightness(brightness);

            if (iteration == 0) {
                leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.show();
                // delay(5000);
                set_interrupt(5000);
            } else if (iteration == 1) {
                leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.show();
                // delay(100);
                set_interrupt(100);
            } else if (iteration == 2) {
                leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.show();
                // delay(300);
                set_interrupt(300);
            } else {
                leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(2, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                leftEyePixels.show();
                // delay(100);
                set_interrupt(100);
            }

            iteration = (iteration + 1) % 4;
        }

        ISR(TIMER1_COMPA_vect) {
            TNCT1 = t1_load;
            blink(155);
        }

        void set_interrupt(int millis) {
            // 1. calculate the number of ticks

            // 2. reset Timer1 and set compare value

            // 3. enable Timer1 overflow interrupt

            // 4. enable global interrupts
        }

    public:
        explicit dbEyes(int pin) {
            leftEyePixels = Adafruit_NeoPixel(7, pin, NEO_RGBW+NEO_KHZ800);
            leftEyePixels.begin();
        }

        void run_expression() {
            leftEyePixels.clear();

            switch (expression) {
                static int ledID = 0;
                case Expression::LOADING:
                    leftEyePixels.setBrightness(10);
                    leftEyePixels.setPixelColor(ledID, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    ledID = (ledID + 1) % NUM_PIXELS;
                    break;

                case Expression::HAPPY:
                    fade();
                    leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    break;

                case Expression::SAD:
                    fade();
                    leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(3, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    break;

                case Expression::LOWKEY:
                    fade();
                    leftEyePixels.setPixelColor(0, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    break;

                case Expression::WINKY:
                    fade();
                    leftEyePixels.setPixelColor(4, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(5, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(6, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.setPixelColor(1, leftEyePixels.Color(0, 0, 255, 0));
                    leftEyePixels.show();
                    break;

                case Expression::CLEAR:
                    break;

                default:
                    blink(155);
                    break;
            }
        }

        void set_expression(Expression _expression) {
            leftEyePixels.clear();
            expression = _expression;
        }

        Expression get_expression() {
            return expression;
        }
};

// int main()
// {
//     dbEyes robotEyes = dbEyes(0);
//     robotEyes.set_expression(robotEyes.HAPPY);
//     while(1) {
//         if (updateState() != "") {
//             // check for each type of expression
//             dbEyes::Expression newExpression = robotEyes.get_expression();
//             // set the relevant enum
//             if (updateState() == "angry") {
//                 newExpression = dbEyes::ANGRY;
//             }
//             ...
//             robotEyes.set_expression(newExpression);
//         }
//         robotEyes.run_expression();
//         // timer
//     }
//     return 1;
// }


// interrupt 1: change expressions -> clears everythings, goes to the next expression
// interrupt 2: blink, timer based eye movements -> calls the next iteration of the eye expression