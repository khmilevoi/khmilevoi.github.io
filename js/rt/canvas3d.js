Number.prototype.map = function(s1, e1, s2, e2) {
  const w1 = e1 - s1;
  const w2 = e2 - s2;

  return (this * w2) / w1 + s2;
};

class Canvas3d {
  constructor(context, w, h) {
    this.width = w;
    this.height = h;

    this.context = context;

    this.size = 0;

    this.rays = null;
  }

  setBg(color) {
    this.context.fillStyle = color;
    this.context.fillRect(0, 0, this.width, this.height);
  }

  setRays(rays) {
    this.rays = rays;

    this.size = this.width / this.rays.length;
  }

  drawEnv() {
    const hyp = Math.sqrt(this.width ** 2 + this.height ** 2);

    for (let ray = 0; ray < this.rays.length; ++ray) {
      const color = `rgb(
        ${Math.abs(255 - this.rays[ray].d).map(0, hyp, 50, 255)},
       ${Math.abs(255 - this.rays[ray].d).map(0, hyp, 50, 255)}, 
      ${Math.abs(255 - this.rays[ray].d).map(0, hyp, 50, 255)})`;

      const height = this.rays[ray].d.map(0, hyp, this.height, 50);

      this.context.fillStyle = color;
      this.context.fillRect(
        ray * this.size,
        this.height / 2 - height / 2,
        this.size,
        height
      );
    }
  }

  draw() {
    this.context.save();

    this.context.translate(this.width, 0);

    this.setBg("#000");

    if (this.rays !== null) {
      this.drawEnv();
    }

    this.context.restore();
  }
}
