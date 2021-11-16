TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QT += core

SOURCES += \
        fibonaccibigint.cpp \
        fibonacciull.cpp \
        main.cpp

HEADERS += \
    fibonacci.h \
    fibonaccibigint.h \
    fibonacciull.h
