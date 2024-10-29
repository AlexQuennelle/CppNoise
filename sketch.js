let loaded = false;
let cppGoodbye = Module.cwrap('Goodbye',null,[null])

function setup() {
  createCanvas(800,800);
}

function draw() {
  if (!loaded) {
    postload()
    loaded = true;
  }
  background(220);
}
function postload() {
  _Goodbye()
  //cppGoodbye();
}
