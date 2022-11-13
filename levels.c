#include <gb/gb.h>
#include "example_level.map"

#define MAP_SIZE 63

// Load level map elements
void show_level(UBYTE *src) {
  UBYTE i, t, index;
  UWORD offset, j, row, col;
  
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
	  unit_pos[index+6] = t > 3; 
	  
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
  
    // load commands
  /*command_max = sizeof(src) / sizeof(src[0]);
  for (i = MAP_SIZE; i != command_max; i++) {
    commands[i-MAP_SIZE] = src[i];
  }
  command_max -= MAP_SIZE;
  */
  // hide unused units
  
  
  // show commands
  for(i = 0; i != command_max; i++) {
  	current_level[COMMAND_INDEX_FIRST + (i<<1)] = 54 + (commands[i] - CommandUp) / 4;
  }
  
  current_level[COMMAND_INDEX_FIRST + 20] = 84;
  set_bkg_tiles(0, 0, 20, 18, current_level);
}

const UBYTE level1_commands[] = {
  CommandDown, CommandRight, CommandDown
};
const UBYTE level1[] = {
  CritterDown,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapBlocked,MapEmpty,MapBlocked,MapBlockedPlantA,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapBlocked,
  MapEmpty,MapGoalTwo,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapBlockedPlantB,MapEmpty,MapBlocked,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalThree,
  MapBlockedRockA,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapBlocked,
};

const UBYTE level2_commands[] = {
  CommandUp, CommandDown, CommandLeft
};
const UBYTE level2[] = {
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlockedRockB,MapEmpty,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlockedRockA,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapGoalTwo,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapGoalThree,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
};

const UBYTE level3_commands[] = {
  CommandUp
};