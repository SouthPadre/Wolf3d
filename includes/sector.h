//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//

#ifndef WOLF3D_SECTOR_H
#define WOLF3D_SECTOR_H

/* Sectors: Floor and ceiling height; list of edge vertices and neighbors */

    static struct sector
    {
        float floor, ceil;
        struct xy { float x,y; } *vertex; // Each vertex has an x and y coordinate
        signed char *neighbors;		   // Each edge may have a corresponding neighboring sector
        unsigned npoints;				 // How many vertexes there are
    } *sectors = NULL;

#endif //WOLF3D_SECTOR_H
