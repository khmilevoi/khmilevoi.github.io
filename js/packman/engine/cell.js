class Cell {
  constructor(x, y, type) {
    if ((x === null && x === undefined) || (y === null && y === null)) {
      throw TypeError();
    }

    if (isNaN(Number(x)) || isNaN(Number(y))) {
      throw TypeError();
    }

    if (typeof type !== "number" && typeof type !== "string") {
      throw TypeError();
    }

    this.x = Number(x);
    this.y = Number(y);

    if (isNaN(Number(type))) {
      this.type = type;
    } else {
      this.type = type_of_cell[type];
    }
  }

  draw(context, size) {
    if (this.type === "wall") {
      context.fillStyle = "white";
    } else {
      context.fillStyle = "black";
    }

    context.fillRect(this.x * size, this.y * size, size, size);
  }

  set_coord(x, y) {
    this.x = x | null;
    this.y = y | null;
  }

  set_type(type) {
    if (typeof type !== "number" || typeof type !== "string") {
      throw TypeError();
    }

    if (isNaN(Number(type))) {
      this.type = type;
    } else {
      this.type = type_of_cell[type | 0];
    }
  }
}
