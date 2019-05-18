class Ray {
  constructor(context, x, y, angle) {
    this.start_x = x;
    this.start_y = y;

    this.angle = (angle / 180) * Math.PI;

    this.context = context;

    this.length = 1;

    this.direct_x = Math.sin(this.angle) * this.length;
    this.direct_y = Math.cos(this.angle) * this.length;
  }

  moveTo(x, y) {
    this.start_x = x;
    this.start_y = y;
  }

  cast(wall) {
    const x1 = +this.start_x.toFixed(2);
    const y1 = +this.start_y.toFixed(2);
    const x2 = +(this.start_x - this.direct_x).toFixed(2);
    const y2 = +(this.start_y + this.direct_y).toFixed(2);

    const x3 = wall.start_x;
    const y3 = wall.start_y;
    const x4 = wall.end_x;
    const y4 = wall.end_y;

    const px_top =
      (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);

    const p_down = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    const px = +(px_top / p_down).toFixed(2);

    const py_top =
      (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);

    const py = +(py_top / p_down).toFixed(2);

    let check_x = (px - x3) / (x3 - x4) || 0;
    let check_y = (py - y3) / (y3 - y4) || 0;

    check_x *= -1;
    check_y *= -1;

    const check_in =
      check_x <= 1 && check_x >= 0 && check_y <= 1 && check_y >= 0;

    const check_dir = px >= x1 == x2 >= x1 && py >= y1 == y2 >= y1;

    if (check_in && check_dir) {
      return { x: px, y: py };
    } else {
      return null;
    }
  }

  draw(r) {
    this.context.beginPath();
    this.context.moveTo(this.start_x, this.start_y);
    this.context.lineTo(
      this.start_x - this.direct_x * r * 2,
      this.start_y + this.direct_y * r * 2
    );
    this.context.strokeStyle = "#fff";
    this.context.stroke();
  }
}
