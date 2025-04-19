#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// ✅ 여기! 기기 고유 ID 정의
const char* DEVICE_ID = "gentle-tiger";

const char* ssid = "KT_WiFi_2G_4DFE";   // ✅ 너의 와이파이 이름
const char* password = "FFz54bd791";   // ✅ 와이파이 비밀번호

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("WiFi 연결 중");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi 연결됨!");
  Serial.print("기기 ID: ");
  Serial.println(DEVICE_ID);

  // 여기서 바로 서버에 요청 보낼 수 있음 (지금은 준비 단계니까 생략해도 됨)
}

void loop() {
  // 버튼 누르면 서버에 요청 → 그 로직은 다음 단계에 넣을 거야
}
