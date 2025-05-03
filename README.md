# 🐯 MusicTiger

**MusicTiger**는 버튼 하나로 서버에서 지정된 mp3 음원을 불러와 재생하는  
**Wi-Fi 기반 ESP8266 미니 스피커 프로젝트**입니다.

---

## 🧩 프로젝트 개요

- 버튼을 누르면 Wi-Fi를 통해 Spring 서버에 요청
- 서버는 각 기기에 맞는 mp3 경로를 반환
- ESP8266은 이 mp3 경로를 받아 디코더 모듈로 재생
- 작고 귀여운 사운드 기기, IoT 기반 확장 가능!

---

## 🛠️ 기술 스택

| 파트 | 사용 기술 |
|------|------------|
| 하드웨어 | NodeMCU ESP8266, PAM8403 앰프, VS1053 , 1W 스피커 |
| 펌웨어 | Arduino C++ |
| 서버 | Java Spring Boot (REST API) |
| 통신 | HTTP (Wi-Fi) |

---

## 📁 프로젝트 디렉토리 구조

```plaintext
music-tiger/
├── client/                     # ESP8266 아두이노 코드 (MusicTigerClient.ino)
│   └── MusicTigerClient.ino
│
├── server/                     # Spring Boot 기반 REST API 서버
│   ├── build.gradle            # Gradle 빌드 설정 파일
│   ├── settings.gradle
│   └── src/
│       └── main/
│           ├── java/
│           │   └── com/
│           │       └── musictiger/
│           │           └── MusictigerApplication.java   # 서버 메인 실행 클래스
│           └── resources/
│               └── static/
│                   └── song1.mp3                        # 재생할 mp3 파일


