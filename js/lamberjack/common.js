canvasWidth = 400;
canvasHeight = 600;
speed = 10;
keypushed = false;
score = 0;
record = 0;

//

heightEarth = 50;
widthTree = 60;

//

jackSize = 100;
jackPosition = canvasWidth / 2 - widthTree / 2 - jackSize - 20;

//

twigsWidth = 100;
twigsHeight = 25;
twigsX = canvasWidth / 2 - widthTree / 2 - twigsWidth;
twigsY = 25 - 12.5;
twigs = [{
	x: twigsX,
	y: twigsY
}];
twigsMove = 100;

makeBody = () => {
	document.body.innerHTML =
		"\
	<div id = 'wrapper'>\
    	<canvas id = 'game'></canvas>\
    	<div id = 'playerInformation'>\
			<div id = 'score'>Score: </div>\
			<div id = 'record'>Record: </div>\
		</div>\
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
	let playerInformation = document.getElementById("playerInformation");
	playerInformation.style.width = canvasWidth + "px";
	playerInformation.style.height = "auto";
	playerInformation.style.boxSizing = "border-box";
	playerInformation.style.marginTop = 5 + "px";
	playerInformation.style.padding = 3 + "px";
	playerInformation.style.backgroundColor = "lightgray"
	playerInformation.style.display = "flex";
	playerInformation.style.justifyContent = "space-between";
};

makeCanvas = () => {
	canvas = document.getElementById("game");
	canvas.width = canvasWidth;
	canvas.height = canvasHeight;
	context = canvas.getContext("2d");
};

window.onload = () => {
	makeBody();
	makeCanvas();
	document.addEventListener("keydown", keyPush);
	setInterval(game, 1000 / speed);
};

game = () => {
	context.fillStyle = "#519fa5";
	context.fillRect(0, 0, canvasWidth, canvasHeight);

	context.fillStyle = "#7e401f";
	context.fillRect(0, canvasHeight - heightEarth, canvasWidth, heightEarth);

	context.fillStyle = "#7e401f";
	context.fillRect(canvasWidth / 2 - widthTree / 2, 0, widthTree, canvasHeight);

	for (let i = 0; i < twigs.length; i++) {
		context.fillStyle = "#7e401f";
		context.fillRect(twigs[i].x, twigs[i].y, twigsWidth, twigsHeight);
	}

	if (twigs[0].y >= canvasHeight - heightEarth - twigsHeight - 12.5)
		if (twigs[0].x - jackPosition == 20 || twigs[0].x - jackPosition == -20) {
			score = 0;
			document.body.style.backgroundColor = "red";
		} else {
			document.body.style.backgroundColor = "white";
		}

	document.getElementById("score").innerText = "Score: " + score;
	document.getElementById("record").innerText = "Record: " + record;

	if (twigs[0].y >= canvasHeight - heightEarth - twigsHeight - 12.5) {
		if (twigs[0].x != -twigsHeight * 4) score++;
		twigs.shift();
	}

	if (score > record) record = score;

	context.fillStyle = "#960f16";
	context.fillRect(
		jackPosition,
		canvasHeight - heightEarth - jackSize,
		jackSize,
		jackSize
	);
};

keyPush = evt => {
	switch (evt.keyCode) {
		case 37:
			jackPosition = canvasWidth / 2 - widthTree / 2 - jackSize - 20;
			keypushed = true;
			break;
		case 39:
			jackPosition = canvasWidth / 2 + widthTree / 2 + 20;
			keypushed = true;
			break;
	}
	if (keypushed) {
		twigsX = Math.round(0 - 0.5 + Math.random() * 3);
		if (twigsX == 0) twigsX = -twigsHeight * 4;
		else if (twigsX == 1) twigsX = canvasWidth / 2 - widthTree / 2 - twigsWidth;
		else if (twigsX == 2) twigsX = canvasWidth / 2 + widthTree / 2;
		for (let i = 0; i < twigs.length; i++) twigs[i].y += twigsMove;
		if (twigs.length <= (canvasHeight - heightEarth) / twigsMove)
			twigs.push({
				x: twigsX,
				y: twigsY
			});
	}
	keypushed = false;
};