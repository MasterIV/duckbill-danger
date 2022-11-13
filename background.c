// Fill level fixed UI elements (border, map, preview)
void init_background(UBYTE *output) {
  output[0] = 1;
}

// Update level with variable level elements
void update_background(UBYTE *objects, UBYTE *background) {
  UWORD x, y, offset;
  for (x = 0; x != 9; x++) {
    for (y = 0; y != 7; y++) {
	  offset = y + x;
	  
	  // TODO !!!
	  background[offset] = objects[x];
	}
  }
}