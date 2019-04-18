var svg = d3.select("svg"),
  width = +svg.node().getBoundingClientRect().width,
  height = +svg.node().getBoundingClientRect().height;
var nodeContainer = d3.select("#nodeContainer")

// svg objects
var link, node, circles, labels, flags;
// the data - an object with nodes and links
var graph;

var nodes, txt, pTxt, recipe, html;

var serialJSON = [];

function mapRange(value, a, b, c, d) {
  // first map value from (a..b) to (0..1)
  value = (value - a) / (b - a);
  // then map it from (0..1) to (c..d) and return it
  return c + value * (d - c);
}

// load the data
d3.json("forD3_employ_code_ITP.json", function(error, _graph) {
  if (error) throw error;
  graph = _graph;
  initializeDisplay();
  initializeSimulation();
});

//////////// FORCE SIMULATION ////////////

// force simulator
var simulation = d3.forceSimulation();

// set up the simulation and event to update locations after each tick
function initializeSimulation() {
  simulation.nodes(graph.nodes);
  initializeForces();
  simulation.on("tick", ticked);
}

// values for all forces
forceProperties = {
  center: {
    x: 0.5,
    y: 0.5
  },
  charge: {
    enabled: true,
    strength: -10,
    distanceMin: 1,
    distanceMax: 2000
  },
  collide: {
    enabled: true,
    strength: .7,
    iterations: 1,
    radius: 5
  },
  forceX: {
    enabled: false,
    strength: .1,
    x: .5
  },
  forceY: {
    enabled: false,
    strength: .1,
    y: .5
  },
  link: {
    enabled: true,
    distance: 30,
    iterations: 1
  }
}

// add forces to the simulation
function initializeForces() {
  // add forces and associate each with a name
  simulation
    .force("link", d3.forceLink())
    .force("charge", d3.forceManyBody())
    .force("collide", d3.forceCollide())
    .force("center", d3.forceCenter())
    .force("forceX", d3.forceX())
    .force("forceY", d3.forceY());
  // apply properties to each of the forces
  updateForces();
}

// apply new force properties
function updateForces() {
  // get each force by name and update the properties
  simulation.force("center")
    .x(width * forceProperties.center.x)
    .y(height * forceProperties.center.y);
  simulation.force("charge")
    .strength(forceProperties.charge.strength * forceProperties.charge.enabled)
    .distanceMin(forceProperties.charge.distanceMin)
    .distanceMax(forceProperties.charge.distanceMax);
  simulation.force("collide")
    .strength(forceProperties.collide.strength * forceProperties.collide.enabled)
    .radius(forceProperties.collide.radius)
    .iterations(forceProperties.collide.iterations);
  simulation.force("forceX")
    .strength(forceProperties.forceX.strength * forceProperties.forceX.enabled)
    .x(width * forceProperties.forceX.x);
  simulation.force("forceY")
    .strength(forceProperties.forceY.strength * forceProperties.forceY.enabled)
    .y(height * forceProperties.forceY.y);
  simulation.force("link")
    .distance(function(d) {
      return d.distance * 20;
    }).strength(0.002)
    .iterations(forceProperties.link.iterations)
    .links(forceProperties.link.enabled ? graph.links : []);

  // updates ignored until this is run
  // restarts the simulation (important if simulation has already slowed down)
  simulation.alpha(1).restart();
}



//////////// DISPLAY ////////////

