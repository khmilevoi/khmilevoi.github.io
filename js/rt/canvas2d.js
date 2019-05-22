class Canvas2d {
  constructor(context, w, h) {
    this.context = context;
    this.width = w;
    this.height = h;

    this.walls = new Array();
    this.ball = new Ball(this.context, this.width / 2);
  }

  mousePosHandler = e => {
    if (e.clientX <= this.width && e.clientY <= this.width) {
      this.ball.moveTo(e.clientX, e.clientY);
    }
  };

  keyHandler = event => {
    switch (event.key) {
      case "a": {
        this.ball.rotate(-1);
        break;
      }
      case "d": {
        this.ball.rotate(1);
        break;
      }
      case "w": {
        this.ball.move(1);
        break;
      }
      case "s": {
        this.ball.move(0);
        break;
      }
      default:
        break;
    }
  };

  setBg(color) {
    this.context.fillStyle = color;
    this.context.fillRect(0, 0, this.width, this.height);
  }

  setWall(number) {
    this.walls.push(new Wall(this.context, 0, 0, this.width, 0));
    this.walls.push(new Wall(this.context, 0, 0, 0, this.height));
    this.walls.push(
      new Wall(this.context, this.width, this.height, this.width, 0)
    );
    this.walls.push(
      new Wall(this.context, this.width, this.height, 0, this.height)
    );

    for (let index = 0; index < number; ++index) {
      this.walls.push(
        new Wall(
          this.context,
          Math.random() * this.width,
          Math.random() * this.height,
          Math.random() * this.width,
          Math.random() * this.height
        )
      );
    }
  }

  draw() {
    this.context.clearRect(0, 0, this.w, this.h);

    this.setBg("#000");

    for (let wall of this.walls) {
      wall.draw();
    }

    this.ball.draw();
    this.ball.checkCast(this.walls);
  }
}
