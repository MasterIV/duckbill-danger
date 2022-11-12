#define CURSOR_X_MIN 8
#define CURSOR_X_MAX 136
#define CURSOR_Y_MIN 16
#define CURSOR_Y_MAX 128
#define CURSOR_SPEED 8

struct Cursor {
  UBYTE x;
  UBYTE y;
  BYTE dir_x;
  BYTE dir_y;
} cursor;

UBYTE cursor_counter;


UBYTE commands[] = {
	CommandUp,
	CommandRight,
	CommandLeft,
	CommandDown
};

void cursor_move(WORD x, WORD y) {
  WORD destx = cursor.x + x * CURSOR_SPEED;
  WORD desty = cursor.y + y * CURSOR_SPEED;
  
  // don't move out the map
  if(destx < CURSOR_X_MIN || destx > CURSOR_X_MAX || desty < CURSOR_Y_MIN || desty > CURSOR_Y_MAX) 
	return;
  
  cursor.dir_x = x;
  cursor.dir_y = y;
  cursor_counter = CURSOR_SPEED;
  
  //move_cursor_sound();
}

void cursor_update() {
  UBYTE keys;
  keys = joypad();
  
  if(cursor_counter == 0) {
	switch(keys) {
	  case J_UP: cursor_move(0, -2); break;
	  case J_DOWN: cursor_move(0, 2); break;
	  case J_LEFT: cursor_move(-2, 0); break;
	  case J_RIGHT: cursor_move(2, 0); break;
	  // case J_A: cursor_toggle(); return;
	  // case J_SELECT:return;
	}
  } else {
	cursor.x += cursor.dir_x;
	cursor.y += cursor.dir_y;
	cursor_counter--;
  }

  move_sprite(0, cursor.x, cursor.y);	
  move_sprite(1, cursor.x+8, cursor.y);	
  move_sprite(2, cursor.x+24, cursor.y);	
  move_sprite(3, cursor.x+16, cursor.y);	
  
  move_sprite(4, cursor.x, cursor.y+16);	
  move_sprite(5, cursor.x+8, cursor.y+16);
  move_sprite(6, cursor.x+24, cursor.y+16);	
  move_sprite(7, cursor.x+16, cursor.y+16);		
}

void cursor_reset() {
  cursor_counter = 0;
  cursor.x = CURSOR_X_MIN;
  cursor.y = CURSOR_Y_MIN;
  cursor.dir_x = 0;
  cursor.dir_y = 0;
}

void cursor_init() {
  // top left of cursor
  set_sprite_tile(0, 2);
  set_sprite_tile(1, 4);

  // top right of cursor
  set_sprite_tile(2, 2);
  set_sprite_prop(2, S_FLIPX);
  set_sprite_tile(3, 4);
  set_sprite_prop(3, S_FLIPX);

  // bottom left of cursor
  set_sprite_tile(4, 2);
  set_sprite_prop(4, S_FLIPY);
  set_sprite_tile(5, 4);
  set_sprite_prop(5, S_FLIPY);

  // bottom right of cursor
  set_sprite_tile(6, 2);
  set_sprite_prop(6, S_FLIPX | S_FLIPY);
  set_sprite_tile(7, 4);
  set_sprite_prop(7, S_FLIPX | S_FLIPY);
  
  cursor_reset();
  cursor_update();
}
