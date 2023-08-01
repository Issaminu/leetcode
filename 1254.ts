const enum CellType {
  UnvisitedLand = 0,
  Water = 1,
  VisitedLand = 2,
  VisitedEdge = 3,
}
class Cell {
  value: CellType;
  positionX: number;
  positionY: number;
  isAnUnvisitedLand(): boolean {
    return this.value === CellType.UnvisitedLand;
  }
  isWater(): boolean {
    return this.value === CellType.Water;
  }
  isAVisitedLand(): boolean {
    return this.value === CellType.VisitedLand;
  }
  isAVisitedEdge(): boolean {
    return this.value === CellType.VisitedEdge;
  }
  constructor(positionX: number, positionY: number, value: number) {
    this.positionX = positionX;
    this.positionY = positionY;
    this.value = value;
  }
}

class Ocean {
  cells: Cell[][];
  constructor(grid: number[][]) {
    this.cells = [];
    for (let i = 0; i < grid.length; i++) {
      this.cells[i] = [];
      for (let j = 0; j < grid[i].length; j++) {
        this.cells[i][j] = new Cell(i, j, grid[i][j]);
      }
    }
  }
}

function closeddIsland(grid: number[][]): number {
  if (grid.length < 3 || grid[0].length < 3) return 0;
  let ocean = new Ocean(grid);
  // printOcean(ocean);
  let numberOfIslands = 0;
  for (let i = 1; i < ocean.cells.length - 1; i++) {
    for (let j = 1; j < ocean.cells[i].length - 1; j++) {
      // Sailing the ocean until we discover land
      if (ocean.cells[i][j].isAnUnvisitedLand()) {
        if (isLandAdjacentToWater(ocean, ocean.cells[i][j])) {
          console.log("New land discovered at: " + i + " " + j);
          defineIslandEdges(ocean, ocean.cells[i][j]); // We just discovered a new island!

          numberOfIslands++;
        } else {
          ocean.cells[i][j].value = CellType.VisitedLand;
        }
      }
    }
  }
  console.log("END OF FUNCTION");

  printOcean(ocean);
  return numberOfIslands;
}
function isLandAdjacentToWater(ocean: Ocean, cell: Cell): boolean {
  return (
    ocean.cells[cell.positionX][cell.positionY - 1].value === CellType.Water ||
    ocean.cells[cell.positionX][cell.positionY + 1].value === CellType.Water ||
    ocean.cells[cell.positionX - 1][cell.positionY].value === CellType.Water ||
    ocean.cells[cell.positionX + 1][cell.positionY].value === CellType.Water
  );
}
function defineIslandEdges(ocean: Ocean, cell: Cell): void {
  // The goal of this function is to turn island edges into visited edges (`CellType.VisitedEdge`).
  // This would allow us to distinguish between visited islands and unvisited islands.
  // And therefore not count the same island twice.
  let currentLand: Cell | null = cell;
  while (currentLand && currentLand.isAnUnvisitedLand()) {
    console.log(
      "Current land: " + currentLand.positionX + " " + currentLand.positionY
    );
    if (isLandAdjacentToWater(ocean, currentLand)) {
      // console.log(1);

      currentLand.value = CellType.VisitedEdge;
      printOcean(ocean);
      // console.log(currentLand.value);

      let nextEdge = findNextUnvisitedEdge(ocean, currentLand);
      if (nextEdge) {
        currentLand = nextEdge;
      } else {
        if (isDeadEnd(ocean, currentLand)) {
          currentLand = resolveDeadEnd(ocean, currentLand);
        } else {
          // if there is no next unvisited edge, mark the current land cell as visited and exit the loop
          currentLand.value = CellType.VisitedLand;
          break;
        }
      }
    } else {
      // If the current land cell is visited, break out of the loop.
      currentLand.value = CellType.VisitedLand;
      break;
    }
  }
}

function findNextUnvisitedEdge(ocean: Ocean, cell: Cell): Cell | null {
  let nextCell = ocean.cells[cell.positionX][cell.positionY - 1];
  if (
    nextCell &&
    nextCell.isAnUnvisitedLand() &&
    isLandAdjacentToWater(ocean, nextCell)
  ) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX][cell.positionY + 1];
  if (
    nextCell &&
    nextCell.isAnUnvisitedLand() &&
    isLandAdjacentToWater(ocean, nextCell)
  ) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX - 1][cell.positionY];
  if (
    nextCell &&
    nextCell.isAnUnvisitedLand() &&
    isLandAdjacentToWater(ocean, nextCell)
  ) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX + 1][cell.positionY];
  if (
    nextCell &&
    nextCell.isAnUnvisitedLand() &&
    isLandAdjacentToWater(ocean, nextCell)
  ) {
    return nextCell;
  }
  return null;
}

function isDeadEnd(ocean: Ocean, cell: Cell): boolean {
  return (
    !ocean.cells[cell.positionX][cell.positionY - 1].isAnUnvisitedLand() &&
    !ocean.cells[cell.positionX][cell.positionY + 1].isAnUnvisitedLand() &&
    !ocean.cells[cell.positionX - 1][cell.positionY].isAnUnvisitedLand() &&
    !ocean.cells[cell.positionX + 1][cell.positionY].isAnUnvisitedLand()
  );
}

function resolveDeadEnd(ocean: Ocean, cell: Cell): Cell | null {
  let curentCell: Cell | null = cell;
  while (curentCell && curentCell.isAVisitedEdge()) {
    curentCell = findNextVisitedEdge(ocean, cell);
    if (curentCell) {
      let edge = findNextUnvisitedEdge(ocean, curentCell);
      if (edge) {
        return edge;
      }
    }
  }
  return null;
}

function findNextVisitedEdge(ocean: Ocean, cell: Cell): Cell | null {
  let nextCell = ocean.cells[cell.positionX][cell.positionY - 1];
  if (nextCell && nextCell.isAVisitedEdge()) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX][cell.positionY + 1];
  if (nextCell && nextCell.isAVisitedEdge()) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX - 1][cell.positionY];
  if (nextCell && nextCell.isAVisitedEdge()) {
    return nextCell;
  }
  nextCell = ocean.cells[cell.positionX + 1][cell.positionY];
  if (nextCell && nextCell.isAVisitedEdge()) {
    return nextCell;
  }
  return null;
}

function printOcean(ocean: Ocean): void {
  for (let i = 0; i < ocean.cells.length; i++) {
    let line = "";
    for (let j = 0; j < ocean.cells[i].length; j++) {
      line += ocean.cells[i][j].value + " ";
    }
    console.log(line);
  }
}

let grid = [
  [1, 1, 1, 1, 1, 1, 1, 0],
  [1, 0, 0, 0, 0, 1, 1, 0],
  [1, 0, 1, 0, 1, 1, 1, 0],
  [1, 0, 0, 0, 0, 1, 0, 1],
  [1, 1, 1, 1, 1, 1, 1, 0],
];
console.log(closedIsland(grid));
