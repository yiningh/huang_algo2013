class Bird {
  
    PVector pos, mousePos;
    float angle;
//    
//    void setup(){
//      mousePos = new PVector(mouseX, mouseY);
//    }
    Bird(float posX, float posY, float thatMousePosX, float thatMousePosY ){
      mousePos = new PVector(thatMousePosX, thatMousePosY);
      pos = new PVector(posX, posY);
//      mousePos.x = thatMousePosX;
//      mousePos.y = thatMousePosY;
    }

    void draw() {
        pushMatrix();{
            translate( pos.x, pos.y );

            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;

            angle = atan2( dy , dx );

            rotate( angle ); //ofRadToDeg

            fill(0);
            beginShape();
              vertex(101,61);
              vertex(101,43);
              vertex(232,52);
              vertex(101,61);
            endShape();

            fill(255,127,0);
            beginShape();
              vertex(55,0);
              bezierVertex(47,0,40,1,33,4);
              bezierVertex(23,6,9,8,0,1);
              bezierVertex(0,1,11,11,23,11);
              bezierVertex(11,20,4,35,4,51);
              bezierVertex(4,79,27,103,55,103);
              bezierVertex(84,103,107,79,107,51);
              bezierVertex(107,23,84,0,55,0);
            endShape();

            fill(255);
            beginShape();
              vertex(97,37);
              bezierVertex(97,48,88,57,76,57);
              bezierVertex(65,57,55,48,55,37);
              bezierVertex(55,25,65,16,76,16);
              bezierVertex(88,16,97,25,97,37);
            endShape();

            fill(0);
            beginShape();
              vertex(90,37);
              bezierVertex(90,44,84,51,76,51);
              bezierVertex(68,51,62,44,62,37);
              bezierVertex(62,29,68,23,76,23);
              bezierVertex(84,23,90,29,90,37);
            endShape();

        }popMatrix();
    }

};
