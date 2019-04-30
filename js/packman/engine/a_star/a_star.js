class A_star {
  constructor(map, evills) {
    this.grid = [];

    for (let row in map) {
      let new_row = [];

      for (let col in map[row]) {
        let element = {};

        element.f = 0;
        element.g = 0;
        element.h = 0;
        element.parent = null;
        element.type = map[row][col].type;
        element.x = map[row][col].x;
        element.y = map[row][col].y;

        new_row.push(element);
      }

      this.grid.push(new_row);
    }

    for (let el in evills) {
      this.grid[evills[el].y][evills[el].x].type = wall;
    }
  }

  search(start_cell, end_cell) {
    let start = this.grid[start_cell.y][start_cell.x];
    let end = this.grid[end_cell.y][end_cell.x];

    let open_list = [];
    let closed_list = [];

    open_list.push(start);

    while (open_list.length > 0) {
      let low_ind = 0;

      for (let index in open_list) {
        if (open_list[index].f < open_list[low_ind].f) {
          low_ind = index;
        }
      }

      let current_node = open_list[low_ind];

      if (current_node.x == end.x && current_node.y == end.y) {
        let curr = current_node;
        let ret = [];

        while (curr.parent) {
          ret.push(curr);

          curr = curr.parent;
        }

        return ret.reverse();
      }

      remove(open_list, current_node);

      closed_list.push(current_node);

      let neighbors = this.neighbors(current_node);

      for (let index in neighbors) {
        let neighbor = neighbors[index];

        if (closed_list.indexOf(neighbor) >= 0 || neighbor.type === wall) {
          continue;
        }

        let g_score = current_node.g + 1;
        let g_score_is_best = false;

        if (open_list.indexOf(neighbor) === -1) {
          g_score_is_best = true;
          neighbor.h = this.heurestic(neighbor, end);
          open_list.push(neighbor);
        } else if (g_score < neighbor.g) {
          g_score_is_best = true;
        }

        if (g_score_is_best) {
          neighbor.parent = current_node;
          neighbor.g = g_score;
          neighbor.f = neighbor.g + neighbor.h;
        }
      }
    }

    return [];
  }

  heurestic(curr, end) {
    let d1 = Math.abs(curr.x - end.x);
    let d2 = Math.abs(curr.y - end.y);

    return d1 + d2;
  }

  neighbors(node) {
    let ret = [];

    let x = node.x;
    let y = node.y;

    if (this.grid[y - 1] && this.grid[y - 1][x]) {
      ret.push(this.grid[y - 1][x]);
    }
    if (this.grid[y + 1] && this.grid[y + 1][x]) {
      ret.push(this.grid[y + 1][x]);
    }
    if (this.grid[y][x - 1]) {
      ret.push(this.grid[y][x - 1]);
    }
    if (this.grid[y][x + 1]) {
      ret.push(this.grid[y][x + 1]);
    }

    return ret;
  }
}
