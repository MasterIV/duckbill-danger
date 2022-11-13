#include <gb/gb.h>
#include <stdio.h>
#include "tiles.c"

#include "level.tiles"
#include "units.tiles"

UBYTE loop = 1;
UBYTE defeat = 0;
UBYTE current_level[360];

UBYTE goal_count = 0;
UBYTE goal_max = 2;

UBYTE command_current = 0;
UBYTE command_max = 4;
UBYTE commands[] = {
	CommandUp,
	CommandRight,
	CommandLeft,
	CommandDown
};

// UBYTE level = 0;
// UBYTE level_objects[63];

/*
 Sprites:
   0-7 Cursor
   8-15 Creepers
   16-31 Enemies / Hazards?
*/

#include "cursor.c"
#include "unit.c"
#include "levels.c"

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

  set_sprite_data(0, 200, units);
  set_bkg_data(0, 200, level);

  show_level(level1);
  
  cursor_init();
  
  SHOW_SPRITES;
  SHOW_BKG;
  DISPLAY_ON;
  
  while(loop) {
    if( defeat ) {
		// animate dying duck
		// show game over screen
  		waitpad(255);
  		show_level(level1);
  	} else if( command_current == command_max )
		units_update();
	else
		cursor_update();

	wait_vbl_done();
  }
}
