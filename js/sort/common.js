canvasWidth = 1000;
canvasHeight = 500;
speed = 50000000;
n = 100;
x = 0;
y = 0;
z = 0;
let mas = [];

makeBody = () => {
    document.body.innerHTML =
        "\
	<div id = 'wrapper'>\
    	<canvas id = 'draw'></canvas>\
	</div>\
	";
    document.body.style.margin = "0px";
    document.body.style.padding = "0px";
    wrapper = document.getElementById("wrapper");
    wrapper.style.width = "100%";
    wrapper.style.height = "100vh";
    wrapper.style.display = "flex";
    wrapper.style.flexDirection = "column";
    wrapper.style.justifyContent = "center";
    wrapper.style.alignItems = "center";
};

set = () => {
    for (let i = 0; i < n; i++) {
        pos = Math.floor(Math.random() * (n - 1) + 1);
        r = Math.floor(Math.random() * (256));
        g = Math.floor(Math.random() * (256));
        b = Math.floor(Math.random() * (256));
        gr = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        // gr = 0.3 * r + 0.3 * g + 0.3 * b;
        // gr = 0.299 * r + 0.587 * g + 0.114 * b;
        sz = canvasHeight;
        mas.push({
            pos: pos,
            sz: (gr / 255) * sz,
            r: r,
            g: g,
            b: b,
            gr: gr,
            color: '#' + r.toString(16) + g.toString(16) + b.toString(16)
        });
    }
}

makeCanvas = () => {
    canvas = document.getElementById("draw");
    canvas.width = canvasWidth;
    canvas.height = canvasHeight;
    context = canvas.getContext("2d");
};

window.onload = () => {
    n = prompt("Amount: ", 100);
    makeBody();
    makeCanvas();
    set();
    setInterval(draw, 1000 / speed);
};

draw = () => {
    context.fillStyle = "lavender";
    context.fillRect(0, 0, canvasWidth, canvasHeight);

    art(n);

    // Bubble sort
    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - i - 1; j++) {
            if (mas[i].gr < mas[i + 1].gr) {
                let tmp = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = tmp;
            }
        }
    }

};

art = (n) => {
    for (let i = 0; i < n; i++) {
        context.fillStyle = "rgb(" + mas[i].r + "," + mas[i].g + "," + mas[i].b + ")";
        context.fillRect((canvasWidth / n) * i, canvasHeight - mas[i].sz, canvasWidth / n, mas[i].sz);
    }
}