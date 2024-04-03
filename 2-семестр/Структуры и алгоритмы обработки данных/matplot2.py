 
import matplotlib.pyplot as plt
import numpy as np




plt.xticks([0, 200000, 400000, 600000, 800000, 1000000])
plt.ticklabel_format(axis="x", style='plain')

plt.title("График количества операций")
plt.xlabel("n")
plt.ylabel("T(n)")


x = np.array([100, 1000, 100000, 1000000])
y = np.array([9999, 999999, 99999999, 9999999999])
plt.plot(x, y, "-r", label="Худший случай")

x = np.array([100, 1000, 100000, 1000000])
y = np.array([5091, 425377, 44078245, 4464575959])
plt.plot(x, y, "-b",  label="Случайный массив")

x = np.array([100, 1000, 100000, 1000000])
y = np.array([99, 999, 9999, 99999])
plt.plot(x, y, "-g", label="Лучший случай")



plt.legend(loc="upper left")

plt.show()
