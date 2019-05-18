window.onload = function() {
  const canvas = new Canvas(document.getElementById("canvas"));

  canvas.createCanvas(500, 500);

  canvas.setFor2dRaycasting(500, 500);

  // canvas.setFor3dRaycasting(500, 500);

  canvas.setWall(5);

  canvas.play();
};
