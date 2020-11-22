# MazeGenerator
Maze Generator

## Contents

- [About](#about)
- [Execution](#execution)
- [Demo](#demo)

## About
A simple maze generation algorithm which outputs an image in PPM format based on a map randomly generated. The
algorithm map is based on a cell grid and goes as follows:

     1 - Choose an inital cell in the grid and mark it as visited
      
     2 - While its stack is not empty
         1 - Push the current cell to the stack
         2 - Choose one of the unvisited neighbours
         3 - Remove the wall between the current cell and the chosen cell
         4 - Mark the chosen cell as visited and push it to the stack
          (source https://en.wikipedia.org/wiki/Maze_generation_algorithm)
          
      
## Execution
The executable takes 2 arguments from command line, one for the map size other for the cell size,
always pick an odd number for the map size, otherwise the maze won't fit well in the boundaries. By default
map size will be 33 and cell size 32.

## Demo
 - 16x16 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map16x16.jpg" width="270" height="420">
 - 32x32 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map32x32.jpg" width="270" height="420">
 - 64x64 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map64x64.jpg" width="270" height="420">
