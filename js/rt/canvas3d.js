class Canvas3d {
  constructor(context, start_x, start_y, w, h) {
    this.start_x = start_x;
    this.start_y = start_y;

    this.width = w;
    this.height = h;

    this.context = context;

    console.log(arguments);
  }

  setBg(color) {
    this.context.fillStyle = color;
    this.context.fillRect(0, 0, this.width, this.height);
  }

  setRays(rays) {
    this.rays = rays;
  }

  draw() {
    this.context.save();

    this.context.translate(this.start_x, this.start_y);

    this.setBg("#000");

    this.context.restore();
  }
}
