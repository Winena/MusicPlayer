# MusicPlayer
This project aims to use Data Structures to implement a Music Player Manager that add songs, plays next song, plays previous song and displays song list.

The Data Structure chosen in this case was a Doubly Linked list. 

# Justification
Doubly linked lists default to making it easier to navigate to the previous and next address due to the theoretical structure of their nodes. 
As a given node contains the address to both the previous and next node, it makes the time complexity for playing the next song and playing the previous song a perfect O(1). 
Adding a song to the list is also a perfect O(1). However, the Data Structure gives a O(n) for dispaying the list of songs.

