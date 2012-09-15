#include <TVout.h>
#include <fontALL.h>
#include "Finn.h"
#include "pitches.h"
#include "AdventureTheme.h"

TVout TV;

void togglePixel(int x, int y) {
  TV.set_pixel(x, y - 1, 2); //Toggle pixel. Messing with X since my image editor coordinates are off by one, boo
}

void finnWink() {
  togglePixel(32, 22); 
}

void finnTongue() {
  //Make him stick out his tongue
  togglePixel(26, 28);
  togglePixel(28, 28);
  togglePixel(26, 29);
  togglePixel(27, 29);
}

void setup() {
  static bool hasSmiled = false;
  static bool finnHasWinked = false;
  bool loopMusic = false;
  TV.begin(NTSC,120,96);
  TV.select_font(font6x8);
  TV.bitmap(0, 0, Finn);
  TV.delay(6000);
  TV.set_cursor(0, 65);
  TV.print("Music time!");
  do {
    for (int thisNote = 0; thisNote < 9; thisNote++) {
  
      // to calculate the note duration, take one second 
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1500/noteDurations[thisNote];
      TV.tone(mIntro[thisNote],noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      TV.delay(pauseBetweenNotes);
      // stop the tone playing:
      TV.noTone();
    } while (loopMusic);
    
    //Stuff we only want done on the first loop, if the music is looping
    if (!finnHasWinked) {
      finnHasWinked = true;
      finnTongue();
      TV.delay(1000);
    }
    if (!hasSmiled) {
      hasSmiled = true;
      TV.println(" :)");
    }
    
    TV.delay(2500);
  } while (loopMusic);
  
  //Stop doing stuff, loop forever!
  while (1);
  
  
  TV.clear_screen();
  TV.println("I generate a PAL\nor NTSC composite  video using\ninterrupts\n");
  TV.delay(2500);
  TV.println("My schematic:");
  TV.delay(1500);
  TV.bitmap(0,0,schematic);
  TV.delay(10000);
  TV.clear_screen();
  TV.println("Lets see what\nwhat I can do");
  TV.delay(2000);
  
  //fonts
  TV.clear_screen();
  TV.println(0,0,"Multiple fonts:");
  TV.select_font(font4x6);
  TV.println("4x6 font FONT");
  TV.select_font(font6x8);
  TV.println("6x8 font FONT");
  TV.select_font(font8x8);
  TV.println("8x8 font FONT");
  TV.select_font(font6x8);
  TV.delay(2000);
  
  TV.clear_screen();
  TV.print(9,44,"Draw Basic Shapes");
  TV.delay(2000);
  
  //circles
  TV.clear_screen();
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/3,WHITE);
  TV.delay(500);
  TV.draw_circle(TV.hres()/2,TV.vres()/2,TV.vres()/2,WHITE,INVERT);
  TV.delay(2000);
  
  //rectangles and lines
  TV.clear_screen();
  TV.draw_rect(20,20,80,56,WHITE);
  TV.delay(500);
  TV.draw_rect(10,10,100,76,WHITE,INVERT);
  TV.delay(500);
  TV.draw_line(60,20,60,76,INVERT);
  TV.draw_line(20,48,100,48,INVERT);
  TV.delay(500);
  TV.draw_line(10,10,110,86,INVERT);
  TV.draw_line(10,86,110,10,INVERT);
  TV.delay(2000);
}

void loop() {
}
