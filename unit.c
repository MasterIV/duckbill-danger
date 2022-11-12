#define UNIT_SPRITE_INDEX 8

UBYTE unit_animation = 0;
UBYTE unit_count = 0;
WORD unit_pos[20];

const UBYTE unit_directions[] = {
  10,// up
  42,// right
  26,// donw
  58// left
};

void unit_set_direction(UBYTE index, UBYTE d) {
	unit_pos[index+2] = d;
	
	switch(d) {
		case 0: unit_pos[index+3] = 0; unit_pos[index+4] = -1; break; // up
		case 1: unit_pos[index+3] = 1; unit_pos[index+4] = 0; break; // rigth
		case 2: unit_pos[index+3] = 0; unit_pos[index+4] = 1; break; // down
		case 3: unit_pos[index+3] = -1; unit_pos[index+4] = 0; break; // left
	}
}

UBYTE get_tile_at(UBYTE x, UBYTE y) {
	WORD t = ((x-8)>>3) + ((y-16)>>3)*20;
	
	if(x < 16 || y < 24 || x > 152 || y > 144 )
		return MapBlocked;
		
	return current_level[t];
}

UBYTE unit_get_destination(UBYTE index) {
	return get_tile_at(
	  unit_pos[index] + (unit_pos[index+3]<<4),
	  unit_pos[index+1] + (unit_pos[index+4]<<4)
	);
}

void units_init(UBYTE count) {
	unit_count = count;
	
	unit_pos[0] = 16; // x
	unit_pos[1] = 24; // y
	unit_set_direction(0, 0);

	unit_pos[5] = 64; // x
	unit_pos[6] = 88; // y
	unit_set_direction(5, 1);
	
	// hide unused units sprites
}

void units_update() {
  UBYTE i, index, x, y, d, frame;
  
  frame = ((unit_animation>>2)%4)<<2;
  
  for(i = 0; i != unit_count; i++) {
    index = i*5;
  	x = unit_pos[index];
	y = unit_pos[index+1];
	
	
  	if(unit_animation == 0) {
		// check if current tile is command and adjust direction according to it
		switch(get_tile_at(x, y)) {
			case CommandUp: unit_set_direction(index, 0); break;
			case CommandRight: unit_set_direction(index, 1); break;
			case CommandLeft: unit_set_direction(index, 2); break;
			case CommandDown: unit_set_direction(index, 3); break;
		}
		
		// while next tile is blocked, turn left
		while(unit_get_destination(index) == MapBlocked) {
			if(unit_pos[index+2] == 0) unit_set_direction(index, 3);
			else unit_set_direction(index, unit_pos[index+2]-1);
		}
	} 
	
	
	// move sprites to critter position
  	x = unit_pos[index] += unit_pos[index+3];
	y = unit_pos[index+1] += unit_pos[index+4];
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1), x, y);
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1)+1, x+8, y);
	
	// set right animation sprite in correct direction
	d = unit_pos[index+2];
    set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1), unit_directions[d]+frame);
    set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1)+1, unit_directions[d]+frame+2);
	
  }
  
  if(unit_animation == 0) 
		unit_animation = 16;
  unit_animation--;
}