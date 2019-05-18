class Wall {
  constructor(context, x0, y0, x1, y1) {
    this.start_x = x0;
    this.start_y = y0;

    this.context = context;

    this.end_x = x1;
    this.end_y = y1;
  }

  draw() {
    this.context.beginPath();
    this.context.moveTo(this.start_x, this.start_y);
    this.context.lineTo(this.end_x, this.end_y);
    this.context.strokeStyle = "#fff";
    this.context.stroke();
  }
}
