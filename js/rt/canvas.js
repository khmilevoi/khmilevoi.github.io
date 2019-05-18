class Canvas {
  constructor(canvas) {
    this.canvas = canvas;
    this.context = canvas.getContext("2d");

    this.walls = new Array();
    this.ball = new Ball(this.context, this.width / 2);

    this.canvas3d = null;
  }

  createCanvas(w, h) {
    this.width = w;
    this.height = h;

    canvas.width = w;
    canvas.height = h;

    canvas.style.width = w;
    canvas.style.height = h;

    this.canvas.addEventListener("mousemove", this.mousePosHandler);
  }

  mousePosHandler = e => {
    if (e.clientX <= this.width2d && e.clientY <= this.width2d) {
      this.ball.moveTo(e.clientX, e.clientY);
    }
  };

  setBg(color) {
    this.context.fillStyle = color;
    this.context.fillRect(0, 0, this.width, this.height);
  }

  play() {
    setInterval(this.draw, 1);
  }

  setWall(number) {
    this.walls.push(new Wall(this.context, 0, 0, this.width2d, 0));
    this.walls.push(new Wall(this.context, 0, 0, 0, this.height));
    this.walls.push(
      new Wall(this.context, this.width2d, this.height, this.width2d, 0)
    );
    this.walls.push(
      new Wall(this.context, this.width2d, this.height, 0, this.height)
    );

    for (let index = 0; index < number; ++index) {
      this.walls.push(
        new Wall(
          this.context,
          Math.random() * this.width2d,
          Math.random() * this.height2d,
          Math.random() * this.width2d,
          Math.random() * this.height2d
        )
      );
    }
  }

  setFor2dRaycasting(w, h) {
    this.width2d = w;
    this.height2d = h;
  }

  setFor3dRaycasting(w, h) {
    this.width3d = w;
    this.height3d = h;

    this.canvas3d = new Canvas3d(this.context, this.width2d, 0, 500, 500);

    this.canvas3d.setRays(this.ball.raysToWall);
  }

  draw = () => {
    this.context.clearRect(0, 0, this.w, this.h);

    this.setBg("#000");

    for (let wall of this.walls) {
      wall.draw();
    }

    this.ball.draw();
    this.ball.checkCast(this.walls);

    if (this.canvas3d) {
      this.canvas3d.draw();
    }
  };
}
