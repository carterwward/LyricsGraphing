Brandon Lee, Cameron Hudson, Carter Ward, and Jayce Slesar
** must "pip install spotipy" for this to work, it is a package we use to pull song lengths **

Welcome to our Final Project on MPL!

Our project combines c++ with python to make an easy one stop shop to collect data on music lyrics. Our project uses MPL, 
as Python is used by pulling song lyrics directly from genius.com just by the user entering in the album name and artist name. 
Essentially, we scraped genius.com to obtain a map of the album, where the key is the song name and the val is the lyrics of the 
song in a single string! Wow! Are you saying that all I have to enter into my computer is the album name and artist and 
the program will do everything else for me? You betcha!! A difficulty the team ran into was data scrapping for the song 
length on genius.com. This was not achieved, so the user will have to enter the song lengths for each song in the album. 

After a user enters "album, artist" (in that format) and selects the type of music and then hits submit, the backend goes to work
pulling lyrics and song lengths.

A graph is made based on the type of song, which is the polymorphism aspect.  Certain types of songs have different 
stats.  A pop song calculates different stats than rap song.  This took a hot minute so please appreciate.
*Note: not all albums and artists will work because of the way Spotifies API chooses to respresent album titles as string in contrast
with the way Genius represents these titles. Below is a list of working examples:


Rap:
- care for me, saba
- damn, kendrick lamar
- circles, mac miller

Pop:
- my world, justin bieber
- believe, justin bieber
- the fame, lady gaga
