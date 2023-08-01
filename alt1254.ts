function closedIsland(grid: number[][]): number {
  let count = 0;

  // helper function to check if a cell is out of bounds or surrounded by 1s
  const isClosed = (row: number, col: number): boolean => {
    if (row < 0 || col < 0 || row >= grid.length || col >= grid[0].length) {
      // out of bounds
      return false;
    }
    if (grid[row][col] === 1) {
      // surrounded by water
      return true;
    }
    // mark as visited
    grid[row][col] = 1;
    // recursively check neighbors
    const left = isClosed(row, col - 1);
    const right = isClosed(row, col + 1);
    const up = isClosed(row - 1, col);
    const down = isClosed(row + 1, col);
    // if any neighbor is not closed, then this island is not closed
    return left && right && up && down;
  };

  // iterate through each cell in the grid
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 0 && isClosed(i, j)) {
        // found a closed island
        printGrid(grid);
        count++;
      }
    }
  }
  return count;
}

const printGrid = (grid: number[][]): void => {
  console.log("");
  for (let i = 0; i < grid.length; i++) {
    let row = "";

    for (let j = 0; j < grid[i].length; j++) {
      row += grid[i][j] + " ";
    }
    console.log(row);
  }
};

let gg = [
  [1, 1, 1, 1, 1, 1, 1, 0],
  [1, 0, 0, 0, 0, 1, 1, 0],
  [1, 0, 1, 0, 1, 1, 1, 0],
  [1, 0, 0, 0, 0, 1, 0, 1],
  [1, 1, 1, 1, 1, 1, 1, 0],
];
console.log(closedIsland(gg));
