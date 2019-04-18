let data;

function preload() {
  data = loadJSON("coor.json");
}

function setup() {
  createCanvas(1600, 1000);
  // data = loadJSON("coor.json", drawNodes);
}

function draw() {
  background(100, 100, 100);
  let nodes = data._groups[0];
  let dataLength = nodes.length;
  for (i = 0; i < dataLength; i++) {
    let xCoor = data._groups[0][i].__data__.x;
    let yCoor = data._groups[0][i].__data__.y;
    // console.log(xCoor, yCoor);
    // fill(255,0,0);
    ellipse(xCoor, yCoor, 10, 10);
  }
}
