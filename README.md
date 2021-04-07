<div dir = "rtl" lang = "he">

# Two-dimensional bulletin board

In the neighborhood's bulletin board, people paste an ad on top of each other, and the ads mix ([like this video] (https://www.youtube.com/watch?v=LgIq9BppBLw)).
In this assignment we will write a department for managing the bulletin board.
The department support the following functions:

* `post` - receives a position (line and column), direction (horizontal or vertical), and a string representing an ad,
And post the string on the board in the appropriate place.
* `read '- receives a position (line and column), direction (horizontal or vertical), and a number of characters, reads what is written on the board in the nanton position and the length, and returns a string. The letter in each slot on the board is the last letter pasted there.
* `show` - Displays the current bulletin board in a convenient way to read, in any format of your choice.

Examples of the operation can not be found in [Demo.cpp] (../ Demo.cpp).

Details:

* The line and column numbers and character numbers are non-negative integers (unsigned int).
* The top row is 0 and the left column is 0.
* In each slot on which nothing is pasted, there is an underline
