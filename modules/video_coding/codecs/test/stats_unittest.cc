/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/video_coding/codecs/test/stats.h"

#include "test/gtest.h"

namespace webrtc {
namespace test {

TEST(StatsTest, AddSingleFrame) {
  Stats stats;
  FrameStatistic* frame_stat = stats.AddFrame();
  EXPECT_EQ(0ull, frame_stat->frame_number);
  EXPECT_EQ(1u, stats.size());
}

TEST(StatsTest, AddMultipleFrames) {
  Stats stats;
  const size_t kNumFrames = 1000;
  for (size_t i = 0; i < kNumFrames; ++i) {
    FrameStatistic* frame_stat = stats.AddFrame();
    EXPECT_EQ(i, frame_stat->frame_number);
  }
  EXPECT_EQ(kNumFrames, stats.size());
}

}  // namespace test
}  // namespace webrtc
