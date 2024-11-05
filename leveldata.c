const UBYTE level1_commands[] = {
  CommandRight
};
const UBYTE level1[] = {
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,
  CritterUp,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty
};

const UBYTE level2_commands[] = {
  CommandUp, CommandLeft, CommandDown
};
const UBYTE level2[] = {
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  CommandRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,CritterDown,MapEmpty,MapTrap,MapEmpty,MapBlockedRockB,MapEmpty,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapBlocked,MapEmpty,MapBlockedRockB
};

const UBYTE level3_commands[] = {
  CommandLeft, CommandLeft
};
const UBYTE level3[] = {
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlockedPlantA,MapEmpty,MapEmpty,MapTrap,
  MapEmpty,MapEmpty,MapBlockedPlantB,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapTrap,MapEmpty,CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapBlockedPlantA,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne
};

const UBYTE level4_commands[] = {
  CommandRight, CommandRight
};
const UBYTE level4[] = {
  MapEmpty,MapEmpty,MapEmpty,HazardDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandDown,MapBlocked,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty
};

const UBYTE level5_commands[] = {
  CommandRight, CommandLeft
};
const UBYTE level5[] = {
  MapGoalOne,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapTrap,MapEmpty,CritterDown,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalTwo,
  CritterUp,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty
};

const UBYTE level6_commands[] = {
  CommandRight, CommandUp, CommandLeft
};
const UBYTE level6[] = {
  MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapBlocked,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapBlocked,MapEmpty,MapEmpty,
  MapGoalTwo,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CritterLeft,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  CritterUp,MapEmpty,CommandUp,MapTrap,MapEmpty,MapEmpty,HazardUp,MapEmpty,MapEmpty
};

const UBYTE level7_commands[] = {
  CommandDown, CommandDown, CommandRight, CommandRight, CommandRight, CommandRight
};
const UBYTE level7[] = {
  CritterDown,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapBlocked,CommandDown,CommandDown,HazardDown,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandDown,CommandLeft,CommandLeft,
  MapBlockedRockB,MapBlocked,MapBlocked,MapEmpty,MapBlocked,MapBlocked,CommandDown,MapBlocked,MapBlocked,
  MapBlocked,MapBlockedRockB,MapTrap,MapEmpty,MapEmpty,MapEmpty,CommandLeft,MapBlockedRockB,MapBlocked,
  MapBlocked,MapBlocked,MapBlockedRockB,MapTrap,MapEmpty,MapEmpty,MapBlockedRockB,MapBlocked,MapBlockedRockB,
  MapBlocked,MapBlocked,MapBlocked,MapBlockedRockB,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,
  MapBlocked,MapBlockedRockB,MapBlocked,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne
};

const UBYTE level8_commands[] = {
  CommandRight, CommandRight, CommandLeft, CommandLeft, CommandUp, CommandDown
};
const UBYTE level8[] = {
  MapBlockedPlantB,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CritterLeft,
  MapEmpty,CritterDown,MapEmpty,CommandDown,MapEmpty,HazardLeft,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapBlocked,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapTrap,MapGoalTwo,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CritterLeft,MapEmpty,
  MapEmpty,MapTrap,MapGoalThree,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty
};

const UBYTE level9_commands[] = {
  CommandUp, CommandDown, CommandRight, CommandRight, CommandLeft
};
const UBYTE level9[] = {
  MapBlockedPlantA,MapEmpty,MapEmpty,MapBlockedPlantB,HazardDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlockedPlantA,MapEmpty,MapEmpty,MapTrap,
  MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  CommandDown,MapEmpty,HazardRight,MapEmpty,CritterUp,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,CommandDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandDown,MapTrap,MapEmpty,MapEmpty,
  MapGoalOne,MapEmpty,MapEmpty,MapEmpty,HazardUp,MapEmpty,MapEmpty,MapEmpty,MapEmpty
};


const UBYTE level10_commands[] = {
  CommandDown, CommandLeft
};

