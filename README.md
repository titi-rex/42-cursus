# CC2-so_long
My take on 42 project so-long <br>
### Feature : <br>
- movement and idle animation <br>
- ennemy patrol with random spawn and random move <br>
- death and victory animation <br>
- several sprites for collectible and wall <br>

### Control :
Arrow keys for movement <br>
In bonus, space skip your turn, making enemy try to move <br>
Escape quit the game <br>

### Sprites credits :
#### Found on itch.io <br>
FreePixelFood by Henry Software <br> 
Sprout Lands Asset Pack by Cup NooBle <br>
Cute Legends Heroes Meow-Knight by 9E0 <br>
Silver Font by PoppyWorks <br>
Complete GUI Essential Pack by Crusenho <br>
Skinless Yarik By Novely <br>
#### Found on opengameart.org 
Cardboard Box by cinamerg <br>

### How did i do ?
#### General
I use a structure storing everything i need for the game.
#### Map parsing
First step : get the map. Rather than use GNL, i made a function reading the file in one shot, then split the result by '\n' .<br>
After ward the parsing is quite easy, the biggest difficulty being finding if there is a path. To do that, i used a simple backtraking function. <br>
Th map is stored in struct with position of wall, collectible, starting position and exit in a char ** <br>
#### The game
At start, i load all my sprites into my struc, if a load fail, the program exit. <br>
I print one time all my map, then i only print what i need to print, ie when player move, i "erase" the player sprite by putting a grass sprite over it, and print the player sprite at the new location. <br>
Before moving, the game check if the movement if authorized, ie if there isn't a wall at the new location. <br>
After moving, the map is updated, in particular the number of collectible, and a comparison between player position, exit and enemy trigger end events <br>

