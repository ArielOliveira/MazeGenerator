# MazeGenerator
Maze Generator

## Contents

- [About](#about)
- [Demo](#demo)


## About
A simple maze generation algorithm which outputs an image in PPM format based on a map randomly generated. The
algorithm map is based on a cell grid and goes as follows:
  -[] 1 - Choose an inital cell in the grid and mark it as visited
  -[] 2 - While its stack is not empty
      -[] 1 - Push the current cell to the stack
      -[] 2 - Choose one of the unvisited neighbours
      -[] 3 - Remove the wall between the current cell and the chosen cell
      -[] 4 - Mark the chosen cell as visited and push it to the stack
    (source https://en.wikipedia.org/wiki/Maze_generation_algorithm)


## Demo

 
