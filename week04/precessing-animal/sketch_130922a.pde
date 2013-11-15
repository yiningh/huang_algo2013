Bird bird1;
Bird bird2;
float angle;

void setup(){
  size(1024, 768);
    frameRate( 80 );
    background(255);
    angle = 1;
    //ofSetCircleResolution(100);
}

void draw(){
  fill(255);
  rect(0,0,1024,768);
  angle += 0.002;
  PVector bird1Pos = new PVector(0,0);
  PVector bird2Pos = new PVector(0,0);
  
  bird1Pos.x = 500 + cos( angle * 3.7 )*300 ;
  bird1Pos.y = 300 + sin( angle * 4.5 )*300 ;
  
  bird2Pos.x = 600 + cos( angle * 1.4 )*200 ;
  bird2Pos.y = 200 + sin( angle * 3.6 )*200 ;

  PVector mousePos = new PVector( mouseX, mouseY );
  bird1 = new Bird(bird1Pos.x, bird1Pos.y , mousePos.x, mousePos.y);
  bird2 = new Bird(bird2Pos.x, bird2Pos.y , mousePos.x, mousePos.y);
    
  bird1.draw();
  bird2.draw();
}
