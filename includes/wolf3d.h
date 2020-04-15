//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//

#ifndef WOLF3D_WOLF3D_H
#define WOLF3D_WOLF3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
//#include <SDL.h>
#include <SDL2-2.0.12/include/SDL.h>

#include "sector.h"
#include "player.h"

//static SDL_Surface *restrict surface = NULL;
//static unsigned NumSectors = 0;

/* Define window size */
#define W 608
#define H 480
/* Define various vision related constants */
#define EyeHeight  6	// Camera height from floor when standing
#define DuckHeight 2.5  // And when crouching
#define HeadMargin 1	// How much room there is above camera before the head hits the ceiling
#define KneeHeight 2	// How tall obstacles the player can simply walk over without jumping
#define hfov (0.73f*H)  // Affects the horizontal field of vision
#define vfov (.2f*H)	// Affects the vertical field of vision



// Utility functions. Because C doesn't have templates,
// we use the slightly less safe preprocessor macros to
// implement these functions that work with multiple types.
#define min(a,b)			 (((a) < (b)) ? (a) : (b)) // min: Choose smaller of two scalars.
#define max(a,b)			 (((a) > (b)) ? (a) : (b)) // max: Choose greater of two scalars.
#define clamp(a, mi,ma)	  min(max(a,mi),ma)		 // clamp: Clamp value into set range.
#define vxs(x0,y0, x1,y1)	((x0)*(y1) - (x1)*(y0))   // vxs: Vector cross product
// Overlap:  Determine whether the two number ranges overlap.
#define Overlap(a0,a1,b0,b1) (min(a0,a1) <= max(b0,b1) && min(b0,b1) <= max(a0,a1))
// IntersectBox: Determine whether two 2D-boxes intersect.
#define IntersectBox(x0,y0, x1,y1, x2,y2, x3,y3) (Overlap(x0,x1,x2,x3) && Overlap(y0,y1,y2,y3))
// PointSide: Determine which side of a line the point is on. Return value: <0, =0 or >0.
#define PointSide(px,py, x0,y0, x1,y1) vxs((x1)-(x0), (y1)-(y0), (px)-(x0), (py)-(y0))
// Intersect: Calculate the point of intersection between two lines.
#define Intersect(x1,y1, x2,y2, x3,y3, x4,y4) ((struct xy) { \
	vxs(vxs(x1,y1, x2,y2), (x1)-(x2), vxs(x3,y3, x4,y4), (x3)-(x4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)), \
	vxs(vxs(x1,y1, x2,y2), (y1)-(y2), vxs(x3,y3, x4,y4), (y3)-(y4)) / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4)) })

struct sector * LoadData();
void MovePlayer(const float dx, const float dy, struct sector *sectorS, struct player *playerS);
void DrawScreen();
void UnloadData();
void vline(const int x, int y1,int y2, const int top, const int middle, const int bottom, SDL_Surface **restrict surface);

#endif //WOLF3D_WOLF3D_H
