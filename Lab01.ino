/*
This programm (sketch) a piece called the "buzzer" to play songs.
The Arduino's tone() command will play notes of a given frequency.
We'll provide a function that takes in note characters (a-g),
and returns the corresponding frequency from this table:

  note   frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz

The lights you add will */

const int ledPin = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int buzzerPin = 9;

// We'll set up an array with the notes we want to play
// change these values to make different songs!

// Length must equal the total number of notes and spaces 

const int songLength = 18;

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone).
// An "array" is a collection of different information that a computer
// can read through.

char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest

// Beats is an array values for each note and rest.
// A "1" represents a quarter-note, 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.

int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};

// The tempo is how fast to play the song.
// To make the song play faster, decrease this value.

int tempo = 150;


void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}


void loop() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
   
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    
    else                          // otherwise, play the note
     //This is where the program determines which light to play at what time.
      
    {
      if (beats[i] == 1 || beats[i] == 2){
          tone(buzzerPin, frequency(notes[i]), duration);
          digitalWrite(ledPin, HIGH);
          digitalWrite(ledPin2, HIGH);
          delay(beats[i]);               // wait for the length of the beat
          digitalWrite(ledPin, LOW);    //Turn ledPin off.
          digitalWrite(ledPin2, LOW);    //Turn ledPin2 off.
         }
         else if (beats[i] == 2){
          tone(buzzerPin, frequency(notes[i]), duration);

           
         }
         else if (beats[i] == 4) {
          tone(buzzerPin, frequency(notes[i]), duration);
          digitalWrite(ledPin3, HIGH);
          delay(beats[i]);               // wait for the length of the beat
          digitalWrite(ledPin3, LOW);    //Turn ledPin3 off.
         }

      else {
       tone(buzzerPin, frequency(notes[i]), duration);
   }
      delay(duration);            // wait for tone to finish
    }
  }
  
  // We only want to play the song once, so we'll pause forever:
  while(true){}
  // If you'd like your song to play over and over,
  // remove the above statement
}


int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  
  int i;
  const int numNotes = 8;  // number of notes we're storing
  
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.

  // For the "char" (character) type, we put single characters
  // in single quotes.

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}

