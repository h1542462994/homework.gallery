import json
import math
from datetime import datetime, timedelta
from scipy import linalg
import matplotlib.pyplot as plt
import numpy as np


# 做数据图时用到的数据。
class FigureData:
    def __init__(self, data):
        self.__data__ = data
        self.__curve__ = None

    def __len__(self):
        return len(self.data)

    def __iter__(self):
        return self.data.__iter__

    @property
    def data(self):
        return self.__data__

    @data.setter
    def data(self, value):
        self.__data__ = value

    @property
    def curve(self):
        return self.__curve__

    @curve.setter
    def curve(self, value):
        self.__curve__ = value

    @property
    def start_date(self):
        return FigureData.__parse_date(str(self.data[0]['dateId']))

    @property
    def dates(self):
        results = []
        start = self.start_date
        for i in range(0, len(self.data)):
            date = start + timedelta(days=i)
            results.append(date)
        return results

    @property
    def confirmed_counts(self):
        return [i['confirmedCount'] for i in self.data]

    @property
    def current_confirmed_counts(self):
        return [i['currentConfirmedCount'] for i in self.data]

    @property
    def cured_counts(self):
        return [i['suspectedCount'] for i in self.data]

    @property
    def dead_counts(self):
        return [i['deadCount'] for i in self.__data__]

    @property
    def suspected_counts(self):
        return [i['suspectedCount'] for i in self.__data__]

    @staticmethod
    def __parse_date(s):
        return datetime.strptime(s[0:4] + '-' + s[4:6] + "-" + s[6:8], '%Y-%m-%d')

    # 从url处读取json数据
    @staticmethod
    def load(url):
        with open(url) as fw:
            x = json.load(fw)
            return FigureData(x['data'])

    def figure(self):

        # dates = self.dates
        dates = range(0, len(self.data))
        # dates = [math.sqrt(i) for i in range(0, len(self.data))]
        plt.plot(dates, self.confirmed_counts, 'red')
        plt.plot(dates, self.current_confirmed_counts, 'green')
        if not self.curve is None:
            plt.plot(dates, self.curve, 'blue')
        # plt.show()
        plt.savefig(fname='4')

    @staticmethod
    def to_ln(data):
        return [math.log(i, math.e) for i in data]


# 分析的对象
class AnalyseDataObject:
    def __init__(self, xs, ys, functions):
        self.xs = xs
        self.ys = ys
        self.num = len(functions)
        self.functions = functions

    def y_values(self):
        a = self.construct__matrix()
        return [sum([a[l] * self.functions[l](i) for l in range(self.num)]) for i in self.xs]

    def y_value_other(self, xs):
        a = self.construct__matrix()
        return [sum([a[l] * self.functions[l](i) for l in range(self.num)]) for i in xs]

    def __get__phi(self, a, b):
        return sum([self.functions[a](self.xs[i]) * self.functions[b](self.xs[i]) for i in range(len(self.xs))])

    def __get__phi_f(self, a):
        return sum([self.functions[a](self.xs[i]) * self.ys[i] for i in range(len(self.xs))])

    def construct__matrix(self):
        l1 = []
        l2 = []
        for i in range(0, self.num):
            temp = []
            for j in range(0, self.num):
                temp.append(self.__get__phi(i, j))
            l1.append(temp)
            l2.append(self.__get__phi_f(i))
        return linalg.solve(np.array(l1), np.array(l2))

