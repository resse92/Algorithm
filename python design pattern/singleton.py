#encoding=utf8

import threading
import time

# python的模块天然就是单例模式,模块第一次导入时,会生成.pyc文件,第二次导入时,会直接加载.pyc文件,我们只需要把相关的函数和数据定义在一个木块中,就可以获得一个单例对象了
class Singleton1(object):
    def foo(self):
        pass
singleton1 = Singleton1()

# 这样直接调用就是单例了

# 使用装饰器
from functools import wraps
def singletonWithDecorator(cls):
    instances = {}
    @wraps(cls)
    def getinstance(*args, **kw):
        if cls not in instances:
            instances[cls] = cls(*args, **kw)
        return instances[cls]
    return getinstance
@singletonWithDecorator
class MyClass(object):
    a = 1

# 使用metaclass
# metaclass可以控制类的创建过程,可以做三件事
# 拦截类的创建
# 修改类的定义
# 返回修改后的类

class SingletonWithMetaclass(type):
    _instances = {}
    def __call__(cls):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton2, cls).__call__(*arg, **kwargs)
        return cls._instances[cls]

class MyClss(metaclass=SingletonWithMetaclass):
    pass

# 这里使用__new__来实现单利模式
class Singleton(object): # 抽象单例
    def __new__(cls, *args, **kw):
        if not hasattr(cls, '__instance'):
            orig = super(Singleton, cls)
            cls._instance = orig.__new__(cls, *args, **kw)
        return cls._instance


# 总线
class Bus(Singleton):
    lock = threading.RLock()
    def sendData(self, data):
        self.lock.acquire()
        time.sleep(3)
        print("sending signal data..." + data)
        self.lock.release()

# 线程对象
class VisitEntity(threading.Thread):
    my_bus = ""
    name = ""
    def getName(self):
        return self.name

    def setName(self, name):
        self.my_bus = Bus()
        self.my_bus.sendData(self.name)

if __name__ == "__main__":
    for i in range(3):
        print("entity %d begin to run..." % i)
        my_entity = VisitEntity()
        my_entity.setName("Entity_" + str(i))
        my_entity.start()
