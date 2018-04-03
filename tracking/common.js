window.onload = function () {
    var video = document.getElementById("video");
    var img = document.getElementById("smile");
    // var canvas = document.getElementById("canvas");
    // var context = canvas.getContext("2d");
    var tracker = new tracking.ObjectTracker("face");
    tracker.setInitialScale(1);
    tracker.setStepSize(1.7);
    tracker.setEdgesDensity(0.1);
    tracking.track("#video", tracker, { camera: true });
    tracker.on("track", function (event) {
        // context.clearRect(0, 0, canvas.width, canvas.height);
        event.data.forEach(function (rect) {
            img.width = rect.width + 20;
            img.style.top = rect.y + "px";
            img.style.right = rect.x + "px";
            // context.strokeStyle = "#fff";
            // context.strokeRect(rect.x, rect.y, rect.width, rect.height);
        });
    });
};