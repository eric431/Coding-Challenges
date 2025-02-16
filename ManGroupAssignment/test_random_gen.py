"""
test_random_gen.py

This module provides a test suite implemented for the RandomGen class for \
selecting random numbers based on a given probability distribution. 

Classes:
    - TestRandomGen: Implements test suite for RandomGen class.

Unit Tests:
    - test_mismatched_input_length: Verifies that random numbers and \
      probabilities have the same dimension lists result in a ValueError.

    - test_invalid_probability: Ensures invalid probabilities raise an \
      error.

    - test_invalid_probability_sum: Checks if an error is raised when 
      probabilities do not sum to 1.

    - test_chi_squared_goodness_of_fit: Ensures the generated numbers \
      follow the expected probability distribution.

Author:
    Eric Jaiyesimi <ericojaiyesimi@gmail.com>
"""

from collections import Counter
import unittest

from scipy.stats import chisquare

from random_gen import RandomGen

class TestRandomGen(unittest.TestCase):
    """
    Unit test suite for the RandomGen class.

    This test suite validates the functionality of the RandomGen class, 
    ensuring that the RandomGen class works as specified. It includes tests 
    for probability distribution accuracy, error handling, and input validation.

    Test Cases:
        - test_mismatched_input_length: Verifies that random numbers and \
          probabilities have the same dimension 
          lists result in a ValueError.

        - test_invalid_probability: Ensures invalid probabilities raise an \
          error.

        - test_invalid_probability_sum: Checks if an error is raised when 
          probabilities do not sum to 1.

        - test_chi_squared_goodness_of_fit: Ensures the generated numbers \
          follow the expected probability distribution.

    Example Usage:
        Run the test suite using unittest:
        >>> python -m unittest test_random_gen.py
    """
    def setUp(self):
        """
        This method sets up the random number generator for subsequent tests.
        """
        self.random_numbers = [-1, 0, 1, 2, 3] # test input for random numbers
        self.probabilities = [0.01, 0.3, 0.58, 0.1, 0.01] # test input for probabilities
        self.generator = RandomGen(self.random_numbers, self.probabilities)

    def test_mismatched_input_length(self):
        """
        This function tests if there is mismatched input length between \
        the random_num input and the probability input.
        An exception is expected to be raised in this test
        """
        random_num = [-1, 0]
        probabilities = [0.7]
        with self.assertRaises(Exception):
            RandomGen(random_num, probabilities)

    def test_invalid_probability(self):
        """
        This function tests if there is an invalid probability.
        An exception is expected to be raised in this function
        """
        random_num = [-1, 0]
        probabilities = [1.5, -0.5]
        with self.assertRaises(ValueError):
            RandomGen(random_num, probabilities)

    def test_invalid_probability_sum(self):
        """
        This function tests if the sum of the probability is greater than one.
        An exception is expected to be raised in this function
        """
        random_num = [-1, 0, 1, 2]
        probabilities = [0.7, 0.6, 0.4, 0.3]
        with self.assertRaises(Exception):
            RandomGen(random_num, probabilities)

    def test_chi_square_goodness_of_fit(self):
        """
        This test aims to determine if the distribution of the numbers \
        generated according to the input distribution are consistent using \
        chi-square goodness of fit test.
        """
        sample_size_list = [100, 1000, 10000, 100000] # run test on multiple sample sizes
        for sample_size in sample_size_list:

            # the p_value is sensitive to the sample size, so the lines below
            # adjust the p_value based on the sample size
            if sample_size >= 100000:
                p_value = 0.001
            if sample_size > 1000:
                p_value = 0.01
            else:
                p_value = 0.05

            # create observed distribution from the generator for testing that
            # generated numbers follow the input probability
            observed_distribution = Counter([self.generator.next_num() for _ in range(sample_size)])

            # create expected frequency based on the input probability and
            # sample size
            expected_distribution = {n: p * sample_size for n, p in \
                                     zip(self.random_numbers, self.probabilities)}

            observed = [observed_distribution.get(n, 0) for n in self.random_numbers]
            expected = [expected_distribution[n] for n in self.random_numbers]

            # run the chi-square statistical test to compare the distribution
            # of the generated data
            p_value_distribution = chisquare(observed, expected)[1]

            # assert that calculated p_value from the distribution is greater
            # than the appropriate p_value for the sample size.
            self.assertGreater(p_value_distribution, p_value, f"Chi-Square \
                                test failed! p-value = \
                               {p_value_distribution} at sample size = \
                               {sample_size}")

if __name__ == '__main__':
    unittest.main()
