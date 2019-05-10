let serial; // letiable to hold an instance of the serialport library
let portName = '/dev/cu.usbmodem14241'; // fill in your serial port name here
let inData; // for incoming serial data
let outByte = 0; // for outgoing data

function setup() {
  createCanvas(255, 255); // make the canvas
  serial = new p5.SerialPort(); // make a new instance of the serialport library
  // serial.on('data', serialEvent); // callback for when new data arrives
  serial.on('error', serialError); // callback for errors
  serial.open(portName, {
    baudrate: 9600
  }); // open a serial port
  serial.clear();
}

function serialError(err) {
  console.log('Something went wrong with the serial port. ' + err);
}

function draw() {
  background(255, 255, 255);
  drawCircle();
}

function intervalFunction() {
  getCoords();
  myVar = setInterval(getCoords, 10000);
}

let xPos = 0;
let yPos = 0;
let dir = -1;

// ******* move to stairway location
function getCoords() {
  let serialString = '';
  let offset = 0;
  if (xPos >= 250 || xPos <= 0) {
    dir = -dir;
  }
  offset += 10;
  for (let i = 0; i < 5; i++) {
    xPos += dir * offset;
    yPos += dir * offset;
    let message = "," + xPos + "," + yPos;
    serialString = serialString + message;
    console.log(message);
  }
  serial.write(serialString);
}

let radius = 100;
let angle = 0;
let speed = 0.01;
let centerX = 125;
let centerY = 125;

// ******* move circular motion
function drawCircle(){
  let x = centerX + radius * cos(angle);
  let y = centerY + radius * sin(angle);
  ellipse(x, y, 50, 50);
  angle = angle + speed;
}
function circularMovement () {
    let x = int(centerX + radius * cos(angle));
  	let y = int(centerY + radius * sin(angle));
    ellipse(x, y, 50, 50);
    let other = "," + 100 + "," + 100 + "," + 100 + "," + 100 + "," + 100 + "," + 100 + "," + 100 + "," + 100;
    let message = "," + x + "," + y + other;
    console.log(message);
    serial.write(message);
    angle = angle + speed;
}
