# Random Number Generator

## Overview
This package describes a random generator object implemented in Python that generates any number from a set of input numbers with a probability of occurrence associated with each number.

## Set-up
This package has been shipped as a zip file with necessary package requirements, which can be installed by running the '*pip install -r requrements.txt*' command, and has been tested and implemented in Python 3.12. The corresponding unit tests for this package has been included in this folder, and is explained in more detail in the next section.

## Unit Tests
Unit tests have been written for the following reasons:

* **Mismatched Dimensions**: when using this package, it is important that the dimensions of the random numbers and their associated probability is consistent, and as such a test has been written to ensure that  an exception is raised when it does not have matching dimensions.

* **Invalid Probability**: probability has values between 0 and 1, hence why this test has been written. To test that when the function is called that invalid probability values ,outside of the acceptable range, cannot be entered.

* **Cumulative Sum of Probability greater than 1**: the total sum of input probabilities cannot be greater than 1, and as such a test has been written to ensure that this does not occur.

* **Correct Probability Distribution**: the core functionality of this class is to implement a random number generator according to a specified probability distribution. The main issue that arises when testing this functionality is correct can be summarised by the **Law of Large Numbers**, which can be paraphrased in this context that as the number of independent trials approaches infinity (or very large numbers) the relative frequency of outcomes converge to their true probability. As such, testing whether the distribution works appropriately at smaller sample sizes and is not due to a bug or incorrect logic is tricky. The way this has been resolved is by using the chi square measure of good fit statistical test, as part of a minimal and effective unit test. This is done to ensure that the p value of the generator based on each sample size is appropriate.

## Example Usage
```
from random_gen import RandomGen

if __name__ == '__main__':
    random_numbers = [-5, -4, -1, 0, 1, 2]
    probability = [0.5, 0.1. 0.05, 0.05, 0.15, 0.15]

    generator = RandomGen(random_numbers, probability)

    distribution = [generator.next_num() for _ in range(1000)]
```