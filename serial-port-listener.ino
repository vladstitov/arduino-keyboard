#include <Keyboard.h>
#include <Mouse.h>
char c;
String cmd;
char letter;
void setup() {
  Serial.begin(9600);
  Keyboard.begin();
   Mouse.begin();
  }

void loop() { 
 if(Serial.available()>0) {
char c = Serial.read();
  if (c != '\n' && c != '\r' ) {
    cmd+=c;   
  }else {
     ///Serial.println(" char:" + c);
    /// Serial.println(" cmd:" + cmd);
    if(c == '\n') {      
      ////  Serial.println(cmd +" l: " + String(cmd.length()));
      if(cmd.length() == 1){
        switch(cmd[0]) {
           case 'V': Keyboard.releaseAll();
             break;   
          case 'S': Keyboard.press(KEY_LEFT_SHIFT);
            break;
          case 'I': Keyboard.release(KEY_LEFT_SHIFT);
            break;
          case 'E': Keyboard.write(KEY_RETURN);
            break;
          case 'T': Keyboard.press(KEY_LEFT_CTRL);
            break;
          case 'L': Keyboard.release(KEY_LEFT_CTRL);
             break;
           case 'A': Keyboard.press(KEY_LEFT_ALT);
             break;
           case 'D': Keyboard.press(KEY_DELETE);
             break;             
           case 'Z': Keyboard.release(KEY_LEFT_ALT);
             break;             
           case 'M': Keyboard.write(KEY_RIGHT_ARROW);
             break;
           case 'N': Keyboard.write(KEY_LEFT_ARROW);
             break;
                                 
          case 'B': Keyboard.write(KEY_BACKSPACE);           
            break;
          case 'P': Keyboard.press(KEY_F12);
                   delay(100);
                   Keyboard.release(KEY_F12);
            break;
          case 'O': Keyboard.write(KEY_F11);           
            break;          
           case 'Q':             
                  Keyboard.press(KEY_ESC);
                  delay(100);
                  Keyboard.release(KEY_ESC);        
            break;    
         /// case 'C': Mouse.click();
         ///   break;
          ///case 'D': Mouse.press();
          //  break;             
         // case 'U': Mouse.release();
          //  break;
          default:
                  Keyboard.write(cmd[0]);
          break;          
        }
      }
      else {
         delay(100);
         Serial.println(cmd);
      }
      //  int coma = cmd.indexOf(",");
      //  String x = cmd.substring(0, coma);
      //  String y = cmd.substring(coma + 1); 
      //  Mouse.move(x.toInt(), y.toInt(),0);
     // }
     //String res = cmd;   
   // cmd = "";
  //  delay(100);
  //  Serial.println("end " + res + res.length());
    ////  Serial.println(" V " + cmd + " L " + L); 
       
      
   //int value = cmd.toInt();
  // value +=2;
  ///  Serial.println(value);    
   
        
    /// number_1 = atoi(strings[0]); convert string data to numbers
    }
    
  }
 
 
 
/// Keyboard.write(c);
 }
  /// Keyboard.println(incomingString);
  /// Keyboard.write('A');
 ///  Serial.println(incomingString);
 

}
