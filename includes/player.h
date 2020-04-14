//
// Created by OUT-Takzhanov-AA on 14.04.2020.
//

#ifndef WOLF3D_PLAYER_H
#define WOLF3D_PLAYER_H
/* Player: location */
    static struct player
    {
        struct xyz { float x,y,z; } where,	  // Current position
        velocity;   // Current motion vector
        float angle, anglesin, anglecos, yaw;   // Looking towards (and sin() and cos() thereof)
        unsigned sector;						// Which sector the player is currently in
    } player;
#endif //WOLF3D_PLAYER_H
