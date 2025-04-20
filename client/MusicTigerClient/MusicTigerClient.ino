#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* DEVICE_ID = "gentle-tiger";  // 기기 고유 ID
const char* ssid = "KT_WiFi_2G_4DFE";    // Wi-Fi SSID
const char* password = "ffz54bd791";     // Wi-Fi 비밀번호

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);  // Wi-Fi 연결 시도
  Serial.print("WiFi 연결 중");

  while (WiFi.status() != WL_CONNECTED) {  // 연결될 때까지 대기
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi 연결 완료!");
  Serial.print("기기 ID: ");
  Serial.println(DEVICE_ID);

  sendRequestToServer();  // 동영상 URL 요청 함수 호출
}

void loop() {
  delay(10000);  // 너무 빠르게 루프 안 돌게 잠깐 대기
}

void sendRequestToServer() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverIp = "http://192.168.0.35:8080";  // 서버 IP
    String url = serverIp + "/video/" + DEVICE_ID;  // 동영상 URL 요청 경로

    Serial.print("서버에 요청 중: ");
    Serial.println(url);

    WiFiClient client;  // WiFiClient 객체 생성
    http.begin(client, url);  // 선언한 client 객체 사용

    int httpCode = http.GET();  // GET 요청 보내기

    if (httpCode > 0) {  // 서버에서 정상 응답이 오면
      Serial.printf("📨 응답 코드: %d\n", httpCode);
      String payload = http.getString();  // 동영상 URL을 받아옴
      Serial.println("🎬 받은 동영상 URL:");
      Serial.println(payload);  // 동영상 URL 출력
    } else {
      Serial.printf("❌ 요청 실패. 코드: %d\n", httpCode);  // 요청 실패 시 출력
    }

    http.end();  // HTTP 연결 종료
  } else {
    Serial.println("🚫 WiFi 연결 안 됨");
  }
}
