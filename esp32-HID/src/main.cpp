#include <Arduino.h>
/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("mohamed Keyboard");

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();

  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    Serial.println("Sending 'Hello world'...");

    // change language
    bleKeyboard.press(KEY_RIGHT_ALT);
    bleKeyboard.press(KEY_RIGHT_SHIFT);
    bleKeyboard.releaseAll();
    bleKeyboard.print("mohamed");
    delay(1000);

    // change language
    bleKeyboard.press(KEY_RIGHT_ALT);
    bleKeyboard.press(KEY_RIGHT_SHIFT);
    bleKeyboard.releaseAll();
    bleKeyboard.print("lpl]");
    delay(1000);

    /*
        Serial.println("Sending Enter key...");
        bleKeyboard.write(KEY_RETURN);
        delay(1000);

        Serial.println("Sending Play/Pause media key...");
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
        delay(1000);
    */

    //
    // Below is an example of pressing multiple keyboard modifiers
    // which by default is commented out.
    //
    /* 
     Serial.println("Sending Ctrl+Alt+Delete...");
     bleKeyboard.press(KEY_LEFT_CTRL);
     bleKeyboard.press(KEY_LEFT_ALT);
     bleKeyboard.press(KEY_DELETE);
     delay(100);
     bleKeyboard.releaseAll();
     */
  }
  Serial.println("Waiting 5 seconds...");
  delay(5000);
}