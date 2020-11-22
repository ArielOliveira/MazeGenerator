# MazeGenerator
Maze Generator

## Contents

- [About](#about)
- [Execution](#execution)
- [Demo](#demo)

## About
- A simple maze generation algorithm which outputs an image in PPM format based on a map randomly generated. The
algorithm map is based on a cell grid and goes as follows:

     1 - Choose an inital cell in the grid and mark it as visited
      
     2 - While its stack is not empty
         1 - Push the current cell to the stack
         2 - Choose one of the unvisited neighbours
         3 - Remove the wall between the current cell and the chosen cell
         4 - Mark the chosen cell as visited and push it to the stack
          (source https://en.wikipedia.org/wiki/Maze_generation_algorithm)
          
      
## Execution
- The executable takes 2 arguments from command line, one for the map size other for the cell size,
always pick an odd number for the map size, otherwise the maze won't fit well in the boundaries. By default
map size will be 33x33 and cell size 32.
     - Example:  ./MazeGen 65 32
     
     This example generates a 64x64 map with a 32 size in pixels cell

## Demo
 - 16x16 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map16x16.png" width="270" height="270">
 
 - 32x32 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map32x32.png" width="270" height="270">
 
 - 64x64 Maze
 <img src="https://github.com/ArielOliveira/MazeGenerator/blob/master/demo/map64x64.png" width="270" height="270">
