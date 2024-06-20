# cpp_class_gen
cpp class generator script <br>
This script help you generate your cpp class <br>
Usage : ./class-gen.sh newClass or ./class-gen.sh <br>
<br>
```bash
chmod +x class-gen.sh && cp class-gen.sh ~/.local/bin/ && alias class="~/.local/bin/class-gen.sh" <br>
```
<br>
 eventually make a permanent alias <br>

 # so_long-map-generattor
A map generator  for so_long 42 project  (linux) <br>


## Install
just make in

## Note
This generator is made for unix-like system, using /dev/urandom to generate random-filled map <br>
Map format is specific to so_long project from 42 school <br>
You can change the distribution of Token and change Token via the DISTRIBUTION macro in map_gen.h <br>
Token are E : exit, P : player, 0 : floor, 1 : wall, C : collectible <br>
This map generator doesn't perform very well with little size <br>
Warning ! Do not change relative position of E and P in distribution, E first and P last. Otherwise you gonna have more than one exit and starting position <br>
Warning ! Due to random nature of the map, if you increase too much the wall in distribution, there will be no path possible and you'll end up with a non-valid map <br>

## Use
map_gen take 2 or 3 argument : map's name, height and width (width can be ignored for a square map) <br>
