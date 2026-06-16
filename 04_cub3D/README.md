_This project has been created as part of the 42 curriculum by pang and chllee._

# Description
The goal of this project is to build a basic 3D graphical game using the technique of raycasting, inspired by the classic 1992 game _Wolfenstein 3D_.

Using the MiniLibX library, this game parse a 2D maze map, transforming it into a pseudo-3D environment featuring real-time player movement, smooth camera controls, and textured walls.

# Instructions
### 📋 Prerequisites (Linux)

Before compiling, you must ensure that your system has the necessary X11 development headers and build tools installed. 

On Debian/Ubuntu-based systems, run the following command:
```bash
sudo apt-get update
sudo apt-get install make libx11-dev libxext-dev libbsd-dev
```

### Installation & Compilation
Clone or download the repository, navigate to the root directory, and compile the project using make:
```Bash
make
```
This command automatically initializes dependencies, runs the internal configuration scripts, and compiles the source files.

### Running the game
Launch the engine by passing the path of a valid `.cub` scene description file as an argument:
```Bash
./cub3d maps/map.cub
```

### Game controls
| Key | Action |
|:-------:|:-----:|
| w | Move Forward |
| s | Move Backward |
| a | Move Left |
| d | Move Right | 
| <- (left arrow) | Rotate Camera Left |
| -> (right arrow) | Rotate Camera Right |
| Esc / Window `x` | Clo se the game |
| Mouse | Rotate Camera Left or Right |

The minimap at the top-left corner shows your current poistion and surrounding layout.


## Customization Guide
You can customize the environment by using your own textures. They must meet the following criteria:

### 🧱 Wall Textures <br>
**Format:** `.xpm` (X PixMap) <br>
**Resolution:** Exactly 64 x 64 pixels <br>
**Naming Convention:** Rename your assets to `north.xpm`, `south.xpm`, `east.xpm`, or `west.xpm` depending on the wall orientation you wish to replace and placed in the **textures** folder <br>

### 🎨 Floor & Ceiling Colours
Open your `.cub` map file. <br>
The floor (F) and ceiling (C) colors are configured using standard RGB values (0 to 255), separated by commas:
```
F 220,100,0 (Floor color)

C 135,206,235 (Ceiling color)
```

### 🗺️ Map Design Rules
The map layout grid inside the `.cub` file utilizes specific characters:
```
1 : Wall

0 : Empty/Walkable Space

N, S, E, or W : Player spawn point and initial camera direction (Must choose exactly one).
```

**Strict Validation Note:** <br>
**Spaces ( ):** You can use spaces to create padding or irregular map shapes. Spaces are treated as an empty void.

**Enclosure:** The walkable layout (0 and player start element) must be perfectly sealed and enclosed by walls (1). If a walkable coordinate leaks into an unmapped space or void boundary, the parser will throw an error and exit to prevent out-of-bounds rendering crashes.

**Example map layout:**
```plain text
  11111
  10001
 1001001
1101 101
100S1001
11111111
```


# Resources
[Raycasting](https://lodev.org/cgtutor/raycasting.html)<br>
[Ray-Casting[C]](https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc130)

## Feature list
**Directional Texture Mapping:** 
Determines wall orientation (North, South, East, West) on ray impact and maps corresponding pixel columns dynamically to avoid visual warping.<br>

**Real-Time Minimap:** 
Features a minimap overlay that tracks player position, view direction and surrounding walls in real time, providing tactical navigation <br>

**Map Customisation:** 
Allow players to design custom levels via text files, supporting custom asset paths for unique wall textures and fully adjustable RGB variables for the environment's sky and floor colours

**Immersive Pseudo-3D Perspective:** 
Translates a flat 2D layout grid into a immersive, first-person 3D environment using Raycasting, simulating a natural field of view (FOV) and depth perception, trapping the player directly inside the maze

### Technical choice
**Rendering Technique:** Raycasting with DDA
This project utilises Raycasting backed by Digital Differential Analysis (DDA) algorithm. DDA steps systematically through a 2D grid matrix by jumping to the closest horizontal or vertical line intersection rather than tracking pixel-by-pixel increments.
