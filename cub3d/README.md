# CUB3D

*This project has been created as part of the 42 curriculum by manuelfe & hmolina*

## DESCRIPTION

cub3d is a project that aims to introduce us to the world of 3D graphics programming.
Starting with a 2D representation of a map, the program generates a first-person view using raycasting technique, inspired by the mechanics of classics games such as Wolfestein 3D

The project does not focus solely ono the visual result, but also on understanding how a basic graphics engine is built internally: how a tree-dimensional space is projected on to a 2D screen, how keyboard events, player movement, collisions, and texture loading are managed

All development is done in C language, using the graphics library provided by 42, which requires precise management of memory data structures, and program flow. Cub3d is, in essence, a project that combined mathematics, logic, and graphics, and serves as a first real approach to how video games work inside


## INSTRUCTIONS

To compile and run the project, you need a Linux or macOS system with a C-compatible compiler (gcc or clang) installed. The project uses MLX graphics library, which is included or configured according to the 42 School environment

### Compilation
Download the project by running ***git clone*** with the SSH link or downloading the project in .zip format

From the project root, run:

	make

This will generate the cub3d executable
If at any time you need to clean up the generated files:

	make clean

Or for a thorough cleaning:

	make fclean

### Execution
The program is executed by passing a map file with the .cub extension as an argument:

	./cub3d /maps/map.cub

If the map is valid, a window will open showing a first-person view of the scene

### Controls

***W / A / S / D***			->	Player movement

***Left / Right arrows***	->	Camera rotation

***ESC or close window***	->	Exit program

The player cannot pass through walls, and movement is limited by the map structure

### Maps

The .cub file defines:

Wall textures

Floor and ceiling colors

The 2D layout of the map

The player's initial position and orientation

Any errors in the file (open map, invalid characters, multiple player position, etc) will cause the program to terminate with an error message


## RESOURCES

During the development of cub3d, these resources were particularly useful for understanding the key concepts of the project and resolving technical questions:

Official MLX codumentation

Tutorial and articles on raycasting that explain the concept from a mathematical and practical point of view, such as this one

	https://lodev.org/cgtutor/raycasting.html

Artificial Intelligence has been used as a consultation and theoretical support tool, similar to a tutor or reading additional documentation. Its use focused mainly on:

Better understanding complex concepts such as raycasting

Clarifying specific questions about calculations, data structures or program flow

Reviewing technical explanations to ensure correct understangind implementing solutions