// generate the svg objects and force simulation
function initializeDisplay() {
  let maxDistance = d3.max(graph.links, function(d) {
    return d.distance;
  });
  let minDistance = d3.min(graph.links, function(d) {
    return d.distance;
  })
  console.log("max:", maxDistance, " min:", minDistance);
  // set the data and properties of link lines

  // flags = d3.select('.container').append('div')
  //  .attr('width', width)
  //  .attr('height', height)
  //  .attr('class', 'flag-container')

  link = svg.append("g")
    .attr("class", "links")
    .selectAll("line")
    .data(graph.links)
    // .data(graph.links.filter(d => d.distance < 1))
    .enter().append("line")
    .style('stroke-opacity', '0.2')
    .style("stroke-width", function(d) {
      let wid = mapRange(d.distance, minDistance, maxDistance, 0.02, 3);
      return 1 / wid;
    });

  // // set the data and properties of node circles
  // node = svg.append("g")
  //       .attr("class", "nodes")
  //       .selectAll("g")
  //       .data(graph.nodes)
  //       .enter().append("g");

  node = nodeContainer.selectAll('.node')
    .data(graph.nodes)
    .enter().append('div')
    .call(d3.drag);

  flags = node.append("div")
    .attr('class', d => `node scaled flag flag-${d.Code}`)
    .call(d3.drag()
      .on("start", dragstarted)
      .on("drag", dragged)
      .on("end", dragended));

  // circles = node.append("circle")
  //     .attr("r", 5)
  //     .call(d3.drag()
  //         .on("start", dragstarted)
  //         .on("drag", dragged)
  //         .on("end", dragended));

  // labels = node.append("text")
  //              .style('color', 'white')
  //              .text(function(d) { return d.Country; })
  //              .attr("x", 60)
  //              .attr("y", 10);


  // visualize the graph
  updateDisplay();
}

// update the display based on the forces (but not positions)
function updateDisplay() {
  node
    .attr("r", forceProperties.collide.radius)
    .attr("stroke", forceProperties.charge.strength > 0 ? "blue" : "red")
  //.attr("stroke-width", forceProperties.charge.enabled==false ? 0 : Math.abs(forceProperties.charge.strength)/15);

  link
    .attr("stroke-width", forceProperties.link.enabled ? 1 : .5)
    .attr("opacity", forceProperties.link.enabled ? 1 : 0);
}

// update the display positions after each simulation tick
function ticked() {
  link
    .attr("x1", function(d) {
      return d.source.x;
    })
    .attr("y1", function(d) {
      return d.source.y;
    })
    .attr("x2", function(d) {
      return d.target.x;
    })
    .attr("y2", function(d) {
      return d.target.y;
    });

  node.attr("style", function(d) {
    return "transform: translate(" + d.x + "px," + d.y + "px)";
  });

  d3.select('#alpha_value').style('flex-basis', (simulation.alpha() * 100) + '%');
}



//////////// UI EVENTS ////////////

function dragstarted(d) {
  if (!d3.event.active) simulation.alphaTarget(0.3).restart();
  d.fx = d.x;
  d.fy = d.y;
}

function dragged(d) {
  d.fx = d3.event.x;
  d.fy = d3.event.y;
}

function dragended(d) {
  if (!d3.event.active) simulation.alphaTarget(0.0001);
  d.fx = null;
  d.fy = null;
}

// update size-related forces
d3.select(window).on("resize", function() {
  width = +svg.node().getBoundingClientRect().width;
  height = +svg.node().getBoundingClientRect().height;
  updateForces();
});

// convenience function to update everything (run after UI input)
function updateAll() {
  updateForces();
  updateDisplay();
}

function keyPressed() {
  if (keyCode === LEFT_ARROW) {
    getCoords();
  }
}

let myVar;

function intervalFunction() {
  getCoords();
  myVar = setInterval(getCoords, 20000);
}

function getCoords() {
  txt = JSON.stringify(node);
  let txtJson = JSON.parse(txt);
  let group = txtJson._groups[0];
  if (pTxt != undefined) {
    let pTxtJson = JSON.parse(pTxt);
    let pGroup = pTxtJson._groups[0];
    // console.log(pTxt);


  txtNew = JSON.stringify(serialJSON);


  for(i = 0; i < group.length; i++) {
    let items = group[i].__data__;
    let pItems = pGroup[i].__data__;
    serialJSON.push({
      "key" : items.key,
      "value" : items.value,
      "px" : pItems.x,
      "py" : pItems.y,
      "x" : items.x,
      "y" : items.y
    })
  }
    console.log(serialJSON);
  }

  pTxt = txt;
  serialJSON = [];
  // getPreviousCoords();
  // recipe = window.open('', 'ResultWindow', 'width=1600,height=1000');
  // html = '<html><head><title>Result Window</title></head><body><div>' + txtNew + '</div></body></html>';
  // recipe.document.open();
  // recipe.document.write(html);
  // recipe.document.close();
}

function getPreviousCoords() {
  pTxt = txt;
}
