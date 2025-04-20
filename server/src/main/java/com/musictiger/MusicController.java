package com.musictiger;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MusicController {

  // 예시 동영상 URL 반환
  @GetMapping("/video/{deviceId}")
  public String getVideoUrl(@PathVariable String deviceId) {
    // 간단한 예시로 동영상 URL을 반환
    String videoUrl = "https://youtu.be/wj23uKJi3aM?si=DJm7QoV3YCnSmnTr"; // 동영상 링크
    return videoUrl;  // 동영상 URL을 클라이언트에게 반환
  }
}
