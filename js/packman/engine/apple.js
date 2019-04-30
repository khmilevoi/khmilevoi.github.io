class Apple extends Cell {
  constructor(x, y) {
    super(x, y, apple);
  }

  draw(context, size) {
    let n_size = Math.min(size, size) * 0.8;

    context.fillStyle = "black";
    context.fillRect(this.x * size, this.y * size, size, size);

    context.beginPath();
    context.fillStyle = "red";
    context.arc(
      this.x * size + size / 2,
      this.y * size + size / 2,
      n_size / 8,
      0,
      Math.PI * 2
    );
    context.fill();
  }
}
