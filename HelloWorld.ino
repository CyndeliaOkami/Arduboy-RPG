/*
Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include "Arduboy.h"
#include "bitmaps.ino"

int aniNum = 0;

// make an instance of arduboy used for many functions
Arduboy arduboy;

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);

  // first we clear our screen to black
  arduboy.clear();

  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0) 
  arduboy.setCursor(4, 9);

  // then we print to screen what is in the Quotation marks ""
  arduboy.print(F("Welcome to"));
  arduboy.setCursor(4, 19);
  arduboy.print(F("Arduboy RPG!"));
  //arduboy.setCursor(4, 29);
  //arduboy.print(F("It works!"));
  arduboy.setCursor(4, 39);
  arduboy.print(F("Press 'A' to begin."));
  
  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  while(not(arduboy.pressed(A_BUTTON))) {
    // Do something awesome  
  }
  
  // first we clear our screen to black
  arduboy.clear();
  arduboy.drawRoundRect(0, 5, 86, 25, 3, 1);
  arduboy.drawRoundRect(85, 5, 43, 25, 3, 1);
  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
  
  if (!(arduboy.nextFrame())) return;
  
  arduboy.clear();
  arduboy.drawRoundRect(0, 5, 86, 25, 3, 1);
  arduboy.drawRoundRect(85, 5, 43, 25, 3, 1);
  arduboy.drawBitmap(5, 45, bitmaps.fighter[aniNum], 16, 16, WHITE);
  
  if (arduboy.everyXFrames(5)) aniNum++;
  if (aniNum == 4)aniNum = 0;
  
  arduboy.display();
}

