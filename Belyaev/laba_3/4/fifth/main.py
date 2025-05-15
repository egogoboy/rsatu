import numpy
import matplotlib.pyplot as pyplot
import matplotlib

matplotlib.use('TkAgg')

x = numpy.linspace(-5, 5, 400)
y1 = x**2 + x**4 - x + 5
y2 = -x**2 + 2*x + 15

pyplot.plot(x, y1, label='y1 = x^2 + x^4 - x + 5')
pyplot.plot(x, y2, label='y2 = -x^2 + 2x + 15')
pyplot.legend()
pyplot.grid()
pyplot.title('Graphics')
pyplot.xlabel('x')
pyplot.ylabel('y')

pyplot.show()
