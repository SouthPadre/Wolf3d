//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//
#include <wolf3d.h>

/* vline: Draw a vertical line on screen, with a different color pixel in top & bottom */

void vline(const int x, int y1,int y2, const int top, const int middle, const int bottom)
{
    int *const restrict pix = surface->pixels;
    y1 = clamp(y1, 0, H-1);
    y2 = clamp(y2, 0, H-1);
    if(y2 == y1)
        pix[y1*W+x] = middle;
    else if(y2 > y1)
    {
        pix[y1*W+x] = top;
        for(int y=y1+1; y<y2; ++y) pix[y*W+x] = middle;
        pix[y2*W+x] = bottom;
    }
}