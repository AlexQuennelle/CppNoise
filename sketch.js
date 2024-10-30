let loaded = false;

let noiseGrid = [];
let img;

function setup() {
  createCanvas(800, 800);
  img = createImage(width, height)
}

function draw() {
  if (!loaded) {
    postload();
    loaded = true;
  }
  background(img);
}
function postload() {
  img.loadPixels()
  //console.log(_FractalPerlin2D(1,0,1,100,2))
  noiseDetail(15, 0.5)
  for (let x = 0; x < width; x++) {
    for (let y = 0; y < height; y++) {
      img.set(x, y, color(_FractalPerlin2D(x, y, 1, 100, 15) * 255))
      //img.set(x,y, color(noise(x * 0.01, y * 0.01) * 255))
    }
  }
  img.updatePixels();
}
