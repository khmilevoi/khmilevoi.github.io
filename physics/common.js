window.onload = () => {
    document.body.innerHTML = "<div id='wrapper'><span id='heading'>Physics model</span><br><canvas id='canvas'></canvas></div>";
    document.body.style.width = "100vw";
    document.body.style.height = "100vh";
    document.body.style.margin = "0";
    document.body.style.padding = "0";
    document.body.style.display = "flex";
    document.body.style.placeContent = "center";
    
    document.getElementById("wrapper").style.width = "auto";
    document.getElementById("wrapper").style.height = "425px";
    document.getElementById("wrapper").style.display = "flex";
    document.getElementById("wrapper").style.flexDirection = "column";
    document.getElementById("wrapper").style.alignContent = "center";
    document.getElementById("wrapper").style.justifyContent = "space-between";
    document.getElementById("wrapper").style.textAlign = "center";
    
    document.getElementById("heading").style.fontSize = "25px";
    canvas = document.getElementById("canvas");
    context = canvas.getContext("2d");
    
    canvas.width = 400;
    canvas.height = 400;

    w = canvas.width;
    h = canvas.height;

    
    angle = 90;
    speed = 60;
    h_earth = 25;
    r_circle = 15;

    pos_x = 25;

    // pos_y = 25;
    pos_y = h - h_earth - r_circle;

    x_val = y_val = 0;
    t = 0;
    g = 9.81;

    setInterval(draw, 1000 / 60);
}

draw = () => {
    context.fillStyle = "#BBD5DB";
    context.fillRect(0, 0, h, w);
    
    context.fillStyle = "#1F4752";
    context.fillRect(0, h - h_earth, w, h_earth);

    context.fillStyle = "#1F4752";    
    var circle = new Path2D();
    circle.arc(x_val + pos_x, y_val + pos_y, r_circle, 0, 2 * Math.PI);
    context.fill(circle);
    
    if(t <= 2 * speed * Math.sin(Math.PI * angle / 180) / g) {
        x_val = speed * Math.cos(Math.PI * angle / 180) * t;
        y_val = -(speed * Math.sin(Math.PI * angle / 180) * t - g * t * t / 2); 
    }

    t += 0.1;
}

// draw = () => {
    
//     context.fillStyle = "#BBD5DB";
//     context.fillRect(0, 0, h, w);
    
//     context.fillStyle = "#1F4752";
//     context.fillRect(0, h - h_earth, w, h_earth);
    
//     context.fillStyle = "#1F4752";
//     var circle = new Path2D();
//     circle.arc(x_val + pos_x, y_val + pos_y, r_circle, 0, 2 * Math.PI);
//     context.fill(circle);

//     if(t < Math.sqrt(2 * (h - pos_y - h_earth) / g)) {
//         x_val = speed * t;
//         y_val = g * t * t / 2;
//     } else {
//         x_val = speed * Math.sqrt(2 * (h - pos_y - h_earth) / g);
//         y_val = g * Math.pow(Math.sqrt(2 * (h - pos_y - h_earth) / g), 2) / 2 - r_circle;
//     }

//     t += 0.1;
// }