# 封装了关于图像的一系列操作
class FigureOperation:
    def __init__(self, data: FigureData, is_file=False):
        self.data = data
        self.is_file = is_file
        plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签

    def get_vars(self, vs):
        return [math.sqrt(-1/vs[0]), math.sqrt(-vs[1]/vs[0]*0.5), math.pow(math.e, vs[2]+(vs[1]/vs[0]*0.5)**2)]

    # 计算残差
    def __get__diff(self, ys):
        ys_raw = self.data.current_confirmed_counts
        return sum([(ys[i]-ys_raw[i])**2 for i in range(len(ys_raw))])

    def __show(self):
        if self.is_file:
            plt.savefig('out')
        else:
            plt.show()

    # 显示原始的数据
    def figure_raw_data(self):
        plt.plot(self.data.dates, self.data.confirmed_counts, 'red')
        plt.plot(self.data.dates, self.data.current_confirmed_counts, 'green')
        self.__show()

    # 显示y-sqrt(x)的图像
    def figure_a_data(self):
        xs = [math.sqrt(i) for i in range(0, len(self.data.data))]
        plt.plot(xs, self.data.confirmed_counts, 'red')
        plt.plot(xs, self.data.current_confirmed_counts, 'green')
        self.__show()

    # 显示ln(y)-x的图像
    def figure_b_data_with_curve(self):
        xs = range(0, len(self.data.data))

        confirm = [math.log(i, math.e) for i in self.data.confirmed_counts]
        current = [math.log(i, math.e) for i in self.data.current_confirmed_counts]
        fs = [lambda x: x, lambda x: math.sqrt(x), lambda x: 1]
        ana = AnalyseDataObject(xs, current, fs)
        print(ana.construct__matrix())

        plt.plot(xs, confirm, 'red')
        plt.plot(xs, current, 'green')
        plt.plot(xs, ana.y_values(), 'blue')
        self.__show()

    def figure_b_data_with_curve_raw(self):
        xs = range(0, len(self.data.data))

        current = [math.log(i, math.e) for i in self.data.current_confirmed_counts]
        fs = [lambda x: x, lambda x: math.sqrt(x), lambda x: 1]
        ana = AnalyseDataObject(xs, current, fs)
        print(ana.construct__matrix())
        ys = [math.pow(math.e, i) for i in ana.y_values()]
        print(self.__get__diff(ys))

        plt.plot(xs, self.data.confirmed_counts, 'red')
        plt.plot(xs, self.data.current_confirmed_counts, 'green')
        plt.plot(xs, ys, 'blue')
        self.__show()

    def figure_b_data(self):
        xs = range(0, len(self.data.data))

        confirm = [math.log(i, math.e) for i in self.data.confirmed_counts]
        current = [math.log(i, math.e) for i in self.data.current_confirmed_counts]

        plt.plot(xs, confirm, 'red')
        plt.plot(xs, current, 'green')
        self.__show()

    def figure_c_data(self, th):
        confirm_raw = self.data.current_confirmed_counts
        confirm = list(filter(lambda x: x[1] >= math.pow(math.e, th),[[i, confirm_raw[i]] for i in range(0, len(self.data.data))]))
        xs = [i[0] for i in confirm]
        ys = [math.log(i[1],math.e) for i in confirm]
        fs = [lambda x: x, lambda x: math.sqrt(x), lambda x: 1]
        ana = AnalyseDataObject(xs, ys, fs)
        m = ana.construct__matrix()
        print(m)
        print(self.get_vars(m))
        raw_xs = range(0, len(self.data.data))
        y_values = [math.pow(math.e, i) for i in ana.y_value_other(raw_xs)]
        print(self.__get__diff(y_values))
        plt.plot(raw_xs, self.data.confirmed_counts, 'red')
        plt.plot(raw_xs, self.data.current_confirmed_counts, 'green')
        plt.plot(raw_xs, y_values, 'blue')
        self.__show()

    def figure_re(self, th):
        confirm_raw = self.data.current_confirmed_counts
        confirm = list(filter(lambda x: x[1] >= math.pow(math.e, th),
                              [[i, confirm_raw[i]] for i in range(0, len(self.data.data))]))
        xs = [i[0] for i in confirm]
        ys = [math.log(i[1], math.e) for i in confirm]
        fs = [lambda x: x, lambda x: math.sqrt(x), lambda x: 1]
        ana = AnalyseDataObject(xs, ys, fs)
        vs = self.get_vars(ana.construct__matrix())
        l = len(self.data.data)
        dates = self.data.dates[1:l]
        raw_xs = range(1, l)
        y_values = [(1-1/(vs[0]**2)+vs[1]/(vs[0]**2)/math.sqrt(i)) for i in raw_xs]
        ys = [(confirm_raw[i]-confirm_raw[i-1])/confirm_raw[i-1] + 1 for i in raw_xs]
        us = [0.95 for _ in raw_xs]
        plt.plot(dates, y_values, 'red')
        plt.plot(dates, ys, 'green')
        plt.plot(dates, us, 'orange')
        self.__show()


if __name__ == '__main__':
    f = FigureOperation(FigureData.load('./data.json'), True)
    # f.figure_raw_data()
    # f.figure_a_data()
    # f.figure_b_data()
    # f.figure_b_data_with_curve()
    # f.figure_b_data_with_curve_raw()
    # f.figure_c_data(9)
    f.figure_re(0)
    functions = [lambda x: x, lambda x: math.sqrt(x), lambda x: 1]
