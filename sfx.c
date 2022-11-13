#include <gb/gb.h>
#include <stdio.h>

typedef enum {
  C3, Cd3, D3, Dd3, E3, F3, Fd3, G3, Gd3, A3, Ad3, B3,
  C4, Cd4, D4, Dd4, E4, F4, Fd4, G4, Gd4, A4, Ad4, B4,
  C5, Cd5, D5, Dd5, E5, F5, Fd5, G5, Gd5, A5, Ad5, B5,
  C6, Cd6, D6, Dd6, E6, F6, Fd6, G6, Gd6, A6, Ad6, B6,
  C7, Cd7, D7, Dd7, E7, F7, Fd7, G7, Gd7, A7, Ad7, B7,
  C8, Cd8, D8, Dd8, E8, F8, Fd8, G8, Gd8, A8, Ad8, B8,
  SILENCE
} Pitch;

const UWORD frequencies[] = { //values based on a formula used by the GB processor
  44, 156, 262, 363, 457, 547, 631, 710, 786, 854, 923, 986,
  1046, 1102, 1155, 1205, 1253, 1297, 1339, 1379, 1417, 1452, 1486, 1517,
  1546, 1575, 1602, 1627, 1650, 1673, 1694, 1714, 1732, 1750, 1767, 1783,
  1798, 1812, 1825, 1837, 1849, 1860, 1871, 1881, 1890, 1899, 1907, 1915,
  1923, 1930, 1936, 1943, 1949, 1954, 1959, 1964, 1969, 1974, 1978, 1982,
  1985, 1988, 1992, 1995, 1998, 2001, 2004, 2006, 2009, 2011, 2013, 2015,
  0
};
enum DurationNote
{
    LONG = 0x84U,
    SHORT = 0x81U,
    LONG_LONG = 135
};

enum WaveDuty {
	WAVE_A = 0,
    WAVE_B = 0x40U,
    WAVE_C = 0x80U,
    WAVE_D = 0xC0U,
};

typedef struct {
	Pitch p; // pitch
	UINT16 w; // wave duty
	UINT16 l; // length
} Note;

void init_sound() {
  NR52_REG = 0x80U;
  NR51_REG = 0x00U;
  NR50_REG = 0xFFU;
}
UBYTE music_tick = 0;
UBYTE music_beat = 0;
UBYTE music_speed = 0;
UBYTE music_length = 0;

const Note *channel1[128];
const Note *channel2[128];
const Note *noise[128];

void update_music() {
  if(!(music_tick % music_speed)) {
	music_tick = 0;
	
  	NR10_REG = 0x00U; //pitch sweep
	
	if(channel1[music_beat]->p != SILENCE) {
	  NR11_REG = channel1[music_beat]->w; //wave duty
	  NR12_REG = channel1[music_beat]->l; //envelope
	  NR13_REG = (UBYTE)frequencies[channel1[music_beat]->p]; //low bits of frequency
	  NR14_REG = 0x80U | ((UWORD)frequencies[channel1[music_beat]->p]>>8); //high bits of frequency (and sound reset)
	  NR51_REG |= 0x11U;
	}
	
	if(channel2[music_beat]->p != SILENCE) {
	  NR21_REG = channel2[music_beat]->w; //wave duty
	  NR22_REG = channel2[music_beat]->l; //envelope
	  NR23_REG = (UBYTE)frequencies[channel2[music_beat]->p]; //low bits of frequency
	  NR24_REG = 0x80U | ((UWORD)frequencies[channel2[music_beat]->p]>>8); //high bits of frequency (and sound reset)
	  NR51_REG |= 0x22U;
	}
	
    
	if(noise[music_beat]->p != SILENCE) {
	  NR41_REG = noise[music_beat]->w; //wave duty
	  NR42_REG = noise[music_beat]->l; //envelope
	  NR43_REG = (UBYTE)frequencies[noise[music_beat]->p]; //low bits of frequency
	  NR44_REG = 0x80U | ((UWORD)frequencies[noise[music_beat]->p]>>8); //high bits of frequency (and sound reset)
	  NR51_REG |= 0x88U;
	}
	
	music_beat++;
	if(music_beat == music_length) {
	  music_beat = 0;
	}
  }
	   
  music_tick++;
}


void sound_correct() {
  // {D3(262), WAVE_C(0x80U,), LONG(0x84U)}, //correct

  	NR41_REG = 0x80U; //wave duty // WAVE_C
	NR42_REG = 0x84U; //envelope //<-LONG
    NR43_REG = 0x06U; //low bits of frequency
	NR44_REG = 0x81U; //high bits of frequency (and sound reset)
	NR51_REG |= 0x88U;
}