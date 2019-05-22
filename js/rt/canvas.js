class Canvas {
  constructor(canvas) {
    this.canvas = canvas;
    this.context = canvas.getContext("2d");

    this.canvas2d = null;
    this.canvas3d = null;
  }

  createCanvas(w, h) {
    this.width = w;
    this.height = h;

    canvas.width = w;
    canvas.height = h;

    canvas.style.width = w;
    canvas.style.height = h;

    this.canvas2d = new Canvas2d(this.context, this.width / 2, this.height);

    this.canvas2d.setWall(5);

    this.canvas3d = new Canvas3d(this.context, this.width / 2, this.height);

    this.canvas.addEventListener("mousemove", this.canvas2d.mousePosHandler);

    document.addEventListener("keydown", this.canvas2d.keyHandler);
  }

  play() {
    setInterval(this.draw, 1000 / 60);
  }

  draw = () => {
    if (this.canvas2d.ball.raysToWall !== null) {
      this.canvas3d.setRays(this.canvas2d.ball.raysToWall);
    }

    this.canvas2d.draw();
    this.canvas3d.draw();
  };
}
