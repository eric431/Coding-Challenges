How Would I Test The Code Worked?
=================================

As part of the assignment description, the third question was titled as above. How would I test that my code worked? I will break down my response into three bullet points as follows.

* Test cases, I have written a few test case files in this folder that reflect edge cases that result in the code breaking, these are:
    * Negative volume and/or prices (Both volumes and prices cannot be negative).
    * Division by zero due to a total volume of zero for a stock.
    * Invalid parsing formats such the field of a price having a value that contains a character and not a number, 
    * Empty input files
    * Missing files 

* Use of unit testing frameworks such as Google Tests, to mock functions and test the internal workings of code are as expected. However, that seems a bit overkill for this take home assignment so I simply implemented test case files and ran them from my command line.

* Use of system testing frameworks, to test integration of this code with the rest of the codebase.

Notes:

* I have made some fundamental assumptions which means there are test cases I did not test for due to these assumptions and my limited time availability. These are:
    * I assume that the maximum size of trades never exceeds 1000, due to trading hours of the day, limited shares and quantised units of time at which trades happen, trusting the judgement of other members of the team. Had this not been the case I would have implemented, stocks and intervals with a vector and not a c-style array.
    * I assume the maximum total volume never exceeds the capacity of an int type on a 64 bit machine. Were it not the case I would implememt that data type as a long and not an int.

