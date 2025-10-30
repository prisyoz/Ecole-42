# So_long

> A project involving the creation of a _2D game_ with a graphical library, MiniLibX, the 42 graphical library.

### Overview
"So Long" is a simple 2D game where the player navigates a maze to reach the exit while avoiding obstacles and enemies. It consists of a mandatory part (basic gameplay) and an additional bonus part (with enemies and extra features). The game uses the MiniLibX library for graphics and input handling.

**Mandatory**: Implement a playable 2D game where the player navigates a maze to collect items and reach the exit. Focus is on map parsing, basic graphics, input handling, and a functional game loop.

**Bonus**: Add extra features such as animations, multiple enemy types, a timer or move counter, and enhanced graphics or sound effects to make the game more interactive and polished.

<img width="1200" height="700" alt="Screenshot from 2025-10-30 11-20-02" src="https://github.com/user-attachments/assets/72519364-deac-4394-b7e3-2faf627ab29f" />

---

### Compilation

To compile the project, run one of the following commands:

1. Compile the Mandatory Part
This will compile the basic version of the game without enemies:
```shell
make
```

This will generate an executable called so_long. You can then run the game with:
```shell
./so_long ./maps/normal_map.ber
```
**Note: The map file must have a .ber extension.**

2. Compile the Bonus Part
To enable the bonus features (like enemies), run:
```shell
make bonus
```

This will compile the version with extra features and generate an executable called so_long_bonus. You can run it with:
```shell
./so_long_bonus ./maps/bonus_map.ber
```
**Note: Bonus maps must also have a .ber extension.**

---

### Map Format

The game uses a map to define the layout of the maze. The map is a grid, and each character represents a different element in the game world.

Characters in the Map: <br>
P = Player (starting position) <br>
E = Exit (where the player needs to go)<br>
0 = Empty space (walkable area) <br>
1 = Wall (non-walkable area) <br>
H = Enemy (only in bonus maps) <br>

Example of a Simple Map (map.ber):
```shell
111111
1P0001
100001
10E001
111111
```
<br>
Example of a Bonus Map (bonus_map.ber):
```shell
111111
1P0H01
100001
10E001
111111
```

### How to Change or Create Maps:

Maps are located in the ./maps folder.

You can modify or add new maps by editing the existing files or creating new ones with the same format.

After creating or modifying a map, simply save the map and run the executable again with the path to the new map. The game will automatically use the updated map.

---

### Packages to be installed
Check that these libraries are installed so that X11 / MiniLibX can run properly
1. X11 Libraries:
libx11-dev
libxext-dev
libxrender-dev

2. Zlib (for compression):
zlib1g-dev

For Debian-based systems/Ubuntu
```shell
> sudo apt update
> sudo apt install libx11-dev libxext-dev libxrender-dev zlib1g-dev
```

---

### Running the game
After compilation, run the game with the following commands:

For the mandatory or bonus version:
```shell
./so_long ./maps/map.ber
./so_long_bonus ./maps/bonus_map.ber
```

Use the arrow keys or WASD to move the player (P) through the maze. Reach the exit (E) to win the game.

In bonus mode, avoid the enemies (H) to survive.

---

### Cleaning Up

To remove the compiled files and clean up the project, run:
```shell
make clean
```

To remove all files, including the executables, run:
```shell
make fclean
```

To recompile everything from scratch, run:
```shell
make re
```

