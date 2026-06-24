// 1. Declare as a 16-bit volatile integer at the top of your file
volatile uint16_t stream_var; 

// 2. Call this function ONCE to start the 3-second sound
void start_music_stream()
{
    stream_var = 1200;         // 1200 * 2.5ms = 3000ms (3 seconds)
    Btn_Data_Status[12] = 1;   // Mark as playing
    
    // Explicitly turn the buzzer/audio pin ON here if needed
    // e.g., PORTR.OUTSET = 0x02; 
}

// 3. Keep calling this in your main loop to handle turning it off
void music_stream_playback()
{
    // If 3 seconds have passed and the sound is still flagged as active
    if (stream_var == 0 && Btn_Data_Status[12] == 1)
    {    
        PORTR.OUTTGL = 0x02;      // Toggles the pin to turn off (or use PORTR.OUTCLR = 0x02)
        Btn_Data_Status[12] = 0;   // Clear the status flag so it doesn't repeat
    }   
}

// 4. Your ISR (Stays the same, but handles the 16-bit countdown perfectly)
interrupt [TCF0_OVF_vect] void tcf0_overflow_isr(void) 
{
   if(new_timer_variable != 0)
   { 
      new_timer_variable--;
   }    
   
   if(stream_var != 0)
   {
      stream_var--; // Decrements by 1 every 2.5ms
   }
}
