class Ball {
  constructor(context, x = 0, y = 0, r = 10) {
    this.x = x;
    this.y = y;
    this.r = r;
    this.angle = 0;

    this.step = 10;

    this.context = context;

    this.rays = new Array();
    for (let ang = 0; ang < 60; ang += 0.2) {
      this.rays.push(new Ray(this.context, this.x, this.y, ang));
    }

    this.raysToWall = null;
  }

  moveTo(x, y) {
    this.x = x;
    this.y = y;
  }

  move(dir) {
    const angle = (this.angle * Math.PI) / 180 + (Math.PI * 2) / 3;

    const xoff = Math.cos(angle) * this.step;
    const yoff = Math.sin(angle) * this.step;

    if (dir === 1) {
      this.x += xoff;
      this.y += yoff;
    } else {
      this.x -= xoff;
      this.y -= yoff;
    }
  }

  rotate(angleoff) {
    this.angle += angleoff;

    this.angle = this.angle % 360;

    this.rays.forEach(val => val.rotate((this.angle * Math.PI) / 180));
  }

  checkCast(walls) {
    this.raysToWall = new Array();

    for (let ray of this.rays) {
      let best_pt = null;
      let best_dist = Infinity;

      for (let wall of walls) {
        const pt = ray.cast(wall);

        if (pt) {
          const dist = Math.sqrt((this.x - pt.x) ** 2 + (this.y - pt.y) ** 2);

          if (dist < best_dist) {
            best_dist = dist;
            best_pt = pt;
          }
        }
      }

      if (best_pt) {
        this.context.save();

        this.context.translate(this.x, this.y);

        this.context.rotate(
          Math.PI / 2 + ray.angle + (this.angle * Math.PI) / 180
        );

        this.context.fillStyle = "rgba(255, 255, 255, 0.3)";
        this.context.fillRect(0, 0, best_dist, 1);

        this.raysToWall.push({ x: this.x, y: this.y, d: best_dist });

        this.context.restore();
      }
    }
  }

  draw() {
    this.context.beginPath();
    this.context.ellipse(this.x, this.y, this.r, this.r, 0, 0, Math.PI * 2);
    this.context.fillStyle = "#fff";
    this.context.fill();

    for (let ray of this.rays) {
      ray.moveTo(this.x, this.y);
      ray.draw(this.r);
    }
  }
}
