#ifndef ENUMS_H
#define ENUMS_H

namespace MWEngine
{
/** Enumerator for the directions */


enum 
{
	STATE_MENU,
	STATE_STARTLEVEL,
	STATE_GAMEPLAY,
	STATE_LOSTLIFE,
	STATE_GAMEOVER
};

enum
{
    STOP, /// 0
    LEFT, /// 1
    RIGHT, /// 2
    UP,  /// 3
    DOWN ///4
};


enum
{
	TILESIZE = 128
};

enum
{
	TILE_Q,
	TILE_W,
	TILE_E,
	TILE_A,
	TILE_S,
	TILE_D,
	TILE_Z,
	TILE_X,
	TILE_C,
	TILE_R,
	TILE_T,
	TILE_F,
	TILE_G,
	TILE_SIGN_2,
	

};

enum
{
    B0_SIGN1,
    B1_SIGN2,
    B2_BUSH1,
    B3_BUSH2,
    B4_BUSH3,
    B5_BUSH4,
    B6_TREE1,
    B7_TREE2,
    B8_TREE3
};

enum
{
	HUD_MARGIN_TOP = 30,
	HUD_MARGIN_LEFT = 50
};

}
#endif
