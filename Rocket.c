#include <gb/gb.h>
#include <stdio.h>
#include "tiles.c"

#include "level.tiles"
#include "units.tiles"
#include "example_level.map"

UBYTE loop = 1;
UBYTE current_level[360];




/*
 Sprites:
   0-7 Cursor
   8-15 Creepers
   16-31 Enemies / Hazards?
*/

#include "cursor.c"
#include "unit.c"

void main() {
  SPRITES_8x16;
  
  VBK_REG = 1;
  VBK_REG = 0;
  
  
UWORD j;
for(j=0; j != 360; j++) {
	current_level[j] = example_level[j];
}

  set_sprite_data(0, 200, units);
  set_bkg_data(0, 200, level);
  
  cursor_init();
  units_init(2);
  
  SHOW_SPRITES;
  SHOW_BKG;
  DISPLAY_ON;
  
  set_bkg_tiles(0, 0, 20, 18, current_level);
  
  
  while(loop) {
	cursor_update();
	//units_update();
	wait_vbl_done();
  }
}