const UBYTE level10[] = { // 1 player 3 enemies timetrap 
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapBlocked,MapBlocked,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty
};
/*const UBYTE level10[] = { // 1 player 3 enemies timetrap .. testarrows
  CritterRight,MapEmpty,MapEmpty,CommandDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,
  MapEmpty,MapBlocked,MapEmpty,CommandLeft,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapBlocked,MapBlocked,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapEmpty,MapEmpty,MapEmpty
};*/

const UBYTE level11_commands[] = {
  CommandRight, CommandDown, CommandDown, CommandUp, CommandRight, CommandDown,CommandRight
};

const UBYTE level11[] = { // 2 player 4 volatile enemies
  MapTrap,MapTrap,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapBlocked,MapGoalOne,MapEmpty,
  HazardRight,MapTrap,MapEmpty,CritterLeft,CritterRight,MapEmpty,MapTrap,HazardLeft,MapBlocked,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalTwo
};
/*const UBYTE level[] = { // 2 player 4 volatile enemies .. testarrows
  MapTrap,MapTrap,MapTrap,MapEmpty,MapEmpty,CommandRight,MapEmpty,CommandDown,MapEmpty,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,
  MapTrap,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapBlocked,MapGoalOne,MapEmpty,
  HazardRight,MapTrap,CommandDown,CritterLeft,CritterRight,CommandUp,MapTrap,HazardLeft,MapBlocked,
  MapTrap,MapEmpty,CommandRight,MapEmpty,MapEmpty,CommandDown,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,CommandRight,MapEmpty,MapEmpty,MapGoalTwo
};*/

const UBYTE level12_commands[] = {
  CommandRight, CommandDown, CommandDown, CommandDown, CommandUp, CommandLeft 
};

const UBYTE level12[] = { // 3 player 3 enemies 
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,
  MapTrap,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapBlocked,MapGoalTwo,MapEmpty,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,HazardLeft,HazardLeft,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapGoalOne,MapEmpty,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,MapEmpty,MapEmpty,
  MapTrap,MapTrap,MapEmpty,MapGoalThree,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty
};
/*const UBYTE level[] = { // 3 player 3 enemies .. testarrows
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandRight,MapEmpty,CommandDown,MapTrap,
  MapTrap,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapBlocked,MapGoalTwo,MapEmpty,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandDown,MapTrap,
  CritterRight,CommandDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,HazardLeft,HazardLeft,
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandUp,MapEmpty,MapEmpty,MapEmpty,
  MapGoalOne,CommandLeft,MapEmpty,MapTrap,MapTrap,MapTrap,MapBlocked,MapEmpty,MapEmpty,
  MapTrap,MapTrap,MapEmpty,MapGoalThree,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty
};*/

const UBYTE level13_commands[] = {
  CommandDown, CommandDown
};

const UBYTE level13[] = {// 1 player 4 enemies run! 
  CritterRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapTrap,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapTrap,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapEmpty,MapTrap,MapBlocked,
  MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapBlocked,
  MapTrap,MapEmpty,MapBlocked,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapTrap
};
/*const UBYTE level[] = {// 1 player 4 enemies run! ..testarrows
  CritterRight,MapEmpty,MapEmpty,CommandDown,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,
  MapEmpty,HazardDown,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapTrap,MapBlocked,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapTrap,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,HazardLeft,MapEmpty,MapEmpty,MapTrap,MapBlocked,
  MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapBlocked,
  MapTrap,MapEmpty,MapBlocked,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapGoalOne,MapTrap
};*/

const UBYTE level14_commands[] = {
  CommandRight, CommandLeft, CommandRight, CommandUp, CommandUp
};
const UBYTE level14[] = {
  MapGoalOne,MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapTrap,MapEmpty,CritterDown,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapGoalTwo,
  CritterUp,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapTrap,MapEmpty,MapEmpty
};

const UBYTE levelend_commands[] = {
  CommandUp
};
const UBYTE levelend[] = {
  CommandRight,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandDown,
  MapEmpty,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,
  MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapGoalOne,MapBlocked,MapEmpty,MapEmpty,MapEmpty,
  MapEmpty,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapBlocked,MapEmpty,MapEmpty,
  CritterUp,MapBlocked,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapBlocked,MapEmpty,
  MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,MapEmpty,CommandLeft
};