import time

from logic import normal_distribution, calculate


def test_normal_dist(cycles: int) -> float:
    start = time.time()

    for i in range(cycles):
        calculate(0.006, 0.055, 0.026, 0.012)

    totalTime: float = time.time() - start
    print(f"Time: {totalTime}")
    return totalTime


if __name__ == '__main__':
    cycles: int = 1000
    countTests: int = 10
    summ: float = 0

    for i in range(countTests):
        summ += test_normal_dist(cycles)
    print("Current time:", summ / countTests)