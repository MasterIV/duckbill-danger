#include <gb/gb.h>
#include "level_tiles.tiles"
#include "example_level.map"

#define MAP_SIZE 63

// Load level map elements
void show_level(UBYTE *src) {
  UBYTE i, t, index;
  UWORD offset, j, row, col;
  
  DISPLAY_OFF;
  
  // reset gloabls
  defeat = 0;
  unit_animation = 0;
  unit_count = 0;
  goal_count = 0;
  goal_max = 0;
  command_current = 0;
  
  // replace this if space gets tight!
  for(j=0; j != 360; j++) {
	  current_level[j] = example_level[j];
  }
  
  // load level
  for(i = 0; i != MAP_SIZE; i++) {
  	t = src[i];
  	row = i/9;
	col = i%9;
	
	if(t < MapEmpty) {
	  // spawn units
	  index = unit_count * 6;
	  unit_pos[index] = 16 + (col<<4);
	  unit_pos[index+1] = 24 + (row<<4);
	  unit_set_direction(index, t%4);
	  unit_pos[index+5] = t > 3; 
	  
	  unit_show(unit_count, index, 0);
	  
	  unit_count++;
	  t = MapEmpty;
	} else if(t == MapGoalOne || t == MapGoalTwo || t == MapGoalThree || t == MapGoalFour) {
	  // count how many objectives are on the map
	  goal_max++;
	}
	
	offset = (i<<1)+row*22;
	current_level[21+offset] = t;
	current_level[22+offset] = t+1;
	current_level[41+offset] = t+2;
	current_level[42+offset] = t+3;
  }
  
  // hide unused units
  for(i = unit_count; i != 10; i++) {
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1), 0, 0);
  	move_sprite(UNIT_SPRITE_INDEX + (i<<1)+1, 0, 0);
  }
  
  // show commands
  for(i = 0; i != command_max; i++) {
  	current_level[COMMAND_INDEX_FIRST + (i<<1)] = 54 + (commands[i] - CommandUp) / 4;
  }
  
  current_level[COMMAND_INDEX_FIRST + 20] = 84;
  set_sprite_data(0, 200, units);
  set_bkg_data(0, 90, level_tiles);
  set_bkg_tiles(0, 0, 20, 18, current_level);
  SHOW_SPRITES;
  DISPLAY_ON;
}


void display_level() {
	switch(level) {
		case 0:
			command_max = 1;
			commands = level1_commands;
			show_level(level1);
			break;
		case 1:
			command_max = 3;
			commands = level2_commands;
			show_level(level2);
			break;
		case 2:
			command_max = 2;
			commands = level3_commands;
			show_level(level3);
			break;
		case 3:
			command_max = 2;
			commands = level4_commands;
			show_level(level4);
			break;
		case 4:
			command_max = 2;
			commands = level5_commands;
			show_level(level5);
			break;
		case 5:
			command_max = 3;
			commands = level6_commands;
			show_level(level6);
			break;
		case 6:
			command_max = 6;
			commands = level7_commands;
			show_level(level7);
			break;
		case 7:
			command_max = 6;
			commands = level8_commands;
			show_level(level8);
			break;
		case 8:
			command_max = 5;
			commands = level9_commands;
			show_level(level9);
			break;
		case 9:
			command_max = 2;
			commands = level10_commands;
			show_level(level10);
			break;			
		case 10:
			command_max = 7;
			commands = level11_commands;
			show_level(level11);
			break;	
		case 11:
			command_max = 6;
			commands = level12_commands;
			show_level(level12);
			break;	
		case 12:
			command_max = 2;
			commands = level13_commands;
			show_level(level13);
			break;
		case 13:
			command_max = 5;
			commands = level14_commands;
			show_level(level14);
			break;
		default:
			command_max = 1;
			commands = levelend_commands;
			show_level(levelend);
			break;
	}
}