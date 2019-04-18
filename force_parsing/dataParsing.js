let data = {};
let links = [];

let fs = require('fs');

data = JSON.parse(fs.readFileSync('merged_code.json'));

function setup() {
  // console.log(data);
  for (let i = 0; i < data.length; i++) {
    for (let j = i + 1; j < data.length; j++) {
        links.push({
          "source": i,
          "target": j,
          "distance": Math.abs(data[i].Unemployment - data[j].Unemployment)
        })
    }
  }
  let linksDATA = JSON.stringify(links);
  fs.writeFileSync('links.json', linksDATA);
}

setup()
