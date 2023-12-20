#include "Gameboard.h"

// start_beat_millis is used in our transition table, but it is realistically always set to mils.


void runTestSuite() {
  Serial.println("Running test suite...");

  curr_song = songList[0];
  beatmap = curr_song.beats;
  bpm_values = curr_song.bpm_values;
  bpm_change_indexes = curr_song.bpm_change_indexes;
  
  // state updateFSM(state curState, long mils, bool startBtn, bool upBtn)
  // void setMillis(unsigned long millis)
  // unsigned long myMillis()
  // 1 = sSONG_MENU, 2=sCOUNTDOWN, 3=sUPDATE_GAME, 4=sGAME_OVER

  // Todo: Reset updateFSM?

  // Test 1
  // 1-1, mils=10000, start_button=false, up_button=false
  // checks isFirstCall = False
  setMillis(10000);
  outputFunctionsCalled = "";
  state curState = updateFSM(sSONG_MENU, myMillis(), false, false);
  if (curState != sSONG_MENU) {
    Serial.println("Test #1 1-1a failed");
    Serial.println("Expected: sSONG_MENU");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (isFirstCall) {
    Serial.println("Test #1 1-1a failed");
    Serial.println("Expected: isFirstCall = false");
    Serial.print("Actual: ");
    Serial.println(isFirstCall);
    return;
  } else if (outputFunctionsCalled != "displayStart_LCD(0, 0, 1)\n") {
    Serial.println("Test #1 1-1a failed");
    Serial.println("Expected: displayStart_LCD(0, 0, 1)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }




  // Test 2
  // 1-1, mils=5000, start_button=false, up=true
  setMillis(5000);
  outputFunctionsCalled = "";
  curState = updateFSM(sSONG_MENU, myMillis(), false, true);
  if (curState != sSONG_MENU) {
    Serial.println("Test #2 1-1b failed");
    Serial.println("Expected: sSONG_MENU");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (outputFunctionsCalled != "displayStart_LCD(0, 1, 0)\n") {
    Serial.println("Test #2 1-1b failed");
    Serial.println("Expected: displayStart_LCD(0, 1, 0)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 3
  // 1-2, mils=5500, start_button=True, up_button=false
  // checks isFirstCall = true
  // mocked displayStart_LCD(true, false, false)
  setMillis(5500);
  outputFunctionsCalled = "";
  curState = updateFSM(sSONG_MENU, myMillis(), true, false);
  if (curState != sCOUNTDOWN) {
    Serial.println("Test #3 1-2 failed");
    Serial.println("Expected: sCOUNTDOWN");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (!isFirstCall) {
    Serial.println("Test #3 1-2 failed");
    Serial.println("Expected: isFirstCall = true");
    Serial.print("Actual: ");
    Serial.println(isFirstCall);
    return;
  } else if (outputFunctionsCalled != "displayStart_LCD(1, 0, 0)\n") {
    Serial.println("Test #3 1-2 failed");
    Serial.println("Expected: displayStart_LCD(1, 0, 0)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 4
  // 2-2, mils=7000, start_button=false, end_button=false
  // set savedClock=6000, countdown=2 //
  // checks savedClock=6000, countdown=1 //
  // mocked displayCountdown_LCD(countdown=1) TODO Mock these
  setMillis(7000);
  outputFunctionsCalled = "";
  savedClock = 6000;
  countdown = 2;
  curState = updateFSM(sCOUNTDOWN, myMillis(), false, false);
  if (curState != sCOUNTDOWN) {
    Serial.println("Test #4 2-2 failed");
    Serial.println("Expected: sCOUNTDOWN");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 7000) {
    Serial.println("Test #4 2-2 failed");
    Serial.println("Expected: savedClock = 7000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (countdown != 1) {
    Serial.println("Test #4 2-2 failed");
    Serial.println("Expected: countdown = 1");
    Serial.print("Actual: ");
    Serial.println(countdown);
    return;
  } else if (outputFunctionsCalled != "displayCountdown_LCD(2)\n") {
    Serial.println("Test #4 2-2 failed");
    Serial.println("Expected: displayCountdown_LCD(2)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 5
  // 2-3, mils=10000, start_button=false, end_button=false
  // set savedClock=9000, countdown=-1 //
  // checks savedClock=10000, countdown=-1 //
  // mock displayGame_LCD(combo_max, combo)
  setMillis(10000);
  outputFunctionsCalled = "";
  savedClock = 9000;
  countdown = -1;
  combo_max = 10;
  combo = 4;
  curState = updateFSM(sCOUNTDOWN, myMillis(), false, false);
  if (curState != sUPDATE_GAME) {
    Serial.println("Test #5 2-3 failed");
    Serial.println("Expected: sUPDATE_GAME");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 10000) {
    Serial.println("Test #5 2-3 failed");
    Serial.println("Expected: savedClock = 10000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (countdown != -1) {
    Serial.println("Test #5 2-3 failed");
    Serial.println("Expected: countdown = -1");
    Serial.print("Actual: ");
    Serial.println(countdown);
    return;
  } else if (outputFunctionsCalled != "displayGame_LCD(10, 4)\n") {
    Serial.println("Test #5 2-3 failed");
    Serial.println("Expected: displayGame_LCD(10, 4)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 6
  // 3-4, mils=11000, start_button=true, end_button=false
  // set savedClock=10500 //
  // checks savedClock=11000, finish_count=6 //
  // mock clearLEDs()
  setMillis(11000);
  outputFunctionsCalled = "";
  curState = updateFSM(sUPDATE_GAME, myMillis(), true, false);
  if (curState != sGAME_OVER) {
    Serial.println("Test #6 3-4 failed");
    Serial.println("Expected: sGAME_OVER");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 11000) {
    Serial.println("Test #6 3-4 failed");
    Serial.println("Expected: savedClock = 11000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (finish_count != 6) {
    Serial.println("Test #6 3-4 failed");
    Serial.println("Expected: finish_count = 6");
    Serial.print("Actual: ");
    Serial.println(finish_count);
    return;
  } else if (outputFunctionsCalled != "clearLEDs()\n") {
    Serial.println("Test #6 3-4 failed");
    Serial.println("Expected: clearLEDs()");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 7
  // 3-3, mils=8000, start_button=false, end_button=false
  // set savedClock=7900, nextUpdateTime=7000, beatmap[0]=0b10110110, beat_index=0, beats_length=100
  // checks savedClock=8000, nextUpdateTime=7000, beat_index=1
  // mock moveLEDs(false), displayGame_LCD(10, 4), performTimeStepDelay(8000)
  setMillis(8000);
  outputFunctionsCalled = "";
  savedClock = 7900;
  nextUpdateTime = 7000;
  beatmap[0] = 0b10110110;
  beat_index = 0;
  curr_song.beats_length = 100;
  curState = updateFSM(sUPDATE_GAME, myMillis(), false, false);
  if (curState != sUPDATE_GAME) {
    Serial.println("Test #7 3-3 failed");
    Serial.println("Expected: sUPDATE_GAME");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 8000) {
    Serial.println("Test #7 3-3 failed");
    Serial.println("Expected: savedClock = 8000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (nextUpdateTime != 7000) {
    Serial.println("Test #7 3-3 failed");
    Serial.println("Expected: nextUpdateTime = 7000");
    Serial.print("Actual: ");
    Serial.println(nextUpdateTime);
    return;
  } else if (beat_index != 1) {
    Serial.println("Test #7 3-3 failed");
    Serial.println("Expected: beat_index = 1");
    Serial.print("Actual: ");
    Serial.println(beat_index);
    return;
  } else if (outputFunctionsCalled != "moveLEDs(0)\ndisplayGame_LCD(10, 4)\nperformTimeStepDelay(8000)\n") {
    Serial.println("Test #7 3-3 failed");
    Serial.println("Expected: moveLEDs(0)\ndisplayGame_LCD(10, 4)\nperformTimeStepDelay(8000)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  } 

  // Test 8
  // 3-3, mils=8000, start_button=false, end_button=false 
  // set nextUpdateTime=7000, beatmap[100] = 0b11111111, beat_index=100, finish_count=5, beats_length=100
  // check nextUpdateTime=7000, beat_index=100, finish_count=4, beats_length=100
  // performTimeStepDelay(8000), moveLEDs(true), displayGame_LCD(max_combo=10, combo=4)
  setMillis(8000);
  outputFunctionsCalled = "";
  nextUpdateTime = 7000;
  beatmap[100] = 0b11111111;
  beat_index = 100;
  finish_count = 5;
  curState = updateFSM(sUPDATE_GAME, myMillis(), false, false);
  if (curState != sUPDATE_GAME) {
    Serial.println("Test #8 3-3 failed");
    Serial.println("Expected: sUPDATE_GAME");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (nextUpdateTime != 7000) {
    Serial.println("Test #8 3-3 failed");
    Serial.println("Expected: nextUpdateTime = 7000");
    Serial.print("Actual: ");
    Serial.println(nextUpdateTime);
    return;
  } else if (beat_index != 100) {
    Serial.println("Test #8 3-3 failed");
    Serial.println("Expected: beat_index = 100");
    Serial.print("Actual: ");
    Serial.println(beat_index);
    return;
  } else if (finish_count != 4) {
    Serial.println("Test #8 3-3 failed");
    Serial.println("Expected: finish_count = 4");
    Serial.print("Actual: ");
    Serial.println(finish_count);
    return;
  } else if (outputFunctionsCalled != "performTimeStepDelay(8000)\nmoveLEDs(1)\ndisplayGame_LCD(10, 4)\n") {
    Serial.println("Test #8 3-3 failed");
    Serial.println("Expected: performTimeStepDelay(8000)\nmoveLEDs(1)\ndisplayGame_LCD(10, 4)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 9
  // 3-4, mils=5000, start_button=false, end_button=false
  // set savedClock=4900, nextUpdateTime=4000, finish_count=-1
  // check savedClock=5000, nextUpdateTime=4000, finish_count=6
  // mock performTimeStepDelay(5000)
  setMillis(5000);
  outputFunctionsCalled = "";
  savedClock = 4900;
  nextUpdateTime = 4000;
  finish_count = -1;
  curState = updateFSM(sUPDATE_GAME, myMillis(), false, false);
  if (curState != sGAME_OVER) {
    Serial.println("Test #9 3-4 failed");
    Serial.println("Expected: sGAME_OVER");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 5000) {
    Serial.println("Test #9 3-4 failed");
    Serial.println("Expected: savedClock = 5000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (nextUpdateTime != 4000) {
    Serial.println("Test #9 3-4 failed");
    Serial.println("Expected: nextUpdateTime = 4000");
    Serial.print("Actual: ");
    Serial.println(nextUpdateTime);
    return;
  } else if (finish_count != 6) {
    Serial.println("Test #9 3-4 failed");
    Serial.println("Expected: finish_count = 6");
    Serial.print("Actual: ");
    Serial.println(finish_count);
    return;
  } else if (outputFunctionsCalled != "performTimeStepDelay(5000)\n") {
    Serial.println("Test #9 3-4 failed");
    Serial.println("Expected: performTimeStepDelay(5000)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 10
  // 4-4, mils=7000, start_button=false, end_button=false
  // set savedClock=6000, isFirstCall=True
  // check savedClock=6000, isFirstCall=False
  // mock displayEnd_LCD(10, false, true)
  setMillis(7000);
  outputFunctionsCalled = "";
  savedClock = 6000;
  isFirstCall = true;
  curState = updateFSM(sGAME_OVER, myMillis(), false, false);
  if (curState != sGAME_OVER) {
    Serial.println("Test #10 4-4 failed");
    Serial.println("Expected: sGAME_OVER");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 6000) {
    Serial.println("Test #10 4-4 failed");
    Serial.println("Expected: savedClock = 6000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (isFirstCall) {
    Serial.println("Test #10 4-4 failed");
    Serial.println("Expected: isFirstCall = false");
    Serial.print("Actual: ");
    Serial.println(isFirstCall);
    return;
  } else if (outputFunctionsCalled != "displayEnd_LCD(10, 0, 1)\n") {
    Serial.println("Test #10 4-4 failed");
    Serial.println("Expected: displayEnd_LCD(10, 0, 1)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  // Test 11
  // 4-1, mils=7000, start_button=true, end_button=false
  // set savedClock=1000
  // check savedClock=7000, countdown=3, beat_index=0, isFirstCall=false
  // mock displayEnd_LCD(20, true, false)
  setMillis(7000);
  outputFunctionsCalled = "";
  savedClock = 1000;
  combo_max = 20;
  curState = updateFSM(sGAME_OVER, myMillis(), true, false);
  if (curState != sSONG_MENU) {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: sSONG_MENU");
    Serial.print("Actual: ");
    Serial.println(curState);
    return;
  } else if (savedClock != 7000) {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: savedClock = 7000");
    Serial.print("Actual: ");
    Serial.println(savedClock);
    return;
  } else if (countdown != 3) {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: countdown = 3");
    Serial.print("Actual: ");
    Serial.println(countdown);
    return;
  } else if (beat_index != 0) {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: beat_index = 0");
    Serial.print("Actual: ");
    Serial.println(beat_index);
    return;
  } else if (!isFirstCall) {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: isFirstCall = true");
    Serial.print("Actual: ");
    Serial.println(isFirstCall);
    return;
  } else if (outputFunctionsCalled != "displayEnd_LCD(20, 1, 0)\n") {
    Serial.println("Test #11 4-1 failed");
    Serial.println("Expected: displayEnd_LCD(20, 1, 0)");
    Serial.print("Actual: ");
    Serial.println(outputFunctionsCalled);
    return;
  }

  Serial.println("All tests passed!");
  
}
