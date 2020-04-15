//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//

#include <wolf3d.h>

void UnloadData(unsigned *NumSectorsS, struct sector *sectorsS)
{
    struct sector *sectors = sectorsS;
    unsigned NumSectors = *NumSectorsS;
    for(unsigned a=0; a<NumSectors; ++a) free(sectors[a].vertex), sectors[a].vertex=NULL;
    for(unsigned a=0; a<NumSectors; ++a) free(sectors[a].neighbors), sectors[a].neighbors=NULL;
    free((void*)sectors);
    sectors	= NULL;
    NumSectors = 0;
    *NumSectorsS = NumSectors;

}