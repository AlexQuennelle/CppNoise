let loaded = false;

function setup() {
  createCanvas(800, 800);
}

function draw() {
  if (!loaded) {
    postload();
    loaded = true;
  }
  background(220);
}
function postload() {
  console.log(_Hash(1, 0, 214));
}
