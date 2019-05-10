var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem14241'; // fill in your serial port name here
var inData; // for incoming serial data
var outByte = 0; // for outgoing data

function setup() {
  // createCanvas(400, 300); // make the canvas
  serial = new p5.SerialPort(); // make a new instance of the serialport library
  serial.on('data', serialEvent); // callback for when new data arrives
  serial.on('error', serialError); // callback for errors
  serial.open(portName); // open a serial port
}

function serialEvent() {
  // read a byte from the serial port:
  var inByte = serial.read();
  // store it in a global variable:
  inData = inByte;
}

function serialError(err) {
  console.log('Something went wrong with the serial port. ' + err);
}

function draw() {
  // black background, white text:
  background(0);
  fill(255);
  // display the incoming serial data as a string:
  text("incoming value: " + inData, 30, 30);
  ellipse(mouseX, mouseY, 50, 50)
}

// let y1 = serialJSON[1].y;

function mousePressed() {
  // map the mouseY to a range from 0 to 255:
  outByte = int(map(mouseX, 0, width, 0, 255));
  // send it out the serial port:
  serial.write(outByte);
  // serial.write(outByte + '\n');
  console.log(serialJSON[0].y);
  console.log(outByte);
}

// function keyPressed() {
//  if (key >=0 && key <=9) { // if the user presses 0 through 9
//  outByte = byte(key * 25); // map the key to a range from 0 to 225
//  }
//  serial.write(outByte); // send it out the serial port
//   console.log(outByte);
// }

function keyPressed() {
  if (key === 'H' || key === 'L') { // if the user presses H or L
    serial.write(key); // send it out the serial port
  }
}
