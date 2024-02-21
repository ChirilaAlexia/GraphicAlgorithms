# GraphicAlgorithms

Find the shortest paths to all exits in a maze using breadth-first traversal of a graph.

Read the matrix from an input file and transform it into a graph (the graph should not contain nodes corresponding to the maze walls).
Implement the path procedure to determine the exit paths using breadth-first algorithm .
Draw the exit paths on the graph in a different color.
Draw the maze and exit paths (1.5p).

Notes for the exit paths:

The file from which the maze will be read is encoded as follows:
Values of 1 represent paths where one can move.
Values of 0 represent walls.
The value 3 will be the maze entrance.
Values of 2 will be the exit points.
Walls will be displayed in black, paths in white, the entrance point in blue, and exit points in red. Paths identified by the algorithm's execution will be colored in green.
