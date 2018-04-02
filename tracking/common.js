window.onload = function () {
    var video = document.getElementById("video");
    var img = document.getElementById("img");
    var canvas = document.getElementById("canvas");
    var context = canvas.getContext("2d");
    var tracker = new tracking.ObjectTracker("face");
    tracker.setInitialScale(1);
    tracker.setStepSize(1.7);
    tracker.setEdgesDensity(0.1);
    tracking.track("#video", tracker, { camera: true });
    tracker.on("track", function (event) {
        context.clearRect(0, 0, canvas.width, canvas.height);
        event.data.forEach(function (rect) {
            // window.plot(rect.x, rect.y, rect.width, rect.height);
            // for (let i = 1; i <= rect.total; i++) {
            // name = "move_" + i;
            // console.log(name);
            // let show = document.createElement("div");
            // show.id = name;
            // show.className = "move";
            // wrapper.appendChild(show);
            // if (document.getElementById(window[name]) != null) {
            //     document.getElementById(window[name]).style.width = rect.width + "px";
            //     document.getElementById(window[name]).style.height = rect.height + "px";
            //     document.getElementById(window[name]).style.top = rect.y + "px";
            //     document.getElementById(window[name]).style.left = rect.x + "px";
            //         document.getElementById(window[name]).style.backgroundColor = parseInt(window[name].style.left) > (canvas.width / 2) - rect.width / 2 ? "#C3E885" : "#FF4E57";
            //     }
            // }
            context.strokeStyle = "#fff";
            context.strokeRect(rect.x, rect.y, rect.width, rect.height);
            console.log(rect);
        });
    });
    window.plot = (x, y, w, h) => {
        var rect = document.createElement("div");
        document.querySelector(".demo-container").appendChild(rect);
        rect.classList.add("rect");
        rect.style.width = w + "px";
        rect.style.height = h + "px";
        rect.style.left = (img.offsetLeft + x) + "px";
        rect.style.top = (img.offsetTop + y) + "px";
    };
};