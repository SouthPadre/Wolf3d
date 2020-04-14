//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//

#include <wolf3d.h>

void UnloadData()
{
    for(unsigned a=0; a<NumSectors; ++a) free(sectors[a].vertex), sectors[a].vertex=NULL;
    for(unsigned a=0; a<NumSectors; ++a) free(sectors[a].neighbors), sectors[a].neighbors=NULL;
    free(sectors);
    sectors	= NULL;
    NumSectors = 0;
}