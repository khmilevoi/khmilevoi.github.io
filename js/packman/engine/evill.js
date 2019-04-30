class Evill extends Cell {
  constructor(x, y) {
    super(x, y, evill);

    this.direction = move.stop;

    this.old_x = null;
    this.old_y = null;
  }

  draw(context, size) {
    let n_size = Math.min(size, size) * 0.8;

    context.beginPath();
    context.fillStyle = "green";
    context.arc(
      this.x * size + size / 2,
      this.y * size + size / 2,
      n_size / 2,
      0,
      Math.PI * 2
    );
    context.fill();
  }

  move() {
    this.old_x = this.x;
    this.old_y = this.y;

    switch (this.direction) {
      case move.up: {
        this.set_coord(this.x, this.y - 1);
        break;
      }
      case move.right: {
        this.set_coord(this.x + 1, this.y);
        break;
      }
      case move.dawn: {
        this.set_coord(this.x, this.y + 1);
        break;
      }
      case move.left: {
        this.set_coord(this.x - 1, this.y);
        break;
      }
      default: {
        break;
      }
    }
  }

  moveTo(keyCode) {
    switch (keyCode) {
      case keyCodeStore.up: {
        this.move_up();
        break;
      }
      case keyCodeStore.right: {
        this.move_right();
        break;
      }
      case keyCodeStore.dawn: {
        this.move_dawn();
        break;
      }
      case keyCodeStore.left: {
        this.move_left();
        break;
      }
      default: {
        break;
      }
    }
  }

  back() {
    this.set_coord(this.old_x, this.old_y);
  }

  move_up() {
    this.direction = move.up;
  }

  move_right() {
    this.direction = move.right;
  }

  move_dawn() {
    this.direction = move.dawn;
  }

  move_left() {
    this.direction = move.left;
  }

  stop() {
    this.direction = move.stop;
  }
}
