#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ESP8266WebServer.h>

const int MIC = A0; // 假设麦克风连接到模拟引脚 A0
int value;

void setup() {
  pinMode(MIC, INPUT); // 设置模拟引脚为输入模式
  Serial.begin(115200); // 初始化串口通信
}

void loop() {
  value = analogRead(MIC); // 读取模拟引脚的值
  Serial.print("Sound Level: ");
  Serial.println(value); // 打印读取的值
  delay(1000); // 每秒读取一次（可根据需要调整）
}
