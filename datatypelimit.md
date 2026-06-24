We often come across bugs that appear as a result of wrong data type declreation.
Recently I created a timer variable and declared it as unsigned char (0 - 256). 
It was related to an audio output control.I observed that even though I give more than 1 second counters for 2.5 ms interupt timer my audio playback finishes up faster.
The delay was not properly applied as delay time variable was char and limited hence changing it to integer helped me to resolve the bug and make my audio playback work properly in timestamp.

