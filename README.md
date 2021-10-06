# Air-Conditioning-Automization
Atomization of AC unit that utilizes two Arduinos communicating over radio. This is accomplished by having an Arduino at a focal point of the room, monitoring the temperature using a TMP36 temperature sensor. The monitoring Arduino sends data across a radio channel and received by the controller Arduino. This Arduino deserializes the data and controls a relay which powers the AC unit.
