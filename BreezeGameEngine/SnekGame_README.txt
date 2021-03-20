SNEK GAME

GAME PLAY

Enter/Space will begin the game or restart it from the "Game Over" Screen

Snake initially be at rest until theres input from the arrow keys or WASD keys.

Snake will continue to move forward at an automatic pace- use the arrow or WASD keys to change direction

Collecting the white food tiles elongates and increases the speed of the snake

Each food eaten will generate a new food as well as a Doom tile.

Colliding with the game bounds the snake body, or a Doom tile results in Game Over


OPTIONS FILE

Some game parameters may be controlled in the "configs.txt" file. These are decribed below.
This file is order independent, and any missed or invalid values should be automatically set to the default.

[Board Size]
Determines the number of horizontal and vertical tiles in the game board. 
(note: if there is a problem with either value, both are set to the default)

MAX: 38 26
DEFAULT: 30 20

[Snake Color : 0 - Natural, 1 - Rainbow]
Determine the coloration of the snake body segment.

0 Gives a natural body made of a few hues of green, with a yellow head

1 Gives a bright, rainbow colored body.

DEFAULT: 0

[Snake Shape : 0 - Flat, 1 - 3D]

Determines the drawing effect of the snake body.

0 Gives smooth, flat body segments

1 Gives uses beveled segments to give a 3D appearance

Default: 0
