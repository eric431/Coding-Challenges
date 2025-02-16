"""
random_gen.py

This module provides a `RandomGen` class for generating random numbers \
based on a given probability distribution.

Classes:
    - RandomGen: Implements random mnumber selection.
    
Functions:
    - next_num(): Generates random numbers based on input choice and frequency.

Author:
    Eric Jaiyesimi <ericojaiyesimi@gmail.com>
"""

import random

class RandomGen:
    """
    Class to generate random numbers from a set of numbers according to a specified distribution.

    Attributes:
        random_nums (list): list of random numbers to choose from.
        probabilities (list): list of probabilities corresponding to each random number.

    Methods:
        next_num: Returns the next random generated number give the input
        arguments random_nums and probabilities.

    Example:
        >>> generator = RandomGen([1, 2], [0.6, 0.4])
        >>> generator.next_num()
        1
    """
    def __init__(self, random_nums, probabilities):
        """
        Initialise the random generator class with random numbers to choose
        from and the curresponding probability

        Args:
            random_nums (list): list of random numbers to choose from.
            probabilities (list): list of probabilities corresponding to each random number.
        """
        if len(random_nums) != len(probabilities):
            raise RuntimeError("There is a mismatch between the random \
                                numbers and the probabilities!")
        if sum(probabilities) != 1:
            raise RuntimeError("The cumulative sum of probability is not equal to 1!")
        if any(p < 0 or p > 1 for p in probabilities):
            raise ValueError("Invalid probability entered!")

        self._random_nums = random_nums
        self._probabilities = probabilities

    def next_num(self):
        """Return the next random generated number from the distribution"""
        return random.choices(self._random_nums, weights=self._probabilities) \
            [0]
