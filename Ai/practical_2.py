import copy
from heapq import heappush, heappop

# Variable for puzzle size (3x3 for 8-puzzle)
n = 3

# Directions for moving the blank tile (down, left, up, right)
row = [1, 0, -1, 0]
col = [0, -1, 0, 1]

# A class for Priority Queue
class priorityQueue:
    def __init__(self):
        self.heap = []
    
    def push(self, k):
        heappush(self.heap, k)
    
    def pop(self):
        return heappop(self.heap)
    
    def empty(self):
        return len(self.heap) == 0

# Node structure to store the puzzle state
class node:
    def __init__(self, parent, mat, empty_tile_pos, cost, level):
        self.parent = parent  # Parent node
        self.mat = mat  # Puzzle state (matrix)
        self.empty_tile_pos = empty_tile_pos  # Position of the blank tile
        self.cost = cost  # Heuristic cost (misplaced tiles)
        self.level = level  # Level of the node (depth)
    
    # Compare nodes based on cost for priority queue
    def __lt__(self, nxt):
        return self.cost < nxt.cost

# Function to calculate the number of misplaced tiles
def calculateCost(mat, final) -> int:
    count = 0
    for i in range(n):
        for j in range(n):
            if mat[i][j] and mat[i][j] != final[i][j]:
                count += 1
    return count

# Function to create a new node after moving a tile
def newNode(mat, empty_tile_pos, new_empty_tile_pos, level, parent, final) -> node:
    new_mat = copy.deepcopy(mat)  # Copy data from the parent matrix
    # Move the tile by swapping the empty tile with a new position
    new_mat[empty_tile_pos[0]][empty_tile_pos[1]], new_mat[new_empty_tile_pos[0]][new_empty_tile_pos[1]] = new_mat[new_empty_tile_pos[0]][new_empty_tile_pos[1]], new_mat[empty_tile_pos[0]][empty_tile_pos[1]]
    
    # Calculate the cost using the heuristic
    cost = calculateCost(new_mat, final)
    
    # Return a new node with updated data
    return node(parent, new_mat, new_empty_tile_pos, cost, level)

# Function to check if a position is within the puzzle grid
def isSafe(x, y):
    return 0 <= x < n and 0 <= y < n

# Function to print the puzzle matrix
def printMatrix(mat):
    for i in range(n):
        for j in range(n):
            print(f"{mat[i][j]:2}", end=" ")
        print()

# Function to print the solution path from the root node to the destination node
def printPath(root):
    if root is None:
        return
    printPath(root.parent)
    printMatrix(root.mat)
    print()

# A* algorithm to solve the puzzle
def solve(initial, empty_tile_pos, final):
    # Create a priority queue
    pq = priorityQueue()
    
    # Create the root node and calculate the cost (misplaced tiles)
    root = node(None, initial, empty_tile_pos, calculateCost(initial, final), 0)
    
    # Add the root node to the priority queue
    pq.push(root)
    
    # Set to keep track of visited states
    visited = set()
    visited.add(tuple(map(tuple, initial)))  # Add the initial state to the set
    
    # Loop until we find the solution
    while not pq.empty():
        # Get the node with the lowest cost
        min_node = pq.pop()
        
        # If the current node is the goal state, print the solution path
        if min_node.cost == 0:
            printPath(min_node)
            return
        
        # Move the blank tile in all possible directions
        for i in range(4):
            new_x = min_node.empty_tile_pos[0] + row[i]
            new_y = min_node.empty_tile_pos[1] + col[i]
            
            if isSafe(new_x, new_y):
                # Create a new node by moving the blank tile
                child = newNode(min_node.mat, min_node.empty_tile_pos, [new_x, new_y], min_node.level + 1, min_node, final)
                
                # If the new state hasn't been visited yet, add it to the priority queue
                if tuple(map(tuple, child.mat)) not in visited:
                    pq.push(child)
                    visited.add(tuple(map(tuple, child.mat)))

# Example usage
initial = [
    [1, 2, 3],
    [4, 5, 6],
    [0, 7, 8]
]

# Goal state
final = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

# Blank tile position
empty_tile_pos = [2, 0]

# Solve the puzzle
solve(initial, empty_tile_pos, final)
