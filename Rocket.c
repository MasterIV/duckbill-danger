#include <gb/gb.h>
#include <stdio.h>
#include "tiles.c"
#include "sfx.c"
#include "song1.c"
#include "units.tiles"

UBYTE level = 0;
UBYTE loop = 1;
UBYTE defeat = 0;
UBYTE current_level[360];

UBYTE goal_count = 0;
UBYTE goal_max = 2;

UBYTE command_current = 0;
UBYTE command_max = 4;
const UBYTE *commands;

// UBYTE level = 0;
// UBYTE level_objects[63];

/*
 Sprites:
   0-7 Cursor
   8-15 Creepers
   16-31 Enemies / Hazards?
*/

#include "screens.c"
#include "unit.c"
#include "leveldata.c"
#include "levels.c"
#include "cursor.c"

/*
void display_level() {
  DISPLAY_OFF;
  
  init_background(&current_level);
  load_level(level, level_objects);
  update_background(&level_objects, &current_level);

  set_bkg_tiles(0, 0, 20, 18, current_level);

  DISPLAY_ON;
}
*/

void main() {
  SPRITES_8x16;
  
  VBK_REG = 1;
  VBK_REG = 0;
  
  show_title();
  
  SHOW_BKG;
  
  waitpad(255);
  
  display_level();
  cursor_init();
  
  UBYTE keys, musicCnt = 0;

  init_sound();
  song1();

  while(loop) {
    if( defeat ) {
		// animate dying duck
		show_defeat();
  		waitpad(255);
  		display_level();
  	} else if (goal_count == goal_max) {
		show_win();
  		waitpad(255);
		level++;
  		display_level();
	} else if( command_current == command_max ) {
	  keys = joypad();
  
  	  if(keys == J_B) { 
  		display_level();
	  } else {
		units_update();
	  }
	} else {
		cursor_update();
	}

	wait_vbl_done();
	musicCnt++;
	if (musicCnt == 4) {
		update_music();
		musicCnt = 0;
	}
	
  }
}
