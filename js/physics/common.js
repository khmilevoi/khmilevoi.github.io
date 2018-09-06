window.onload = () => {
    document.body.innerHTML = "\
        <div id='wrapper'>\
            <span id='heading'>Physics model</span>\
            <canvas id='canvas'></canvas>\
            <button type='button' onclick='reload()' width='50px' height='25px'>Start</button>\
        </div>";

    document.body.style.width = "100vw";
    document.body.style.height = "100vh";
    document.body.style.margin = "0";
    document.body.style.padding = "0";
    document.body.style.display = "flex";
    document.body.style.justifyContent = "center";
    document.body.style.alignItems = "center";
    
    document.getElementById("wrapper").style.width = "auto";
    document.getElementById("wrapper").style.height = "500px";
    document.getElementById("wrapper").style.display = "flex";
    document.getElementById("wrapper").style.flexDirection = "column";
    document.getElementById("wrapper").style.alignContent = "center";
    document.getElementById("wrapper").style.justifyContent = "space-between";
    document.getElementById("wrapper").style.textAlign = "center";

    // speed = 60;
    // angle = 90;
    
    document.getElementById("heading").style.fontSize = "25px";
    canvas = document.getElementById("canvas");
    context = canvas.getContext("2d");
    
    canvas.width = 400;
    canvas.height = 400;
    
    w = canvas.width;
    h = canvas.height;  
    h_earth = 25;
    r_circle = 15;
    g = 9.81;
    
    speed = prompt("Speed", 45);
    angle = prompt("Angle", 45);
    h_platform = prompt("Height", 45);

    pos_x = 25;
    // pos_y = 25;
    pos_y = h - h_earth - r_circle - h_platform;
    

    x_val = y_val = 0;
    t = 0;
    d_t = 0.1;
    t_up = (speed * Math.sin(Math.PI * angle / 180) / g);
    t_dawn = (Math.sqrt(2 * ((h - h_earth - pos_y - r_circle) + (speed * speed * Math.pow(Math.sin(Math.PI * angle / 180), 2) / (2 * g))) / g));
    
    setInterval(draw, 1000 / 60);
}

draw = () => {
    context.fillStyle = "#BBD5DB";
    context.fillRect(0, 0, h, w);
    
    context.fillStyle = "#1F4752";
    context.fillRect(0, h - h_earth, w, h_earth);

    context.fillStyle = "#1F4752";
    context.fillRect(0, h - h_earth - h_platform, pos_x, h_platform);
    
    context.fillStyle = "#0B1215";    
    var circle = new Path2D();
    circle.arc(x_val + pos_x, y_val + pos_y, r_circle, 0, 2 * Math.PI);
    context.fill(circle);
    
    if(t <= t_up + t_dawn + d_t) {
        x_val = speed * Math.cos(Math.PI * angle / 180) * t;
        y_val = -(speed * Math.sin(Math.PI * angle / 180) * t - g * t * t / 2); 
        console.log(((t_up + t_dawn + d_t) - t).toFixed(1), (t_up + t_dawn + d_t).toFixed(1));
    }
    
    t += d_t;
}

reload = () => {
    t = 0;
    x_val = y_val = 0;
}