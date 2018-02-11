x_val = 0,
y_val = 0;
pos_x = 20,
pos_y = 20;
gr_sz = 20;
apple_x = 15,
apple_y = 15;
train = [];
tail = 1;
score = 0;
speed = 10;
push = 0;
record;
window.onload = function () {
    canvas  = document.getElementById("game_snake"),
    canvas.width = 400,
    canvas.height = 400,
    context = canvas.getContext("2d");
    setInterval(game, 1000/speed);
    document.addEventListener("keydown", keyPush); 
}
function game () {   
    GetCookie();
    if (!isNaN(record)) {
        record = +cookieValue;
    } else {
        record = 0;
    }

    if (score == 1) {
        tail = 3;
    }

    pos_x += x_val;
    pos_y += y_val;

    if (pos_x > canvas.width - gr_sz) {
        pos_x = 0;
    }
    if (pos_x < 0) {
        pos_x = canvas.width - gr_sz;
    }
    if (pos_y > canvas.height - gr_sz) {
        pos_y = 0;
    }
    if (pos_y < 0) {
        pos_y = canvas.height - gr_sz;
    }

    // bg

    context.fillStyle = "#B0D58D";
    context.fillRect(0, 0, canvas.width, canvas.height);

    // snake

    train.push({ x : pos_x, y : pos_y});
    while (train.length > tail) {
        train.shift();
    }

    for (i = 1; i < train.length; i++) {
        context.fillStyle = "#5967B2";
        context.fillRect(train[i].x, train[i].y, gr_sz - 2, gr_sz - 2);
    }
    context.fillStyle = "#20429C";
    context.fillRect(train[tail - 1].x, train[tail - 1].y, gr_sz - 2, gr_sz - 2);

    // apple

    context.fillStyle = "#F59179";
    context.fillRect(apple_x * gr_sz, apple_y * gr_sz, gr_sz - 2, gr_sz - 2);

    if (apple_x * gr_sz == pos_x && apple_y * gr_sz == pos_y) {
        ++tail;
        ++score;
        apple_x = Math.floor((Math.random() * canvas.width) / gr_sz);
        apple_y = Math.floor((Math.random() * canvas.height) / gr_sz);
        for (i = 0; i < train.length - 2; i++) {
            if (apple_x * gr_sz == train[i].x && apple_y * gr_sz == train[i].y){
                apple_x = Math.floor((Math.random() * (canvas.width / gr_sz)));
                apple_y = Math.floor((Math.random() * (canvas.height / gr_sz)));
            }
        }
        console.log(train, apple_x * gr_sz, apple_y * gr_sz);
    }

    // score

    for (i = 0; i < train.length - 1; i++) {
        if (train[tail - 1].x == train[i].x && train[tail - 1].y == train[i].y) {
            tail = 1;
            score = 0;
            x_val = 0;
            y_val = 0;
            pos_x = 20,
            pos_y = 20;
            apple_x = 15,
            apple_y = 15;
            document.getElementById("gameover").style.display = "flex";
            document.getElementById("your_record").innerHTML = "Your record: " + record;
        }
    }
    document.getElementById("score").innerHTML = "<span>Score: " + score + "</span>";            

    // record

    if (record <= score) {
        record = score;
    }
    document.getElementById("record").innerHTML = "<span>Record: " + record + "</span>"; 
    document.cookie = "userRecord=" + record + "; ";
}

function reload () {
    document.cookie = "userRecord=" + record + "; ";   
    document.getElementById("gameover").style.display = "none";
}

function keyPush (evt) {
    switch(evt.keyCode) {
        case 37:
            if (push != 39 && tail > 1) {
                x_val = -gr_sz;
                y_val = 0;
                console.log("left");
                push = 37;
            } else if (tail == 1) {
                x_val = -gr_sz;
                y_val = 0;
                console.log("left");
                push = 37;
            }

            break;
        case 38:
            if (push != 40 && tail > 1) {
                x_val = 0;
                y_val = -gr_sz;
                console.log("up");                
                push = 38;
            } else if (tail == 1) {
                x_val = 0;
                y_val = -gr_sz;
                console.log("up");                
                push = 38;
            }
            break;
        case 39:
            if (push != 37 && tail > 1) {
                x_val = gr_sz;
                y_val = 0;
                console.log("right");
                push = 39;
            } else if (tail == 1) {
                x_val = gr_sz;
                y_val = 0;
                console.log("right");
                push = 39;                    
            }
            break;
        case 40:
            if (push != 38 && tail > 1) {
                x_val = 0;
                y_val = gr_sz;
                console.log("down");
                push = 40;
            } else if (tail == 1) {
                x_val = 0;
                y_val = gr_sz;
                console.log("down");
                push = 40;
            }
            break;
    }
    if (evt.keyCode) {
        console.log(push);
    }
}

function GetCookie() {
    var cookieName = "userRecord";
    function getCookie (cookieName) {
        var name = cookieName + "=";
        var decodedCookie = decodeURIComponent(document.cookie);
        var ca = decodedCookie.split(";");
        for(var i = 0; i <ca.length; i++) {
            var c = ca[i];
            while (c.charAt(0) == " ") {
                c = c.substring(1);
            }
            if (c.indexOf(name) == 0) {
                return c.substring(name.length);
                console.log("cookie update");
            }
        }
        return "";
    };
    cookieValue = getCookie(cookieName);
}