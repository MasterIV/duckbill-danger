#define UNIT_SPRITE_INDEX 8
#define UNIT_MAX_X 152
#define UNIT_MAX_Y 128

#define UNIT_TYPE_GOOD 0
#define UNIT_TYPE_BAD 1
#define UNIT_TYPE_DEAD 2
#define UNIT_TYPE_HATCHED 3

#define UNIT_DEAD 98
#define UNIT_HATCHED 114

UBYTE unit_animation = 0;
UBYTE unit_count = 0;

// x, y, d, mx, my, type (good, bad, dead, victory)
WORD unit_pos[60];

const UBYTE unit_directions[] = {
  10,// up
  42,// right
  26,// donw
  58// left
};

const UBYTE enemy_directions[] = {
  90,// up
  74,// right
  98,// donw
  82// left
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

void unit_show(UBYTE i, UBYTE index, UBYTE frame) {
    UBYTE  x, y, d;

	// move sprites to critter position
  	x = unit_pos[index];
	y = unit_pos[index+1];
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1), x, y);
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1)+1, x+8, y);
	
	// set right animation sprite in correct direction
	d = unit_pos[index+2];
	UBYTE myType = unit_pos[index+5];
	
	if(myType == UNIT_TYPE_HATCHED) {
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1), UNIT_HATCHED+frame);
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1)+1, UNIT_HATCHED+frame+2);
	} else if(myType == UNIT_TYPE_BAD) {
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1), enemy_directions[d]+frame%8);
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1)+1, enemy_directions[d]+frame%8+2);
	} else if(myType == UNIT_TYPE_GOOD) {
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1), unit_directions[d]+frame);
    	set_sprite_tile(UNIT_SPRITE_INDEX + (i<<1)+1, unit_directions[d]+frame+2);
	}
}

void unit_defeat(UBYTE index) {
	if(unit_pos[index+5] == UNIT_TYPE_GOOD)
		defeat = index+1;
	else 
		unit_pos[index+5] = UNIT_TYPE_DEAD;
}

void unit_check_victory(UBYTE index, UBYTE goal) {
	// ignore hatched platypus
	if(unit_pos[index+5] == UNIT_TYPE_HATCHED) return;

	if(goal != goal_count || unit_pos[index+5] == UNIT_TYPE_BAD) {
		// wrong goal order!
		defeat = index+1;
		return;
	}
		
	unit_pos[index+5] = UNIT_TYPE_HATCHED;
	goal_count++;
}

UBYTE get_tile_at(UBYTE x, UBYTE y) {
	WORD t = ((x-8)>>3) + ((y-16)>>3)*20;
	
	if(x < 16 || y < 24 || x > UNIT_MAX_X || y > UNIT_MAX_Y )
		return MapBlocked;
	if(current_level[t] == MapBlockedPlantA)
		return MapBlocked;
	if(current_level[t] == MapBlockedPlantB)
		return MapBlocked;
	if(current_level[t] == MapBlockedRockB)
		return MapBlocked;
		
	return current_level[t];
}

UBYTE unit_get_destination(UBYTE index) {
	return get_tile_at(
	  unit_pos[index] + (unit_pos[index+3]<<4),
	  unit_pos[index+1] + (unit_pos[index+4]<<4)
	);
}

void units_update() {
  UBYTE i, index, x, y, frame;
  
  frame = ((unit_animation>>2)%4)<<2;
  
  for(i = 0; i != unit_count; i++) {
    index = i*6;
  	x = unit_pos[index];
	y = unit_pos[index+1];	
	
  	if(unit_animation == 0 && unit_pos[index+5] != UNIT_TYPE_DEAD) {
		if (unit_pos[index+5] == UNIT_TYPE_BAD) {
		
			// Check if snake touches a cute little duckling
			for (UBYTE j = 0; j != unit_count; j++) {
				UBYTE otherIndex = j*6;
				if (unit_pos[otherIndex+5] == UNIT_TYPE_GOOD) {
					UBYTE otherX = unit_pos[otherIndex];
					UBYTE otherY = unit_pos[otherIndex+1];
					if (otherX == x && otherY == y) {
						unit_defeat(otherIndex);
					}
				}
			}
		}
		
		// check if current tile is command and adjust direction according to it
		switch(get_tile_at(x, y)) {
			case CommandUp: unit_set_direction(index, 0); break;
			case CommandRight: unit_set_direction(index, 1); break;
			case CommandDown: unit_set_direction(index, 2); break;
			case CommandLeft: unit_set_direction(index, 3); break;
			case MapGoalOne: unit_check_victory(index, 0); break;
			case MapGoalTwo: unit_check_victory(index, 1); break;
			case MapGoalThree: unit_check_victory(index, 2); break;
			case MapGoalFour: unit_check_victory(index, 3); break;
			case MapTrap: unit_defeat(index); break;
		}
		
		// while next tile is blocked, turn left
		while(unit_get_destination(index) == MapBlocked) {
			if(unit_pos[index+2] == 0) unit_set_direction(index, 3);
			else unit_set_direction(index, unit_pos[index+2]-1);
		}
	} 
	
	if(unit_pos[index+5] < UNIT_TYPE_DEAD) {
  		unit_pos[index] += unit_pos[index+3];
		unit_pos[index+1] += unit_pos[index+4];
	}
	
	unit_show(i, index, frame);
  }
  
  if(unit_animation == 0) 
		unit_animation = 16;
  unit_animation--;
}